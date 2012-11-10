#ifndef DATASOURCE_H
#define DATASOURCE_H
#include <QString>


class DataSource
{
public:
    DataSource(QString _name);
    QString getName() { return name;}

private:
   QString name;



};

#endif // DATASOURCE_H
