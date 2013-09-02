#ifndef GRAPHICSSCENE_H
#define GRAPHICSSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsSceneMouseEvent>
#include <QAbstractItemModel>
#include <QVector>
#include <QTimer>
#include <QGraphicsItem>
#include <QGraphicsView>

#include <QSqlTableModel>   //REMOVE
#include <QSqlTableModel> //REMOVE
#include <QSqlQuery> //REMOVE
#include <QSqlRecord> //REMOVE
#include <QSqlField> //REMOVE

#include <QDebug>
#include "entityicon.h"
#include "gvgraph.h"
#include "edge.h"
#include "cmath"
#include "math.h"
#include "gvgraph.h"
#include "graphicsview.h"



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
    void addEntityIcon(QGraphicsItem * parent  ,QGraphicsScene* scene,  QModelIndex  index, EntityType*  entityType ,QPointF pos);


    void addSheetLink(QSqlTableModel* projectLink);
    void addModel(QAbstractItemModel *model,EntityType*  entityType);
    void addJoin(QString entityType1,QString entityType2,QAbstractItemModel *model);
    void addSheetMap(QMap<QString, QMap<QString,QPointF>*   >* sheet);

    void hideOrphan();
    void createEdge   ( EntityIcon* source, EntityIcon* dest);
    void storeEdge    ( EntityIcon* source, EntityIcon* dest);
    void createEdge( QString src_entitytype,QString src_uid,QString dest_entitytype,QString dest_uid );


    void layoutItems(QString layout);
    void setAutoLayout(QString layout);

    void setLinkMode(bool linkEnabled);

    void autoZoom();
    void save();
    void removeSelected();

    QMap<QString, QMap<QString,QPointF>*   >*  getSheetMap();

private :
       QVector<QAbstractItemModel*>* models;
       QVector<EntityIcon*>* entityIcons;
       QVector<Edge*>* edges;
       QTimer* timer;
       bool linkMode;
       GVGraph*  gvgraph;

       QMap<QString, QMap<QString,QPointF>*   >* sheetMap;
       QSqlTableModel* projectLink;
       QMap <QString, QMap<QString, EntityIcon*>* >* entityLookup;
};

#endif // GRAPHICSSCENE_H
