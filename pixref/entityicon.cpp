#include "entityicon.h"
#include <QPainter>
#include <QDebug>


EntityIcon::EntityIcon(QGraphicsItem *parent, QPixmap *_normal,QPixmap *_selected) : QGraphicsPixmapItem(parent)
{

    this->normal=_normal;
    this->selected=  _selected;
    this->setPixmap(*(this->normal));
    this->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
    this->setPos((qrand() % 1024),(qrand() % 1024));
    this->setScale(0.25);
    //this->setSelected();

   qDebug()<<this->normal;



}

void EntityIcon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QStyleOptionGraphicsItem* style = const_cast<QStyleOptionGraphicsItem*>( option );
    style->state &= ~( QStyle::State_Selected | QStyle::State_HasFocus );
    QGraphicsPixmapItem::paint(painter,style,widget);

}


QVariant  EntityIcon::itemChange(GraphicsItemChange change, const QVariant &value)
{
  if (change==QGraphicsItem::ItemSelectedHasChanged)
    {
     if(value.toBool()) this->setPixmap(*(this->selected));
               else
   this->setPixmap(*(this->normal));
  }


  return QGraphicsPixmapItem::itemChange(change, value);
}

void EntityIcon::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{

}


