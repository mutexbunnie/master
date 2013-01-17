#ifndef PROJECTSHEET_H
#define PROJECTSHEET_H
#include <QtCore>
#include <QSqlTableModel>
#include <QSqlQuery>

class ProjectSheet
{
public:
    ProjectSheet( QString _sheetName, QString _linkTableName, QString _mapTableName);
    void loadSheet();
    void setProjectdb(QSqlDatabase _projectdb);

    QString linkTableName;
    QString mapTableName;
    QString sheetname;
    QMap<QString, QMap<QString,QPointF>*>* projectSheet;
    QSqlTableModel* projectLink;
    QSqlDatabase projectdb;

};

#endif // PROJECTSHEET_H
