#include "edge.h"
#include <QDebug>
#include <QGraphicsView>


Edge::Edge(EntityIcon *_sourceIcon, EntityIcon *_destIcon)
{
    sourceIcon=_sourceIcon;
    destIcon=_destIcon;
    this->setZValue(-1);
}


void Edge::adjust()
{
}

QRectF Edge::boundingRect() const
{
    return QRectF(sourceIcon->pos(), QSizeF( destIcon->pos().x() - sourceIcon->pos().x(),
                                             destIcon->pos().y() - sourceIcon->pos().y()))
        .normalized();

}

void Edge::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{


   // QLineF debugline(destIcon->pos(), sourceIcon->pos());
    //qDebug() << debugline.length();



     QPointF startPoint(sourceIcon->pos().x()+EntityIcon::totalWidth/2 ,sourceIcon->pos().y()+EntityIcon::totalHeight/2);
     QPointF endPoint  (destIcon->pos().x()+EntityIcon::totalWidth/2, destIcon->pos().y()+EntityIcon::totalHeight/2);

     QLineF line(startPoint,endPoint);

     QPointF startPoint2(startPoint.x()+(line.unitVector().dx()*EntityIcon::totalWidth/2), startPoint.y()+(line.unitVector().dy()*EntityIcon::totalHeight/2));
     QPointF endPoint2  (endPoint.x()-(line.unitVector().dx()*EntityIcon::totalWidth/2), endPoint.y()-(line.unitVector().dy()*EntityIcon::totalHeight/2));

     QLineF line2(startPoint2,endPoint2);


 /*   if (qFuzzyCompare(line.length(), qreal(0.)))
        return;*/

     if (this->scene()->views().at(0)->transform().m11() < 0.2)
      {
     painter->setPen(QPen(QColor(127, 127, 127,200), 1/this->scene()->views().at(0)->transform().m11(), Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
      }
     else
     {
         painter->setPen(QPen(QColor(127, 127, 127,200), 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
     }


     //painter->setPen(QPen(QColor(127, 127, 127,200), 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
     painter->drawLine(line2);

   /* double angle = ::acos(line.dx() / line.length());
    if (line.dy() >= 0)
        angle = TwoPi - angle;

    QPointF sourceArrowP1 = sourcePoint + QPointF(sin(angle + Pi / 3) * arrowSize,
                                                  cos(angle + Pi / 3) * arrowSize);
    QPointF sourceArrowP2 = sourcePoint + QPointF(sin(angle + Pi - Pi / 3) * arrowSize,
                                                  cos(angle + Pi - Pi / 3) * arrowSize);
    QPointF destArrowP1 = destPoint + QPointF(sin(angle - Pi / 3) * arrowSize,
                                              cos(angle - Pi / 3) * arrowSize);
    QPointF destArrowP2 = destPoint + QPointF(sin(angle - Pi + Pi / 3) * arrowSize,
                                              cos(angle - Pi + Pi / 3) * arrowSize);*/

    /*painter->setBrush(Qt::black);
    painter->drawPolygon(QPolygonF() << line.p1() << sourceArrowP1 << sourceArrowP2);
    painter->drawPolygon(QPolygonF() << line.p2() << destArrowP1 << destArrowP2);*/

 }
