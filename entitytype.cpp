#include "entitytype.h"


EntityType::EntityType()
{
   normal=0;
   selected=0;
}

void EntityType::addIcon(QString iconPath)
{
    plain= QPixmap(iconPath);
    this->iconPath=iconPath;
    normal= QPixmap(QSize(EntityIcon::totalWidth,EntityIcon::totalHeight));

    normal.fill(QColor(255, 255, 255,0));

    QPainter painterNormal(&normal);
    painterNormal.setRenderHint(QPainter::HighQualityAntialiasing, true);
    painterNormal.setRenderHint(QPainter::SmoothPixmapTransform, true);

    QBrush brush(QColor(0, 0, 0,100));
    QPen pen(brush,4);
    painterNormal.setPen(pen);
    painterNormal.drawPixmap(EntityIcon::horizMargin,EntityIcon::verticalMargin,EntityIcon::iconSize,EntityIcon::iconSize,plain);
    painterNormal.end();

    selected= QPixmap(QSize(EntityIcon::totalWidth,EntityIcon::totalHeight));
    selected.fill(QColor(0, 0, 255, 50));
    QPainter painter(&selected);

    painter.setRenderHint(QPainter::HighQualityAntialiasing, true);
    painter.setRenderHint(QPainter::SmoothPixmapTransform, true);

    painter.setPen(pen);
    painter.drawRect(selected.rect());
    painter.drawPixmap(EntityIcon::horizMargin,EntityIcon::verticalMargin,EntityIcon::iconSize,EntityIcon::iconSize,plain);
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
