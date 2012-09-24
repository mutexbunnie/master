#include "projectstore.h"
#include "mysqldatasource.h"

void ProjectStore::loadProject(QString filenname)
{
    entityTypes= new QVector<EntityType*>();
    dataSources= new QVector<DataSource*>();


    QXmlSimpleReader* parser  = new QXmlSimpleReader();
    parser->setContentHandler(this);

    if(parser->parse(new QXmlInputSource(new QFile(filenname))))    std::cout<<"Parsed Successfully!"<< std::endl;
    else std::cout<<"Parsing Failed..."<< std::endl;

    for (int i=0; i<entityTypes->size(); i++)
    {
        for (int k=0; k<dataSources->size(); k++)
        {
            if ((*entityTypes)[i]->datasourcename == ((*dataSources)[k]->getName()))
            {
               (*entityTypes)[i]->datasource=(*dataSources)[k];

              QVector<StringIntTurple*>* tmpFields= (*dataSources)[k]->getFieldsDesc((*entityTypes)[i]->datalocation);

              for (int j=0; j<tmpFields->size(); j++)
                  (*entityTypes)[i]->fieldMap->addField((*tmpFields)[j]->getString(),(*tmpFields)[j]->getInt());
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

        for(int index = 0 ; index<atts.length();index++)
         {
            if (atts.localName(index)=="icon")           {     tmpEntity->addIcon(atts.value(index));           }
            if (atts.localName(index)=="name")           {     tmpEntity->setName(atts.value(index));           }
            if (atts.localName(index)=="datasource")     {     tmpEntity->setDataSourceName(atts.value(index)); }
            if (atts.localName(index)=="datalocation")  {     tmpEntity->setDataSourceLocation(atts.value(index)); }
          }



        entityTypes->append(tmpEntity);

     }

    if (localName=="datesource")
    {
        QString host;
        QString type;
        QString user;
        QString pass;
        QString db;
        QString name;

        for (int index = 0 ; index<atts.length();index++)
         {
            if (atts.localName(index)=="name")   {     name=atts.value(index); }
            if (atts.localName(index)=="host")   {     host=atts.value(index); }
            if (atts.localName(index)=="type")   {     type=atts.value(index); }
            if (atts.localName(index)=="pass")   {     pass=atts.value(index); }
            if (atts.localName(index)=="user")   {     user=atts.value(index); }
            if (atts.localName(index)=="db")     {     db=atts.value(index);   }
         }


        if (type=="mysql")
        {
            dataSources->append(new  MysqlDataSource(name,host,user,pass,db));
        }
    }

    return true;
}




