#ifndef GRAPHICSSCENE_H
#define GRAPHICSSCENE_H

#include <QGraphicsScene>
#include <QAbstractItemModel>
#include "entityicon.h"
#include <QSqlTableModel>
#include <QGraphicsSceneMouseEvent>
#include <QVector>
#include <QTimer>

class GraphicsScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit GraphicsScene(QObject *parent);

signals:
    
public slots:


    void reset();                                                                   /*! helper function to implement a reset call for a custom view */
    void layoutChanged();
    void rowsInserted(const QModelIndex & parent, int start, int end );             /*! callback which is called by the model on item insertion operations */
    void rowsAboutToBeRemoved( const QModelIndex & parent, int start, int end );    /*! callback which is called by the model on item removal operations */
    void dataChanged(const QModelIndex& topLeft, const QModelIndex& bottomRight);   /*! callback which is called by the model on item change operations */

    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void addEntityIcon(QGraphicsItem * parent  , QModelIndex  index, EntityType*  entityType );
    void layoutItems();
    void addModel(QAbstractItemModel *model,EntityType*  entityType);

private :
       QVector<QAbstractItemModel*>* models;
       QVector<EntityIcon*>* entityIcons;
       QTimer* timer;
};

#endif // GRAPHICSSCENE_H
