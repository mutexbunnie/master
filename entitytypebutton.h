#ifndef ENTITYTYPEBUTTON_H
#define ENTITYTYPEBUTTON_H

#include <QPushButton>
#include  "entitytype.h"

class EntityTypeButton : public QPushButton
{
    Q_OBJECT
public:
    explicit EntityTypeButton(QWidget *parent, EntityType* entityType);

    EntityType getEntityType();
    EntityType* entityType;

private:



signals:
    
public slots:


    
};

#endif // ENTITYTYPEBUTTON_H
