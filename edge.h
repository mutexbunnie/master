#ifndef EDGE_H
#define EDGE_H

#include "entityicon.h"
#include <QDebug>
#include <QGraphicsView>
#include  <QPainter>

class Edge :public QGraphicsItem
{

protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

public:
    Edge(EntityIcon*  _sourceIcon, EntityIcon* _destIcon);

//TODO:: SHOUD be private:
    EntityIcon* sourceIcon;
    EntityIcon* destIcon;

};

#endif // EDGE_H
