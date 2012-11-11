#ifndef ENTITYTYPE_H
#define ENTITYTYPE_H

#include <QString>
#include <QPixmap>
#include "entitysource.h"

class EntityType
{
public:
    EntityType();

    QString iconPath;
    QPixmap selected;
    QPixmap normal;

    QString name;
    EntitySource* entitySource;


    void setName(QString _name);
    void addIcon(QString iconPath);
    void setEntitySource(EntitySource* _entitySource);

};

#endif // ENTITYTYPE_H
