#ifndef ENTITYSOURCE_H
#define ENTITYSOURCE_H
#include <QString>
#include <QAbstractItemModel>


class EntitySource
{
public:
    EntitySource(QString _name,QString _entityname);
    QString getName() { return name;}
    QString getEntityName() { return entityName;}
    QAbstractItemModel* getModel() {return model;}

protected:
   QString name;
   QString entityName;
   QAbstractItemModel* model;


};

#endif //ENTITYSOURCE_H
