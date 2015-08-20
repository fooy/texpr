// A Bison parser, made by GNU Bison 3.0.4.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.


// First part of user declarations.

#line 37 "TExpr.tab.cc" // lalr1.cc:404

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "TExpr.tab.hh"

// User implementation prologue.

#line 51 "TExpr.tab.cc" // lalr1.cc:412
// Unqualified %code blocks.
#line 51 "TExpr.y" // lalr1.cc:413

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

#line 157 "TExpr.tab.cc" // lalr1.cc:413


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif



// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << std::endl;                  \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace yy {
#line 224 "TExpr.tab.cc" // lalr1.cc:479

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  TExpr::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr = "";
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              // Fall through.
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  TExpr::TExpr (SymbolTablePtr symTable_yyarg, condStack cond_yyarg, ExprValTable &valTable_yyarg, ExprValuePtr fieldValue_yyarg, std::string &msg_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      symTable (symTable_yyarg),
      cond (cond_yyarg),
      valTable (valTable_yyarg),
      fieldValue (fieldValue_yyarg),
      msg (msg_yyarg)
  {}

  TExpr::~TExpr ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/

  inline
  TExpr::syntax_error::syntax_error (const std::string& m)
    : std::runtime_error (m)
  {}

  // basic_symbol.
  template <typename Base>
  inline
  TExpr::basic_symbol<Base>::basic_symbol ()
    : value ()
  {}

  template <typename Base>
  inline
  TExpr::basic_symbol<Base>::basic_symbol (const basic_symbol& other)
    : Base (other)
    , value ()
  {
      switch (other.type_get ())
    {
      case 41: // args
        value.copy< ExprArgsPtr > (other.value);
        break;

      case 37: // expr_arg
      case 38: // expr
        value.copy< ExprValueType > (other.value);
        break;

      case 11: // "double"
        value.copy< double > (other.value);
        break;

      case 10: // "int"
        value.copy< int > (other.value);
        break;

      case 9: // "string"
      case 12: // "identifier"
        value.copy< std::string > (other.value);
        break;

      default:
        break;
    }

  }


  template <typename Base>
  inline
  TExpr::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const semantic_type& v)
    : Base (t)
    , value ()
  {
    (void) v;
      switch (this->type_get ())
    {
      case 41: // args
        value.copy< ExprArgsPtr > (v);
        break;

      case 37: // expr_arg
      case 38: // expr
        value.copy< ExprValueType > (v);
        break;

      case 11: // "double"
        value.copy< double > (v);
        break;

      case 10: // "int"
        value.copy< int > (v);
        break;

      case 9: // "string"
      case 12: // "identifier"
        value.copy< std::string > (v);
        break;

      default:
        break;
    }
}


  // Implementation of basic_symbol constructor for each type.

  template <typename Base>
  TExpr::basic_symbol<Base>::basic_symbol (typename Base::kind_type t)
    : Base (t)
    , value ()
  {}

  template <typename Base>
  TExpr::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const ExprArgsPtr v)
    : Base (t)
    , value (v)
  {}

  template <typename Base>
  TExpr::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const ExprValueType v)
    : Base (t)
    , value (v)
  {}

  template <typename Base>
  TExpr::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const double v)
    : Base (t)
    , value (v)
  {}

  template <typename Base>
  TExpr::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const int v)
    : Base (t)
    , value (v)
  {}

  template <typename Base>
  TExpr::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::string v)
    : Base (t)
    , value (v)
  {}


  template <typename Base>
  inline
  TExpr::basic_symbol<Base>::~basic_symbol ()
  {
    clear ();
  }

  template <typename Base>
  inline
  void
  TExpr::basic_symbol<Base>::clear ()
  {
    // User destructor.
    symbol_number_type yytype = this->type_get ();
    basic_symbol<Base>& yysym = *this;
    (void) yysym;
    switch (yytype)
    {
   default:
      break;
    }

    // Type destructor.
    switch (yytype)
    {
      case 41: // args
        value.template destroy< ExprArgsPtr > ();
        break;

      case 37: // expr_arg
      case 38: // expr
        value.template destroy< ExprValueType > ();
        break;

      case 11: // "double"
        value.template destroy< double > ();
        break;

      case 10: // "int"
        value.template destroy< int > ();
        break;

      case 9: // "string"
      case 12: // "identifier"
        value.template destroy< std::string > ();
        break;

      default:
        break;
    }

    Base::clear ();
  }

  template <typename Base>
  inline
  bool
  TExpr::basic_symbol<Base>::empty () const
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  inline
  void
  TExpr::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move(s);
      switch (this->type_get ())
    {
      case 41: // args
        value.move< ExprArgsPtr > (s.value);
        break;

      case 37: // expr_arg
      case 38: // expr
        value.move< ExprValueType > (s.value);
        break;

      case 11: // "double"
        value.move< double > (s.value);
        break;

      case 10: // "int"
        value.move< int > (s.value);
        break;

      case 9: // "string"
      case 12: // "identifier"
        value.move< std::string > (s.value);
        break;

      default:
        break;
    }

  }

  // by_type.
  inline
  TExpr::by_type::by_type ()
    : type (empty_symbol)
  {}

  inline
  TExpr::by_type::by_type (const by_type& other)
    : type (other.type)
  {}

  inline
  TExpr::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
  TExpr::by_type::clear ()
  {
    type = empty_symbol;
  }

  inline
  void
  TExpr::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  inline
  int
  TExpr::by_type::type_get () const
  {
    return type;
  }
  // Implementation of make_symbol for each symbol type.
  TExpr::symbol_type
  TExpr::make_END ()
  {
    return symbol_type (token::TOK_END);
  }

  TExpr::symbol_type
  TExpr::make_LOR ()
  {
    return symbol_type (token::TOK_LOR);
  }

  TExpr::symbol_type
  TExpr::make_LAND ()
  {
    return symbol_type (token::TOK_LAND);
  }

  TExpr::symbol_type
  TExpr::make_EQ ()
  {
    return symbol_type (token::TOK_EQ);
  }

  TExpr::symbol_type
  TExpr::make_NE ()
  {
    return symbol_type (token::TOK_NE);
  }

  TExpr::symbol_type
  TExpr::make_GE ()
  {
    return symbol_type (token::TOK_GE);
  }

  TExpr::symbol_type
  TExpr::make_LE ()
  {
    return symbol_type (token::TOK_LE);
  }

  TExpr::symbol_type
  TExpr::make_STRING (const std::string& v)
  {
    return symbol_type (token::TOK_STRING, v);
  }

  TExpr::symbol_type
  TExpr::make_INT (const int& v)
  {
    return symbol_type (token::TOK_INT, v);
  }

  TExpr::symbol_type
  TExpr::make_DOUBLE (const double& v)
  {
    return symbol_type (token::TOK_DOUBLE, v);
  }

  TExpr::symbol_type
  TExpr::make_IDENTIFIER (const std::string& v)
  {
    return symbol_type (token::TOK_IDENTIFIER, v);
  }

  TExpr::symbol_type
  TExpr::make_NOT ()
  {
    return symbol_type (token::TOK_NOT);
  }

  TExpr::symbol_type
  TExpr::make_NEG ()
  {
    return symbol_type (token::TOK_NEG);
  }

  TExpr::symbol_type
  TExpr::make_COMP ()
  {
    return symbol_type (token::TOK_COMP);
  }



  // by_state.
  inline
  TExpr::by_state::by_state ()
    : state (empty_state)
  {}

  inline
  TExpr::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  TExpr::by_state::clear ()
  {
    state = empty_state;
  }

  inline
  void
  TExpr::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  inline
  TExpr::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  TExpr::symbol_number_type
  TExpr::by_state::type_get () const
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  inline
  TExpr::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  TExpr::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s)
  {
      switch (that.type_get ())
    {
      case 41: // args
        value.move< ExprArgsPtr > (that.value);
        break;

      case 37: // expr_arg
      case 38: // expr
        value.move< ExprValueType > (that.value);
        break;

      case 11: // "double"
        value.move< double > (that.value);
        break;

      case 10: // "int"
        value.move< int > (that.value);
        break;

      case 9: // "string"
      case 12: // "identifier"
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

  inline
  TExpr::stack_symbol_type&
  TExpr::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
      switch (that.type_get ())
    {
      case 41: // args
        value.copy< ExprArgsPtr > (that.value);
        break;

      case 37: // expr_arg
      case 38: // expr
        value.copy< ExprValueType > (that.value);
        break;

      case 11: // "double"
        value.copy< double > (that.value);
        break;

      case 10: // "int"
        value.copy< int > (that.value);
        break;

      case 9: // "string"
      case 12: // "identifier"
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    return *this;
  }


  template <typename Base>
  inline
  void
  TExpr::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  TExpr::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " (";
    switch (yytype)
    {
            case 9: // "string"

#line 185 "TExpr.y" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::string > (); }
#line 782 "TExpr.tab.cc" // lalr1.cc:636
        break;

      case 10: // "int"

#line 185 "TExpr.y" // lalr1.cc:636
        { yyoutput << yysym.value.template as< int > (); }
#line 789 "TExpr.tab.cc" // lalr1.cc:636
        break;

      case 11: // "double"

#line 185 "TExpr.y" // lalr1.cc:636
        { yyoutput << yysym.value.template as< double > (); }
#line 796 "TExpr.tab.cc" // lalr1.cc:636
        break;

      case 12: // "identifier"

#line 185 "TExpr.y" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::string > (); }
#line 803 "TExpr.tab.cc" // lalr1.cc:636
        break;

      case 37: // expr_arg

#line 185 "TExpr.y" // lalr1.cc:636
        { yyoutput << yysym.value.template as< ExprValueType > (); }
#line 810 "TExpr.tab.cc" // lalr1.cc:636
        break;

      case 38: // expr

#line 185 "TExpr.y" // lalr1.cc:636
        { yyoutput << yysym.value.template as< ExprValueType > (); }
#line 817 "TExpr.tab.cc" // lalr1.cc:636
        break;

      case 41: // args

#line 185 "TExpr.y" // lalr1.cc:636
        { yyoutput << yysym.value.template as< ExprArgsPtr > (); }
#line 824 "TExpr.tab.cc" // lalr1.cc:636
        break;


      default:
        break;
    }
    yyo << ')';
  }
#endif

  inline
  void
  TExpr::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  TExpr::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  TExpr::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  TExpr::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  TExpr::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  TExpr::debug_level_type
  TExpr::debug_level () const
  {
    return yydebug_;
  }

  void
  TExpr::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  inline TExpr::state_type
  TExpr::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  inline bool
  TExpr::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  TExpr::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  TExpr::parse ()
  {
    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    // User initialization code.
    #line 47 "TExpr.y" // lalr1.cc:745
{
    cond.push(true);
}

#line 939 "TExpr.tab.cc" // lalr1.cc:745

    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << std::endl;

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:

    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
        try
          {
            yyla.type = yytranslate_ (yylex (&yyla.value));
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
        switch (yyr1_[yyn])
    {
      case 41: // args
        yylhs.value.build< ExprArgsPtr > ();
        break;

      case 37: // expr_arg
      case 38: // expr
        yylhs.value.build< ExprValueType > ();
        break;

      case 11: // "double"
        yylhs.value.build< double > ();
        break;

      case 10: // "int"
        yylhs.value.build< int > ();
        break;

      case 9: // "string"
      case 12: // "identifier"
        yylhs.value.build< std::string > ();
        break;

      default:
        break;
    }



      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
      try
        {
          switch (yyn)
            {
  case 2:
#line 189 "TExpr.y" // lalr1.cc:859
    { *fieldValue = yystack_[0].value.as< ExprValueType > (); }
#line 1065 "TExpr.tab.cc" // lalr1.cc:859
    break;

  case 3:
#line 191 "TExpr.y" // lalr1.cc:859
    { CHECK_COND;
            yylhs.value.as< ExprValueType > () = yystack_[0].value.as< ExprValueType > ();
        }
#line 1073 "TExpr.tab.cc" // lalr1.cc:859
    break;

  case 4:
#line 194 "TExpr.y" // lalr1.cc:859
    { CHECK_COND;
            yylhs.value.as< ExprValueType > ().setNone();
        }
#line 1081 "TExpr.tab.cc" // lalr1.cc:859
    break;

  case 5:
#line 199 "TExpr.y" // lalr1.cc:859
    { CHECK_COND; 
            if(! (yystack_[2].value.as< ExprValueType > ().isNumber() &&  yystack_[0].value.as< ExprValueType > ().isNumber()) ){
                yylhs.value.as< ExprValueType > ().setStr(yystack_[2].value.as< ExprValueType > ().getStr() + yystack_[0].value.as< ExprValueType > ().getStr());
                break;
            }
            expr_bi_op1<std::plus>(yylhs.value.as< ExprValueType > (),yystack_[2].value.as< ExprValueType > (),yystack_[0].value.as< ExprValueType > ());
        }
#line 1093 "TExpr.tab.cc" // lalr1.cc:859
    break;

  case 6:
#line 206 "TExpr.y" // lalr1.cc:859
    { CHECK_COND;
            CHECK_TYPE(yystack_[2].value.as< ExprValueType > ().isNumber() && yystack_[0].value.as< ExprValueType > ().isNumber(), "-");
            expr_bi_op1<std::minus>(yylhs.value.as< ExprValueType > (),yystack_[2].value.as< ExprValueType > (),yystack_[0].value.as< ExprValueType > ());
        }
#line 1102 "TExpr.tab.cc" // lalr1.cc:859
    break;

  case 7:
#line 210 "TExpr.y" // lalr1.cc:859
    { CHECK_COND; 
            CHECK_TYPE(yystack_[2].value.as< ExprValueType > ().isNumber() && yystack_[0].value.as< ExprValueType > ().isNumber(), "*");
            expr_bi_op1<std::multiplies>(yylhs.value.as< ExprValueType > (),yystack_[2].value.as< ExprValueType > (),yystack_[0].value.as< ExprValueType > ());
        }
#line 1111 "TExpr.tab.cc" // lalr1.cc:859
    break;

  case 8:
#line 214 "TExpr.y" // lalr1.cc:859
    { CHECK_COND;
            CHECK_TYPE(yystack_[2].value.as< ExprValueType > ().isNumber() && yystack_[0].value.as< ExprValueType > ().isNumber(), "/");
            expr_bi_op1<std::divides>(yylhs.value.as< ExprValueType > (),yystack_[2].value.as< ExprValueType > (),yystack_[0].value.as< ExprValueType > ());
        }
#line 1120 "TExpr.tab.cc" // lalr1.cc:859
    break;

  case 9:
#line 218 "TExpr.y" // lalr1.cc:859
    { CHECK_COND;
            CHECK_TYPE(yystack_[2].value.as< ExprValueType > ().isNumber() && yystack_[0].value.as< ExprValueType > ().isNumber(), "%");
            expr_mod(yylhs.value.as< ExprValueType > (),yystack_[2].value.as< ExprValueType > (),yystack_[0].value.as< ExprValueType > ());
        }
#line 1129 "TExpr.tab.cc" // lalr1.cc:859
    break;

  case 10:
#line 222 "TExpr.y" // lalr1.cc:859
    { CHECK_COND;
            CHECK_TYPE(yystack_[2].value.as< ExprValueType > ().isNumber() && yystack_[0].value.as< ExprValueType > ().isNumber(), "^");
            expr_pow(yylhs.value.as< ExprValueType > (),yystack_[2].value.as< ExprValueType > (),yystack_[0].value.as< ExprValueType > ());
        }
#line 1138 "TExpr.tab.cc" // lalr1.cc:859
    break;

  case 11:
#line 226 "TExpr.y" // lalr1.cc:859
    { CHECK_COND;
            CHECK_TYPE( (yystack_[2].value.as< ExprValueType > ().isNumber() && yystack_[0].value.as< ExprValueType > ().isNumber()) || (yystack_[2].value.as< ExprValueType > ().isStr() && yystack_[0].value.as< ExprValueType > ().isStr()), ">");
            expr_bi_op2<std::greater>(yylhs.value.as< ExprValueType > (),yystack_[2].value.as< ExprValueType > (),yystack_[0].value.as< ExprValueType > ());
        }
#line 1147 "TExpr.tab.cc" // lalr1.cc:859
    break;

  case 12:
#line 230 "TExpr.y" // lalr1.cc:859
    { CHECK_COND;
            CHECK_TYPE( (yystack_[2].value.as< ExprValueType > ().isNumber() && yystack_[0].value.as< ExprValueType > ().isNumber()) || (yystack_[2].value.as< ExprValueType > ().isStr() && yystack_[0].value.as< ExprValueType > ().isStr()), ">=");
            expr_bi_op2<std::greater_equal>(yylhs.value.as< ExprValueType > (),yystack_[2].value.as< ExprValueType > (),yystack_[0].value.as< ExprValueType > ());
        }
#line 1156 "TExpr.tab.cc" // lalr1.cc:859
    break;

  case 13:
#line 234 "TExpr.y" // lalr1.cc:859
    { CHECK_COND;
            CHECK_TYPE( (yystack_[2].value.as< ExprValueType > ().isNumber() && yystack_[0].value.as< ExprValueType > ().isNumber()) || (yystack_[2].value.as< ExprValueType > ().isStr() && yystack_[0].value.as< ExprValueType > ().isStr()), "<");
            expr_bi_op2<std::less>(yylhs.value.as< ExprValueType > (),yystack_[2].value.as< ExprValueType > (),yystack_[0].value.as< ExprValueType > ());
        }
#line 1165 "TExpr.tab.cc" // lalr1.cc:859
    break;

  case 14:
#line 238 "TExpr.y" // lalr1.cc:859
    { CHECK_COND;
            CHECK_TYPE( (yystack_[2].value.as< ExprValueType > ().isNumber() && yystack_[0].value.as< ExprValueType > ().isNumber()) || (yystack_[2].value.as< ExprValueType > ().isStr() && yystack_[0].value.as< ExprValueType > ().isStr()), "<=");
            expr_bi_op2<std::less_equal>(yylhs.value.as< ExprValueType > (),yystack_[2].value.as< ExprValueType > (),yystack_[0].value.as< ExprValueType > ());
        }
#line 1174 "TExpr.tab.cc" // lalr1.cc:859
    break;

  case 15:
#line 242 "TExpr.y" // lalr1.cc:859
    { CHECK_COND;
            if( (yystack_[2].value.as< ExprValueType > ().isNumber() && yystack_[0].value.as< ExprValueType > ().isNumber()) || (yystack_[2].value.as< ExprValueType > ().isStr() && yystack_[0].value.as< ExprValueType > ().isStr()) ){
                expr_bi_op2<std::equal_to>(yylhs.value.as< ExprValueType > (),yystack_[2].value.as< ExprValueType > (),yystack_[0].value.as< ExprValueType > ());
            } else {
                yylhs.value.as< ExprValueType > ().setBool(false);
            }
        }
#line 1186 "TExpr.tab.cc" // lalr1.cc:859
    break;

  case 16:
#line 249 "TExpr.y" // lalr1.cc:859
    { CHECK_COND;
            if( yystack_[2].value.as< ExprValueType > ().isStr() && yystack_[0].value.as< ExprValueType > ().isStr() ){
                yylhs.value.as< ExprValueType > ().setBool( yystack_[2].value.as< ExprValueType > ().getStr().compare(yystack_[0].value.as< ExprValueType > ().getStr()) != 0 );
            }else if(  yystack_[2].value.as< ExprValueType > ().isNumber() && yystack_[0].value.as< ExprValueType > ().isNumber() ) {
                expr_bi_op2<std::not_equal_to>(yylhs.value.as< ExprValueType > (),yystack_[2].value.as< ExprValueType > (),yystack_[0].value.as< ExprValueType > ());
            }else{
                yylhs.value.as< ExprValueType > ().setBool(true);
            }
        }
#line 1200 "TExpr.tab.cc" // lalr1.cc:859
    break;

  case 17:
#line 258 "TExpr.y" // lalr1.cc:859
    { CHECK_COND;
            CHECK_TYPE(yystack_[2].value.as< ExprValueType > ().isLogical() && yystack_[0].value.as< ExprValueType > ().isLogical() , "&&");
            expr_bi_op3<std::logical_and>(yylhs.value.as< ExprValueType > (),yystack_[2].value.as< ExprValueType > (),yystack_[0].value.as< ExprValueType > ());
        }
#line 1209 "TExpr.tab.cc" // lalr1.cc:859
    break;

  case 18:
#line 262 "TExpr.y" // lalr1.cc:859
    { CHECK_COND;
            CHECK_TYPE(yystack_[2].value.as< ExprValueType > ().isLogical() && yystack_[0].value.as< ExprValueType > ().isLogical() , "||");
            expr_bi_op3<std::logical_or>(yylhs.value.as< ExprValueType > (),yystack_[2].value.as< ExprValueType > (),yystack_[0].value.as< ExprValueType > ());
        }
#line 1218 "TExpr.tab.cc" // lalr1.cc:859
    break;

  case 19:
#line 266 "TExpr.y" // lalr1.cc:859
    { CHECK_COND;
            CHECK_TYPE(yystack_[0].value.as< ExprValueType > ().isLogical() , "!");
            yylhs.value.as< ExprValueType > ().setBool( ! yystack_[0].value.as< ExprValueType > ().getBool() );
        }
#line 1227 "TExpr.tab.cc" // lalr1.cc:859
    break;

  case 20:
#line 270 "TExpr.y" // lalr1.cc:859
    { CHECK_COND;
            CHECK_TYPE(yystack_[2].value.as< ExprValueType > ().isInt() && yystack_[0].value.as< ExprValueType > ().isInt(), "&");
            yylhs.value.as< ExprValueType > ().setInt( yystack_[2].value.as< ExprValueType > ().getInt() & yystack_[0].value.as< ExprValueType > ().getInt() );
        }
#line 1236 "TExpr.tab.cc" // lalr1.cc:859
    break;

  case 21:
#line 274 "TExpr.y" // lalr1.cc:859
    { CHECK_COND;
            CHECK_TYPE(yystack_[2].value.as< ExprValueType > ().isInt() && yystack_[0].value.as< ExprValueType > ().isInt(), "|");
            yylhs.value.as< ExprValueType > ().setInt( yystack_[2].value.as< ExprValueType > ().getInt() | yystack_[0].value.as< ExprValueType > ().getInt() );
        }
#line 1245 "TExpr.tab.cc" // lalr1.cc:859
    break;

  case 22:
#line 278 "TExpr.y" // lalr1.cc:859
    { CHECK_COND;
            CHECK_TYPE(yystack_[0].value.as< ExprValueType > ().isInt(), "~");
            yylhs.value.as< ExprValueType > ().setInt( ~ yystack_[0].value.as< ExprValueType > ().getInt() );
        }
#line 1254 "TExpr.tab.cc" // lalr1.cc:859
    break;

  case 23:
#line 282 "TExpr.y" // lalr1.cc:859
    { CHECK_COND;
            CHECK_TYPE(yystack_[0].value.as< ExprValueType > ().isNumber(), "-");
            if(yystack_[0].value.as< ExprValueType > ().isInt())
                yylhs.value.as< ExprValueType > ().setInt(-yystack_[0].value.as< ExprValueType > ().getInt());
            else if(yystack_[0].value.as< ExprValueType > ().isDouble())
                yylhs.value.as< ExprValueType > ().setDouble(-yystack_[0].value.as< ExprValueType > ().getDouble());
        }
#line 1266 "TExpr.tab.cc" // lalr1.cc:859
    break;

  case 24:
#line 289 "TExpr.y" // lalr1.cc:859
    { CHECK_COND;
            yylhs.value.as< ExprValueType > () = yystack_[1].value.as< ExprValueType > ();
        }
#line 1274 "TExpr.tab.cc" // lalr1.cc:859
    break;

  case 25:
#line 292 "TExpr.y" // lalr1.cc:859
    { CHECK_COND; yylhs.value.as< ExprValueType > ().setInt(yystack_[0].value.as< int > ()); }
#line 1280 "TExpr.tab.cc" // lalr1.cc:859
    break;

  case 26:
#line 293 "TExpr.y" // lalr1.cc:859
    { CHECK_COND; yylhs.value.as< ExprValueType > ().setDouble(yystack_[0].value.as< double > ()); }
#line 1286 "TExpr.tab.cc" // lalr1.cc:859
    break;

  case 27:
#line 294 "TExpr.y" // lalr1.cc:859
    { CHECK_COND; yylhs.value.as< ExprValueType > ().setStr(yystack_[0].value.as< std::string > ()); }
#line 1292 "TExpr.tab.cc" // lalr1.cc:859
    break;

  case 28:
#line 295 "TExpr.y" // lalr1.cc:859
    { CHECK_COND;
            ExprValuePtr sfd=valTable.getField(yystack_[0].value.as< std::string > ());
            if(!sfd){
                error(string("no such field: ")+yystack_[0].value.as< std::string > ());
                YYERROR;
            }
            yylhs.value.as< ExprValueType > ()=*sfd;
        }
#line 1305 "TExpr.tab.cc" // lalr1.cc:859
    break;

  case 29:
#line 303 "TExpr.y" // lalr1.cc:859
    { CHECK_COND;
            string fdname=yystack_[3].value.as< std::string > ()+"#"+yystack_[1].value.as< ExprValueType > ().getStr();
            ExprValuePtr sfd=valTable.getField(fdname);
            if(!sfd){
                error(string("no such field: ")+fdname);
                YYERROR;
            }
            yylhs.value.as< ExprValueType > ()=*sfd;
        }
#line 1319 "TExpr.tab.cc" // lalr1.cc:859
    break;

  case 30:
#line 312 "TExpr.y" // lalr1.cc:859
    { CHECK_COND;
            ExprValuePtr rv = ExprValuePtr( new(ExprValue) );
            if( symTable->call( yystack_[3].value.as< std::string > (), valTable, yystack_[1].value.as< ExprArgsPtr > () , rv ) ){
                yylhs.value.as< ExprValueType > () = *rv;
            }else{
                error(string("error call function: ")+yystack_[3].value.as< std::string > ());
                YYERROR;
            }
        }
#line 1333 "TExpr.tab.cc" // lalr1.cc:859
    break;

  case 31:
#line 321 "TExpr.y" // lalr1.cc:859
    {
            if(cond.top()){
                if(! yystack_[1].value.as< ExprValueType > ().isLogical() ){
                    error("error condition before '?'");
                    YYERROR;
                }
                cond.push(yystack_[1].value.as< ExprValueType > ().getBool());
            }else{
                cond.push(false);
            }
        }
#line 1349 "TExpr.tab.cc" // lalr1.cc:859
    break;

  case 32:
#line 332 "TExpr.y" // lalr1.cc:859
    {
            bool if_cond = cond.top();
            cond.pop();
            cond.push( (!if_cond) && cond.top() );
        }
#line 1359 "TExpr.tab.cc" // lalr1.cc:859
    break;

  case 33:
#line 337 "TExpr.y" // lalr1.cc:859
    {
            yylhs.value.as< ExprValueType > () = cond.top() ? yystack_[0].value.as< ExprValueType > () : yystack_[3].value.as< ExprValueType > (); 
            cond.pop();
        }
#line 1368 "TExpr.tab.cc" // lalr1.cc:859
    break;

  case 34:
#line 343 "TExpr.y" // lalr1.cc:859
    { CHECK_COND;
            yylhs.value.as< ExprArgsPtr > () = ExprArgsPtr (new ExprArgsType);
            yylhs.value.as< ExprArgsPtr > ()->push_back(ExprValuePtr(new ExprValueType(yystack_[0].value.as< ExprValueType > ())));
        }
#line 1377 "TExpr.tab.cc" // lalr1.cc:859
    break;

  case 35:
#line 347 "TExpr.y" // lalr1.cc:859
    { CHECK_COND;
            assert(yystack_[2].value.as< ExprArgsPtr > ());
            yystack_[2].value.as< ExprArgsPtr > ()->push_back(ExprValuePtr(new ExprValueType(yystack_[0].value.as< ExprValueType > ())));
            yylhs.value.as< ExprArgsPtr > () = yystack_[2].value.as< ExprArgsPtr > ();
        }
#line 1387 "TExpr.tab.cc" // lalr1.cc:859
    break;


#line 1391 "TExpr.tab.cc" // lalr1.cc:859
            default:
              break;
            }
        }
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, yylhs);
    }
    goto yynewstate;

  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yysyntax_error_ (yystack_[0].state, yyla));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }


      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
  TExpr::error (const syntax_error& yyexc)
  {
    error (yyexc.what());
  }

  // Generate an error message.
  std::string
  TExpr::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    size_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state
         merging (from LALR or IELR) and default reductions corrupt the
         expected token list.  However, the list is correct for
         canonical LR with one exception: it will still contain any
         token that will not be accepted due to an error action in a
         later state.
    */
    if (!yyla.empty ())
      {
        int yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];
        int yyn = yypact_[yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yyterror_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
        YYCASE_(0, YY_("syntax error"));
        YYCASE_(1, YY_("syntax error, unexpected %s"));
        YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    size_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char TExpr::yypact_ninf_ = -26;

  const signed char TExpr::yytable_ninf_ = -1;

  const short int
  TExpr::yypact_[] =
  {
     176,   -26,   -26,   -26,   -25,   176,   176,   176,   176,     6,
     -26,   114,   176,   176,   -26,   -26,   -26,    62,   -26,   176,
     176,   176,   176,   176,   176,   -26,   176,   176,   176,   176,
     176,   176,   176,   176,   176,   176,   -26,     9,    31,   -26,
     159,   193,   202,   202,   202,   202,   176,   202,   202,   126,
     126,   -13,   -13,   -12,   -12,   -12,   -12,   -26,   176,   -26,
      91,   -26,   -26,   176,   137
  };

  const unsigned char
  TExpr::yydefact_[] =
  {
       4,    27,    25,    26,    28,     0,     0,     0,     0,     0,
       2,     3,     4,     0,    22,    23,    19,     0,     1,     0,
       0,     0,     0,     0,     0,    31,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    34,     0,     0,    24,
      18,    17,    15,    16,    12,    14,     0,    13,    11,    20,
      21,     5,     6,     7,     8,     9,    10,    30,     4,    29,
       0,    35,    32,     0,    33
  };

  const signed char
  TExpr::yypgoto_[] =
  {
     -26,   -26,    -8,    -5,   -26,   -26,   -26
  };

  const signed char
  TExpr::yydefgoto_[] =
  {
      -1,     9,    10,    11,    46,    63,    37
  };

  const unsigned char
  TExpr::yytable_[] =
  {
      14,    15,    16,    17,    36,    12,    18,    13,    38,    32,
      33,    34,    35,    35,    40,    41,    42,    43,    44,    45,
       0,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,     0,     0,     0,    19,    20,    21,    22,    23,    24,
      57,    60,     0,    58,    25,     0,    26,    27,    28,    29,
      61,    30,    31,    32,    33,    34,    35,     0,    64,     0,
       0,     0,     0,     0,    59,    19,    20,    21,    22,    23,
      24,     0,     0,     0,     0,    25,     0,    26,    27,    28,
      29,     0,    30,    31,    32,    33,    34,    35,     0,     0,
       0,     0,     0,    39,    19,    20,    21,    22,    23,    24,
       0,     0,     0,     0,    25,    62,    26,    27,    28,    29,
       0,    30,    31,    32,    33,    34,    35,    19,    20,    21,
      22,    23,    24,     0,     0,     0,     0,    25,     0,    26,
      27,    28,    29,     0,    30,    31,    32,    33,    34,    35,
      19,    20,    21,    22,    23,    24,    30,    31,    32,    33,
      34,    35,    26,    27,    28,    29,     0,    30,    31,    32,
      33,    34,    35,    20,    21,    22,    23,    24,     0,     0,
       0,     0,     0,     0,    26,    27,    28,    29,     0,    30,
      31,    32,    33,    34,    35,     1,     2,     3,     4,     0,
       0,     0,     0,     0,     0,     5,     0,     6,    21,    22,
      23,    24,     0,     0,     0,     7,     8,     0,    26,    27,
      28,    29,     0,    30,    31,    32,    33,    34,    35,    28,
      29,     0,    30,    31,    32,    33,    34,    35
  };

  const signed char
  TExpr::yycheck_[] =
  {
       5,     6,     7,     8,    12,    30,     0,    32,    13,    22,
      23,    24,    25,    25,    19,    20,    21,    22,    23,    24,
      -1,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    -1,    -1,    -1,     3,     4,     5,     6,     7,     8,
      31,    46,    -1,    34,    13,    -1,    15,    16,    17,    18,
      58,    20,    21,    22,    23,    24,    25,    -1,    63,    -1,
      -1,    -1,    -1,    -1,    33,     3,     4,     5,     6,     7,
       8,    -1,    -1,    -1,    -1,    13,    -1,    15,    16,    17,
      18,    -1,    20,    21,    22,    23,    24,    25,    -1,    -1,
      -1,    -1,    -1,    31,     3,     4,     5,     6,     7,     8,
      -1,    -1,    -1,    -1,    13,    14,    15,    16,    17,    18,
      -1,    20,    21,    22,    23,    24,    25,     3,     4,     5,
       6,     7,     8,    -1,    -1,    -1,    -1,    13,    -1,    15,
      16,    17,    18,    -1,    20,    21,    22,    23,    24,    25,
       3,     4,     5,     6,     7,     8,    20,    21,    22,    23,
      24,    25,    15,    16,    17,    18,    -1,    20,    21,    22,
      23,    24,    25,     4,     5,     6,     7,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    15,    16,    17,    18,    -1,    20,
      21,    22,    23,    24,    25,     9,    10,    11,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    19,    -1,    21,     5,     6,
       7,     8,    -1,    -1,    -1,    29,    30,    -1,    15,    16,
      17,    18,    -1,    20,    21,    22,    23,    24,    25,    17,
      18,    -1,    20,    21,    22,    23,    24,    25
  };

  const unsigned char
  TExpr::yystos_[] =
  {
       0,     9,    10,    11,    12,    19,    21,    29,    30,    36,
      37,    38,    30,    32,    38,    38,    38,    38,     0,     3,
       4,     5,     6,     7,     8,    13,    15,    16,    17,    18,
      20,    21,    22,    23,    24,    25,    37,    41,    38,    31,
      38,    38,    38,    38,    38,    38,    39,    38,    38,    38,
      38,    38,    38,    38,    38,    38,    38,    31,    34,    33,
      38,    37,    14,    40,    38
  };

  const unsigned char
  TExpr::yyr1_[] =
  {
       0,    35,    36,    37,    37,    38,    38,    38,    38,    38,
      38,    38,    38,    38,    38,    38,    38,    38,    38,    38,
      38,    38,    38,    38,    38,    38,    38,    38,    38,    38,
      38,    39,    40,    38,    41,    41
  };

  const unsigned char
  TExpr::yyr2_[] =
  {
       0,     2,     1,     1,     0,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       3,     3,     2,     2,     3,     1,     1,     1,     1,     4,
       4,     0,     0,     7,     1,     3
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const TExpr::yytname_[] =
  {
  "\"end of input\"", "error", "$undefined", "\"||\"", "\"&&\"", "\"==\"",
  "\"!=\"", "\">=\"", "\"<=\"", "\"string\"", "\"int\"", "\"double\"",
  "\"identifier\"", "'?'", "':'", "'<'", "'>'", "'&'", "'|'", "'~'", "'+'",
  "'-'", "'*'", "'/'", "'%'", "'^'", "NOT", "NEG", "COMP", "'!'", "'('",
  "')'", "'['", "']'", "','", "$accept", "expr_start", "expr_arg", "expr",
  "$@1", "$@2", "args", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short int
  TExpr::yyrline_[] =
  {
       0,   189,   189,   191,   194,   199,   206,   210,   214,   218,
     222,   226,   230,   234,   238,   242,   249,   258,   262,   266,
     270,   274,   278,   282,   289,   292,   293,   294,   295,   303,
     312,   321,   332,   321,   343,   347
  };

  // Print the state stack on the debug stream.
  void
  TExpr::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  TExpr::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):" << std::endl;
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  // Symbol number corresponding to token number t.
  inline
  TExpr::token_number_type
  TExpr::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
    {
     0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    29,     2,     2,     2,    24,    17,     2,
      30,    31,    22,    20,    34,    21,     2,    23,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    14,     2,
      15,     2,    16,    13,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    32,     2,    33,    25,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    18,     2,    19,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    26,    27,
      28
    };
    const unsigned int user_token_number_max_ = 270;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }


} // yy
#line 1872 "TExpr.tab.cc" // lalr1.cc:1167
#line 352 "TExpr.y" // lalr1.cc:1168


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
