#ifndef ENTITYTYPE_H
#define ENTITYTYPE_H

#include <QString>
#include <QPixmap>
#include "fieldmap.h"

class EntityType
{
public:
    EntityType();
    void addIcon(QString iconPath);
    void setFieldNum(int fieldNum);


    QString iconPath;
    QPixmap* selectedPixmap;
    QPixmap* normalPixmap;
    FieldMap*  fieldMap;

};

#endif // ENTITYTYPE_H
