#include "stringintturple.h"

StringIntTurple::StringIntTurple( QString _s,int _i)
{
    i=_i;
    s=_s;

}

QString StringIntTurple::getString()
{
 return s;
}


int StringIntTurple::getInt()
{
 return i;
}
