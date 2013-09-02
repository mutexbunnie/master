#include "autolink.h"

AutoLink::AutoLink(QString _name, QString _entityType1, QString _entityType2, QString _query, QString _dataSourceName)
{
    name=_name;
    entityType1=_entityType1;
    entityType2=_entityType2;
    query=_query;
    dataSourceName=_dataSourceName;
    model = new  QSqlQueryModel();
    ((QSqlQueryModel*)(model))->setQuery(query,QSqlDatabase::database(dataSourceName));
}

QAbstractItemModel* AutoLink::getModel()
{
    return model;
}
