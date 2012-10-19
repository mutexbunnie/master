#include "graphicsscene.h"
#include <QDebug>


GraphicsScene::GraphicsScene(QObject *parent, QAbstractItemModel  *model) :QGraphicsScene(parent)
{
   this->model=model;

    connect( model, SIGNAL(modelReset ()), this, SLOT(reset()));
    connect( model, SIGNAL(layoutChanged ()), this, SLOT(layoutChanged()));
    connect( model, SIGNAL(rowsInserted ( const QModelIndex & , int , int  )), this, SLOT(rowsInserted ( const QModelIndex & , int , int  )));
    connect( model, SIGNAL(rowsAboutToBeRemoved ( const QModelIndex & , int , int  )), this, SLOT(rowsAboutToBeRemoved ( const QModelIndex & , int , int  )));
    connect( model, SIGNAL(dataChanged ( const QModelIndex & , const QModelIndex &  )), this, SLOT(dataChanged ( const QModelIndex & , const QModelIndex &  )));
   this->setItemIndexMethod(QGraphicsScene::NoIndex);


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

// qDebug()<<"GraphicsScene::rowsInserted( const QModelIndex & parent, int start "<<start<< "int end "<<end <<")";

 for ( int i = start; i <= end; ++i )
    {
      QModelIndex item = model->index( i, 0, parent );
      EntityIcon* pix=new EntityIcon(0,item);
      this->addItem(pix);
    }
}

/*! callback which is called by the model on item removal operations */
void GraphicsScene::rowsAboutToBeRemoved( const QModelIndex & parent, int start, int end )
{
 // qDebug()<<" GraphicsScene::rowsAboutToBeRemoved(  const QModelIndex & parent, int start "<<start<< "int end "<<end <<")";
}

/*! callback which is called by the model on item change operations */
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
