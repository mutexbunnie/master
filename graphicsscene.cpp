#include "graphicsscene.h"
#include <QDebug>
#include <QSqlTableModel>
#include <QGraphicsSceneMouseEvent>
#include "edge.h"


GraphicsScene::GraphicsScene(QObject *parent,  QSqlQueryModel* model) :QGraphicsScene(parent)
{
   this->model=model;
    entityIcons=new QVector<EntityIcon*>();


    connect( model, SIGNAL(modelReset ()), this, SLOT(reset()));
    connect( model, SIGNAL(layoutChanged ()), this, SLOT(layoutChanged()));
    connect( model, SIGNAL(rowsInserted ( const QModelIndex & , int , int  )), this, SLOT(rowsInserted ( const QModelIndex & , int , int  )));
    connect( model, SIGNAL(rowsAboutToBeRemoved ( const QModelIndex & , int , int  )), this, SLOT(rowsAboutToBeRemoved ( const QModelIndex & , int , int  )));
    connect( model, SIGNAL(dataChanged ( const QModelIndex & , const QModelIndex &  )), this, SLOT(dataChanged ( const QModelIndex & , const QModelIndex &  )));
    this->setItemIndexMethod(QGraphicsScene::NoIndex);
    activeIcons=0;

    /* fix*/
    tmpEntity=new EntityType();
    tmpEntity->addIcon(":/icons/star.png");
    tmpEntity->setName("star");
    /*fix*/

    qDebug()<<model->rowCount();
    for ( int i = 0; i <model->rowCount(); ++i )
       {
         QModelIndex item = model->index( i, 0);
         addEntityIcon(0,item,tmpEntity);
         //qDebug() << item.data();
       }
    lastSelectedIcon=0;

}


void GraphicsScene::addEntityIcon(QGraphicsItem *parent, QModelIndex index, EntityType *entityType)
{
    EntityIcon* pix=new EntityIcon(parent,index,entityType);
    this->addItem(pix);
    this->entityIcons->append(pix);
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
void GraphicsScene::rowsInserted( const QModelIndex & parent, int start, int end )
{

 qDebug()<<"GraphicsScene::rowsInserted( const QModelIndex & parent, int start "<<start<< "int end "<<end <<")";

 for ( int i = start; i <= end; ++i )
    {
      QModelIndex item = model->index( i, 0, parent );
      addEntityIcon(0,item,tmpEntity);
    }
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
               Edge* tmpEdge = new Edge((EntityIcon*)selectedNow[j],(EntityIcon*)prevSelected[i]);
               addItem(tmpEdge);
               update();
               tmpEdge->update();
            }
        }
    }
}

void GraphicsScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    //qDebug() <<"QGraphicsScene::mouseReleaseEvent(event)1";
    QGraphicsScene::mouseReleaseEvent(event);
   // qDebug() <<"QGraphicsScene::mouseReleaseEvent(event)2";
}
