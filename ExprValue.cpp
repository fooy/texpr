#include <stdio.h>
#include <stdlib.h>
#include "ExprValue.h"

using namespace std;

string ExprValue::getStrValue()
{
    return getStr();
}
string ExprValue::getPrintStr()
{
    switch ( type ) {
    case VTYPE_INT:
    case VTYPE_DOUBLE:
    case VTYPE_BOOL:
        return getStr();
    case VTYPE_NULL:
        return "NULL";
    case VTYPE_STR:
        return string("\"")+getStr()+"\"";
    case VTYPE_IMG:
        return string("[")+getStr()+"]";
    default:
        return "#<?>";
    }
}
string ExprValue::getStr()
{
    int iv,len;
    char *hexstr;
    string s;
    char ss[20];
    int i;
    switch ( type ) {
    case VTYPE_INT:
        iv = ntohl( *( uint32_t* )&bytes[0] );
        snprintf( ss, sizeof( ss ), "%d", iv );
        s = ss;
        break;
    case VTYPE_STR:
    case VTYPE_DOUBLE:
        s = string( ( char* )&bytes[0], bytes.size() );
        break;
    case VTYPE_IMG:
        len = getLen();
        if(len>0){
            hexstr=(char*)malloc( len * 3 );
            for(i=0; i<len; i++){
                snprintf(ss, 4, "%02X ", bytes[i]);
                memcpy(hexstr + i * 3, ss, 3);
            }
            *(hexstr + len * 3 - 1)=0;
            s = hexstr;
            free(hexstr);
        }else{
            s="";
        }
        break;
    case VTYPE_BOOL:
        s = getBool()?"TRUE":"FALSE";
        break;
    case VTYPE_NULL:
        s = "";
        break;
    default:
        snprintf( ss, sizeof( ss ), "#<?%d>[%d]", type , getLen() );
        s = ss;
    }
    return s;
}
bool ExprValue::setStrValue(int type,string value)
{
    int i,len,hex;
    char *p;
    switch(type) {
        case VTYPE_INT:
            setInt(atoi(value.c_str()));
            break;
        case VTYPE_DOUBLE:
            setDouble(atof(value.c_str()));
            break;
        case VTYPE_STR:
            setStr(value);
            break;
        case VTYPE_IMG:
            len = (value.length()+1)/3 ;
            p = (char*)malloc(len);
            for(i=0; i<len; i++){
                sscanf(value.substr(i*3,2).c_str(),"%X",&hex);
                *(p+i)=(char)hex;
            }
            setImage(p,len);
            free(p);
            break;
        case VTYPE_BOOL:
            setBool( !(value == "0" || value == "false" || value=="FALSE") );
            break;             
        default:
             return false;
    }
    return true;
}
