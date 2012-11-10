#include "datasource.h"
#include "mysqldatasource.h"


MysqlDataSource::MysqlDataSource(QString _name,QString _host,QString _user, QString _pass,QString _db):DataSource(_name)
{
    host=_host;
    user=_user;
    pass=_pass;
    db="test";//_db;

    dbConnection =  (QSqlDatabase::addDatabase("QMYSQL"));
    dbConnection.setHostName(host);
    dbConnection.setDatabaseName(db);
    dbConnection.setUserName(user);
    dbConnection.setPassword(pass);

    bool ok = dbConnection.open();
    qDebug()<<ok;
    model = new  QSqlQueryModel();
    model->setQuery("select concat(FirstName,' ',LastName) from Persons limit 100",dbConnection);

    //model->setQuery("select username,externalip from fwauth limit 4000",dbConnection);
    //model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    //model->select();
}
