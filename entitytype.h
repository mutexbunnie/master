#ifndef ENTITYTYPE_H
#define ENTITYTYPE_H

#include <QString>
#include <QPixmap>
#include <QIcon>
#include <QPainter>
#include <QBrush>
#include <QPen>
#include <QDebug>
#include "entitysource.h"
#include "entityicon.h"

class EntityType
{
public:
    EntityType();
    void setName(QString _name);
    void addIcon(QString iconPath);
    void setEntitySource(EntitySource* _entitySource);

    //TODO::SHOULD be private
    QString iconPath;
    QPixmap plain;
    QPixmap selected;
    QPixmap normal;
    QString name;
    EntitySource* entitySource;

};

#endif // ENTITYTYPE_H
