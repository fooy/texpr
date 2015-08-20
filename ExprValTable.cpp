#include <stdlib.h>
#include <sys/types.h>
#include <string>

#include "ExprValTable.h"
using namespace std;

bool ExprValTable::setField(const string name, ExprValuePtr field )
{
    valueDict[name] = field;
    return true;
}

ExprValuePtr ExprValTable::getField( const string name )
{
    ValueDictType::const_iterator got = valueDict.find( name );
    if ( got == valueDict.end() ) {
        return ExprValuePtr();
    } else {
        return got->second;
    }
}
bool ExprValTable::removeField( const string name )
{
    valueDict.erase( name );
}
bool ExprValTable::clear()
{
    valueDict.clear();
}

