#include "fieldmap.h"


FieldMap::FieldMap(int fieldNum)
{


    fieldDiscriptions = new FieldDescription*[fieldNum];
    for (int i=0;i<fieldNum;i++)
    {
        fieldDiscriptions[i]=0;
    }

    stringFields=0;
    intFields=0;
    fieldMapSize=0;
    this->fieldNum=fieldNum;

}



void FieldMap::addField(QString _fieldName,int _fieldType)
{
    if ((fieldMapSize+1)>fieldNum) return;

    int _fieldPos;
    if (_fieldType==0)
    {
        _fieldPos = stringFields;
        stringFields++;
    }
    else
    {
        _fieldPos = intFields;
        intFields++;
    }

    fieldDiscriptions[fieldMapSize]=new FieldDescription(_fieldName,_fieldType,_fieldPos);
    fieldMapSize++;

}


 int FieldMap::getArrPos(QString _fieldName)
 {
     for (int i=0; i<fieldMapSize ;i++)

     {
         if (fieldDiscriptions[i]->fieldName==_fieldName)
         {
          return fieldDiscriptions[i]->arrayPos;
         }
     }
      return -1;
  }
