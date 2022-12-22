// A Bison parser, made by GNU Bison 3.7.5.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

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

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





#include "parser.hh"


// Unqualified %code blocks.
#line 26 "../parser/parser.yy"

    #include <iostream>
    #include <string>
    #include <map>

    #include "scanner.hh"
    #include "driver.hh"

    #undef  yylex
    #define yylex scanner.yylex

    std::map<std::string, InstPtr> fonctions;

#line 60 "parser.cc"


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


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


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
      *yycdebug_ << '\n';                       \
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
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 152 "parser.cc"

  /// Build a parser object.
   Parser :: Parser  (Scanner &scanner_yyarg, Driver &driver_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      scanner (scanner_yyarg),
      driver (driver_yyarg)
  {}

   Parser ::~ Parser  ()
  {}

   Parser ::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | symbol kinds.  |
  `---------------*/

  // basic_symbol.
  template <typename Base>
   Parser ::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
    , location (that.location)
  {
    switch (this->kind ())
    {
      case symbol_kind::S_operation: // operation
        value.copy< ExpressionPtr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_instruction: // instruction
      case symbol_kind::S_action: // action
        value.copy< InstPtr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_verification: // verification
        value.copy< VerifPtr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NUMBER: // NUMBER
        value.copy< float > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_SENS: // SENS
      case symbol_kind::S_IdTortue: // IdTortue
      case symbol_kind::S_DIRECTION: // DIRECTION
      case symbol_kind::S_CONDITION: // CONDITION
      case symbol_kind::S_MODE_COULEUR: // MODE_COULEUR
      case symbol_kind::S_mode: // mode
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_selection: // selection
        value.copy< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_COULEUR: // COULEUR
      case symbol_kind::S_CHEMIN_JARDIN: // CHEMIN_JARDIN
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }



  template <typename Base>
   Parser ::symbol_kind_type
   Parser ::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }

  template <typename Base>
  bool
   Parser ::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
   Parser ::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
    {
      case symbol_kind::S_operation: // operation
        value.move< ExpressionPtr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_instruction: // instruction
      case symbol_kind::S_action: // action
        value.move< InstPtr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_verification: // verification
        value.move< VerifPtr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_NUMBER: // NUMBER
        value.move< float > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_SENS: // SENS
      case symbol_kind::S_IdTortue: // IdTortue
      case symbol_kind::S_DIRECTION: // DIRECTION
      case symbol_kind::S_CONDITION: // CONDITION
      case symbol_kind::S_MODE_COULEUR: // MODE_COULEUR
      case symbol_kind::S_mode: // mode
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_selection: // selection
        value.move< int > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_COULEUR: // COULEUR
      case symbol_kind::S_CHEMIN_JARDIN: // CHEMIN_JARDIN
        value.move< std::string > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_kind.
   Parser ::by_kind::by_kind ()
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
   Parser ::by_kind::by_kind (by_kind&& that)
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

   Parser ::by_kind::by_kind (const by_kind& that)
    : kind_ (that.kind_)
  {}

   Parser ::by_kind::by_kind (token_kind_type t)
    : kind_ (yytranslate_ (t))
  {}

  void
   Parser ::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  void
   Parser ::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

   Parser ::symbol_kind_type
   Parser ::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }

   Parser ::symbol_kind_type
   Parser ::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  // by_state.
   Parser ::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

   Parser ::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
   Parser ::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
   Parser ::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

   Parser ::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

   Parser ::symbol_kind_type
   Parser ::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

   Parser ::stack_symbol_type::stack_symbol_type ()
  {}

   Parser ::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_operation: // operation
        value.YY_MOVE_OR_COPY< ExpressionPtr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_instruction: // instruction
      case symbol_kind::S_action: // action
        value.YY_MOVE_OR_COPY< InstPtr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_verification: // verification
        value.YY_MOVE_OR_COPY< VerifPtr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NUMBER: // NUMBER
        value.YY_MOVE_OR_COPY< float > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_SENS: // SENS
      case symbol_kind::S_IdTortue: // IdTortue
      case symbol_kind::S_DIRECTION: // DIRECTION
      case symbol_kind::S_CONDITION: // CONDITION
      case symbol_kind::S_MODE_COULEUR: // MODE_COULEUR
      case symbol_kind::S_mode: // mode
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_selection: // selection
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_COULEUR: // COULEUR
      case symbol_kind::S_CHEMIN_JARDIN: // CHEMIN_JARDIN
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

   Parser ::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_operation: // operation
        value.move< ExpressionPtr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_instruction: // instruction
      case symbol_kind::S_action: // action
        value.move< InstPtr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_verification: // verification
        value.move< VerifPtr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NUMBER: // NUMBER
        value.move< float > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_SENS: // SENS
      case symbol_kind::S_IdTortue: // IdTortue
      case symbol_kind::S_DIRECTION: // DIRECTION
      case symbol_kind::S_CONDITION: // CONDITION
      case symbol_kind::S_MODE_COULEUR: // MODE_COULEUR
      case symbol_kind::S_mode: // mode
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_selection: // selection
        value.move< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_COULEUR: // COULEUR
      case symbol_kind::S_CHEMIN_JARDIN: // CHEMIN_JARDIN
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
   Parser ::stack_symbol_type&
   Parser ::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_operation: // operation
        value.copy< ExpressionPtr > (that.value);
        break;

      case symbol_kind::S_instruction: // instruction
      case symbol_kind::S_action: // action
        value.copy< InstPtr > (that.value);
        break;

      case symbol_kind::S_verification: // verification
        value.copy< VerifPtr > (that.value);
        break;

      case symbol_kind::S_NUMBER: // NUMBER
        value.copy< float > (that.value);
        break;

      case symbol_kind::S_SENS: // SENS
      case symbol_kind::S_IdTortue: // IdTortue
      case symbol_kind::S_DIRECTION: // DIRECTION
      case symbol_kind::S_CONDITION: // CONDITION
      case symbol_kind::S_MODE_COULEUR: // MODE_COULEUR
      case symbol_kind::S_mode: // mode
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_selection: // selection
        value.copy< int > (that.value);
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_COULEUR: // COULEUR
      case symbol_kind::S_CHEMIN_JARDIN: // CHEMIN_JARDIN
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

   Parser ::stack_symbol_type&
   Parser ::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_operation: // operation
        value.move< ExpressionPtr > (that.value);
        break;

      case symbol_kind::S_instruction: // instruction
      case symbol_kind::S_action: // action
        value.move< InstPtr > (that.value);
        break;

      case symbol_kind::S_verification: // verification
        value.move< VerifPtr > (that.value);
        break;

      case symbol_kind::S_NUMBER: // NUMBER
        value.move< float > (that.value);
        break;

      case symbol_kind::S_SENS: // SENS
      case symbol_kind::S_IdTortue: // IdTortue
      case symbol_kind::S_DIRECTION: // DIRECTION
      case symbol_kind::S_CONDITION: // CONDITION
      case symbol_kind::S_MODE_COULEUR: // MODE_COULEUR
      case symbol_kind::S_mode: // mode
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_selection: // selection
        value.move< int > (that.value);
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_COULEUR: // COULEUR
      case symbol_kind::S_CHEMIN_JARDIN: // CHEMIN_JARDIN
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
   Parser ::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
   Parser ::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
   Parser ::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
   Parser ::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
   Parser ::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
   Parser ::debug_stream () const
  {
    return *yycdebug_;
  }

  void
   Parser ::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


   Parser ::debug_level_type
   Parser ::debug_level () const
  {
    return yydebug_;
  }

  void
   Parser ::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

   Parser ::state_type
   Parser ::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
   Parser ::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
   Parser ::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
   Parser ::operator() ()
  {
    return parse ();
  }

  int
   Parser ::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.kind_ = yytranslate_ (yylex (&yyla.value, &yyla.location));
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

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
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_operation: // operation
        yylhs.value.emplace< ExpressionPtr > ();
        break;

      case symbol_kind::S_instruction: // instruction
      case symbol_kind::S_action: // action
        yylhs.value.emplace< InstPtr > ();
        break;

      case symbol_kind::S_verification: // verification
        yylhs.value.emplace< VerifPtr > ();
        break;

      case symbol_kind::S_NUMBER: // NUMBER
        yylhs.value.emplace< float > ();
        break;

      case symbol_kind::S_SENS: // SENS
      case symbol_kind::S_IdTortue: // IdTortue
      case symbol_kind::S_DIRECTION: // DIRECTION
      case symbol_kind::S_CONDITION: // CONDITION
      case symbol_kind::S_MODE_COULEUR: // MODE_COULEUR
      case symbol_kind::S_mode: // mode
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_selection: // selection
        yylhs.value.emplace< int > ();
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_COULEUR: // COULEUR
      case symbol_kind::S_CHEMIN_JARDIN: // CHEMIN_JARDIN
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // programme: FONCTION MAIN DOUBLEPOINT NL instruction END FONCTION NL
#line 87 "../parser/parser.yy"
                                                            {
        yystack_[3].value.as < InstPtr > ()->parcourir(driver);
        YYACCEPT;
    }
#line 877 "parser.cc"
    break;

  case 3: // $@1: %empty
#line 91 "../parser/parser.yy"
                                                             {
        fonctions[yystack_[6].value.as < std::string > ()]= yystack_[3].value.as < InstPtr > ();
    }
#line 885 "parser.cc"
    break;

  case 5: // instruction: instruction comment NL
#line 96 "../parser/parser.yy"
    { yylhs.value.as < InstPtr > () = yystack_[2].value.as < InstPtr > (); }
#line 891 "parser.cc"
    break;

  case 6: // instruction: SI verification NL instruction SINON NL instruction END SI
#line 97 "../parser/parser.yy"
                                                                 {
        auto res = std::make_shared<Si>(yystack_[7].value.as < VerifPtr > ());
        res->ajouterFils(yystack_[5].value.as < InstPtr > ());
        res->ajouterFils(yystack_[2].value.as < InstPtr > ());
        yylhs.value.as < InstPtr > () = res;
    }
#line 902 "parser.cc"
    break;

  case 7: // instruction: SI verification NL instruction END SI
#line 103 "../parser/parser.yy"
                                           {
        auto res = std::make_shared<Si>(yystack_[4].value.as < VerifPtr > ());
        res->ajouterFils(yystack_[2].value.as < InstPtr > ());
        yylhs.value.as < InstPtr > () = res;
    }
#line 912 "parser.cc"
    break;

  case 8: // instruction: TANTQUE verification NL instruction END TANTQUE
#line 108 "../parser/parser.yy"
                                                     {
        auto res = std::make_shared<TantQue>(yystack_[4].value.as < VerifPtr > ());
        res->ajouterFils(yystack_[2].value.as < InstPtr > ());
        yylhs.value.as < InstPtr > () = res;
    }
#line 922 "parser.cc"
    break;

  case 9: // instruction: REPETE expression DOUBLEPOINT NL instruction END REPETE
#line 113 "../parser/parser.yy"
                                                             {
        auto res = std::make_shared<Repete>(yystack_[5].value.as < int > ());
        res->ajouterFils(yystack_[2].value.as < InstPtr > ());
        yylhs.value.as < InstPtr > () = res;
    }
#line 932 "parser.cc"
    break;

  case 10: // instruction: SI verification NL instruction END SI
#line 118 "../parser/parser.yy"
                                           {
        auto res = std::make_shared<Si>(yystack_[4].value.as < VerifPtr > ());
        res->ajouterFils(yystack_[2].value.as < InstPtr > ());
        yylhs.value.as < InstPtr > () = res;
    }
#line 942 "parser.cc"
    break;

  case 11: // instruction: action
#line 123 "../parser/parser.yy"
      { yylhs.value.as < InstPtr > () = yystack_[0].value.as < InstPtr > (); }
#line 948 "parser.cc"
    break;

  case 12: // instruction: instruction instruction
#line 124 "../parser/parser.yy"
                              {
        yylhs.value.as < InstPtr > () = std::make_shared<Bloc>(yystack_[1].value.as < InstPtr > (), yystack_[0].value.as < InstPtr > ());
    }
#line 956 "parser.cc"
    break;

  case 13: // instruction: ID
#line 127 "../parser/parser.yy"
         {
        yylhs.value.as < InstPtr > () = fonctions[yystack_[0].value.as < std::string > ()];
    }
#line 964 "parser.cc"
    break;

  case 14: // action: AVANCE expression selection
#line 133 "../parser/parser.yy"
                                {
        yylhs.value.as < InstPtr > () = std::make_shared<Action>("avance", yystack_[0].value.as < int > (), yystack_[1].value.as < int > ());
    }
#line 972 "parser.cc"
    break;

  case 15: // action: RECULE expression selection
#line 136 "../parser/parser.yy"
                                  {
        yylhs.value.as < InstPtr > () = std::make_shared<Action>("avance", yystack_[0].value.as < int > (), -yystack_[1].value.as < int > ());
    }
#line 980 "parser.cc"
    break;

  case 16: // action: SAUTE expression selection
#line 139 "../parser/parser.yy"
                                 {        
        yylhs.value.as < InstPtr > () = std::make_shared<Action>("saute", yystack_[0].value.as < int > (), 0);
    }
#line 988 "parser.cc"
    break;

  case 17: // action: TOURNE SENS selection
#line 142 "../parser/parser.yy"
                            {
        yylhs.value.as < InstPtr > () = std::make_shared<Action>("tourne", yystack_[0].value.as < int > (), yystack_[1].value.as < int > ());
    }
#line 996 "parser.cc"
    break;

  case 18: // action: MODIF_COULEUR mode COULEUR selection
#line 145 "../parser/parser.yy"
                                           {
        yylhs.value.as < InstPtr > () = std::make_shared<Action>("couleur", yystack_[0].value.as < int > (), yystack_[2].value.as < int > (), yystack_[1].value.as < std::string > ());
    }
#line 1004 "parser.cc"
    break;

  case 19: // action: TORTUES expression NL
#line 148 "../parser/parser.yy"
                           {
        yylhs.value.as < InstPtr > () = std::make_shared<Action>("tortues", yystack_[1].value.as < int > ());
    }
#line 1012 "parser.cc"
    break;

  case 20: // action: JARDIN CHEMIN_JARDIN
#line 151 "../parser/parser.yy"
                          {
        yylhs.value.as < InstPtr > () = std::make_shared<Action>("jardin", 0, 0, yystack_[0].value.as < std::string > ());
    }
#line 1020 "parser.cc"
    break;

  case 21: // verification: CONDITION SENS selection DOUBLEPOINT
#line 156 "../parser/parser.yy"
                                        {
        yylhs.value.as < VerifPtr > () = std::make_shared<Verification>(yystack_[3].value.as < int > (), yystack_[2].value.as < int > (), yystack_[1].value.as < int > ());
    }
#line 1028 "parser.cc"
    break;

  case 22: // mode: MODE_COULEUR
#line 161 "../parser/parser.yy"
                 {
        yylhs.value.as < int > () = yystack_[0].value.as < int > ();
    }
#line 1036 "parser.cc"
    break;

  case 23: // mode: %empty
#line 164 "../parser/parser.yy"
      {
        yylhs.value.as < int > () = 0;
    }
#line 1044 "parser.cc"
    break;

  case 24: // expression: operation fois
#line 169 "../parser/parser.yy"
                   {
        yylhs.value.as < int > () = (int)yystack_[1].value.as < ExpressionPtr > ()->calculer(driver.getContexte());
    }
#line 1052 "parser.cc"
    break;

  case 25: // expression: %empty
#line 172 "../parser/parser.yy"
      {
        yylhs.value.as < int > () = 1;
    }
#line 1060 "parser.cc"
    break;

  case 27: // comment: %empty
#line 178 "../parser/parser.yy"
      {}
#line 1066 "parser.cc"
    break;

  case 28: // fois: FOIS
#line 181 "../parser/parser.yy"
         {}
#line 1072 "parser.cc"
    break;

  case 29: // fois: %empty
#line 182 "../parser/parser.yy"
      {}
#line 1078 "parser.cc"
    break;

  case 30: // selection: IdTortue
#line 185 "../parser/parser.yy"
             {
        yylhs.value.as < int > () = yystack_[0].value.as < int > ();
    }
#line 1086 "parser.cc"
    break;

  case 31: // selection: %empty
#line 188 "../parser/parser.yy"
      {
        yylhs.value.as < int > () = -1;
    }
#line 1094 "parser.cc"
    break;

  case 32: // operation: NUMBER
#line 193 "../parser/parser.yy"
          {
        yylhs.value.as < ExpressionPtr > () = std::make_shared<Constante>(yystack_[0].value.as < float > ());
    }
#line 1102 "parser.cc"
    break;

  case 33: // operation: '(' operation ')'
#line 196 "../parser/parser.yy"
                        {
        yylhs.value.as < ExpressionPtr > () = yystack_[1].value.as < ExpressionPtr > ();
    }
#line 1110 "parser.cc"
    break;

  case 34: // operation: operation '+' operation
#line 199 "../parser/parser.yy"
                              {
        yylhs.value.as < ExpressionPtr > () = std::make_shared<ExpressionBinaire>(yystack_[2].value.as < ExpressionPtr > (), yystack_[0].value.as < ExpressionPtr > (), OperateurBinaire::plus);
    }
#line 1118 "parser.cc"
    break;

  case 35: // operation: operation '-' operation
#line 202 "../parser/parser.yy"
                              {
        yylhs.value.as < ExpressionPtr > () = std::make_shared<ExpressionBinaire>(yystack_[2].value.as < ExpressionPtr > (), yystack_[0].value.as < ExpressionPtr > (), OperateurBinaire::moins);
    }
#line 1126 "parser.cc"
    break;

  case 36: // operation: operation '*' operation
#line 205 "../parser/parser.yy"
                              {
        yylhs.value.as < ExpressionPtr > () = std::make_shared<ExpressionBinaire>(yystack_[2].value.as < ExpressionPtr > (), yystack_[0].value.as < ExpressionPtr > (), OperateurBinaire::multiplie);
    }
#line 1134 "parser.cc"
    break;

  case 37: // operation: operation '/' operation
#line 208 "../parser/parser.yy"
                              {
        if (yystack_[0].value.as < ExpressionPtr > () == 0) {
            std::cerr << "division par 0\n";
            YYACCEPT;
        }
        yylhs.value.as < ExpressionPtr > () = std::make_shared<ExpressionBinaire>(yystack_[2].value.as < ExpressionPtr > (), yystack_[0].value.as < ExpressionPtr > (), OperateurBinaire::divise);
    }
#line 1146 "parser.cc"
    break;

  case 38: // operation: '-' operation
#line 215 "../parser/parser.yy"
                              {
        yylhs.value.as < ExpressionPtr > () = std::make_shared<ExpressionUnaire>(yystack_[0].value.as < ExpressionPtr > (), OperateurUnaire::neg);
    }
#line 1154 "parser.cc"
    break;


#line 1158 "parser.cc"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
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
        std::string msg = YY_("syntax error");
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
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
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
   Parser ::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

#if YYDEBUG || 0
  const char *
   Parser ::symbol_name (symbol_kind_type yysymbol)
  {
    return yytname_[yysymbol];
  }
#endif // #if YYDEBUG || 0





  const signed char  Parser ::yypact_ninf_ = -28;

  const signed char  Parser ::yytable_ninf_ = -1;

  const short
   Parser ::yypact_[] =
  {
     -10,    -3,    10,     6,    20,   -28,    35,    36,   199,   199,
      21,    21,    21,    47,    34,   -28,    34,    21,    43,    21,
      32,    44,   -28,    76,   -28,    21,    21,    64,     9,    64,
      64,    64,    68,    66,    67,    69,   -28,    57,    75,   -28,
      71,   -28,   171,    79,    77,   -28,    27,   -28,   -28,   -28,
      21,    21,    21,    21,   -28,   -28,   -28,   -28,    64,   199,
     199,    80,    64,   -28,    81,   -28,    83,   -28,   -13,   -13,
     -28,   -28,    85,     3,   104,   199,   -28,   -28,   -28,   -28,
      82,    87,    88,   132,   -10,   -28,   199,   -28,    70,   -28,
     160,   -28,    91,   -28
  };

  const signed char
   Parser ::yydefact_[] =
  {
       0,     0,     0,     0,     0,     1,     0,     0,     0,     0,
      25,    25,    25,     0,     0,    13,     0,    25,    23,    25,
       0,    27,    11,    27,    32,     0,     0,    31,    29,    31,
      31,    31,     0,     0,     0,     0,    22,     0,     0,    20,
       0,    26,    12,     0,     0,    38,     0,    30,    14,    28,
       0,     0,     0,     0,    24,    15,    16,    17,    31,     0,
       0,     0,    31,    19,     0,     5,     0,    33,    35,    34,
      36,    37,     0,    27,    27,     0,    18,     2,     3,    21,
       0,     0,     0,    27,     0,     7,     0,     8,     0,     4,
      27,     9,     0,     6
  };

  const signed char
   Parser ::yypgoto_[] =
  {
     -28,    29,   -28,    -8,   -28,    95,   -28,     7,   -28,   -28,
     -27,   -14
  };

  const signed char
   Parser ::yydefgoto_[] =
  {
       0,     2,    84,    42,    22,    33,    37,    27,    43,    54,
      48,    28
  };

  const signed char
   Parser ::yytable_[] =
  {
      21,    23,    55,    56,    57,     1,    10,    11,    12,    13,
       5,    45,    46,     3,    80,    14,    81,     4,    29,    30,
       6,    52,    53,    15,    35,    41,    38,    16,    17,    18,
      49,    72,    19,    20,     7,    76,    68,    69,    70,    71,
      24,    50,    51,    52,    53,     8,     9,    10,    11,    12,
      13,    73,    74,    25,    31,    40,    14,    32,    26,    50,
      51,    52,    53,    39,    15,    67,    41,    83,    16,    17,
      18,    36,    47,    19,    20,    58,    59,    60,    90,    10,
      11,    12,    13,    61,    62,    63,    64,    44,    14,    65,
      75,    77,    66,    78,    85,    91,    15,    86,    41,    79,
      16,    17,    18,    93,     0,    19,    20,    10,    11,    12,
      13,    34,    87,    89,     0,    82,    14,     0,     0,     0,
       0,     0,     0,     0,    15,     0,    41,     0,    16,    17,
      18,     0,     0,    19,    20,    10,    11,    12,    13,     0,
       0,     0,     0,    88,    14,     0,     0,     0,     0,     0,
       0,     0,    15,     0,    41,     0,    16,    17,    18,     0,
       0,    19,    20,    10,    11,    12,    13,     0,     0,     0,
       0,    92,    14,     0,    10,    11,    12,    13,     0,     0,
      15,     0,    41,    14,    16,    17,    18,     0,     0,    19,
      20,    15,     0,    41,     0,    16,    17,    18,     0,     0,
      19,    20,    10,    11,    12,    13,     0,     0,     0,     0,
       0,    14,     0,     0,     0,     0,     0,     0,     0,    15,
       0,     0,     0,    16,    17,    18,     0,     0,    19,    20
  };

  const signed char
   Parser ::yycheck_[] =
  {
       8,     9,    29,    30,    31,    15,     3,     4,     5,     6,
       0,    25,    26,    16,    11,    12,    13,    20,    11,    12,
      14,    34,    35,    20,    17,    22,    19,    24,    25,    26,
      21,    58,    29,    30,    14,    62,    50,    51,    52,    53,
      19,    32,    33,    34,    35,    10,    10,     3,     4,     5,
       6,    59,    60,    32,     7,    11,    12,    23,    37,    32,
      33,    34,    35,    31,    20,    38,    22,    75,    24,    25,
      26,    28,     8,    29,    30,     7,    10,    10,    86,     3,
       4,     5,     6,    14,    27,    10,    15,    11,    12,    10,
      10,    10,    15,    10,    12,    25,    20,    10,    22,    14,
      24,    25,    26,    12,    -1,    29,    30,     3,     4,     5,
       6,    16,    24,    84,    -1,    11,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    20,    -1,    22,    -1,    24,    25,
      26,    -1,    -1,    29,    30,     3,     4,     5,     6,    -1,
      -1,    -1,    -1,    11,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    20,    -1,    22,    -1,    24,    25,    26,    -1,
      -1,    29,    30,     3,     4,     5,     6,    -1,    -1,    -1,
      -1,    11,    12,    -1,     3,     4,     5,     6,    -1,    -1,
      20,    -1,    22,    12,    24,    25,    26,    -1,    -1,    29,
      30,    20,    -1,    22,    -1,    24,    25,    26,    -1,    -1,
      29,    30,     3,     4,     5,     6,    -1,    -1,    -1,    -1,
      -1,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,
      -1,    -1,    -1,    24,    25,    26,    -1,    -1,    29,    30
  };

  const signed char
   Parser ::yystos_[] =
  {
       0,    15,    40,    16,    20,     0,    14,    14,    10,    10,
       3,     4,     5,     6,    12,    20,    24,    25,    26,    29,
      30,    42,    43,    42,    19,    32,    37,    46,    50,    46,
      46,     7,    23,    44,    44,    46,    28,    45,    46,    31,
      11,    22,    42,    47,    11,    50,    50,     8,    49,    21,
      32,    33,    34,    35,    48,    49,    49,    49,     7,    10,
      10,    14,    27,    10,    15,    10,    15,    38,    50,    50,
      50,    50,    49,    42,    42,    10,    49,    10,    10,    14,
      11,    13,    11,    42,    41,    12,    10,    24,    11,    40,
      42,    25,    11,    12
  };

  const signed char
   Parser ::yyr1_[] =
  {
       0,    39,    40,    41,    40,    42,    42,    42,    42,    42,
      42,    42,    42,    42,    43,    43,    43,    43,    43,    43,
      43,    44,    45,    45,    46,    46,    47,    47,    48,    48,
      49,    49,    50,    50,    50,    50,    50,    50,    50
  };

  const signed char
   Parser ::yyr2_[] =
  {
       0,     2,     8,     0,    10,     3,     9,     6,     6,     7,
       6,     1,     2,     1,     3,     3,     3,     3,     4,     3,
       2,     4,     1,     0,     2,     0,     1,     0,     1,     0,
       1,     0,     1,     3,     3,     3,     3,     3,     2
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const  Parser ::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "AVANCE", "RECULE",
  "SAUTE", "TOURNE", "SENS", "IdTortue", "DIRECTION", "NL", "END", "SI",
  "SINON", "DOUBLEPOINT", "FONCTION", "MAIN", "EGAL", "DIFFERENT",
  "NUMBER", "ID", "FOIS", "COMMENT", "CONDITION", "TANTQUE", "REPETE",
  "MODIF_COULEUR", "COULEUR", "MODE_COULEUR", "TORTUES", "JARDIN",
  "CHEMIN_JARDIN", "'-'", "'+'", "'*'", "'/'", "NEG", "'('", "')'",
  "$accept", "programme", "$@1", "instruction", "action", "verification",
  "mode", "expression", "comment", "fois", "selection", "operation", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const unsigned char
   Parser ::yyrline_[] =
  {
       0,    87,    87,    91,    91,    96,    97,   103,   108,   113,
     118,   123,   124,   127,   133,   136,   139,   142,   145,   148,
     151,   156,   161,   164,   169,   172,   177,   178,   181,   182,
     185,   188,   193,   196,   199,   202,   205,   208,   215
  };

  void
   Parser ::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
   Parser ::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

   Parser ::symbol_kind_type
   Parser ::yytranslate_ (int t)
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const signed char
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      37,    38,    34,    33,     2,    32,     2,    35,     2,     2,
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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    36
    };
    // Last valid token kind.
    const int code_max = 287;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return YY_CAST (symbol_kind_type, translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

} // yy
#line 1591 "parser.cc"

#line 218 "../parser/parser.yy"


void yy::Parser::error(const location_type &l, const std::string & err_msg) {
    std::cerr << "Erreur : " << l << ", " << err_msg << std::endl;
}
