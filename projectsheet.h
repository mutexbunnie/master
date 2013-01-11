#ifndef PROJECTSHEET_H
#define PROJECTSHEET_H

class ProjectSheet
{
public:
    ProjectSheet();
    QString sheetname;

    QMap<QString, QMap<QString,QPointF>*>* projectSheet;
    QSqlTableModel* projectLink;
};

#endif // PROJECTSHEET_H
