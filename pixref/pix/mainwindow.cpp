#include "mainwindow.h"
#include "ui_mainwindow.h"
#include  <entityicon.h>
#include <QGraphicsScene>

#include <QPainter>
#include <QStyleOption>.
#include <QDebug>



MainWindow::MainWindow(QWidget *parent) :  QMainWindow(parent), ui(new Ui::MainWindow)
{

    ui->setupUi(this);

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


    model=new QStandardItemModel(0, 1);
    model->removeRows(0, model->rowCount(QModelIndex()), QModelIndex());



    scene= new  GraphicsScene(0,model);

     qDebug()  <<"rowcount" <<model->rowCount();
     for (int row = 0; row < 200000; row++)
     {

       QStandardItem *item = new QStandardItem();
       item->setData(QString("row %0").arg(row),Qt::EditRole);
         item->setData(*normal,Qt::DecorationRole);
      item->setData(*selected,34);
         model->setItem(row, 0, item);
     }


      qDebug()  <<"rowcount" <<model->rowCount();




    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setDragMode(QGraphicsView::RubberBandDrag);

   // for (int i=0; i<5 ;i++)
    //{

   // }
    scene->setSceneRect(0,0,900,900);

    ui->graphicsView->setScene(scene);




}

MainWindow::~MainWindow()
{
    delete ui;
}
