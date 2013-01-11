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







    QPointF CurrentCenterPoint;
    void setCenter(const QPointF& centerPoint);

    QPointF getCenter() { return CurrentCenterPoint; }

    //From panning the view
    QPoint LastPanPoint;


    virtual void mousePressEvent(QMouseEvent* event);
    virtual void mouseReleaseEvent(QMouseEvent* event);
    virtual void mouseMoveEvent(QMouseEvent* event);
    virtual void wheelEvent(QWheelEvent* event);
    virtual void resizeEvent(QResizeEvent* event);

signals:
    
public slots:
    
};

#endif // GRAPHICSVIEW_H



