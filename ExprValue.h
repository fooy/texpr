#ifndef _EXPR_VALUE_H
#define _EXPR_VALUE_H
#include <sys/types.h>
#include <vector>
#include <string>
#include <iostream>
enum {
    VTYPE_NULL,
    VTYPE_INT ,
    VTYPE_DOUBLE,
    VTYPE_STR ,
    VTYPE_IMG ,
    VTYPE_BOOL
};

class ExprValue
{
private:
    int type;
    std::vector<uint8_t> bytes;
public :
    ExprValue() {};
    ExprValue( int t ): type( t ) {};

    void setData( void *v, uint32_t l ) {
        bytes.assign( ( uint8_t* )v, ( uint8_t* )v + l );
    }
    uint8_t* getData() {
        return &bytes[0];
    }

    int getLen() {
        return bytes.size();
    }

    void set( int t, void *v, uint32_t l ) {
        type = t;
        bytes.assign( ( uint8_t* )v, ( uint8_t* )v + l );
    }
    void setNone(){
        type = VTYPE_NULL;
        //bytes.clear();
    }
    void setInt( int i ) {
        uint32_t nl = htonl( i );
        set( VTYPE_INT, ( uint8_t* )( &nl ), sizeof( uint32_t ) );
    }
    int getInt() {
        return ntohl( *( uint32_t * )&bytes[0] );
    }

    void setDouble( double dvalue ) {
        char double_buf[20] = {0};
        snprintf( double_buf,  sizeof( double_buf ), "%0.6f", dvalue );
        set( VTYPE_DOUBLE, ( uint8_t* )double_buf, strlen( double_buf ) );
    }

    double getDouble() {
        return atof( ( char* )&bytes[0] );
    }

    int getType() {
        return type;
    }
    
    bool isLogical(){
        return isNumber() || isStr();
    }

    void setBool( bool b ) {
        setInt( b );
        type = VTYPE_BOOL;
    }
    bool getBool() {
        if(isType(VTYPE_STR)){
            return getLen();
        }else if(isType(VTYPE_BOOL)){
            return getInt();
        }else if(isType(VTYPE_DOUBLE)){
            return getDouble();
        }else if(isType(VTYPE_INT)){
            return getInt();
        }
        return false;
    }
    void setStr( std::string s ) {
        set( VTYPE_STR, ( uint8_t* )s.c_str(), s.length() );
    }
    std::string getStr();
    std::string getStrValue();
    std::string getPrintStr();
    bool setStrValue(int type,std::string value);
    void setImage( void *d, int len ) {
        set( VTYPE_IMG, d, len );
    }
    void *getImage() {
        return ( void* )&bytes[0];
    }
    bool isType( int t ) {
        return type == t ;
    }
    bool isInt(){
        return type == VTYPE_BOOL || type == VTYPE_INT;
    }
    bool isNumber(){
        return type == VTYPE_BOOL || type == VTYPE_INT || type == VTYPE_DOUBLE;
    }
    bool isDouble(){
        return type == VTYPE_DOUBLE;
    }
    bool isStr(){
        return type == VTYPE_STR;
    }
    void clear() {
        type = 0;
        bytes.clear();
    }
    bool isNone() {
        return type == 0;
    }
    friend std::ostream& operator<< (std::ostream& os,const ExprValue& expr) {
        os << (expr.type==VTYPE_INT?
            "<INT>":
            expr.type==VTYPE_BOOL?
                "<BOOL>":
                expr.type==VTYPE_STR?
                    "<STR>":
                    expr.type==VTYPE_DOUBLE?
                        "<DOUBLE>":
                        "<?>");
        return os;
    }
};

#endif /* _EXPR_VALUE_H */
