#include "entityicon.h"
#include <QPainter>
#include <QDebug>
#include "graphicsscene.h"
#include "edge.h"

EntityIcon::EntityIcon(QGraphicsItem *parent, QModelIndex index, EntityType *entityType) : QGraphicsItem(parent)
{
    this->entityType=entityType;
    this->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
    this->index=index;

    //fix location by model//
    setPos((qrand() % 1024)+100,(qrand() % 1024)+100);

    currentPixmap=entityType->normal;
    setFlag(ItemIsMovable);
    setFlag(ItemSendsGeometryChanges);
    setCacheMode(QGraphicsItem::NoCache);

   connectionList= new QVector<EntityIcon*>() ;
   //labelItem = new QGraphicsSimpleTextItem("4", this);

}

/*void EntityIcon::updateText()
{
  //fix//
  if  (index.data(Qt::EditRole).toString() !=labelItem->text())
  {
   labelItem->setText(index.data().toString());
   labelItem->setPos(0,50);
  }
}*/


void EntityIcon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
   // updateText();
    QStyleOptionGraphicsItem* style = const_cast<QStyleOptionGraphicsItem*>( option );
    style->state &= ~( QStyle::State_Selected | QStyle::State_HasFocus );
    painter->drawPixmap(0,0,75,75,currentPixmap);


    /*QPixmap selected( QSize(75,75));
    selected.fill(QColor(0, 0, 255, 50));
    painter->drawPixmap(0,0,75,75,selected);
    painter->drawPixmap(15,5,50,50,entityType->normal);
    QBrush brush(QColor(0, 0, 255,100));
    QPen pen(brush,4);
    painter->setPen(pen);
    painter->drawRect(selected.rect());*/

    painter->drawText(QRectF(15,60,50,1000), Qt::TextWrapAnywhere,index.data().toString());

   // painter->end();

}


QVariant  EntityIcon::itemChange(GraphicsItemChange change, const QVariant &value)
{

  if (change==QGraphicsItem::ItemSelectedHasChanged)
    {

       if(value.toBool()) currentPixmap=this->entityType->selected;
       else               currentPixmap=this->entityType->normal;
    }
  return QGraphicsItem::itemChange(change, value);

}

void EntityIcon::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
  //  qDebug() <<"EntityIcon::mouseReleaseEvent1";
  QGraphicsItem::mouseReleaseEvent(event);
 // qDebug() <<"EntityIcon::mouseReleaseEvent2";
}

void EntityIcon::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    //qDebug() <<"EntityIcon::mousePressEvent1";
    QGraphicsItem::mousePressEvent(event);
    //qDebug()<<entityType->name;
    // qDebug() <<"EntityIcon::mousePressEvent2";
}

QRectF EntityIcon::boundingRect() const
{
    return QRectF(QPoint(0,0),QSize(100,100));
}

void EntityIcon::addConnection(EntityIcon *dest)
{
    Edge* tmpEdge = new Edge(this,dest);
    scene()->addItem(tmpEdge);
    scene()->update();
    this->connectionList->append(dest);
}


