#include "datasource.h"

Datasource::Datasource(QString _name, QString _type, QString _host, QString _user, QString _pass, QString _db)
{
    host=_host;
    user=_user;
    pass=_pass;
    db=_db;
    name=_name;
    type=_type;

    if (type=="mysql")
    {
        QSqlDatabase dbConnection =  (QSqlDatabase::addDatabase("QMYSQL",name));
        dbConnection.setHostName(host);
        dbConnection.setDatabaseName(db);
        dbConnection.setUserName(user);
        dbConnection.setPassword(pass);
        qDebug()<< "Opening Datasource "<<  name <<" : " << dbConnection.open();
    }

}
