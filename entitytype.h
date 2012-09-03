#ifndef ENTITYTYPE_H
#define ENTITYTYPE_H

#include <QString>
#include <QPixmap>

class EntityType
{
public:
    EntityType(QString iconPath);
    QString iconPath;
    QPixmap* selectedPixmap;
    QPixmap* normalPixmap;

};

#endif // ENTITYTYPE_H
