#include "entitytype.h"
#include <QIcon>
#include <QPainter>
#include <QBrush>
#include <QPen>
#include <QDebug>

EntityType::EntityType()
{
   normal=0;
   selected=0;
}


void EntityType::addIcon(QString iconPath)
{
    this->iconPath=iconPath;
    normal= QPixmap(iconPath);
    normal=normal.scaled(50,50, Qt::KeepAspectRatio);

    selected= QPixmap(normal.size());
    selected.fill(QColor(0, 0, 255, 50));
    QPainter painter(&selected);
    QBrush brush(QColor(0, 0, 255,100));
    QPen pen(brush,4);
    painter.drawPixmap(0, 0, normal);
    painter.setPen(pen);
    painter.drawRect(normal.rect());
    painter.end();
}


void EntityType::setEntitySource(EntitySource* _entitySource)
{
  entitySource =_entitySource;
}

void EntityType::setName(QString _name)
{
  name =_name;
}
