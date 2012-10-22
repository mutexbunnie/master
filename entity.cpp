#include "entity.h"
#include "activedialog.h"
#include <QDebug>
#include <QIcon>

Entity::Entity(QWidget *parent,EntityType *entityType): QLabel(parent)
{

        this->entityType=entityType;
        //stringFields=new QString[entityType->fieldMap->getStringFields()];
        //intFields= new int[entityType->fieldMap->getintFields()];

        this->setObjectName("label");
        int x=qrand() % 1024;
        int y=qrand() % 1024;
        this->setGeometry(QRect(x, y, 50, 50));
        this->setPixmap((entityType->normal));
        this->setScaledContents(true);
        //this->setMouseTracking(true);
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
     this->setPixmap((entityType->selected));
    }
    else
    {
         qDebug()<<"Deselected";
         this->entityActive=false;
         this->setPixmap((entityType->normal));
    }

}

void Entity::mousePressEvent ( QMouseEvent * event )
{

       ((ActiveDialog*)(this->parent()))->clickWidget=true;
       ((ActiveDialog*)(this->parent()))->setActiveEntity(this);

       event->ignore();
}




void  Entity::showMenu()
{
    menu->exec(((ActiveDialog*)(this->parent()))->mapToGlobal(this->pos()));

}



void Entity::addField(QString fieldValue,QString fieldName)
{
    //stringFields[entityType->fieldMap->getArrPos(fieldName)]=fieldValue;
}

void Entity::addField(int fieldValue,QString fieldName)
{
      //  intFields[entityType->fieldMap->getArrPos(fieldName)]=fieldValue;
}

Entity::~Entity()
{

}

