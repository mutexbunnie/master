#include "entityicon.h"

//TODO::FORWARD DECLARATION FIX
#include "entitytype.h"
#include "edge.h"
#include "graphicsscene.h"

EntityIcon::EntityIcon (QGraphicsItem * parent,  QGraphicsScene* scene, QModelIndex  index, EntityType*  entityType , QPointF pos) : QGraphicsItem(parent)
{
    this->setZValue(1);
    this->entityType=entityType;
    this->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
    this->index=index;


    //TODO::fix location by model
    if (pos.x()==0 && pos.y()==0) setPos((qrand() %1024 )+ scene->sceneRect().width()/2,(qrand() % 1024)+ scene->sceneRect().height()/2);
    else  setPos(pos);

    setFlag(ItemIsMovable);
    setFlag(ItemSendsGeometryChanges);
    setCacheMode(QGraphicsItem::NoCache);
    currentPixmap=entityType->normal;
    scene->addItem(this);
    connectionList= new QVector<EntityIcon*>() ;
 }

void EntityIcon::advance()
{
    if (newPos != pos()) setPos(newPos);
}


void EntityIcon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    QStyleOptionGraphicsItem* style = const_cast<QStyleOptionGraphicsItem*>( option );
    style->state &= ~( QStyle::State_Selected | QStyle::State_HasFocus );

    //TODO:MOVE LOGIC OUT OF HERE
    if (this->scene()->views().at(0)->transform().m11() < 0.2)
    {
        painter->setBrush(QBrush(QColor(255,0,0,150+1/this->scene()->views().at(0)->transform().m11())));
        painter->drawEllipse(EntityIcon::horizMargin,EntityIcon::verticalMargin,EntityIcon::iconSize,EntityIcon::iconSize);
    }
    else
    {
        painter->drawPixmap(0,0,EntityIcon::totalWidth,EntityIcon::totalHeight,currentPixmap);

        QRectF textRect=QRectF(EntityIcon::horizMargin/2,EntityIcon::verticalMargin+EntityIcon::iconSize,EntityIcon::iconSize+EntityIcon::horizMargin,EntityIcon::fontSize*2);
        QFont f = painter->font();
        f.setPointSizeF(EntityIcon::fontSize);
        painter->setFont(f);

        if (this->isSelected())
        painter->drawText(textRect,Qt::AlignHCenter+Qt::TextWrapAnywhere+Qt::TextDontClip,index.data().toString() );
        else
        {
          QString text= painter->fontMetrics().elidedText( index.data().toString() ,Qt::ElideRight ,textRect.width());
          painter->drawText(textRect,Qt::AlignHCenter+Qt::TextWrapAnywhere,text );
        }
    }
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
    return QRectF(QPoint(0,0),QSize(EntityIcon::totalWidth,EntityIcon::totalHeight));
}

void EntityIcon::addConnection(EntityIcon *dest)
{
     this->connectionList->append(dest);
}

QString EntityIcon::getUidValue()
{
    return index.data().toString();
}


