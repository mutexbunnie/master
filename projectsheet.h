#ifndef PROJECTSHEET_H
#define PROJECTSHEET_H
#include <QtCore>
#include <QSqlTableModel>
#include <QSqlQuery>


class ProjectSheet
{
public:
    ProjectSheet( QString _sheetName, QString _linkTableName, QString _mapTableName,QString _dataSourceName);
    void loadSheet();


    QString linkTableName;
    QString mapTableName;
    QString sheetname;
    QString dataSourceName;
    QMap<QString, QMap<QString,QPointF>*>* projectSheet;
    QSqlTableModel* projectLink;



};

#endif // PROJECTSHEET_H
