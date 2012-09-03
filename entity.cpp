#include "entity.h"
#include "activedialog.h"
#include <QDebug>
#include <QIcon>

Entity::Entity(QWidget *parent): QLabel(parent)
{
        this->setObjectName("label");
        int x=qrand() % 1024;
        int y=qrand() % 1024;
        this->setGeometry(QRect(x, y, 64, 64));
        this->setPixmap(QPixmap(QString::fromUtf8(":/icons/star.png")));
        this->setScaledContents(true);
        this->setMouseTracking(true);
        entityActive=false;
        moveable=false;
        moved=false;
        this->show();
        dx=0;
        dy=0;
        connection= new QVector<Entity*> ;
        eParent=0;
        menu= new QMenu(this);
        action_del=new QAction("Delete",this);
        menu->addAction(action_del);
        connect(action_del, SIGNAL(triggered()), this, SLOT(del()));

        normalPixmap= new QPixmap(*this->pixmap());

        QIcon icon;
        icon.addPixmap(*normalPixmap);
        selectedPixmap= new QPixmap( icon.pixmap(this->width(),this->height(),QIcon::Selected,QIcon::On));

}


void Entity::del()
{
    qDebug()<< "DEL" ;
}

void Entity::updatePos()
{
   float newX=this->x()+this->dx;
   float newY=this->y()+this->dy;

   //qDebug()<<"new dx:"<<this->dx<<"new dy:"<<this->dy;

   this->move(newX ,newY);
}


void Entity:: addConnection(Entity* entity)
{
  this->connection->append(entity);
}


void Entity::mousePressEvent ( QMouseEvent * event )
{
    moveable=true;
    moved=true;

    if  (((ActiveDialog*)(this->parent()))->selectionActive)
    {
            if (entityActive==false)
            {
               if (((ActiveDialog*)(this->parent()))->activeEntity!=0)
               {
                   addConnection(((ActiveDialog*)(this->parent()))->activeEntity);
                   ((ActiveDialog*)(this->parent()))->activeEntity->addConnection(this);

                   if (this->eParent==0) this->eParent=((ActiveDialog*)(this->parent()))->activeEntity;
                   ((ActiveDialog*)(this->parent()))->activeEntity=0;
               }
              else
              {
                qDebug()<<"Selected";
                 ((ActiveDialog*)(this->parent()))->activeEntity=this;
                 this->entityActive=true;
                 this->setPixmap(*selectedPixmap);
               }
            }

     }
}

void Entity::mouseMoveEvent (QMouseEvent * event)
{
   if (((ActiveDialog*)(this->parent()))->selectionActive)
    {
        this->parentWidget()->update();
         if (moveable)
        {
             qDebug()<<"Moved!";
           moved=false;
           this->setGeometry(this->x()+event->x() -this->size().width()/2  , this->y()+event->y() -this->size().height()/2 ,this->size().width(),this->size().height());

        }
    }
}



void  Entity::mouseReleaseEvent ( QMouseEvent * event )
{
    if (((ActiveDialog*)(this->parent()))->selectionActive)

    {


         if (event->button()==Qt::RightButton)
         {
            menu->exec(event->globalPos());

         }
    }

     moveable=false;

    if (!moved)
    {
       qDebug()<<"Deselected";
       this->entityActive=false;
       //((ActiveDialog*)(this->parent()))->activeEntity=0;
       this->setPixmap(*normalPixmap);
    }

}

Entity::~Entity()
{

}
