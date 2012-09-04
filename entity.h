#ifndef ENTITY_H
#define ENTITY_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QLabel>
#include <QMouseEvent>
#include <QVector>
#include <QMenu>
#include <entitytype.h>

class Entity : public QLabel
{
    Q_OBJECT

public:
    Entity(QWidget *parent,EntityType* entityType);
    ~Entity();
    virtual void  mouseMoveEvent    ( QMouseEvent * event );
    virtual void  mousePressEvent   ( QMouseEvent * event );
    virtual void  mouseReleaseEvent ( QMouseEvent * event );
    void addConnection(Entity*);
    void setSelected(bool selected);
    void updatePos();

    bool moveable;
    float dx,dy;
    QVector<Entity*> * connection;
    Entity* eParent;
    QMenu* menu;
    QAction* action_del;
    EntityType* entityType;


private:
        bool entityActive;

private slots:
    void del();
};

#endif // ENTITY_H

