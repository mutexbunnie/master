#ifndef DATASOURCE_H
#define DATASOURCE_H
#include <QString>
#include <QVariant>

#include "stringintturple.h"

class DataSource
{
public:
    DataSource(QString _name);
    virtual QVector<StringIntTurple*>* getFieldsDesc(QString location)=0;
    virtual QVector<QVector<QVariant>*>* getFields(QString location,QString specifier)=0;

    QString getName() { return name;}
private:
   QString name;



};

#endif // DATASOURCE_H
