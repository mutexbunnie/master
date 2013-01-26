#include "projectstore.h"

#include <QDebug>


void ProjectStore::loadProject(QString filenname)
{

    entityTypes   = new QVector<EntityType*>();
    entitySources = new QVector<EntitySource*>();
    projectSheets = new QVector<ProjectSheet*>();
    dataSources   = new QVector<Datasource*>();
    autoLinks     = new QVector<AutoLink*>();

    QXmlSimpleReader* parser  = new QXmlSimpleReader();
    parser->setContentHandler(this);

    if(parser->parse(new QXmlInputSource(new QFile(filenname))))
        qDebug()<<"Parsed Successfully!";
    else
        qDebug()<<"Parsing Failed...";

    for (int i=0; i<entityTypes->size(); i++)
    {
        for (int k=0; k<entitySources->size(); k++)
        {
            if ((*entityTypes)[i]->name == ((*entitySources)[k]->getEntityType()))
            {
                qDebug()<<(*entityTypes)[i]->name;
               (*entityTypes)[i]->entitySource=(*entitySources)[k];
               break;
            }
        }
    }

   for(int i=0; i<projectSheets->size(); i++)
   {
        (*projectSheets)[i]->loadSheet();
   }

}

void ProjectStore::saveScene()
{

  /*  QSqlDatabase dbConnection =  QSqlDatabase::database("projectdb");
    dbConnection.exec("truncate entityMap;");


    QMapIterator<QString, QMap<QString,QPointF>*  > i(*projectSheet);
    while (i.hasNext())
    {
        i.next();

        QMapIterator<QString,QPointF> k((*(i.value())));
        while (k.hasNext())
        {
            k.next();


            dbConnection.exec("insert into entityMap (EntityName,uid,x,y) values('"+i.key()+"','"+k.key()+"',"+QString::number(k.value().x()) +","+QString::number(k.value().y())+")");
            //qDebug() <<       "insert into entityMap (EntityName,uid,x,y) values('"+i.key()+"','"+k.key()+"',"+QString::number(k.value().x()) +","+QString::number(k.value().y())+")";
            //qDebug() << i.key()<<k.key() << ": " << k.value().x() <<":"<<k.value().y() ;
       }
    }



   // dbConnection.exec("truncate link;");


*/
}

QString ProjectStore::getProjectName()
{
    return projectname;
}


ProjectStore::ProjectStore():QXmlDefaultHandler()
{

}

ProjectStore::~ProjectStore()
{

}

bool ProjectStore::startElement(const QString & namespaceURI, const QString & localName,const QString & qName, const QXmlAttributes & atts )
{

    if (localName=="project")
    {
        for (int index = 0 ; index<atts.length();index++)
         {
                if (atts.localName(index)=="name")   {     projectname=atts.value(index); }
         }
    }

    if (localName=="datasource")
    {

        QString name;
        QString host;
        QString type;
        QString pass;
        QString user;
        QString db;

        for (int index = 0 ; index<atts.length();index++)
         {
                if (atts.localName(index)=="name")   {    name=atts.value(index);  }
                if (atts.localName(index)=="host")   {     host=atts.value(index); }
                if (atts.localName(index)=="type")   {     type=atts.value(index); }
                if (atts.localName(index)=="pass")   {     pass=atts.value(index); }
                if (atts.localName(index)=="user")   {     user=atts.value(index); }
                if (atts.localName(index)=="db")     {     db=atts.value(index);   }
         }

        dataSources->append(new  Datasource(name,type,host,user,pass,db));
    }

    if (localName=="entitytype")
    {

        EntityType* tmpEntity=new EntityType();

        for (int index = 0 ; index<atts.length();index++)
         {
            if (atts.localName(index)=="icon")           {     tmpEntity->addIcon(atts.value(index));           }
            if (atts.localName(index)=="name")           {     tmpEntity->setName(atts.value(index));           }
         }
         entityTypes->append(tmpEntity);
    }

    if (localName=="entitysource")
    {

        QString name;
        QString entitytype;
        QString query;
        QString datasource;

        for (int index = 0 ; index<atts.length();index++)
         {
            if (atts.localName(index)=="name")        {  name=atts.value(index);        }
            if (atts.localName(index)=="entitytype")  {  entitytype=atts.value(index);  }
            if (atts.localName(index)=="datasource")  {  datasource=atts.value(index);  }
            if (atts.localName(index)=="query")       {  query=atts.value(index);       }
         }

        entitySources->append(new EntitySource(name,entitytype,query,datasource));
    }


    if (localName=="projectsheet")
    {
        QString mapTableName;
        QString linkTableName;
        QString sheetName;
        QString datasource;

        for (int index = 0 ; index<atts.length();index++)
        {
              if (atts.localName(index)=="name")           sheetName=atts.value(index);
              if (atts.localName(index)=="mapTableName")   mapTableName=atts.value(index);
              if (atts.localName(index)=="linkTableName")  linkTableName=atts.value(index);
              if (atts.localName(index)=="datasource")     datasource=atts.value(index);
        }

        projectSheets->append(new ProjectSheet(sheetName,linkTableName,mapTableName,datasource));
    }


    if (localName=="autolink")
    {

        QString name;
        QString entityType1;
        QString entityType2;
        QString query;
        QString datasource;

        for (int index = 0 ; index<atts.length();index++)
         {
            if (atts.localName(index)=="name")          name=atts.value(index);
            if (atts.localName(index)=="entitytype1")   entityType1=atts.value(index);
            if (atts.localName(index)=="entitytype2")   entityType2=atts.value(index);
            if (atts.localName(index)=="query")         query=atts.value(index);
            if (atts.localName(index)=="datasource")    datasource=atts.value(index);
         }
        autoLinks->append(new AutoLink(name,entityType1,entityType2,query,datasource));
    }

    return true;
}




