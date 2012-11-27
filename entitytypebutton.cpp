#include "entitytypebutton.h"

EntityTypeButton::EntityTypeButton(QWidget *parent, EntityType *entityType) :  QToolButton(parent)
{
    this->entityType=entityType;
    this->setText(this->entityType->name);
    this->setMaximumSize(75,75);
    this->setMinimumSize(75,75);
    QSize s(50,50);
    this->setIconSize(s);
    this->setCheckable(true);
    this->setAutoExclusive(true);
    this->setIcon((entityType->normal));
    this->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
}
