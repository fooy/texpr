%skeleton "lalr1.cc" /* C++ */
%require "3.0.4"
%language "c++"
%defines
//%file-prefix "TExpr"
%define parser_class_name {TExpr}
%define api.value.type variant
//%define api.token.constructor
%define parse.assert 
%define parse.trace
%define parse.error verbose

%code requires {
    #include <iostream>
    #include <string>
    #include <stack>
    #include <vector>

    #include "ExprValTable.h"

    typedef std::vector<ExprValuePtr> ExprArgsType;
    typedef std::tr1::shared_ptr<ExprArgsType> ExprArgsPtr;

    typedef bool ( *exprFuncType )( ExprValTable&, ExprArgsPtr, ExprValuePtr );
    typedef std::tr1::unordered_map<std::string, exprFuncType>  symbolTableType;

    class exprSymbolTable {
    public:
        bool call( std::string symbolName, ExprValTable &valTable, ExprArgsPtr args, ExprValuePtr rt );
        static symbolTableType symbolTable;
    };
    typedef std::tr1::shared_ptr<exprSymbolTable> SymbolTablePtr;

    typedef std::stack<bool> condStack;
    #define YY_NULLPTR 0
}

%parse-param { SymbolTablePtr symTable } { condStack cond } { ExprValTable &valTable } { ExprValuePtr fieldValue } { std::string &msg }

%code provides {
    #define YY_DECL \
            int yylex (yy::TExpr::semantic_type* yylval)
    int SDExprEval( ExprValTable &valTable, ExprValuePtr srvField, const char* sexpr, std::string &msg );

}

%initial-action {
    cond.push(true);
}

%code {
    YY_DECL;
    #include<functional>
    #include <cmath>
    using namespace std;

    template<template<typename> class OP>
    void expr_bi_op1( ExprValueType &exp, ExprValueType &exp1, ExprValueType &exp2 )
    {
        if ( exp1.isInt() && exp2.isInt() ) {
            exp.setInt( OP<int>()( exp1.getInt() , exp2.getInt() ) );
            return;
        }
        if ( exp1.isInt() && exp2.isDouble() ) {
            exp.setDouble( OP<double>()( exp1.getInt() , exp2.getDouble() ) );
            return;
        }
        if ( exp1.isDouble() && exp2.isInt() ) {
            exp.setDouble( OP<double>()( exp1.getDouble() , exp2.getInt() ) );
            return;
        }
        if ( exp1.isDouble() && exp2.isDouble() ) {
            exp.setDouble( OP<double>()( exp1.getDouble() , exp2.getDouble() ) );
            return;
        }
    }
    template<template<typename> class OP>
    void expr_bi_op2( ExprValueType &exp, ExprValueType &exp1, ExprValueType &exp2 )
    {
        if ( exp1.isStr() && exp2.isStr() ) {
            exp.setBool( OP<string>()( exp1.getStr() , exp2.getStr() ) );
        }
        if ( exp1.isInt() && exp2.isInt() ) {
            exp.setBool( OP<int>()( exp1.getInt() , exp2.getInt() ) );
            return;
        }
        if ( exp1.isInt() && exp2.isDouble() ) {
            exp.setBool( OP<double>()( exp1.getInt() , exp2.getDouble() ) );
            return;
        }
        if ( exp1.isDouble() && exp2.isInt() ) {
            exp.setBool( OP<double>()( exp1.getDouble() , exp2.getInt() ) );
            return;
        }
        if ( exp1.isDouble() && exp2.isDouble() ) {
            exp.setBool( OP<double>()( exp1.getDouble() , exp2.getDouble() ) );
            return;
        }
    }

    template<template<typename> class OP>
    void expr_bi_op3( ExprValueType &exp, ExprValueType &exp1, ExprValueType &exp2 )
    {
        exp.setBool( OP<bool>()( exp1.getBool() , exp2.getBool() ) );
    }

    void expr_mod( ExprValueType &exp, ExprValueType &exp1, ExprValueType &exp2 )
    {
        if ( exp1.isInt() && exp2.isInt() ) {
            exp.setInt( modulus<int>()( exp1.getInt() , exp2.getInt() ) );
            return;
        }
        if ( exp1.isInt() && exp2.isDouble() ) {
            exp.setDouble( fmod( ( double )exp1.getInt() , exp2.getDouble() ) );
            return;
        }
        if ( exp1.isDouble() && exp2.isInt() ) {
            exp.setDouble( fmod(  exp1.getDouble() , ( double )exp2.getInt() ) );
            return;
        }
        if ( exp1.isDouble() && exp2.isDouble() ) {
            exp.setDouble( fmod( exp1.getDouble() , exp2.getDouble() ) );
            return;
        }
    }

    void expr_pow( ExprValueType &exp, ExprValueType &exp1, ExprValueType &exp2 )
    {
        if ( exp1.isInt() && exp2.isInt() ) {
            exp.setInt( std::pow( (double)exp1.getInt() , exp2.getInt() ) );
            return;
        }
        if ( exp1.isInt() && exp2.isDouble() ) {
            exp.setDouble( std::pow( exp1.getInt() , exp2.getDouble() ) );
            return;
        }
        if ( exp1.isDouble() && exp2.isInt() ) {
            exp.setDouble( std::pow( exp1.getDouble() , exp2.getInt() ) );
            return;
        }
        if ( exp1.isDouble() && exp2.isDouble() ) {
            exp.setDouble( std::pow( exp1.getDouble() , exp2.getDouble() ) );
            return;
        }
    }

    #define CHECK_COND  if(!cond.top()) break
    #define CHECK_TYPE(PRED,OP) \
            if (! ( PRED ) ){ \
                error("error type for operator '" OP "'"); \
                YYERROR; \
            }
}

%define api.token.prefix {TOK_}
%token
    END  0      "end of input"
    LOR         "||"
    LAND        "&&"
    EQ          "=="
    NE         "!="
    GE          ">="
    LE          "<="
    STRING      "string"
    INT         "int"
    DOUBLE       "double"
    IDENTIFIER  "identifier"

%type <int> "int"
%type <double> "double"
%type <std::string> "string" "identifier"
%type <ExprValueType> expr expr_arg
%type <ExprArgsPtr> args

%left '?' ':'
%left "||"
%left "&&"
%left "==" "!=" '<' '>' "<=" ">=" 
%left '&' '|' '~'
%left '+' '-' 
%left '*' '/' '%'
%right '^' 
%precedence NOT NEG COMP

%printer { yyoutput << $$; } <*>;

%%
%start expr_start;
expr_start: expr_arg { *fieldValue = $1; }

expr_arg: expr { CHECK_COND;
            $$ = $1;
        }
    | %empty { CHECK_COND;
            $$.setNone();
        }

expr:
     expr '+' expr { CHECK_COND; 
            if(! ($1.isNumber() &&  $3.isNumber()) ){
                $$.setStr($1.getStr() + $3.getStr());
                break;
            }
            expr_bi_op1<std::plus>($$,$1,$3);
        }
    | expr '-' expr  { CHECK_COND;
            CHECK_TYPE($1.isNumber() && $3.isNumber(), "-");
            expr_bi_op1<std::minus>($$,$1,$3);
        }
    | expr '*' expr  { CHECK_COND; 
            CHECK_TYPE($1.isNumber() && $3.isNumber(), "*");
            expr_bi_op1<std::multiplies>($$,$1,$3);
        }
    | expr '/' expr   { CHECK_COND;
            CHECK_TYPE($1.isNumber() && $3.isNumber(), "/");
            expr_bi_op1<std::divides>($$,$1,$3);
        }
    | expr '%' expr   { CHECK_COND;
            CHECK_TYPE($1.isNumber() && $3.isNumber(), "%");
            expr_mod($$,$1,$3);
        }
    | expr '^' expr   { CHECK_COND;
            CHECK_TYPE($1.isNumber() && $3.isNumber(), "^");
            expr_pow($$,$1,$3);
        }
    | expr '>' expr   { CHECK_COND;
            CHECK_TYPE( ($1.isNumber() && $3.isNumber()) || ($1.isStr() && $3.isStr()), ">");
            expr_bi_op2<std::greater>($$,$1,$3);
        }
    | expr ">=" expr   { CHECK_COND;
            CHECK_TYPE( ($1.isNumber() && $3.isNumber()) || ($1.isStr() && $3.isStr()), ">=");
            expr_bi_op2<std::greater_equal>($$,$1,$3);
        }
    | expr '<' expr    { CHECK_COND;
            CHECK_TYPE( ($1.isNumber() && $3.isNumber()) || ($1.isStr() && $3.isStr()), "<");
            expr_bi_op2<std::less>($$,$1,$3);
        }
    | expr "<=" expr   { CHECK_COND;
            CHECK_TYPE( ($1.isNumber() && $3.isNumber()) || ($1.isStr() && $3.isStr()), "<=");
            expr_bi_op2<std::less_equal>($$,$1,$3);
        }
    | expr "==" expr   { CHECK_COND;
            if( ($1.isNumber() && $3.isNumber()) || ($1.isStr() && $3.isStr()) ){
                expr_bi_op2<std::equal_to>($$,$1,$3);
            } else {
                $$.setBool(false);
            }
        }
    | expr "!=" expr   { CHECK_COND;
            if( $1.isStr() && $3.isStr() ){
                $$.setBool( $1.getStr().compare($3.getStr()) != 0 );
            }else if(  $1.isNumber() && $3.isNumber() ) {
                expr_bi_op2<std::not_equal_to>($$,$1,$3);
            }else{
                $$.setBool(true);
            }
        }
    | expr "&&" expr   { CHECK_COND;
            CHECK_TYPE($1.isLogical() && $3.isLogical() , "&&");
            expr_bi_op3<std::logical_and>($$,$1,$3);
        }
    | expr "||" expr   { CHECK_COND;
            CHECK_TYPE($1.isLogical() && $3.isLogical() , "||");
            expr_bi_op3<std::logical_or>($$,$1,$3);
        }
    | '!' expr %prec NOT { CHECK_COND;
            CHECK_TYPE($2.isLogical() , "!");
            $$.setBool( ! $2.getBool() );
        }
    | expr '&' expr    { CHECK_COND;
            CHECK_TYPE($1.isInt() && $3.isInt(), "&");
            $$.setInt( $1.getInt() & $3.getInt() );
        }
    | expr '|' expr    { CHECK_COND;
            CHECK_TYPE($1.isInt() && $3.isInt(), "|");
            $$.setInt( $1.getInt() | $3.getInt() );
        }
    | '~' expr %prec COMP { CHECK_COND;
            CHECK_TYPE($2.isInt(), "~");
            $$.setInt( ~ $2.getInt() );
        }
    | '-' expr %prec NEG { CHECK_COND;
            CHECK_TYPE($2.isNumber(), "-");
            if($2.isInt())
                $$.setInt(-$2.getInt());
            else if($2.isDouble())
                $$.setDouble(-$2.getDouble());
        }
    | '(' expr ')' { CHECK_COND;
            $$ = $2;
        }
    | "int"  { CHECK_COND; $$.setInt($1); }
    | "double" { CHECK_COND; $$.setDouble($1); }
    | "string"  { CHECK_COND; $$.setStr($1); }
    | "identifier" { CHECK_COND;
            ExprValuePtr sfd=valTable.getField($1);
            if(!sfd){
                error(string("no such field: ")+$1);
                YYERROR;
            }
            $$=*sfd;
        }
    | "identifier" '[' expr ']' { CHECK_COND;
            string fdname=$1+"#"+$3.getStr();
            ExprValuePtr sfd=valTable.getField(fdname);
            if(!sfd){
                error(string("no such field: ")+fdname);
                YYERROR;
            }
            $$=*sfd;
        }
    | "identifier" '(' args ')' { CHECK_COND;
            ExprValuePtr rv = ExprValuePtr( new(ExprValue) );
            if( symTable->call( $1, valTable, $3 , rv ) ){
                $$ = *rv;
            }else{
                error(string("error call function: ")+$1);
                YYERROR;
            }
        }
    | expr '?' {
            if(cond.top()){
                if(! $1.isLogical() ){
                    error("error condition before '?'");
                    YYERROR;
                }
                cond.push($1.getBool());
            }else{
                cond.push(false);
            }
        }
        expr ':' {
            bool if_cond = cond.top();
            cond.pop();
            cond.push( (!if_cond) && cond.top() );
        }
        expr {
            $$ = cond.top() ? $7 : $4; 
            cond.pop();
        }

args:
    expr_arg  { CHECK_COND;
            $$ = ExprArgsPtr (new ExprArgsType);
            $$->push_back(ExprValuePtr(new ExprValueType($1)));
        }
    | args ',' expr_arg { CHECK_COND;
            assert($1);
            $1->push_back(ExprValuePtr(new ExprValueType($3)));
            $$ = $1;
        }
%%

#include "TExpr.lex.hh"

using namespace yy;
using namespace std;

int SDExprEval( ExprValTable &valTable, ExprValuePtr srvField, const char* sexpr , string &msg )
{
    SymbolTablePtr symTable = SymbolTablePtr( new exprSymbolTable );
    condStack cond;
    YY_BUFFER_STATE buffer = yy_scan_string( sexpr );
    TExpr expr( symTable, cond , valTable, srvField, msg );
    //expr.set_debug_level (1);
    int res = expr.parse();
    yy_delete_buffer( buffer );
    return res;
}

void yy::TExpr::error ( const std::string& errmsg )
{
    msg.assign( errmsg );
}
