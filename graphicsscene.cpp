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

    entityIcons=new QVector<EntityIcon*>();

    //timer = new QTimer(this);
 //   connect (timer, SIGNAL(timeout()), this, SLOT(layoutItems()));
   // timer->start(100);
    this->linkMode=false;
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

    for ( int i = 0; i <model->rowCount(); ++i )
    {
         QModelIndex item = model->index( i, 0);
         addEntityIcon(0,item,tmpEntity);
    }
}

void GraphicsScene::setLinkMode(bool linkEnabled)
{
    this->linkMode=linkEnabled;
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
                ((EntityIcon*)selectedNow[j])->addConnection(((EntityIcon*)prevSelected[i]));
                (((EntityIcon*)prevSelected[i]))->addConnection((EntityIcon*)selectedNow[j]);
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
