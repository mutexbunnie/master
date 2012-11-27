#include "graphicsview.h"
#include <QDebug>

GraphicsView::GraphicsView(QWidget *parent) :  QGraphicsView(parent)
{
      setRenderHint(QPainter::Antialiasing);
      setDragMode(QGraphicsView::RubberBandDrag);
      setCacheMode(QGraphicsView::CacheNone);
      setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
      setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
      //scale(qreal(0.8), qreal(0.8));
      setRenderHint(QPainter::HighQualityAntialiasing, true);
        setRenderHint(QPainter::SmoothPixmapTransform, true);
}


void GraphicsView::wheelEvent(QWheelEvent *event)
{
    centerOn(event->pos());
    scaleView(pow((double)2, +event->delta() / 240.0));
    centerOn(event->pos());
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


void GraphicsView::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_Plus:
        zoomIn();
        break;
    case Qt::Key_Minus:
        zoomOut();
        break;
    default:
        QGraphicsView::keyPressEvent(event);
    }
}
