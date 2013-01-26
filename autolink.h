#ifndef AUTOLINK_H
#define AUTOLINK_H
#include <QString>
#include <QAbstractItemModel>
#include <QSqlQueryModel>

class AutoLink
{
public:
    AutoLink(QString _name, QString _entityType1,QString _entityType2, QString _query, QString _dataSourceName);

    QString entityType1;
    QString entityType2;
    QAbstractItemModel* getModel();
private:
    QString name;
    QString query;
    QString dataSourceName;

    QAbstractItemModel* model;

};

#endif // AUTOLINK_H
