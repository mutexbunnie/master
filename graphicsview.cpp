#include "graphicsview.h"
#include <QGraphicsTextItem>
#include <QDebug>
#include <QScrollBar>
#include "graphicsscene.h"

GraphicsView::GraphicsView(QWidget *parent) :  QGraphicsView(parent)
{
     setRenderHint(QPainter::Antialiasing);
      setDragMode(QGraphicsView::RubberBandDrag);
      setCacheMode(QGraphicsView::CacheNone);
      setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
      setRenderHint(QPainter::HighQualityAntialiasing, true);
      setRenderHint(QPainter::SmoothPixmapTransform, true);
      setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
      setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
      setMinimumSize(400, 400);
      scale(0.5,0.5);

      //scale(1.0,1.0);


   connect(this->horizontalScrollBar(), SIGNAL(actionTriggered(int)), this,   SLOT(sliderMoved(int)));
   connect(this->verticalScrollBar(), SIGNAL(actionTriggered(int)),this,   SLOT(sliderMoved(int)));

}
void GraphicsView::resizeEvent(QResizeEvent* event)
{
    //Get the rectangle of the visible area in scene coords
    QRectF visibleArea = mapToScene(rect()).boundingRect();
    setCenter(visibleArea.center());

    //Call the subclass resize so the scrollbars are updated correctly
    QGraphicsView::resizeEvent(event);
}

//http://www.qtcentre.org/wiki/index.php?title=QGraphicsView:_Smooth_Panning_and_Zooming
/**
  * Sets the current centerpoint.  Also updates the scene's center point.
  * Unlike centerOn, which has no way of getting the floating point center
  * back, SetCenter() stores the center point.  It also handles the special
  * sidebar case.  This function will claim the centerPoint to sceneRec ie.
  * the centerPoint must be within the sceneRec.
  */

void GraphicsView::setCenter(const QPointF& centerPoint)
{
    //Get the rectangle of the visible area in scene coords
    QRectF visibleArea = mapToScene(rect()).boundingRect();

    //Get the scene area
    QRectF sceneBounds = sceneRect();

    double boundX = visibleArea.width() / 2.0 + sceneBounds.x();
    double boundY = visibleArea.height() / 2.0 + sceneBounds.y();

    double boundWidth = sceneBounds.width() - 2.0 * boundX;
    double boundHeight = sceneBounds.height() - 2.0 * boundY;

    //The max boundary that the centerPoint can be to
    QRectF bounds(boundX, boundY, boundWidth, boundHeight);

    if(bounds.contains(centerPoint))
    {
        //We are within the bounds
        CurrentCenterPoint = centerPoint;
    }
    else
    {
        //We need to clamp or use the center of the screen
        if(visibleArea.contains(sceneBounds))
        {
            //Use the center of scene ie. we can see the whole scene
            CurrentCenterPoint = sceneBounds.center();
        }
        else
        {
            CurrentCenterPoint = centerPoint;
            //We need to clamp the center. The centerPoint is too large
            if(centerPoint.x() > bounds.x() + bounds.width())
            {
                CurrentCenterPoint.setX(bounds.x() + bounds.width());
            }
            else if(centerPoint.x() < bounds.x())
            {
                CurrentCenterPoint.setX(bounds.x());
            }

            if(centerPoint.y() > bounds.y() + bounds.height())
            {
                CurrentCenterPoint.setY(bounds.y() + bounds.height());
            }
            else if(centerPoint.y() < bounds.y())
            {
                CurrentCenterPoint.setY(bounds.y());
            }

        }
    }

    //Update the scrollbars
    centerOn(CurrentCenterPoint);
}


void GraphicsView::setSelectMode(bool selectMode )
{
    this->selectMode=selectMode;
    setCursor(Qt::ArrowCursor);

}

/**
  * Handles when the mouse button is pressed
  */
void GraphicsView::mousePressEvent(QMouseEvent* event)
{
    if (!selectMode)
     {
      //For panning the view
      LastPanPoint = event->pos();
      setCursor(Qt::ClosedHandCursor);
    }
    else
     {
        event->ignore();
        QGraphicsView::mousePressEvent(event);
     }

}

/**
  * Handles when the mouse button is released
  */
void GraphicsView::mouseReleaseEvent(QMouseEvent* event)
{
    if (!selectMode)
     {
        setCursor(Qt::OpenHandCursor);
        LastPanPoint = QPoint();
 }
    else
   {
     event->ignore();
     QGraphicsView::mouseReleaseEvent(event);
    }

}

/**
*Handles the mouse move event
*/
void GraphicsView::mouseMoveEvent(QMouseEvent* event)
{
   if (!selectMode)
   {
       if(!LastPanPoint.isNull()) {
            //Get how much we panned
            QPointF delta = mapToScene(LastPanPoint) - mapToScene(event->pos());
            LastPanPoint = event->pos();

            //Update the center ie. do the pan
            setCenter(getCenter() + delta);
        }

   }
   else
   {
     event->ignore();
         QGraphicsView::mouseMoveEvent(event);
   }

}


void GraphicsView::sliderMoved(int /*value*/)
{

    qDebug()<<"GraphicsView::sliderMoved";
    QRectF visibleArea = mapToScene(rect()).boundingRect();
    updateCenterPoint(visibleArea.center());
}

void GraphicsView::updateCenterPoint(const QPointF& centerPoint)
{
    qDebug()<<"GraphicsView::updateCenterPoint";
    //Get the rectangle of the visible area in scene coords
    QRectF visibleArea = mapToScene(rect()).boundingRect();

    //Get the scene area
    QRectF sceneBounds = sceneRect();

    double boundX = visibleArea.width() / 2.0;
    double boundY = visibleArea.height() / 2.0;
    double boundWidth = sceneBounds.width() - 2.0 * boundX;
    double boundHeight = sceneBounds.height() - 2.0 * boundY;

    //The max boundary that the centerPoint can be to
    QRectF bounds(boundX, boundY, boundWidth, boundHeight);

    if(bounds.contains(centerPoint)) {
        //We are within the bounds
        CurrentCenterPoint = centerPoint;
    } else {
        //We need to clamp or use the center of the screen
        if(visibleArea.contains(sceneBounds)) {
            //Use the center of scene ie. we can see the whole scene
            CurrentCenterPoint = sceneBounds.center();
        } else {

            CurrentCenterPoint = centerPoint;

            //We need to clamp the center. The centerPoint is too large
            if(centerPoint.x() > bounds.x() + bounds.width()) {
                CurrentCenterPoint.setX(bounds.x() + bounds.width());
            } else if(centerPoint.x() < bounds.x()) {
                CurrentCenterPoint.setX(bounds.x());
            }

            if(centerPoint.y() > bounds.y() + bounds.height()) {
                CurrentCenterPoint.setY(bounds.y() + bounds.height());
            } else if(centerPoint.y() < bounds.y()) {
                CurrentCenterPoint.setY(bounds.y());
            }

        }
    }
}

/**
  * Zoom the view in and out.
  */
void GraphicsView::wheelEvent(QWheelEvent* event)
{

    //Get the position of the mouse before scaling, in scene coords
    QPointF pointBeforeScale(mapToScene(event->pos()));

    //Get the original screen centerpoint
    QPointF screenCenter = getCenter(); //CurrentCenterPoint; //(visRect.center());

    //Scale the view ie. do the zoom
    double scaleFactor = 1.15; //How fast we zoom
    if(event->delta() > 0) {
        //Zoom in
        ((GraphicsScene*)scene())->setFontSize(scaleFactor);
        scale(scaleFactor, scaleFactor);
    } else {
        //Zooming out
        scale(1.0 / scaleFactor, 1.0 / scaleFactor);
        ((GraphicsScene*)scene())->setFontSize(1.0 / scaleFactor);
    }

    //Get the position after scaling, in scene coords
    QPointF pointAfterScale(mapToScene(event->pos())); //beaks

    //Get the offset of how the screen moved
    QPointF offset = pointBeforeScale - pointAfterScale;

    //Adjust to the new center for correct zooming
    QPointF newCenter = screenCenter + offset;
    setCenter(newCenter);





}


