#ifndef EDGE_H
#define EDGE_H

#include "entityicon.h"
#include  <QPainter>

class Edge :public QGraphicsItem
{
public:
    Edge(EntityIcon*  _sourceIcon, EntityIcon* _destIcon);
    void adjust();
    EntityIcon* sourceIcon;
    EntityIcon* destIcon;

protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // EDGE_H
