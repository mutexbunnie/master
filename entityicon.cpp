#include "entityicon.h"
#include <QPainter>
#include <QDebug>
#include "graphicsscene.h"
#include "edge.h"

EntityIcon::EntityIcon(QGraphicsItem *parent, QModelIndex index,EntityType *entityType) : QGraphicsPixmapItem(parent)
{
    this->entityType=entityType;

        //this->setPixmap();

    this->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
    this->setPos((qrand() % 4024)+100,(qrand() % 4024)+100);
 //    this->setScale(0.25);
    //this->setSelected();

   /* QPixmap* tmp = new  QPixmap(50,50);
    tmp->fill(Qt::blue);*/
    setPixmap(entityType->normal);
   this->index=index;
   labelItem = new QGraphicsSimpleTextItem("4", this);

   setFlag(ItemIsMovable);
   setFlag(ItemSendsGeometryChanges);
   setCacheMode(QGraphicsItem::NoCache);

   connectionList= new QVector<EntityIcon*>() ;
}




void EntityIcon::updateText()
{
  //qDebug()<<index.data(Qt::EditRole).toString();
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
    // qDebug() <<"EntityIcon::itemChange";
             if(value.toBool())
             {
                 this->setPixmap(this->entityType->selected);
                 ((GraphicsScene*)(this->scene()))->activeIcons++;
                 ((GraphicsScene*)(this->scene()))->lastSelectedIcon=this;
             }
             else
             {
                 this->setPixmap(this->entityType->normal);
                 ((GraphicsScene*)(this->scene()))->activeIcons--;
             }

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

/*GraphicsScene::mousePressEvent1
EntityIcon::mousePressEvent1
EntityIcon::itemChange
EntityIcon::mousePressEvent2
GraphicsScene::mousePressEvent2
QGraphicsScene::mouseReleaseEvent(event)1
EntityIcon::mouseReleaseEvent1
EntityIcon::mouseReleaseEvent2
QGraphicsScene::mouseReleaseEvent(event)2 */
