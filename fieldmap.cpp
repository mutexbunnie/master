#include "fieldmap.h"


FieldMap::FieldMap()
{
    this->fieldDescriptions = new QVector<FieldDescription*>;
    stringFields=0;
    intFields=0;
}



void FieldMap::addField(QString _fieldName,int _fieldType)
{


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

    fieldDescriptions->append( new FieldDescription(_fieldName,_fieldType,_fieldPos));

}


 int FieldMap::getArrPos(QString _fieldName)
 {
     for (int i=0; i<fieldDescriptions->size() ;i++)
     {
         if ((*fieldDescriptions)[i]->fieldName==_fieldName)
         {
          return (*fieldDescriptions)[i]->arrayPos;
         }
     }
      return -1;
  }
