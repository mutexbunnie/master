#ifndef GRAPHICSSCENE_H
#define GRAPHICSSCENE_H

#include <QGraphicsScene>
#include <QAbstractItemModel>
#include "entityicon.h"

class GraphicsScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit GraphicsScene(QObject *parent ,QAbstractItemModel  *model);

    
signals:
    
public slots:

    /*! helper function to implement a reset call for a custom view */
    void reset();

    void layoutChanged();
    /*! callback which is called by the model on item insertion operations */

    void rowsInserted( const QModelIndex & parent, int start, int end );
    /*! callback which is called by the model on item removal operations */

    void rowsAboutToBeRemoved( const QModelIndex & parent, int start, int end );

    /*! callback which is called by the model on item change operations */
    void dataChanged(const QModelIndex& topLeft, const QModelIndex& bottomRight);

private :
       QAbstractItemModel  *model;
};

#endif // GRAPHICSSCENE_H
