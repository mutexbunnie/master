#ifndef ENTITYTYPEBUTTON_H
#define ENTITYTYPEBUTTON_H

#include <QToolButton>
#include  "entitytype.h"

class EntityTypeButton : public QToolButton
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
