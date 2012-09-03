#include "entitytype.h"
#include <QIcon>

EntityType::EntityType(QString iconPath)
{

    normalPixmap= new QPixmap(iconPath);
    QIcon icon;
    icon.addPixmap(*normalPixmap);
    selectedPixmap= new QPixmap( icon.pixmap(64,64,QIcon::Selected,QIcon::On));
}

