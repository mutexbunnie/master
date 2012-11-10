#ifndef MYSQLDATASOURCE_H
#define MYSQLDATASOURCE_H
#include "datasource.h"
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQueryModel>

class MysqlDataSource: public DataSource
{
public:
    MysqlDataSource(QString _name, QString _host, QString _user, QString _pass, QString _db);
    QSqlDatabase dbConnection;
    QSqlQueryModel* model;

private:
    QString host;
    QString type;
    QString user;
    QString pass;
    QString db;
};




#endif // MYSQLDATASOURCE_H
