#ifndef ENTITYSOURCE_H
#define ENTITYSOURCE_H
#include <QString>
#include <QAbstractItemModel>
#include <QSqlQueryModel>

class EntitySource
{
public:
    EntitySource(QString _name, QString _entityType, QString _query, QString _dataSourceName);
    QString getName() { return name;}
    QString getEntityType() { return entityType;}
    QAbstractItemModel* getModel() {return model;}

private:
    QString name;
    QString query;
    QString dataSourceName;
    QString entityType;
   QAbstractItemModel* model;


};

#endif //ENTITYSOURCE_H
