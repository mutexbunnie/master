#ifndef MYSQLDATASOURCE_H
#define MYSQLDATASOURCE_H
#include "entitysource.h"
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQueryModel>

class MysqlDataSource: public EntitySource
{
public:
    MysqlDataSource(QString _name, QString _entityname ,QString _host, QString _user, QString _pass, QString _db,QString _query);
    QSqlDatabase dbConnection;

private:
    QString host;
    QString type;
    QString user;
    QString pass;
    QString db;
    QString query;
};




#endif // MYSQLDATASOURCE_H
