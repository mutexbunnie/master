#include "graphicsscene.h"
#include <QDebug>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QGraphicsSceneMouseEvent>
#include "edge.h"
#include "cmath"
#include "math.h"
#include <QGraphicsItem>
#include <QSqlRecord>
#include <QSqlField>

GraphicsScene::GraphicsScene(QObject *parent) :QGraphicsScene(parent)
{
    models=new QVector<QAbstractItemModel*>();
    this->setItemIndexMethod(QGraphicsScene::NoIndex);

    entityIcons=new QVector<EntityIcon*>();
    this->linkMode=false;


     timer = new QTimer(this);
     connect (timer, SIGNAL(timeout()), this, SLOT(layoutItems()));
     entityLookup =   new  QMap <QString, QMap<QString, EntityIcon*>* >();
     edges=new QVector<Edge*>();

}


void GraphicsScene::addSheetLink( QSqlTableModel* projectLink )
{
    /*model display, not copy and load*/
    this->projectLink=projectLink;

    for ( int i = 0; i <projectLink->rowCount(); ++i )
    {
        QModelIndex item = projectLink->index( i, 0);
        QString entityTypeName1= item.data().toString();
        QString uid1=item.sibling (item.row(),item.column()+1).data().toString();
        QString entityTypeName2= item.sibling(item.row(),item.column()+2).data().toString();
        QString uid2= item.sibling(item.row(),item.column()+3).data().toString();

        EntityIcon* entityIcon1 = entityLookup->value(entityTypeName1)->value(uid1);
        EntityIcon* entityIcon2 = entityLookup->value(entityTypeName2)->value(uid2);
        createEdge(entityIcon1,entityIcon2);
    }

}


void GraphicsScene::hideOrphan()
{
    for( int i =0; i<entityIcons->size() ;i++)
    {
        if (((*entityIcons)[i])->connectionList->size()==0)
         ((*entityIcons)[i])->hide();
    }
}


void GraphicsScene::addEntityIcon(QGraphicsItem *parent, QModelIndex index, EntityType *entityType,QPointF pos)
{
    EntityIcon* tmpEntityIcon=new EntityIcon(parent,index,entityType,pos);

    QString entityTypeName =tmpEntityIcon->entityType->name;

    QMap<QString, EntityIcon*>*  tmpMap = entityLookup->value(entityTypeName);

    if (tmpMap==0)
    {
        tmpMap = new QMap<QString, EntityIcon*>();
        entityLookup->insert(entityTypeName,tmpMap);
    }

    tmpMap->insert(tmpEntityIcon->getUidValue(),tmpEntityIcon);

    this->addItem(tmpEntityIcon);
    this->entityIcons->append(tmpEntityIcon);

}

void GraphicsScene::layoutItems()
{

 float forceX,forceY;


  for( int i=0; i<entityIcons->size(); i++)
  {
      forceX=0;
      forceY=0;
                      if  (!((*entityIcons)[i])->isVisible()) continue;

                      for (int k=i+1; k<entityIcons->size(); k++)
                      {
                              if  (!((*entityIcons)[k])->isVisible()) continue;


                                            //collect force
                                              float distanceX=  ((*entityIcons)[i])->x()-((*entityIcons)[k])->x();
                                              float distanceY=  ((*entityIcons)[i])->y()-((*entityIcons)[k])->y();

                                              float forceXK,forceYK;
                                              forceXK=0;
                                              forceYK=0;

                                              float distance=(distanceX*distanceX)+(distanceY*distanceY);

                                              if (distance>0)
                                              {
                                                   forceXK= (400*distanceX)/distance;
                                                   forceYK= (400*distanceY)/distance;
                                              }
                                              if (distance <10)   forceXK+=100;


                                              if (((*entityIcons)[i])->connectionList->contains((*entityIcons)[k]))
                                              {
                                                   forceXK-= distanceX/75.0;
                                                   forceYK-= distanceY/75.0;
                                              }

                                              (*entityIcons)[k]->moveBy(-forceXK,-forceYK);
                                            forceX+=  forceXK;
                                            forceY+=  forceYK;

                       }

        (*entityIcons)[i]->moveBy(forceX,forceY);

    }


}

void GraphicsScene::addModel(QAbstractItemModel *model,EntityType*  tmpEntity)
{
    models->append(model);
    connect( model, SIGNAL(modelReset ()), this, SLOT(reset()));
    connect( model, SIGNAL(layoutChanged ()), this, SLOT(layoutChanged()));
    connect( model, SIGNAL(rowsInserted ( const QModelIndex & , int , int  )), this, SLOT(rowsInserted ( const QModelIndex & , int , int  )));
    connect( model, SIGNAL(rowsAboutToBeRemoved ( const QModelIndex & , int , int  )), this, SLOT(rowsAboutToBeRemoved ( const QModelIndex & , int , int  )));
    connect( model, SIGNAL(dataChanged ( const QModelIndex & , const QModelIndex &  )), this, SLOT(dataChanged ( const QModelIndex & , const QModelIndex &  )));

    for ( int i = 0; i <model->rowCount(); ++i )
    {
        //fix 0 if not uid?

        QModelIndex item = model->index( i, 0);

         QMap<QString,QPointF>* sourceMap = sheetMap->value(tmpEntity->name);

         QPointF pos=QPointF(0.0,0.0);

         if (sourceMap!=0)
         {
            pos= sourceMap->value(item.data().toString());
            qDebug() <<pos;
         }
         addEntityIcon(0,item,tmpEntity,pos);
    }
}


void GraphicsScene::setLinkMode(bool linkEnabled)
{
    this->linkMode=linkEnabled;
}

void GraphicsScene::setAutoLayout(bool autoLayout)
{
    if (autoLayout) timer->start(100);
    else      timer->stop();
}

void GraphicsScene::addSheetMap(QMap<QString, QMap<QString, QPointF> *> * sheet)
{
    sheetMap=sheet;
}

void GraphicsScene::save()
{
    //memleak here,fix
   sheetMap = new  QMap<QString, QMap<QString,QPointF>* >();
   for( int i=0; i<entityIcons->size(); i++)
   {
       QString entityTypeName =(*entityIcons)[i]->entityType->name;
       QMap<QString,QPointF>*  tmpMap =sheetMap->value(entityTypeName);
       if (tmpMap==0)
       {
           tmpMap= new  QMap<QString,QPointF>();
           sheetMap->insert(entityTypeName,tmpMap);
       }

       tmpMap->insert((*entityIcons)[i]->getUidValue(),(*entityIcons)[i]->pos());

   }





   for( int i=0; i<edges->size(); i++)
   {
       qDebug()<<((*edges)[i])->sourceIcon->entityType->name;
       qDebug()<<((*edges)[i])->sourceIcon->getUidValue();

       qDebug()<<((*edges)[i])->destIcon->entityType->name;
       qDebug()<<((*edges)[i])->destIcon->getUidValue();

  }

}

QMap<QString, QMap<QString, QPointF> *> *GraphicsScene::getSheetMap()
{
     return sheetMap;
}

void GraphicsScene::reset() /*! helper function to implement a reset call for a custom view */
{
    qDebug()<<"GraphicsScene::reset()";
}

void GraphicsScene::layoutChanged()
{
    qDebug()<<"GraphicsScene::layoutChanged()";
}

void GraphicsScene::rowsInserted(const QModelIndex & parent, int start, int end ) /*! callback which is called by the model on item insertion operations */
{
 qDebug()<<"GraphicsScene::rowsInserted( const QModelIndex & parent, int start "<<start<< "int end "<<end <<")";

  /*for ( int i = start; i <= end; ++i )
    {
      QModelIndex item = parent.model()->index( i, 0, parent );
      addEntityIcon(0,item,tmpEntity);
    }*/
}

void GraphicsScene::rowsAboutToBeRemoved( const QModelIndex & parent, int start, int end ) /*! callback which is called by the model on item removal operations */
{
 // qDebug()<<" GraphicsScene::rowsAboutToBeRemoved(  const QModelIndex & parent, int start "<<start<< "int end "<<end <<")";
}

void GraphicsScene::dataChanged(const QModelIndex& topLeft, const QModelIndex& bottomRight ) /*! callback which is called by the model on itemodel.index(4, 2) change operations */
{
   /* //  qDebug()<<"GraphicsScene::dataChanged( const QModelIndex & , const QModelIndex & )";
    for (int row=topLeft.row(); row<=bottomRight.row(); row++)
    {
        for (int col=topLeft.column(); col<=bottomRight.column(); col++)
        {
            qDebug()<<"Row:"<<row<<"Col:"<<col;
        }
    }*/
}

/*creates an edge object for screen viewing*/

void GraphicsScene::createEdge( EntityIcon* source, EntityIcon* dest)
{
    Edge* tmpEdge = new Edge(source,dest);
    source->addConnection(dest);
    addItem(tmpEdge);
    edges->append(tmpEdge);


    update();
}

void GraphicsScene::createEdge( QString src_entitytype,QString src_uid,QString dest_entitytype,QString dest_uid )
{

    QMap<QString,EntityIcon*>*  tmpMap =entityLookup->value(src_entitytype);
    EntityIcon* source= tmpMap->value(src_uid);


    QMap<QString,EntityIcon*>*  tmpMap2 =entityLookup->value(dest_entitytype);
    EntityIcon* dest = tmpMap2->value(dest_uid);

    if (dest&&source)
        createEdge(   source,  dest);

}

/*stores an edge in the db*/
void GraphicsScene::storeEdge(EntityIcon* source, EntityIcon* dest)
{
    QSqlRecord tmp_record;
    QSqlField entitytype_1("entitytype_1",QVariant::String);
    QSqlField uid1        ("UID1",QVariant::String);
    QSqlField entitytype_2("entitytype_2",QVariant::String);
    QSqlField uid2        ("UID2",QVariant::String);
    entitytype_1.setValue(source->entityType->name);
    uid1.setValue(source->getUidValue());
    entitytype_2.setValue(dest->entityType->name);
    uid2.setValue(dest->getUidValue());
    tmp_record.insert(0,entitytype_1);
    tmp_record.insert(1,uid1);
    tmp_record.insert(2,entitytype_2);
    tmp_record.insert(3,uid2);
    projectLink->insertRecord(0,tmp_record);
    projectLink->submitAll();
}


void GraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QList<QGraphicsItem*> prevSelected= this->selectedItems();
   // qDebug() <<"GraphicsScene::mousePressEvent1";
    QGraphicsScene::mousePressEvent(event);

    QList<QGraphicsItem*> selectedNow= this->selectedItems();

    if (this->linkMode)
    {
        for (int i=0; i<prevSelected.size(); i++)
        {
            for (int j=0; j<selectedNow.size(); j++)
            {
                if  (prevSelected[i]!=selectedNow[j])
                {
                //  qDebug()<<"Adding" << ((EntityIcon*)selectedNow[j])->labelItem->text() << "to "<< ((EntityIcon*)prevSelected[i])->labelItem->text();
                    createEdge(((EntityIcon*)selectedNow[j]),((EntityIcon*)prevSelected[i]));
                    storeEdge(((EntityIcon*)selectedNow[j]),((EntityIcon*)prevSelected[i]));
                    createEdge(((EntityIcon*)prevSelected[i]),(EntityIcon*)selectedNow[j]);
                    storeEdge(((EntityIcon*)prevSelected[i]),(EntityIcon*)selectedNow[j]);
                    /*fix double addition*/
                }
            }
        }
    }
}

void GraphicsScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    //qDebug() <<"QGraphicsScene::mouseReleaseEvent(event)1";
    QGraphicsScene::mouseReleaseEvent(event);
    //qDebug() <<"QGraphicsScene::mouseReleaseEvent(event)2";
}
