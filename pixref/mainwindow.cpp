#include "mainwindow.h"
#include "ui_mainwindow.h"
#include  <entityicon.h>
#include <QGraphicsScene>

#include <QPainter>
#include <QStyleOption>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QGraphicsScene* scene= new QGraphicsScene(this);
     scene->setItemIndexMethod(QGraphicsScene::NoIndex);


     QPixmap*  normal =new QPixmap("/home/mutex/Desktop/star.png");
     QPixmap* selected=new QPixmap(normal->size());
     selected->fill(QColor(0, 0, 255, 50));

     QPainter painter( selected);

     QBrush brush(QColor(0, 0, 255,100));
     QPen pen(brush,10);

     painter.drawPixmap(0, 0, *normal);
     painter.setPen(pen);
     painter.drawRect(normal->rect());
     painter.end();





    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setDragMode(QGraphicsView::RubberBandDrag);

    for (int i=0; i<5 ;i++)
    {
             EntityIcon* pix=new EntityIcon(0, normal, selected);
            scene->addItem(pix);
    }
    scene->setSceneRect(0,0,900,900);

    ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}
