#include "entitysource.h"

EntitySource::EntitySource(QString _name, QString _entityType, QString _query, QString _dataSourceName)
{
    name=_name;
    entityType=_entityType;
    query=_query;
    dataSourceName=_dataSourceName;
    model = new  QSqlQueryModel();
    ((QSqlQueryModel*)(model))->setQuery(query,QSqlDatabase::database(dataSourceName));
}


