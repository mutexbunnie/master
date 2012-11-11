#include "entityicon.h"
#include <QPainter>
#include <QDebug>
#include "graphicsscene.h"
#include "edge.h"

EntityIcon::EntityIcon(QGraphicsItem *parent, QModelIndex index, EntityType *entityType) : QGraphicsPixmapItem(parent)
{
    this->entityType=entityType;
    this->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
    this->index=index;

    //fix location by model//
    setPos((qrand() % 4024)+100,(qrand() % 4024)+100);

    setPixmap(entityType->normal);
    setFlag(ItemIsMovable);
    setFlag(ItemSendsGeometryChanges);
    setCacheMode(QGraphicsItem::NoCache);

   connectionList= new QVector<EntityIcon*>() ;
   labelItem = new QGraphicsSimpleTextItem("4", this);
}

void EntityIcon::updateText()
{
  //fix//
  if  (index.data(Qt::EditRole).toString() !=labelItem->text())
  {
   labelItem->setText(index.data().toString());
   labelItem->setPos(0,50);
  }
}


void EntityIcon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    updateText();
    QStyleOptionGraphicsItem* style = const_cast<QStyleOptionGraphicsItem*>( option );
    style->state &= ~( QStyle::State_Selected | QStyle::State_HasFocus );
    QGraphicsPixmapItem::paint(painter,style,widget);
}


QVariant  EntityIcon::itemChange(GraphicsItemChange change, const QVariant &value)
{

  if (change==QGraphicsItem::ItemSelectedHasChanged)
    {

       if(value.toBool()) this->setPixmap(this->entityType->selected);
       else               this->setPixmap(this->entityType->normal);
    }
  return QGraphicsPixmapItem::itemChange(change, value);

}

void EntityIcon::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
  //  qDebug() <<"EntityIcon::mouseReleaseEvent1";
  QGraphicsPixmapItem::mouseReleaseEvent(event);
 // qDebug() <<"EntityIcon::mouseReleaseEvent2";
}

void EntityIcon::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    //qDebug() <<"EntityIcon::mousePressEvent1";
    QGraphicsPixmapItem::mousePressEvent(event);
    //qDebug()<<entityType->name;
    // qDebug() <<"EntityIcon::mousePressEvent2";
}

QRectF EntityIcon::boundingRect()
{
    return QRectF(0,0,50+labelItem->boundingRect().width(),50+labelItem->boundingRect().height());
}

void EntityIcon::addConnection(EntityIcon *dest)
{
    Edge* tmpEdge = new Edge(this,dest);
    scene()->addItem(tmpEdge);
    scene()->update();
    this->connectionList->append(dest);
}
