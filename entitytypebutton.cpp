#include "entitytypebutton.h"

EntityTypeButton::EntityTypeButton(QWidget *parent, EntityType *entityType) :  QPushButton(parent)
{
    this->entityType=entityType;
    this->setText(this->entityType->name);

    this->setMaximumSize(50,50);
    this->setMinimumSize(50,50);
    QSize s(50,50);
    this->setIconSize(s);
    this->setCheckable(true);

    this->setAutoExclusive(true);

    this->setIcon((entityType->normal));

}
