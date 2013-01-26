#ifndef PROJECTSTORE_H
#define PROJECTSTORE_H

#include <QtCore>
#include <QtXml>
#include <iostream>
#include "entitytype.h"
#include "entitysource.h"
#include <QVector>
#include <QMap>
#include <QSqlTableModel>
#include "projectsheet.h"
#include "datasource.h"
#include <autolink.h>


class ProjectStore :public QXmlDefaultHandler
{
  public:
    ProjectStore();
    ~ProjectStore();
    virtual bool startElement(const QString & namespaceURI, const QString & localName,const QString & qName, const QXmlAttributes & atts );
    void loadProject(QString filenname);
    //void saveProject(QString filenname); todo

    void saveScene();

    QVector<AutoLink*>* autoLinks;
    QVector<EntityType*>* entityTypes;
    QVector<Datasource*>* dataSources;
    QVector<EntitySource*>* entitySources;
    QVector<ProjectSheet*>* projectSheets;


    QString  getProjectName();

private:
    QString projectname;

};


#endif // PROJECTSTORE_H
