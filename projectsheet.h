#ifndef PROJECTSHEET_H
#define PROJECTSHEET_H
#include <QtCore>
#include <QSqlTableModel>
#include <QSqlQuery>
#include "graphicsheet.h"

class ProjectStore;

class ProjectSheet
{
public:
    ProjectSheet(QString _sheetName, QString _linkTableName, QString _mapTableName, QString _dataSourceName, ProjectStore* projectStore) ;
    void loadSheet();


    QString linkTableName;
    QString mapTableName;
    QString sheetname;
    QString dataSourceName;
    QMap<QString, QMap<QString,QPointF>*>* projectSheet;
    QSqlTableModel* projectLink;
    GraphicSheet* graphicSheet;
    ProjectStore* projectStore;

};

#endif // PROJECTSHEET_H
