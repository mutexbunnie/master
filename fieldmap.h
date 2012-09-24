#ifndef FIELDMAP_H
#define FIELDMAP_H

#include "fielddescription.h"
#include <QVector>

class FieldMap
{
public:
    FieldMap();


    int stringFields;
    int intFields;

    int getStringFields() {return stringFields;}
    int getintFields() {return intFields;}

    QVector<FieldDescription*>* fieldDescriptions;
    void addField  (QString _fieldName,int _fieldType);
    int  getArrPos (QString _fieldName);

};

#endif // FIELDMAP_H
