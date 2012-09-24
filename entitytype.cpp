#include "entitytype.h"
#include <QIcon>

EntityType::EntityType()
{
   normalPixmap=0;
   selectedPixmap=0;
   fieldMap=new FieldMap();
}


void EntityType::addIcon(QString iconPath)
{
    normalPixmap= new QPixmap(iconPath);
    QIcon icon;
    icon.addPixmap(*normalPixmap);
    selectedPixmap= new QPixmap( icon.pixmap(64,64,QIcon::Selected,QIcon::On));

}

void EntityType::setName(QString _name)
{
  name= _name;
}

void EntityType::setDataSourceName(QString _datasourceName)
{
 datasourcename=_datasourceName;
}

void EntityType::setDataSourceLocation(QString _dataSourceLocation)
{
 datalocation=_dataSourceLocation;
}

void EntityType::setDataSource(DataSource* _dataSource)
{
  datasource=_dataSource;
}
