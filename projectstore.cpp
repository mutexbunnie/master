#include "projectstore.h"
#include "mysqldatasource.h"
#include <QDebug>

void ProjectStore::loadProject(QString filenname)
{
    entityTypes= new QVector<EntityType*>();
    entitySources= new QVector<EntitySource*>();


    QXmlSimpleReader* parser  = new QXmlSimpleReader();
    parser->setContentHandler(this);

    if(parser->parse(new QXmlInputSource(new QFile(filenname))))    std::cout<<"Parsed Successfully!"<< std::endl;
    else std::cout<<"Parsing Failed..."<< std::endl;

   for (int i=0; i<entityTypes->size(); i++)
    {

        for (int k=0; k<entitySources->size(); k++)
        {

            if ((*entityTypes)[i]->name == ((*entitySources)[k]->getEntityName()))
            {
                 qDebug()<<(*entityTypes)[i]->name;
               (*entityTypes)[i]->entitySource=(*entitySources)[k];

               break;
            }
        }
    }



}



ProjectStore::ProjectStore():QXmlDefaultHandler()
{

}

ProjectStore::~ProjectStore()
{

}

bool ProjectStore::startElement(const QString & namespaceURI, const QString & localName,const QString & qName, const QXmlAttributes & atts )
{

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
        QString host;
        QString type;
        QString user;
        QString pass;
        QString db;
        QString name;
        QString entityname;
        QString query;

        for (int index = 0 ; index<atts.length();index++)
         {
            if (atts.localName(index)=="name")   {     name=atts.value(index); }
            if (atts.localName(index)=="entityname")   {entityname=atts.value(index);  }
            if (atts.localName(index)=="host")   {     host=atts.value(index); }
            if (atts.localName(index)=="type")   {     type=atts.value(index); }
            if (atts.localName(index)=="pass")   {     pass=atts.value(index); }
            if (atts.localName(index)=="user")   {     user=atts.value(index); }
            if (atts.localName(index)=="db")     {     db=atts.value(index);   }
            if (atts.localName(index)=="query")     {  query=atts.value(index);   }
         }

        if (type=="mysql")
        {

            entitySources->append(new  MysqlDataSource(name,entityname,host,user,pass,db,query));

        }
    }

    return true;
}




