#include <QApplication>
#include "mainform.h"
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlError>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

  QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setDatabaseName("test");
    db.setUserName("root");
    db.setPassword("root");

    bool ok = db.open();

    QSqlQuery query;
    query.exec("show tables");

    QVector<QString>* tableNames= new QVector<QString>();

    while (query.next())
    {
         tableNames->append(query.value(0).toString());
    }

    QVector<EntityType*>* entityTypes = new QVector<EntityType*>();

    for (int i=0; i< tableNames->size() ;i++)
    {

        query.exec("desc "+ tableNames->at(i));

        EntityType* tmpEntityType = new EntityType();
        tmpEntityType->setFieldNum(query.size());
        tmpEntityType->addIcon(":/icons/star.png");


        while (query.next())
        {
            int fieldType;
            if  (query.value(1).toString().contains("int"))  fieldType=1;
            else fieldType=0;

           tmpEntityType->fieldMap->addField( query.value(0).toString(),fieldType);

        }

        entityTypes->append(tmpEntityType);
    }



    MainForm mainForm(entityTypes);
    mainForm.showMaximized();


    return a.exec();
}
