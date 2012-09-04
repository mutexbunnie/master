#include "activedialog.h"
#include <QPainter>
#define PI 3.14159265
#include <QDebug>
#include <QStyle>

ActiveDialog::ActiveDialog(QWidget *parent) :
    QMainWindow(parent)
{
    //this->setAutoFillBackground(true);
    rubberBand=0;

    selectionActive=true;

    nr=1;
    cConstant=100000;
    hConstant=0.1;
    springLength=100;
    this->setMouseTracking(true);

    this->setStyleSheet("QMainWindow { background-color: White; }");

    this->setMinimumSize(16777215,16777215);
    this->resize(16777215,16777215);
    entity = new  QVector<Entity*>;
    activeEntity=0;
    forceX= new  QVector<QVector <float>* >;
    forceY= new  QVector<QVector <float>* >;

    /*for( int i=0; i<nr; i++)
    {
        entity->append(new Entity(this,));
        forceX->append( new QVector <float>);

        for( int k=0; k<nr; k++)
        {
            (*forceX)[i]->append(0);
        }


        forceY->append( new QVector <float>);

        for( int k=0; k<nr; k++)
        {
            (*forceY)[i]->append(0);
        }

    }*/

     timer = new QTimer(this);
     connect (timer, SIGNAL(timeout()), this, SLOT(velocityUpdate()));
     timer->start(100);
 }



 void ActiveDialog::mouseMoveEvent(QMouseEvent *event)
 {
     if (rubberBand && selectionActive) rubberBand->setGeometry(QRect(origin, event->pos()).normalized());

 }

 void ActiveDialog::mouseReleaseEvent(QMouseEvent *event)
 {
     if (selectionActive)
     {
         if (rubberBand) rubberBand->hide();

           for( int i=0; i<entity->size(); i++)
           {
               if (rubberBand->geometry().intersects((*entity)[i]->geometry()))

               {
                   qDebug()<<i<<" has been selected" << rubberBand->geometry() <<  (*entity)[i]->geometry();

                   (*entity)[i]-> setSelected(true);
               }
           }
                 // determine selection, for example using QRect::intersects() and QRect::contains().
       }
 }



void ActiveDialog::mousePressEvent ( QMouseEvent * event )
{

   if (selectionActive)
    {
       origin = event->pos();
        if (!rubberBand)
        {

            rubberBand = new QRubberBand(QRubberBand::Rectangle, this);

            qDebug()<< rubberBand->style();
        }
        rubberBand->setWindowOpacity(0.0);

        rubberBand->setGeometry(QRect(origin, QSize()));
        rubberBand->show();
   }
   else
   {
        qDebug()<<event->x()<<event->y();


        Entity* tmpEntity=new Entity(this,newEntityType);

        entity->append(tmpEntity);

         forceX->append( new QVector <float>);

         for( int k=0; k<entity->size(); k++)
         {
             (*forceX)[forceX->size()-1]->append(0);
         }

         for( int k=0; k<entity->size()-1; k++)
         {
             (*forceX)[k]->append(0);
         }


        forceY->append( new QVector <float>);

        for( int k=0; k<entity->size(); k++)
        {
            (*forceY)[forceY->size()-1]->append(0);
        }

        for( int k=0; k<entity->size()-1; k++)
        {
            (*forceY)[k]->append(0);
        }

        (*entity)[entity->size()-1]->move(event->x(),event->y());
        update();
   }

}

void ActiveDialog::paintEvent(QPaintEvent * event)
{
     QPainter painter(this) ;
     for ( int i=0; i<entity->size(); i++ )
     {
         for( int k=0; k<((*entity)[i])->connection->size(); k++)
         {
             QLineF line( ((*entity)[i])->x()+((*entity)[i])->width()/2,
                          ((*entity)[i])->y()+((*entity)[i])->height()/2,
                          (*((*entity)[i])->connection)[k]->x()+(*((*entity)[i])->connection)[k]->width()/2,
                          (*((*entity)[i])->connection)[k]->y() +(*((*entity)[i])->connection)[k]->height()/2
                         );
             painter.drawLine(line);
        }

     }

}

void ActiveDialog::velocityUpdate()
{
     for( int i=0; i<entity->size(); i++)
        {
            ((*entity)[i])->dx=0;
            ((*entity)[i])->dy=0;

            for( int k=0; k<entity->size(); k++)
            {

                if (k!=i)
                {
                   int distanceX= ((*entity)[k])->x()- ((*entity)[i])->x();
                   int distanceY= ((*entity)[k])->y()- ((*entity)[i])->y();

                    //float distance=std::max((distanceX*distanceX)+(distanceY*distanceY),1);
                    float distance=(distanceX*distanceX)+(distanceY*distanceY);

                    float angle=std::atan2(distanceY,distanceX);
                    float forceC=cConstant *( 1.0f / distance );

                    (*(*forceX)[i])[k]=  -forceC*std::cos(angle);
                    (*(*forceY)[i])[k]=  -forceC*std::sin(angle);

                    bool sibling=false;

                    if ((*entity)[i]->eParent!=0)
                    {
                      if ((*(((*entity)[i])->eParent->connection)).contains((*entity)[k]))
                      {
                                    //sibling=true;
                                    qDebug() << k <<" IS" << i<<"'s SIBLING!";

                      }
                   }


                   // qDebug()<<i<< k;//<<distanceX<<distanceY<<forceX[i][k]<< forceY[i][k];

                    if (((*entity)[i]->connection->contains((*entity)[k]))|sibling)
                    {
                       float forceH=-hConstant* std::max((int)(std::sqrt(distance)-springLength),0);
                       (*(*forceX)[i])[k]=  -forceH*std::cos(angle);
                       (*(*forceY)[i])[k]=  -forceH*std::sin(angle);
                       //qDebug()<<i<< (*(*forceX)[i])[k]<< (*(*forceY)[i])[k];
                       //qDebug()<<forceH;
                    }






                }
                else
                {
                     ((*(*forceX)[i])[k])=0;
                     ((*(*forceY)[i])[k])=0;
                }

                ((*entity)[i])->dx+=(*(*forceX)[i])[k];
                ((*entity)[i])->dy+=(*(*forceY)[i])[k];
            }




          }
          //  qDebug()<<i<< entity[i]->dx<< entity[i]->dy;



        for( int i=0; i<entity->size(); i++)
        {
        // ((*entity)[i])->updatePos();
        }
        update();

}

ActiveDialog::~ActiveDialog()
{
    /* for( int i=0; i<entity->size(); i++)
      {
          delete entity[i];
      }

      delete[] entity;*/
}


//    /* for( int i=0; i<nr; i++)
//    {
//      for( int k=0; k<nr; k++)
//        {
//            if (k!=i)
//            {

//               //force between entities
//                QLineF line(entity[k]->x()+entity[k]->size().width()/2 ,
//                            entity[k]->y()+entity[k]->size().height()/2 ,
//                            (entity[k]->x()+entity[k]->size().width()/2)-forceX[i][k],
//                            (entity[k]->y()+entity[k]->size().height()/2)-forceY[i][k]);

//                 QLineF line(entity[k]->x()+entity[k]->size().width()/2 ,
//                            entity[k]->y()+entity[k]->size().height()/2 ,
//                            entity[i]->x()+entity[k]->size().width()/2 ,
//                            entity[i]->y()+entity[k]->size().height()/2);
//    }


//        QLineF line(entity[i]->x()+entity[i]->size().width()/2 ,
//                                     entity[i]->y()+entity[i]->size().height()/2 ,
//                                     (entity[i]->x()+entity[i]->size().width()/2)+  std::ceil(entity[i]->dx)*100,
//                                     (entity[i]->y()+entity[i]->size().height()/2)+   std::ceil(entity[i]->dy)*100);

//              painter.drawLine(line);
//               qDebug()<<i<< k <<forceX[i][k]<< forceY[i][k];

//        }*/
