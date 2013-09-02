#include "graphicsscene.h"

//TODO:Fix Foward declaration
#include "entitytype.h"

GraphicsScene::GraphicsScene(QObject *parent) :QGraphicsScene(parent)
{

    models=new QVector<QAbstractItemModel*>();
    this->setItemIndexMethod(QGraphicsScene::NoIndex);

    entityIcons=new QVector<EntityIcon*>();
    this->linkMode=false;

    // timer = new QTimer(this);
     //connect (timer, SIGNAL(timeout()), this, SLOT(layoutItems()));
     entityLookup =   new  QMap <QString, QMap<QString, EntityIcon*>* >();
     edges=new QVector<Edge*>();
     setSceneRect(0,0,1000000,1000000);
     gvgraph = new GVGraph();

}



void GraphicsScene::addSheetLink( QSqlTableModel* projectLink )
{
    //TODO:: model display, not copy and load
    this->projectLink=projectLink;

    for ( int i = 0; i <projectLink->rowCount(); ++i )
    {
        QModelIndex item = projectLink->index( i, 0);
        QString entityTypeName1= item.data().toString();
        QString uid1=item.sibling (item.row(),item.column()+1).data().toString();
        QString entityTypeName2= item.sibling(item.row(),item.column()+2).data().toString();
        QString uid2= item.sibling(item.row(),item.column()+3).data().toString();
        qDebug()<<entityTypeName2;

        EntityIcon* entityIcon1 = entityLookup->value(entityTypeName1)->value(uid1);
        EntityIcon* entityIcon2 = entityLookup->value(entityTypeName2)->value(uid2);
        createEdge(entityIcon1,entityIcon2);
       // createEdge(entityIcon2,entityIcon1);
    }

}

void GraphicsScene::autoZoom()
{
    //QRect viewSize= this->views().at(0)->geometry();
    //this->i

    qreal  ymin=((*entityIcons)[0])->pos().y();
    qreal  xmin=((*entityIcons)[0])->pos().x();

    qreal  xmax=((*entityIcons)[0])->boundingRect().width()+((*entityIcons)[0])->x();
    qreal  ymax=((*entityIcons)[0])->boundingRect().height()+((*entityIcons)[0])->y();

    EntityIcon* smallestX=(*entityIcons)[0];
    EntityIcon* smallestY=(*entityIcons)[0];

    for( int i =1; i<entityIcons->size() ;i++)
    {

        EntityIcon * tmpIcon =(*entityIcons)[i];
        xmin= qMin(tmpIcon->pos().x(), xmin);
        ymin= qMin( tmpIcon->pos().y(), ymin);
        xmax= qMax( tmpIcon->boundingRect().width()+tmpIcon->x(), xmax);
        ymax= qMax( tmpIcon->boundingRect().height()+tmpIcon->y(), ymax);

        if (xmin==tmpIcon->pos().x() ) smallestX=tmpIcon;
        if (ymin==tmpIcon->pos().y()) smallestY=tmpIcon;
    }

    qDebug()<<xmin<<xmax<<ymin<<ymax;
    qDebug()<<this->sceneRect();
    //qDebug()<<"Smalest X"<<smallestX->pos();
   // qDebug()<<"Smalest Y"<<smallestY->pos();
   // qDebug()<<QPointF(xmin+((xmax-xmin)/2),ymin+((ymax-ymin)/2));


   this->views().at(0)->fitInView(xmin,ymin,xmax-xmin,ymax-ymin,Qt::KeepAspectRatio);
   ((GraphicsView*)(this->views().at(0)))->setCenter(QPointF(xmin+((xmax-xmin)/2),ymin+((ymax-ymin)/2)));
   this->addRect(QRectF(xmin,ymin,xmax-xmin,ymax-ymin));
}


void GraphicsScene::addJoin(QString entityType1,QString entityType2,QAbstractItemModel *model)
{
    //connects for model?
    for ( int i = 0; i <model->rowCount(); ++i )
    {
       createEdge(entityType1,model->index( i, 0).data().toString(),entityType2,model->index( i, 1).data().toString());
       createEdge(entityType2,model->index( i, 1).data().toString(),entityType1,model->index( i, 0).data().toString());
    }


 /*  //EntityIcon* icon, QVector<EntityIcon* >* iconVector)

   QVector<EntityIcon* > doneVector;

   int k=0;

   for (int i=0; i< entityIcons->size();i++)
   {
       QVector<EntityIcon* > iconVector;
       if  (!doneVector.contains(entityIcons->at(i)))
       {
           iconVector=outputCluster(entityIcons->at(i),iconVector);

           if (iconVector.size()>0)
           {

               k=k+1;
           }

           for( int j=0; j<iconVector.size(); j++)
           {
               qDebug()<<k<<iconVector.at(j)->getUidValue();
               doneVector.append(iconVector[j]);
           }
       }

   }*/


}


/*QVector<EntityIcon* > GraphicsScene::outputCluster(EntityIcon* icon, QVector<EntityIcon* > iconVector)
{
    QVector<EntityIcon* > emptyResult;
    if (!icon->isVisible()) return emptyResult;

    iconVector.append(icon);

    for ( int i=0; i<icon->connectionList->size(); i++)
    {

        if (!iconVector.contains(icon->connectionList->at(i)))
            {
                QVector<EntityIcon* > tmpResult;
                tmpResult=outputCluster(icon->connectionList->at(i),iconVector);

                for (int j=0; j<tmpResult.size();j++)
                {
                    if (!iconVector.contains(tmpResult[j]))
                    iconVector.append(tmpResult[j]);
                }
            }
    }

     return iconVector;
}*/


void GraphicsScene::hideOrphan()
{
    for( int i =0; i<entityIcons->size() ;i++)
    {
        if (((*entityIcons)[i])->connectionList->size()==0)
         ((*entityIcons)[i])->hide();
        //else
          // ((*entityIcons)[i])->show();
    }
}


void GraphicsScene::addEntityIcon(QGraphicsItem *parent, QGraphicsScene* scene,  QModelIndex index, EntityType *entityType,QPointF pos)
{
    EntityIcon* tmpEntityIcon=new EntityIcon(parent,scene,index,entityType,pos);

    QString entityTypeName =tmpEntityIcon->entityType->name;

    QMap<QString, EntityIcon*>*  tmpMap = entityLookup->value(entityTypeName);

    if (tmpMap==0)
    {
        tmpMap = new QMap<QString, EntityIcon*>();
        entityLookup->insert(entityTypeName,tmpMap);
    }

    tmpMap->insert(tmpEntityIcon->getUidValue(),tmpEntityIcon);

    this->entityIcons->append(tmpEntityIcon);

}

void GraphicsScene::layoutItems(QString layout)
{
    if (layout!="elastic")
    {
        gvgraph->openGraph();

        for( int i=0; i<entityIcons->size(); i++)
        {
            if  (!((*entityIcons)[i])->isVisible()) continue;
            gvgraph->addNode(((*entityIcons)[i]));
        }

        for( int i=0; i<entityIcons->size(); i++)
        {
            for (int k=0; k< ((*entityIcons)[i])->connectionList->size();k++)
            {
                 EntityIcon* tmpIcon=(*((*entityIcons)[i])->connectionList)[k];
                 if  (!tmpIcon->isVisible()) continue;
                 gvgraph->addEdge(((*entityIcons)[i]),tmpIcon);
            }
        }
        //gvgraph->layout("dot");

        gvgraph->layout(layout);
        gvgraph->closeGraph();
        //failure to create cairo surface: out of memory
        autoZoom();
    }
    else
    {
        for (int w=0; w<100; w++)
        {
            for( int i=0; i<entityIcons->size(); i++)
            {
                float forceX=0;
                float forceY=0;
                //push -> sqrt(push*pull)=min distance between 2 objects.
                float pull=2;
                float push=(((150)*(150))/pull);
                if  (!((*entityIcons)[i])->isVisible()) continue;

                for (int k=0; k<entityIcons->size(); k++)
                {
                   if (k==i) continue;
                   if  (!((*entityIcons)[k])->isVisible()) continue;
                                      //collect force
                   qreal distanceX=  ((*entityIcons)[i])->x()-((*entityIcons)[k])->x();
                   qreal distanceY=  ((*entityIcons)[i])->y()-((*entityIcons)[k])->y();
                   float distance=2*((distanceX*distanceX)+(distanceY*distanceY));
                   if (distance>0)
                   {
                      forceX+= ( push*distanceX)/distance;
                      forceY+=  (push*distanceY)/distance;
                   }
                }

                double activeConnections =0;
                for (int k=0; k< ((*entityIcons)[i])->connectionList->size();k++)
                {
                    EntityIcon* tmpIcon=(*((*entityIcons)[i])->connectionList)[k];
                    if  (!tmpIcon->isVisible()) continue;
                    activeConnections+=1;

                }

                double  weight = ( activeConnections+ 1) * pull ;
                //qDebug()<<weight;
                for (int k=0; k< ((*entityIcons)[i])->connectionList->size();k++)
                {

                    EntityIcon* tmpIcon=(*((*entityIcons)[i])->connectionList)[k];
                    if  (!tmpIcon->isVisible()) continue;

                    float distanceX=  ((*entityIcons)[i])->x()-tmpIcon->x();
                    float distanceY=  ((*entityIcons)[i])->y()-tmpIcon->y();
                    forceX-= distanceX/weight;
                    forceY-= distanceY/weight;
                }

                if (qAbs(forceX) < 5 && qAbs(forceY) < 5) forceX = forceY = 0;
                (*entityIcons)[i]->newPos = (*entityIcons)[i]->pos() + QPointF(forceX, forceY);
                //(*entityIcons)[i]->moveBy(forceX,forceY);
               // if ((forceX!=0) && (forceY!=0)) qDebug()<<forceX<<":"<<forceY <<":"<< ((*entityIcons)[i])->getUidValue();
            }


            for( int i=0; i<entityIcons->size(); i++) (*entityIcons)[i]->advance();
        }
        autoZoom();
    }

}
    //qDebug()<<"=====Mark======";


   /* QVector< QList<QString>*>* lists= new QVector< QList<QString>* >();

    for( int i=0; i<entityIcons->size(); i++)
    {
         if (entityIcons->at(i)->isVisible()&&entityIcons->at(i)->connectionList->size()>0)
         {
              QStringList* userList = new QStringList();
              userList->append(entityIcons->at(i)->getUidValue());

              for( int j=0; j<entityIcons->at(i)->connectionList->size(); j++)
              {
                if (entityIcons->at(i)->connectionList->at(j))
                    userList->append(entityIcons->at(i)->connectionList->at(j)->getUidValue());
              }
              userList->sort();
              lists->append(userList);
          }
    }


     for (int i=0; i<lists->size(); i++)
     {
         for (int j=0; j<lists->size(); j++)
         {
           if (j!=i)
           {
                 if ( (*(*lists)[i])==(*(*lists)[j]) )
                   lists->at(j)->clear();
           }
         }
     }

     for (int i=0; i<lists->size(); i++)
     {
       if  (lists->at(i)->size()>0) qDebug() <<"========================";
       for (int j=0; j<lists->at(i)->size(); j++)
       {
                qDebug()<<lists->at(i)->at(j);
       }

     }*/

 //}

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
         addEntityIcon(0,this,item,tmpEntity,pos);
    }
}


void GraphicsScene::setAutoLayout(QString layout)
{
  //  if (autoLayout) timer->start(100);
   // else      timer->stop();

   layoutItems(layout);

}


void GraphicsScene::setLinkMode(bool linkEnabled)
{
    this->linkMode=linkEnabled;
}




void GraphicsScene::addSheetMap(QMap<QString, QMap<QString, QPointF> *> * sheet)
{
    sheetMap=sheet;
}

void GraphicsScene::save()
{
    //TODO::memleak here,fix
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

void GraphicsScene::removeSelected()
{
    QList<QGraphicsItem*> selected= this->selectedItems();

    for (int i=0; i<selected.size(); i++)
    {
        ((EntityIcon*)selected[i])->hide();
        for (int j=0; j<edges->size(); j++)
        {
            if ( ((*edges)[j])->sourceIcon==selected[i] || ((*edges)[j])->destIcon==selected[i]  )
            {
              ((*edges)[j])->hide();
            }
        }

    }



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
   // qDebug()<<"void GraphicsScene::createEdge( EntityIcon* source, EntityIcon* dest);";

    if (dest==source) return;


    if (!source->isVisible() ||!dest->isVisible()) return ;

    for (int i=0; i<edges->size() ;i++)
    {
        if  ( (((*edges)[i]->sourceIcon)==source) &&  (((*edges)[i]->destIcon) == dest) )  return;

    }

    Edge* tmpEdge = new Edge(source,dest);
    //qDebug()<<source->getUidValue()<<":"<<dest->getUidValue();
    source->addConnection(dest);
    addItem(tmpEdge);

    edges->append(tmpEdge);


    update();
}

void GraphicsScene::createEdge( QString src_entitytype,QString src_uid,QString dest_entitytype,QString dest_uid )
{
  //  qDebug()<<"void GraphicsScene::createEdge" << src_entitytype << src_uid << dest_entitytype <<  dest_uid <<")";


    QMap<QString,EntityIcon*>*  tmpMap =entityLookup->value(src_entitytype);
    EntityIcon* source=0;
    EntityIcon* dest =0;

    if (tmpMap)
      source = tmpMap->value(src_uid);


    QMap<QString,EntityIcon*>*  tmpMap2 =entityLookup->value(dest_entitytype);
    if (tmpMap2)
        dest= tmpMap2->value(dest_uid);

    if (dest&&source)
        createEdge(source,dest);

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
