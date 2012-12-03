#ifndef PROJECTSTORE_H
#define PROJECTSTORE_H

#include <QtCore>
#include <QtXml>
#include <iostream>
#include "entitytype.h"
#include "entitysource.h"
#include <QVector>
#include <QMap>


class ProjectStore :public QXmlDefaultHandler
{
  public:
    ProjectStore();
    ~ProjectStore();
    virtual bool startElement(const QString & namespaceURI, const QString & localName,const QString & qName, const QXmlAttributes & atts );
    void loadProject(QString filenname);
    //void saveProject(QString filenname); todo

    void saveScene();

    QVector<EntityType*>* entityTypes;
    QVector<EntitySource*>* entitySources;

    QMap<QString, QMap<QString,QPointF>*   >* projectSheet;


private:
    QString sheetname;
    QString projectdb_host;
    QString projectdb_user;
    QString projectdb_pass;
    QString projectdb_dbname;


};


#endif // PROJECTSTORE_H
