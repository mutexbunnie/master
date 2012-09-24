#ifndef ENTITYTYPE_H
#define ENTITYTYPE_H

#include <QString>
#include <QPixmap>
#include "fieldmap.h"
#include "datasource.h"

class EntityType
{
public:
    EntityType();


    QString iconPath;
    QPixmap* selectedPixmap;
    QPixmap* normalPixmap;
    FieldMap*  fieldMap;

    QString name;
    QString datasourcename;
    DataSource* datasource;
    QString datalocation;

    void setName(QString);
    void setDataSourceName(QString _datasourceName);
    void setDataSourceLocation(QString _dataSourceLocation);
    void addIcon(QString iconPath);
    void setDataSource(DataSource* _dataSource);

};

#endif // ENTITYTYPE_H
