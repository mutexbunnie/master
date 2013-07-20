#include "entityicon.h"
#include <QPainter>
#include <QDebug>
#include "graphicsscene.h"
#include "edge.h"
#include <QGraphicsView>



EntityIcon::EntityIcon (QGraphicsItem * parent,  QGraphicsScene* scene, QModelIndex  index, EntityType*  entityType , QPointF pos) : QGraphicsItem(parent)
{
    this->setZValue(-1);
    this->fontsize=20;
    this->entityType=entityType;
    this->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
    this->index=index;

    //fix location by model//
    //

    if (pos.x()==0 && pos.y()==0) setPos((qrand() %1024 )+ scene->sceneRect().width()/2,(qrand() % 1024)+ scene->sceneRect().height()/2);
    else
       setPos(pos);

    scene->addItem(this);

    currentPixmap=entityType->normal;
    //currentPixmap=entityType->selected;
    setFlag(ItemIsMovable);
    setFlag(ItemSendsGeometryChanges);
    setCacheMode(QGraphicsItem::NoCache);

   connectionList= new QVector<EntityIcon*>() ;
   //labelItem = new QGraphicsSimpleTextItem("4", this);

}


void EntityIcon::advance()
{
  //qDebug()<<pos();
    if (newPos != pos())
    {
        setPos(newPos);
   //     qDebug()<<pos();
    }

}


void EntityIcon::setFontSize(int fontsize)
{
  //this->fontsize=fontsize;
}


void EntityIcon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    QStyleOptionGraphicsItem* style = const_cast<QStyleOptionGraphicsItem*>( option );
    style->state &= ~( QStyle::State_Selected | QStyle::State_HasFocus );

    if (this->scene()->views().at(0)->transform().m11() < 0.2)

    {
        painter->setBrush(QBrush(QColor(255,0,0,150)));
        painter->drawEllipse(0,0,150,150);
    }
    else
    {
        //painter->setPen(Qt::NoPen);

        painter->drawPixmap(0,0,150,150,currentPixmap);

        QRectF textRect=QRectF(0,128,150,150);
        QFont f = painter->font();
        f.setPointSizeF(fontsize);
        painter->setFont(f);

        if (this->isSelected())
        painter->drawText(textRect,Qt::AlignHCenter+Qt::TextWrapAnywhere+Qt::TextDontClip,index.data().toString() );
        else
        {
          QString text= painter->fontMetrics().elidedText( index.data().toString() ,Qt::ElideRight ,150);
          painter->drawText(textRect,Qt::AlignHCenter+Qt::TextWrapAnywhere,text );
        }
    }

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
    return QRectF(QPoint(0,0),QSize(150,150));
}

void EntityIcon::addConnection(EntityIcon *dest)
{
     this->connectionList->append(dest);
}

QString EntityIcon::getUidValue()
{
    return index.data().toString();
}


