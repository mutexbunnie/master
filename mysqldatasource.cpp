#include "datasource.h"
#include "mysqldatasource.h"


MysqlDataSource::MysqlDataSource(QString _name,QString _host,QString _user, QString _pass,QString _db):DataSource(_name)
{
    host=_host;
    user=_user;
    pass=_pass;
    db=_db;

    dbConnection =  (QSqlDatabase::addDatabase("QMYSQL"));
    dbConnection.setHostName(host);
    dbConnection.setDatabaseName(db);
    dbConnection.setUserName(user);
    dbConnection.setPassword(pass);

    bool ok = dbConnection.open();
    model = new  QSqlQueryModel();
    model->setQuery("select distinct username from fwauth",dbConnection);

    //model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    //model->select();
}


QVector<StringIntTurple*>*  MysqlDataSource::getFieldsDesc(QString location)
{
   /*QVector<StringIntTurple*>* tmpVector=new QVector<StringIntTurple*>() ;

   QSqlQuery query;
    query.exec("desc "+ location);


      while (query.next())
      {
              int fieldType;
              if (query.value(1).toString().contains("int")) fieldType=1;
              else fieldType=0;

              tmpVector->append( new StringIntTurple(query.value(0).toString(),fieldType));
      }

     return tmpVector;*/
     return 0;
}


QVector<QVector<QVariant>*>* MysqlDataSource::getFields(QString location,QString specifier)
{

  /*  //qDebug()<< location;
   QSqlQuery query;
    query.exec("select * from "+ location+ " where "+specifier);

    QVector<QVector<QVariant>*>* result = new QVector<QVector<QVariant>*>;

       while (query.next())
       {
          //   qDebug()<<query.value(0).toString();
           QVector<QVariant>* row= new QVector<QVariant>;
           for (int i=0;i<query.record().count();i++)
           {

               //There is no point in telling a story if no one understands it
               row->append(query.value(i));
           }
           result->append(row);
       }

     return result;*/
    return 0;
}
