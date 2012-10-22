#ifndef EDGE_H
#define EDGE_H

#include "entityicon.h"
#include  <QPainter>

class Edge :public QGraphicsItem
{
public:
    Edge(EntityIcon*  _sourceIcon, EntityIcon* _destIcon);
    void adjust();

protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);


private:
     EntityIcon* sourceIcon;
     EntityIcon* destIcon;
};

#endif // EDGE_H
