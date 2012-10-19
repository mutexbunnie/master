#ifndef ENTITYICON_H
#define ENTITYICON_H


#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QStyleOptionGraphicsItem>
 #include <QPersistentModelIndex>



class EntityIcon : public QGraphicsPixmapItem
{

public:
    explicit EntityIcon( QGraphicsItem * parent  , QModelIndex  index );
    virtual void  paint ( QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget );
   virtual QVariant itemChange(GraphicsItemChange change, const QVariant &value);
//    virtual void	mouseReleaseEvent ( QGraphicsSceneMouseEvent * event );

    void updateText();

signals:


public slots:

private:
        QPersistentModelIndex  index;
        QGraphicsSimpleTextItem* labelItem;
        QPixmap* normal;
        QPixmap* selected;

    
};

#endif // ENTITYICON_H
