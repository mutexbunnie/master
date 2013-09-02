#ifndef PROJECTSTORE_H
#define PROJECTSTORE_H

#include <QDebug>
#include <QtCore>
#include <QtXml>
#include <QVector>

#include "autolink.h"
#include "datasource.h"
#include "entitytype.h"
#include "entitysource.h"
#include "projectsheet.h"

class ProjectStore :public QXmlDefaultHandler
{
  public:

    //TODO::Should be private

    QVector<AutoLink*>* autoLinks;
    QVector<EntityType*>* entityTypes;
    QVector<Datasource*>* dataSources;
    QVector<EntitySource*>* entitySources;
    QVector<ProjectSheet*>* projectSheets;


    ProjectStore();
    ~ProjectStore();
    virtual bool startElement(const QString & namespaceURI, const QString & localName,const QString & qName, const QXmlAttributes & atts );
    void loadProject(QString filenname);
    QString  getProjectName();
    //TODO:void saveScene();
    //TODO:void saveProject(QString filenname)

private:
    QString projectname;


};
#endif // PROJECTSTORE_H
