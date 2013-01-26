#include "projectsheet.h"

ProjectSheet::ProjectSheet(QString _sheetName, QString _linkTableName, QString _mapTableName, QString _dataSourceName)
{
   sheetname    = _sheetName;
   linkTableName= _linkTableName;
   mapTableName = _mapTableName;
   dataSourceName   = _dataSourceName;
   projectSheet = new QMap<QString, QMap<QString,QPointF>* >();
}

void ProjectSheet::loadSheet()
{

   QSqlDatabase projectdb= QSqlDatabase::database(dataSourceName);
   QSqlQuery entityQuery("SELECT distinct entityName FROM "+mapTableName+";",projectdb);
   qDebug()  << "Loading";
    while (entityQuery.next())
    {
       QString source = entityQuery.value(0).toString();
       QSqlQuery queryPos("SELECT uid,x,y FROM "+mapTableName+" where entityName='"+source+"';",projectdb);
       QMap<QString,QPointF>*  tmpMap = new   QMap<QString,QPointF> ();
       while (queryPos.next())
       {
        tmpMap->insert(queryPos.value(0).toString(),QPointF(queryPos.value(1).toFloat(),queryPos.value(2).toFloat()) );
       }
       projectSheet->insert(source,tmpMap);
    }
        projectLink = new QSqlTableModel(0, projectdb );
        projectLink->setTable(linkTableName);
        projectLink->setEditStrategy(QSqlTableModel::OnManualSubmit);
        projectLink->select();
        qDebug()  << "Load done";
}

