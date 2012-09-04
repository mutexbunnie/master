#include "entity.h"
#include "activedialog.h"
#include <QDebug>
#include <QIcon>

Entity::Entity(QWidget *parent,EntityType *entityType): QLabel(parent)
{
        this->setObjectName("label");
        int x=qrand() % 1024;
        int y=qrand() % 1024;
        this->setGeometry(QRect(x, y, 25, 25));
        this->setPixmap(*(entityType->normalPixmap));
        this->setScaledContents(true);
        this->setMouseTracking(true);
        entityActive=false;
        this->show();
        dx=0;
        dy=0;
        connection= new QVector<Entity*> ;
        eParent=0;
        menu= new QMenu(this);
        action_del=new QAction("Delete",this);
        menu->addAction(action_del);
        connect(action_del, SIGNAL(triggered()), this, SLOT(del()));
        moveable=false;
        this->entityType=entityType;

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


void Entity::setSelected(bool selected)
{

    if (selected)
    {
     qDebug()<<"Selected";
     this->entityActive=true;
     this->setPixmap(*(entityType->selectedPixmap));

    }

     else
     {
         qDebug()<<"Deselected";
         this->entityActive=false;
         this->setPixmap(*(entityType->normalPixmap));
      }

}

void Entity::mousePressEvent ( QMouseEvent * event )
{
    moveable=true;

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
                 this->setSelected(true);
                 ((ActiveDialog*)(this->parent()))->activeEntity=this;
               }
            }
            else
            {
                 this->setSelected(false);
                ((ActiveDialog*)(this->parent()))->activeEntity=0;

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


}

Entity::~Entity()
{

}

