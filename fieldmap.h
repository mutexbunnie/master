#ifndef FIELDMAP_H
#define FIELDMAP_H

#include "fielddescription.h"
class FieldMap
{
public:
    FieldMap(int fieldNum);

    int fieldMapSize;
    int fieldNum;
    int stringFields;
    int intFields;

    int getStringFields() {return stringFields;}
    int getintFields() {return intFields;}

    FieldDescription** fieldDiscriptions;
    void  addField(QString _fieldName,int _fieldType);
    int getArrPos(QString _fieldName);

};

#endif // FIELDMAP_H
