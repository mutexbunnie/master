#include "projectstore.h"
#include "mysqldatasource.h"
#include <QDebug>


void ProjectStore::loadProject(QString filenname)
{

    entityTypes= new QVector<EntityType*>();
    entitySources= new QVector<EntitySource*>();
    projectSheets = new QVector<ProjectSheet*>();


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


   dbConnection =  QSqlDatabase::addDatabase("QMYSQL","projectdb");
   dbConnection.setHostName(projectdb_host);
   dbConnection.setDatabaseName(projectdb_dbname);
   dbConnection.setUserName(projectdb_user);
   dbConnection.setPassword(projectdb_pass);
   bool ok = dbConnection.open();


   for(int i=0; i<projectSheets->size(); i++)
   {
       (*projectSheets)[i]->setProjectdb(dbConnection);
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
                if (atts.localName(index)=="host")   {     projectdb_host=atts.value(index); }
                if (atts.localName(index)=="pass")   {     projectdb_pass=atts.value(index); }
                if (atts.localName(index)=="user")   {     projectdb_user=atts.value(index); }
                if (atts.localName(index)=="db")     {     projectdb_dbname=atts.value(index);   }
         }
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
        QString mapTableName;
        QString linkTableName;
        QString sheetName;
        for (int index = 0 ; index<atts.length();index++)
        {
              if (atts.localName(index)=="name")           sheetName=atts.value(index);
              if (atts.localName(index)=="mapTableName")   mapTableName=atts.value(index);
              if (atts.localName(index)=="linkTableName")  linkTableName=atts.value(index);
        }

        projectSheets->append(new ProjectSheet(sheetName,linkTableName,mapTableName));
    }

    return true;
}




