#include "graphicsscene.h"
#include <QDebug>
#include <QSqlTableModel>
#include <QGraphicsSceneMouseEvent>
#include "edge.h"
#include "cmath"
#include "math.h"
#include <QGraphicsItem>

GraphicsScene::GraphicsScene(QObject *parent) :QGraphicsScene(parent)
{
    models=new QVector<QAbstractItemModel*>();
    this->setItemIndexMethod(QGraphicsScene::NoIndex);

    activeIcons=0;
    entityIcons=new QVector<EntityIcon*>();
    lastSelectedIcon=0;

    timer = new QTimer(this);
    connect (timer, SIGNAL(timeout()), this, SLOT(layoutItems()));
    timer->start(100);
}




void GraphicsScene::addEntityIcon(QGraphicsItem *parent, QModelIndex index, EntityType *entityType)
{

    EntityIcon* pix=new EntityIcon(parent,index,entityType);
    this->addItem(pix);
    this->entityIcons->append(pix);
}

void GraphicsScene::layoutItems()
{
  float forceX,forceY;
  for( int i=0; i<entityIcons->size(); i++)
   {



            forceX=0;
            forceY=0;



            for( int k=0; k<entityIcons->size(); k++)
            {

                        if (k!=i)
                        {
                              float distanceX= ((*entityIcons)[i])->x()- ((*entityIcons)[k])->x();
                              float distanceY= ((*entityIcons)[i])->y()- ((*entityIcons)[k])->y();
                              float distance=(distanceX*distanceX)+(distanceY*distanceY);

                              if (distance>0)
                              {
                                   forceX+= (75*distanceX)/distance;
                                   forceY+= (75*distanceY)/distance;
                              }

                               if (((*entityIcons)[i])->connectionList->contains((*entityIcons)[k]))
                              {


                                forceX-= distanceX/50;
                                forceY-= distanceY/50;
                               }



                                /*double weight = (edgeList.size() + 1) * 10;
                                foreach (Edge *edge, edgeList) {
                                    QPointF vec;
                                    if (edge->sourceNode() == this)
                                        vec = mapToItem(edge->destNode(), 0, 0);
                                    else
                                        vec = mapToItem(edge->sourceNode(), 0, 0);
                                    xvel -= vec.x() / weight;
                                    yvel -= vec.y() / weight;
                                }

                                if (qAbs(xvel) < 0.1 && qAbs(yvel) < 0.1)
                                    xvel = yvel = 0;*/

                        }

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

    /* fix
    tmpEntity=new EntityType();
    tmpEntity->addIcon(":/icons/star.png");
    tmpEntity->setName("star");
    fix*/
  qDebug()<<tmpEntity->iconPath;
    qDebug()<<model->rowCount();
    for ( int i = 0; i <model->rowCount(); ++i )
       {
         QModelIndex item = model->index( i, 0);
         addEntityIcon(0,item,tmpEntity);

         //qDebug() << item.data();
       }


}

/*! helper function to implement a reset call for a custom view */
void GraphicsScene::reset()
{
    qDebug()<<"GraphicsScene::reset()";
}


void GraphicsScene::layoutChanged()
{
    qDebug()<<"GraphicsScene::layoutChanged()";
}


/*! callback which is called by the model on item insertion operations */

void GraphicsScene::rowsInserted(const QModelIndex & parent, int start, int end )
{

 qDebug()<<"GraphicsScene::rowsInserted( const QModelIndex & parent, int start "<<start<< "int end "<<end <<")";

  /*for ( int i = start; i <= end; ++i )
    {
      QModelIndex item = parent.model()->index( i, 0, parent );
      addEntityIcon(0,item,tmpEntity);
    }*/
}

/*! callback which is called by the model on item removal operations */
void GraphicsScene::rowsAboutToBeRemoved( const QModelIndex & parent, int start, int end )
{
 // qDebug()<<" GraphicsScene::rowsAboutToBeRemoved(  const QModelIndex & parent, int start "<<start<< "int end "<<end <<")";
}

/*! callback which is called by the model on itemodel.index(4, 2) change operations */
void GraphicsScene::dataChanged(const QModelIndex& topLeft, const QModelIndex& bottomRight )
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

void GraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QList<QGraphicsItem*> prevSelected= this->selectedItems();
   // qDebug() <<"GraphicsScene::mousePressEvent1";
    QGraphicsScene::mousePressEvent(event);

    QList<QGraphicsItem*> selectedNow= this->selectedItems();

    for (int i=0; i<prevSelected.size(); i++)
    {
        for (int j=0; j<selectedNow.size(); j++)
        {
            if  (prevSelected[i]!=selectedNow[j])
            {
               qDebug()<<"Adding" << ((EntityIcon*)selectedNow[j])->labelItem->text() << "to "<< ((EntityIcon*)prevSelected[i])->labelItem->text();

               ((EntityIcon*)selectedNow[j])->addConnection(((EntityIcon*)prevSelected[i]));
               (((EntityIcon*)prevSelected[i]))->addConnection((EntityIcon*)selectedNow[j]);
            }
        }
    }
}

void GraphicsScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    //qDebug() <<"QGraphicsScene::mouseReleaseEvent(event)1";
    QGraphicsScene::mouseReleaseEvent(event);
    qDebug() <<"QGraphicsScene::mouseReleaseEvent(event)2";
   // qDebug() << "Woop" <<this->items().size();

    for (int i=0;i<items().size();i++)
    {

        qDebug()<<((EntityIcon*)(this->items()[i]));
    }

}
