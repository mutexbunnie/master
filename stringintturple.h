#ifndef STRINGINTTURPLE_H
#define STRINGINTTURPLE_H
#include <QString>

class StringIntTurple
{
public:
    StringIntTurple( QString s,int i);
    int i;
    QString s;
    QString getString();
    int getInt();

};




#endif // STRINGINTTURPLE_H
