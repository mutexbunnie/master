#include "entityicon.h"
#include <QPainter>
#include <QDebug>


EntityIcon::EntityIcon(QGraphicsItem *parent, QModelIndex index) : QGraphicsPixmapItem(parent)
{

    /* QPixmap *_normal,QPixmap *_selected
    this->normal=_normal;
    this->selected=  _selected;*/




    //this->setPixmap();

    this->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
    this->setPos((qrand() % 100024),(qrand() % 100024));
    // this->setScale(0.25);
    //this->setSelected();

    QPixmap* tmp = new  QPixmap(50,50);
    tmp->fill(Qt::blue);
    setPixmap(*tmp);

   this->index=index;
  //   labelItem = new QGraphicsSimpleTextItem("", this);
   //labelItem->moveBy(-15,-25);


}


void EntityIcon::updateText()
{
  //qDebug()<<index.data(Qt::EditRole).toString();
  //if  (index.data(Qt::EditRole).toString() !=labelItem->text())
 // {
  //  labelItem->setText(index.data(Qt::EditRole).toString());
  //}
}


void EntityIcon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{


//    updateText();
    QStyleOptionGraphicsItem* style = const_cast<QStyleOptionGraphicsItem*>( option );
    style->state &= ~( QStyle::State_Selected | QStyle::State_HasFocus );
    QGraphicsPixmapItem::paint(painter,style,widget);
}


QVariant  EntityIcon::itemChange(GraphicsItemChange change, const QVariant &value)
{
 /*if (change==QGraphicsItem::ItemSelectedHasChanged)
    {
     if(value.toBool()) this->setPixmap(index.data(34).value<QPixmap>());
               else
   this->setPixmap(index.data(Qt::DecorationRole).value<QPixmap>());
  }*/


  return QGraphicsPixmapItem::itemChange(change, value);
}

/*void EntityIcon::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{

}*/


