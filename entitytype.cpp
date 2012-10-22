#include "entitytype.h"
#include <QIcon>
#include <QPainter>
#include <QBrush>
#include <QPen>

EntityType::EntityType()
{
   normal=0;
   selected=0;
   //fieldMap=new FieldMap();
}


void EntityType::addIcon(QString iconPath)
{
    /*normalPixmap= new QPixmap(iconPath);
    QIcon icon;
    icon.addPixmap(*normalPixmap);
    selectedPixmap= new QPixmap( icon.pixmap(64,64,QIcon::Selected,QIcon::On));*/



    normal= QPixmap(iconPath);
    normal=normal.scaled(50,50, Qt::KeepAspectRatio);

    selected= QPixmap(normal.size());
    selected.fill(QColor(0, 0, 255, 50));
    QPainter painter(&selected);
    QBrush brush(QColor(0, 0, 255,100));
    QPen pen(brush,10);
    painter.drawPixmap(0, 0, normal);
    painter.setPen(pen);
    painter.drawRect(normal.rect());
    painter.end();
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
