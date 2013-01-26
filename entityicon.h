#ifndef ENTITYICON_H
#define ENTITYICON_H


#include <QGraphicsItem>

#include <QStyleOptionGraphicsItem>
#include <QPersistentModelIndex>
#include <QGraphicsSceneMouseEvent>
#include "entitytype.h"

class Edge ;


class EntityIcon : public QGraphicsItem
{

public:
    explicit EntityIcon(QGraphicsItem * parent,  QGraphicsScene* scene, QModelIndex  index, EntityType*  entityType , QPointF pos);
    virtual void  paint ( QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget );
    virtual QVariant itemChange(GraphicsItemChange change, const QVariant &value);
    virtual void	mouseReleaseEvent ( QGraphicsSceneMouseEvent * event );
    virtual void	mousePressEvent   (  QGraphicsSceneMouseEvent * event );
    QRectF boundingRect() const;
    void addConnection(EntityIcon* dest);


   // void updateText();
    QString getUidValue();


    QVector<EntityIcon*>* connectionList;
    EntityType* entityType;
signals:


public slots:

private:
        QPersistentModelIndex  index;
        QPixmap currentPixmap;

};

#endif // ENTITYICON_H
