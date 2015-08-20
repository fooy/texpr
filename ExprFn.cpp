#include "TExpr.tab.hh"
#include <functional>

using namespace std;

bool exprSymbolTable::call(string symbolName, ExprValTable &st, ExprArgsPtr args, ExprValuePtr rt)
{
    symbolTableType::iterator it = symbolTable.find( symbolName );
    if ( it == symbolTable.end() ) {
        fprintf(stderr,"%s:no such function\n",symbolName.c_str());
        return false;
    }
    if(args->size() == 1 && args->at(0)->isNone()){
        /* func() == func(null) */
        args->clear();
    }
    return (it->second)(st, args, rt);
}

bool print(ExprValTable &st,ExprArgsPtr args,ExprValuePtr rt)
{
    int i=0;
    for(;i<args->size();i++){
        cout << (*args)[i]->getPrintStr() << " " ;
    }
    cout << endl;
    rt->setInt(i);
    return true;
}

bool str2int(ExprValTable &st,ExprArgsPtr args,ExprValuePtr rt)
{
    if(args->size()<1){
        fprintf(stderr,"error args for str2int\n");
        return false;
    }
    rt->setInt(atoi(args->at(0)->getStr().c_str()));
    return true;
}

bool int2str(ExprValTable &st,ExprArgsPtr args,ExprValuePtr rt)
{
    if(args->size()<1){
        fprintf(stderr,"error args for int2str\n");
        return false;
    }
    rt->setStr(args->at(0)->getStr());
    return true;
}

bool substr(ExprValTable &st,ExprArgsPtr args,ExprValuePtr rt)
{
    if(args->size()<3){
        fprintf(stderr,"error args for substr\n");
        return false;
    }
    ExprValuePtr arg1 =args->at(0);
    ExprValuePtr arg2 =args->at(1);
    ExprValuePtr arg3 =args->at(2);
    if(! (arg2->isInt() && arg3->isInt()) ){
        fprintf(stderr,"error type for substr\n");
        return false;
    }
    string s=arg1->getStr();
    int pos=arg2->getInt();
    int len=arg3->getInt();
    if(pos<0 || pos > s.length()){
        fprintf(stderr,"error:substr out of range\n");
        return false;
    }

    rt->setStr( s.substr(pos,len) ) ;
    return true;
}

bool _strlen(ExprValTable &st,ExprArgsPtr args,ExprValuePtr rt)
{
    if(args->size()<1){
        fprintf(stderr,"error args for strlen\n");
        return false;
    }
    ExprValuePtr arg1 =args->at(0);
    rt->setInt( arg1->getStr().length() );
    return true;
}

inline string _trim( string& str )
{
    if ( str.empty() )
        return str;

    std::size_t first = str.find_first_not_of( ' ' );
    std::size_t last  = str.find_last_not_of( ' ' );
    return str.substr( first, last - first + 1 );
};
bool fn_trim(ExprValTable &st,ExprArgsPtr args,ExprValuePtr rt)
{
    if(args->size()<1){
        fprintf(stderr,"error args for trim\n");
        return false;
    }
    ExprValuePtr arg1 =args->at(0);
    string s=arg1->getStr();
    rt->setStr(_trim(s));
    return true;
}
symbolTableType symbolInit()
{
    symbolTableType st;
    struct symbolEntry{
        const char *name;
        exprFuncType fn;
    } entries[]= {
        { "SUBSTR", &substr     },
        { "STRLEN", &_strlen    },
        { "STR2INT", &str2int   },
        { "INT2STR", &int2str   },
        { "TRIM",   &fn_trim    },
        { "print",  &print      }
    };
    for( int i=0; i< sizeof(entries)/sizeof(symbolEntry) ; i++ ){
        st[entries[i].name] = entries[i].fn;
    }
    return st;
}

symbolTableType exprSymbolTable::symbolTable = symbolInit();
