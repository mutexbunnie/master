#include "projectstore.h"
#include "mysqldatasource.h"
#include <QDebug>


void ProjectStore::loadProject(QString filenname)
{
    entityTypes= new QVector<EntityType*>();
    entitySources= new QVector<EntitySource*>();

    projectSheet = new QMap<QString, QMap<QString,QPointF>* >();


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


   QSqlDatabase dbConnection =  QSqlDatabase::addDatabase("QMYSQL","entityMap");
   dbConnection.setHostName(projectdb_host);
   dbConnection.setDatabaseName(projectdb_dbname);
   dbConnection.setUserName(projectdb_user);
   dbConnection.setPassword(projectdb_pass);
   bool ok = dbConnection.open();

   QSqlQuery entityQuery("SELECT distinct entityName FROM entityMap",dbConnection);



   while (entityQuery.next())
   {
      QString source = entityQuery.value(0).toString();
      QSqlQuery queryPos("SELECT uid,x,y FROM entityMap where entityName='"+source+"';",dbConnection);
      QMap<QString,QPointF>*  tmpMap = new   QMap<QString,QPointF> ();

      while (queryPos.next())
      {
          tmpMap->insert(queryPos.value(0).toString(),QPointF(queryPos.value(1).toFloat(),queryPos.value(2).toFloat()) );
      }
      projectSheet->insert(source,tmpMap);
   }

}

void ProjectStore::saveScene()
{

   QSqlDatabase dbConnection =  QSqlDatabase::database("entityMap");
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

    if (localName=="projectsheet")
    {


        for (int index = 0 ; index<atts.length();index++)
         {
            if (atts.localName(index)=="name")   {     sheetname=atts.value(index); }
            if (atts.localName(index)=="host")   {     projectdb_host=atts.value(index); }
            if (atts.localName(index)=="pass")   {     projectdb_pass=atts.value(index); }
            if (atts.localName(index)=="user")   {     projectdb_user=atts.value(index); }
            if (atts.localName(index)=="db")     {     projectdb_dbname=atts.value(index);   }

         }


    }

    return true;
}




