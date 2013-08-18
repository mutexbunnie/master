#ifndef ENTITYICON_H
#define ENTITYICON_H


#include <QGraphicsItem>

#include <QStyleOptionGraphicsItem>
#include <QPersistentModelIndex>
#include <QGraphicsSceneMouseEvent>
#include "entitytype.h"

class Edge ;
class EntityType;


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
    virtual void advance();
   // void updateText();
    QString getUidValue();
    void setFontSize(int fontsize);
    QVector<EntityIcon*>* connectionList;
    EntityType* entityType;
    QPointF newPos;

    static const int  iconSize=64;
   static const int   horizMargin=40;
    static const int   verticalMargin=10;
    static const int   fontSize=12;
    static const int   totalWidth=horizMargin+iconSize+horizMargin;
    static const int   totalHeight=verticalMargin+iconSize+fontSize+verticalMargin;


signals:


public slots:

private:
        QPersistentModelIndex  index;
        QPixmap currentPixmap;
        int fontsize;


};

#endif // ENTITYICON_H
