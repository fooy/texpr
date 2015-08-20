#ifndef _EXPR_VALUE_DICT_H_
#define _EXPR_VALUE_DICT_H_

#include "ExprValue.h"
#include <tr1/unordered_map>
#include <tr1/memory>

typedef ExprValue ExprValueType;
typedef std::tr1::shared_ptr<ExprValueType> ExprValuePtr;
typedef std::tr1::unordered_map<std::string, ExprValuePtr> ValueDictType;

class ExprValTable
{
private:
    ValueDictType valueDict;
public:
    bool setField( std::string name, ExprValuePtr field );
    ExprValuePtr getField( std::string name );
    bool removeField( const std::string name );
    bool clear();
};

#endif /* _EXPR_VALUE_DICT_H_ */
