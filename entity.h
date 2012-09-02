#ifndef ENTITY_H
#define ENTITY_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QLabel>
#include <QMouseEvent>
#include <QVector>
#include <QMenu>

class Entity : public QLabel
{
    Q_OBJECT

public:
    Entity(QWidget *parent);
    ~Entity();
    virtual void  mouseMoveEvent    ( QMouseEvent * event );
    virtual void  mousePressEvent   ( QMouseEvent * event );
    virtual void  mouseReleaseEvent ( QMouseEvent * event );
    void addConnection(Entity*);
    void updatePos();
    bool entityActive;
    bool moveable;
    bool moved;
    float dx,dy;
    QVector<Entity*> * connection;
    Entity* eParent;
    QMenu* menu;
    QAction* action_del;
    QPixmap* selectedPixmap;
    QPixmap* normalPixmap;


private slots:
    void del();
};

#endif // ENTITY_H

