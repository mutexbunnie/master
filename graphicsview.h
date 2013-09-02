#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

#include <QWidget>
#include <QGraphicsView>
#include <QWheelEvent>
#include <QGraphicsTextItem>
#include <QDebug>
#include <QScrollBar>
#include <math.h>
#include "graphicsscene.h"

class GraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit GraphicsView(QWidget *parent = 0);

    bool selectMode;


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


    void updateCenterPoint(const QPointF &centerPoint);
signals:
    
public slots:
    void setSelectMode(bool linkEnabled);
    void sliderMoved(int);

    
};

#endif // GRAPHICSVIEW_H



