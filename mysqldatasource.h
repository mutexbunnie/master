#ifndef MYSQLDATASOURCE_H
#define MYSQLDATASOURCE_H
#include "datasource.h"
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlError>
#include "stringintturple.h"

class MysqlDataSource: public DataSource
{
public:
    MysqlDataSource(QString _name, QString _host, QString _user, QString _pass, QString _db);
    QVector<StringIntTurple *>* getFieldsDesc(QString location);

   QVector<QVector<QVariant>*>* getFields(QString location,QString specifier);

    QSqlDatabase dbConnection;


private:
    QString host;
    QString type;
    QString user;
    QString pass;
    QString db;

};




#endif // MYSQLDATASOURCE_H
