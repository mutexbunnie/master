#ifndef EDGE_H
#define EDGE_H
#include <QGraphicsItem>
#include <entityicon.h>




class Edge : public QGraphicsItem
{
    Edge(EntityIcon *sourceEntity, EntityIcon *destEntity);


protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
   void  adjust();
private:
    EntityIcon *source, *dest;
    QPointF sourcePoint;
    QPointF destPoint;
    int arrowSize;

};



#endif // EDGE_H


