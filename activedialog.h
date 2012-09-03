#ifndef ACTIVEDIALOG_H
#define ACTIVEDIALOG_H
#include <QPoint>
#include <QRubberBand>
#include <QMainWindow>
#include <QtGui/QLabel>
#include <QtCore/QTimer>
#include <QMouseEvent>

#include "cmath"
#include "math.h"
#include "entity.h"


class ActiveDialog : public QMainWindow
{
    Q_OBJECT
public:
    explicit ActiveDialog(QWidget *parent = 0);
    void mousePressEvent ( QMouseEvent * event );
    void paintEvent(QPaintEvent * event);
    void  mouseMoveEvent(QMouseEvent *event);
    void  mouseReleaseEvent(QMouseEvent *event);
    bool selectionActive;
    EntityType* newEntityType;

    Entity* activeEntity;


    ~ActiveDialog();

private:

        int nr;
        float cConstant,hConstant,springLength;
        QVector<Entity*> * entity;
        QVector<QVector <float>*  >*  forceX;
        QVector<QVector <float>*  > * forceY;
        QTimer* timer;
        QPoint origin;
        QRubberBand* rubberBand;



public slots:

  void  velocityUpdate();
    
};

#endif // ACTIVEDIALOG_H
