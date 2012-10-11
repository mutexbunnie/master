#ifndef ENTITYICON_H
#define ENTITYICON_H


#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QStyleOptionGraphicsItem>



class EntityIcon : public QGraphicsPixmapItem
{

public:
    explicit EntityIcon( QGraphicsItem * parent = 0 ,QPixmap* _normal=0,QPixmap* _selected=0);
    virtual void  paint ( QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget );
    virtual QVariant itemChange(GraphicsItemChange change, const QVariant &value);
    virtual void	mouseReleaseEvent ( QGraphicsSceneMouseEvent * event );

signals:


public slots:

private:
        QPixmap* normal;
        QPixmap* selected;



    
};

#endif // ENTITYICON_H
