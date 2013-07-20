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
    normal= QPixmap(QSize(150,150));

    normal.fill(QColor(255, 255, 255,0));

    QPainter painterNormal(&normal);
    painterNormal.setRenderHint(QPainter::HighQualityAntialiasing, true);
    painterNormal.setRenderHint(QPainter::SmoothPixmapTransform, true);

    QBrush brush(QColor(0, 0, 0,100));
    QPen pen(brush,4);
    painterNormal.setPen(pen);
    //painterNormal.drawRect(normal.rect());
    painterNormal.drawPixmap(11,0,128,128, QPixmap(iconPath));
    painterNormal.end();

    //normal=normal.scaled(50,50, Qt::KeepAspectRatio);


    selected= QPixmap(QSize(150,150));
    selected.fill(QColor(0, 0, 255, 50));
    QPainter painter(&selected);

    painter.setRenderHint(QPainter::HighQualityAntialiasing, true);
    painter.setRenderHint(QPainter::SmoothPixmapTransform, true);

    painter.setPen(pen);
    painter.drawRect(selected.rect());
    painter.drawPixmap(11,0,128,128, QPixmap(iconPath));
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
