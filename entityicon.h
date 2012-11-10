#ifndef ENTITYICON_H
#define ENTITYICON_H


#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QStyleOptionGraphicsItem>
#include <QPersistentModelIndex>
#include <QGraphicsSceneMouseEvent>
#include "entitytype.h"

class Edge ;


class EntityIcon : public QGraphicsPixmapItem
{

public:
    explicit EntityIcon(QGraphicsItem * parent,  QModelIndex  index, EntityType*  entityType );
    virtual void  paint ( QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget );
    virtual QVariant itemChange(GraphicsItemChange change, const QVariant &value);
    virtual void	mouseReleaseEvent ( QGraphicsSceneMouseEvent * event );
    virtual void	mousePressEvent   (  QGraphicsSceneMouseEvent * event );
    virtual QRectF boundingRect();
    void addConnection(EntityIcon* dest);

    void updateText();

    QVector<EntityIcon*>* connectionList;

QGraphicsSimpleTextItem* labelItem;

 EntityType* entityType;
signals:


public slots:

private:
        QPersistentModelIndex  index;
        QPixmap* normal;
        QPixmap* selected;


};

#endif // ENTITYICON_H
