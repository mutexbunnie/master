#include "entitytype.h"
#include <QIcon>

EntityType::EntityType()
{

    fieldMap =0;
    normalPixmap=0;
    selectedPixmap=0;
}


void EntityType::addIcon(QString iconPath)
{
    normalPixmap= new QPixmap(iconPath);
    QIcon icon;
    icon.addPixmap(*normalPixmap);
    selectedPixmap= new QPixmap( icon.pixmap(64,64,QIcon::Selected,QIcon::On));

}

void  EntityType::setFieldNum(int fieldNum)
{
    fieldMap=new FieldMap(fieldNum);
}
