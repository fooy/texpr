%{
#include "TExpr.tab.hh"
using namespace yy;
%}

%option header-file="TExpr.lex.hh"
%option outfile="TExpr.lex.cc"
%option noyywrap

ws      [ \t]+
string  \"[^\n"]*\"
alpha   [A-Za-z]
dig     [0-9]
name    (\.|{alpha}|\$)({alpha}|{dig}|[_.\-#])*
double  {dig}+\.({dig}+|([eE][-+]?{dig}+))?
int     {dig}+
number  {int}|{double}

%%
{ws}        /* skip */
{int}       yylval->build(atoi(yytext));return TExpr::token::TOK_INT;
{double}    yylval->build(atof(yytext));return TExpr::token::TOK_DOUBLE;
"AND"       return TExpr::token::TOK_LAND;/*put keyword first*/
"OR"        return TExpr::token::TOK_LOR;
{name}      yylval->build<std::string>(yytext);return TExpr::token::TOK_IDENTIFIER;
{string}    yylval->build<std::string>()=std::string(yytext+1,yyleng-2);return TExpr::token::TOK_STRING;
"=="        return TExpr::token::TOK_EQ;
"!="        return TExpr::token::TOK_NE;
">="        return TExpr::token::TOK_GE;
"<="        return TExpr::token::TOK_LE;
"&&"        return TExpr::token::TOK_LAND;
"||"        return TExpr::token::TOK_LOR;
\n          return TExpr::token::TOK_END;
.           return yytext[0]; 
%%
