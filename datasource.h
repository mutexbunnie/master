#ifndef DATASOURCE_H
#define DATASOURCE_H
#include <QString>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlError>

class Datasource
{
public:
    Datasource(QString _name, QString _type, QString _host, QString _user, QString _pass, QString _db);

private:
    QString host;
    QString type;
    QString user;
    QString pass;
    QString db;
    QString name;
};

#endif // DATASOURCE_H
