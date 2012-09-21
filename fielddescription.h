#ifndef FIELDDESCRIPTION_H
#define FIELDDESCRIPTION_H

#include <QString>

class FieldDescription
{
public:
    FieldDescription(QString _fieldName,int _fieldType,int _arrayPos):
        fieldName(_fieldName),fieldType(_fieldType),arrayPos(_arrayPos){}

      QString fieldName;
      int fieldType;
      int arrayPos;

private:

};

#endif // FIELDDESCRIPTION_H
