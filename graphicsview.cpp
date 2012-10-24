#include "graphicsview.h"

GraphicsView::GraphicsView(QWidget *parent) :  QGraphicsView(parent)
{
      setRenderHint(QPainter::Antialiasing);
      setDragMode(QGraphicsView::RubberBandDrag);
      setCacheMode(QGraphicsView::CacheNone);
      setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
      setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
      //scale(qreal(0.8), qreal(0.8));

}


void GraphicsView::wheelEvent(QWheelEvent *event)
{
    scaleView(pow((double)2, -event->delta() / 240.0));
}
void GraphicsView::scaleView(qreal scaleFactor)
{
    qreal factor = transform().scale(scaleFactor, scaleFactor).mapRect(QRectF(0, 0, 1, 1)).width();
    if (factor < 0.07 || factor > 100)
        return;

    scale(scaleFactor, scaleFactor);
}
void GraphicsView::zoomIn()
{
    scaleView(qreal(1.2));
}

void GraphicsView::zoomOut()
{
    scaleView(1 / qreal(1.2));
}
