#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

#include <QWidget>
#include <QGraphicsView>
#include <QWheelEvent>
#include <math.h>

class GraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit GraphicsView(QWidget *parent = 0);
    
    void zoomIn();
    void zoomOut();

    void wheelEvent(QWheelEvent *event);
    void scaleView(qreal scaleFactor);

signals:
    
public slots:
    
};

#endif // GRAPHICSVIEW_H



