#ifndef PROJECTSTORE_H
#define PROJECTSTORE_H

#include <QtCore>
#include <QtXml>
#include <iostream>
#include "entitytype.h"
#include "entitysource.h"
#include <QVector>

class ProjectStore :public QXmlDefaultHandler
{
  public:
    ProjectStore();
    ~ProjectStore();
    virtual bool startElement(const QString & namespaceURI, const QString & localName,const QString & qName, const QXmlAttributes & atts );
    void loadProject(QString filenname);
    QVector<EntityType*>* entityTypes;
    QVector<EntitySource*>* entitySources;
};


#endif // PROJECTSTORE_H
