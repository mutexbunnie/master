#include "entitysource.h"
#include "mysqldatasource.h"


MysqlDataSource::MysqlDataSource(QString _name, QString _entityname, QString _host, QString _user, QString _pass, QString _db, QString _query):EntitySource(_name,_entityname)
{
    host=_host;
    user=_user;
    pass=_pass;
    db=_db;
    query=_query;

    dbConnection =  (QSqlDatabase::addDatabase("QMYSQL",name));
    dbConnection.setHostName(host);
    dbConnection.setDatabaseName(db);
    dbConnection.setUserName(user);
    dbConnection.setPassword(pass);

    bool ok = dbConnection.open();
    qDebug()<<ok;
    model = new  QSqlQueryModel();
    ((QSqlQueryModel*)(model))->setQuery(query,dbConnection);
}
