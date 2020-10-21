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

#line 37 "simple.cc" // lalr1.cc:404

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "simple.hh"

// User implementation prologue.

#line 51 "simple.cc" // lalr1.cc:412
// Unqualified %code blocks.
#line 25 "grammar.y" // lalr1.cc:413

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "icode.hh"
#include "symtab.hh"

using namespace std;
extern yy::simple_parser::symbol_type yylex(); 
extern char * yytext;
static int stptr = 0;

extern yy::location loc;

#define INSTRUCTION_NEXT  (itab->tab.size ())
#define INSTRUCTION_LAST  (itab->tab.size () - 1)


#line 73 "simple.cc" // lalr1.cc:413


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
    while (/*CONSTCOND*/ false)
# endif


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
#line 159 "simple.cc" // lalr1.cc:479

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  simple_parser::yytnamerr_ (const char *yystr)
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
  simple_parser::simple_parser (symtab_t * symtab_yyarg, itab_t * itab_yyarg, char * static_mem_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      symtab (symtab_yyarg),
      itab (itab_yyarg),
      static_mem (static_mem_yyarg)
  {}

  simple_parser::~simple_parser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/



  // by_state.
  inline
  simple_parser::by_state::by_state ()
    : state (empty_state)
  {}

  inline
  simple_parser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  simple_parser::by_state::clear ()
  {
    state = empty_state;
  }

  inline
  void
  simple_parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  inline
  simple_parser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  simple_parser::symbol_number_type
  simple_parser::by_state::type_get () const
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  inline
  simple_parser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  simple_parser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s, that.location)
  {
      switch (that.type_get ())
    {
      case 18: // T_FLOAT
        value.move< float > (that.value);
        break;

      case 17: // T_INTEGER
      case 42: // declaration
      case 43: // array_size
      case 44: // datatype
        value.move< int > (that.value);
        break;

      case 16: // T_ID
        value.move< string > (that.value);
        break;

      case 41: // assignment
      case 45: // a_expr
      case 46: // a_term
      case 47: // a_fact
      case 48: // varref
      case 49: // index
        value.move< symbol_t* > (that.value);
        break;

      case 52: // varlist
      case 53: // expr_list
        value.move< vector<symbol_t*>  > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

  inline
  simple_parser::stack_symbol_type&
  simple_parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
      switch (that.type_get ())
    {
      case 18: // T_FLOAT
        value.copy< float > (that.value);
        break;

      case 17: // T_INTEGER
      case 42: // declaration
      case 43: // array_size
      case 44: // datatype
        value.copy< int > (that.value);
        break;

      case 16: // T_ID
        value.copy< string > (that.value);
        break;

      case 41: // assignment
      case 45: // a_expr
      case 46: // a_term
      case 47: // a_fact
      case 48: // varref
      case 49: // index
        value.copy< symbol_t* > (that.value);
        break;

      case 52: // varlist
      case 53: // expr_list
        value.copy< vector<symbol_t*>  > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }


  template <typename Base>
  inline
  void
  simple_parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  simple_parser::yy_print_ (std::ostream& yyo,
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
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  inline
  void
  simple_parser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  simple_parser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  simple_parser::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  simple_parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  simple_parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  simple_parser::debug_level_type
  simple_parser::debug_level () const
  {
    return yydebug_;
  }

  void
  simple_parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  inline simple_parser::state_type
  simple_parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  inline bool
  simple_parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  simple_parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  simple_parser::parse ()
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

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


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
            symbol_type yylookahead (yylex ());
            yyla.move (yylookahead);
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
      case 18: // T_FLOAT
        yylhs.value.build< float > ();
        break;

      case 17: // T_INTEGER
      case 42: // declaration
      case 43: // array_size
      case 44: // datatype
        yylhs.value.build< int > ();
        break;

      case 16: // T_ID
        yylhs.value.build< string > ();
        break;

      case 41: // assignment
      case 45: // a_expr
      case 46: // a_term
      case 47: // a_fact
      case 48: // varref
      case 49: // index
        yylhs.value.build< symbol_t* > ();
        break;

      case 52: // varlist
      case 53: // expr_list
        yylhs.value.build< vector<symbol_t*>  > ();
        break;

      default:
        break;
    }


      // Compute the default @$.
      {
        slice<stack_symbol_type, stack_type> slice (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, slice, yylen);
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
      try
        {
          switch (yyn)
            {
  case 11:
#line 115 "grammar.y" // lalr1.cc:859
    {
        itab_instruction_add ( itab , OP_STORE_ARRAY_CELL , yystack_[5].value.as< symbol_t* > ()->addr , yystack_[3].value.as< symbol_t* > ()->addr , yystack_[0].value.as< symbol_t* > ()->addr );
        yylhs.value.as< symbol_t* > () = yystack_[5].value.as< symbol_t* > () ;
      }
#line 626 "simple.cc" // lalr1.cc:859
    break;

  case 12:
#line 122 "grammar.y" // lalr1.cc:859
    { 
      assert (symtab);
      assert (itab);
      symbol_t * sym = symbol_create (symtab, yystack_[0].value.as< string > (), yystack_[2].value.as< int > (), yystack_[1].value.as< int > ()); 
      assert (sym);
      symbol_add (symtab, sym);
  }
#line 638 "simple.cc" // lalr1.cc:859
    break;

  case 13:
#line 131 "grammar.y" // lalr1.cc:859
    { yylhs.value.as< int > () = yystack_[0].value.as< int > (); }
#line 644 "simple.cc" // lalr1.cc:859
    break;

  case 14:
#line 132 "grammar.y" // lalr1.cc:859
    { yylhs.value.as< int > () = 1; }
#line 650 "simple.cc" // lalr1.cc:859
    break;

  case 15:
#line 135 "grammar.y" // lalr1.cc:859
    { yylhs.value.as< int > () = DTYPE_INT; }
#line 656 "simple.cc" // lalr1.cc:859
    break;

  case 16:
#line 136 "grammar.y" // lalr1.cc:859
    { yylhs.value.as< int > () = DTYPE_FLOAT; }
#line 662 "simple.cc" // lalr1.cc:859
    break;

  case 17:
#line 142 "grammar.y" // lalr1.cc:859
    {
        if (yystack_[2].value.as< symbol_t* > ()->datatype != yystack_[0].value.as< symbol_t* > ()->datatype)
        {
          cout << "Incompatible datatypes\n";
          exit (1);
        }
        // TASK: Abort if the datatype of a_expr and a_term differ.
        symbol_t * res;
        if (yystack_[2].value.as< symbol_t* > ()->datatype == DTYPE_INT)
        {
          res = make_temp (symtab, yystack_[2].value.as< symbol_t* > ()->datatype);
          itab_instruction_add (itab, OP_ADD, res->addr, yystack_[2].value.as< symbol_t* > ()->addr, yystack_[0].value.as< symbol_t* > ()->addr);
        }
        if (yystack_[2].value.as< symbol_t* > ()->datatype == DTYPE_FLOAT)
        {
          // TASK: Modify this semantic action to support both DTYPE_INT and DTYPE_FLOAT.
          // For DTYPE_FLOAT you should generate an OP_FADD instruction.
          res = make_temp (symtab, yystack_[2].value.as< symbol_t* > ()->datatype);
          itab_instruction_add (itab, OP_FADD, res->addr, yystack_[2].value.as< symbol_t* > ()->addr, yystack_[0].value.as< symbol_t* > ()->addr);
        }
        yylhs.value.as< symbol_t* > () = res;
        #ifdef _SMP_DEBUG_
        cout << "On a_expr (1)\n";
        #endif
      }
#line 692 "simple.cc" // lalr1.cc:859
    break;

  case 18:
#line 168 "grammar.y" // lalr1.cc:859
    {
        // TASK: Abort if the datatype of a_expr and a_term differ.
        // TASK: Complete support for OP_SUB and OP_FSUB. See OP_ADD and OP_FADD code above.
        symbol_t * res;
        if (yystack_[2].value.as< symbol_t* > ()->datatype == DTYPE_INT)
        {
          res = make_temp (symtab, yystack_[2].value.as< symbol_t* > ()->datatype);
          itab_instruction_add (itab, OP_SUB, res->addr, yystack_[2].value.as< symbol_t* > ()->addr, yystack_[0].value.as< symbol_t* > ()->addr);
        }
        if (yystack_[2].value.as< symbol_t* > ()->datatype == DTYPE_FLOAT)
        {
          // TASK: Modify this semantic action to support both DTYPE_INT and DTYPE_FLOAT.
          // For DTYPE_FLOAT you should generate an OP_FSUB instruction.
          res = make_temp (symtab, yystack_[2].value.as< symbol_t* > ()->datatype);
          itab_instruction_add (itab, OP_FSUB, res->addr, yystack_[2].value.as< symbol_t* > ()->addr, yystack_[0].value.as< symbol_t* > ()->addr);
        }
        yylhs.value.as< symbol_t* > () = res;
        #ifdef _SMP_DEBUG_
        cout << "On a_expr (2)\n";
        #endif
      }
#line 718 "simple.cc" // lalr1.cc:859
    break;

  case 19:
#line 190 "grammar.y" // lalr1.cc:859
    {
        yylhs.value.as< symbol_t* > () = yystack_[0].value.as< symbol_t* > ();
        #ifdef _SMP_DEBUG_
        cout << "On a_expr (3)\n";
        #endif
      }
#line 729 "simple.cc" // lalr1.cc:859
    break;

  case 20:
#line 199 "grammar.y" // lalr1.cc:859
    {
        // TASK: Abort if the datatype of a_expr and a_term differ.
        // TASK: Complete support for OP_SUB and OP_FSUB. See OP_ADD and OP_FADD code above.
        symbol_t * res;
        if (yystack_[2].value.as< symbol_t* > ()->datatype == DTYPE_INT)
        {
          res = make_temp (symtab, yystack_[2].value.as< symbol_t* > ()->datatype);
          itab_instruction_add (itab, OP_MUL, res->addr, yystack_[2].value.as< symbol_t* > ()->addr, yystack_[0].value.as< symbol_t* > ()->addr);
        }
        if (yystack_[2].value.as< symbol_t* > ()->datatype == DTYPE_FLOAT)
        {
          // TASK: Modify this semantic action to support both DTYPE_INT and DTYPE_FLOAT.
          // For DTYPE_FLOAT you should generate an OP_FMUL instruction.
          res = make_temp (symtab, yystack_[2].value.as< symbol_t* > ()->datatype);
          itab_instruction_add (itab, OP_FMUL, res->addr, yystack_[2].value.as< symbol_t* > ()->addr, yystack_[0].value.as< symbol_t* > ()->addr);
        }
        yylhs.value.as< symbol_t* > () = res;
      }
#line 752 "simple.cc" // lalr1.cc:859
    break;

  case 21:
#line 218 "grammar.y" // lalr1.cc:859
    {
        // TASK: Abort if the datatype of a_expr and a_term differ.
        // TASK: Complete support for OP_SUB and OP_FSUB. See OP_ADD and OP_FADD code above.
        symbol_t * res;
        if (yystack_[2].value.as< symbol_t* > ()->datatype == DTYPE_INT)
        {
          res = make_temp (symtab, yystack_[2].value.as< symbol_t* > ()->datatype);
          itab_instruction_add (itab, OP_DIV, res->addr, yystack_[2].value.as< symbol_t* > ()->addr, yystack_[0].value.as< symbol_t* > ()->addr);
        }
        if (yystack_[2].value.as< symbol_t* > ()->datatype == DTYPE_FLOAT)
        {
          // TASK: Modify this semantic action to support both DTYPE_INT and DTYPE_FLOAT.
          // For DTYPE_FLOAT you should generate an OP_FDIV instruction.
          res = make_temp (symtab, yystack_[2].value.as< symbol_t* > ()->datatype);
          itab_instruction_add (itab, OP_FDIV, res->addr, yystack_[2].value.as< symbol_t* > ()->addr, yystack_[0].value.as< symbol_t* > ()->addr);
        }
        yylhs.value.as< symbol_t* > () = res;
        
      }
#line 776 "simple.cc" // lalr1.cc:859
    break;

  case 22:
#line 238 "grammar.y" // lalr1.cc:859
    {
        yylhs.value.as< symbol_t* > () = yystack_[0].value.as< symbol_t* > ();
        #ifdef _SMP_DEBUG_
        cout << "On a_term (3)\n";
        #endif
      }
#line 787 "simple.cc" // lalr1.cc:859
    break;

  case 23:
#line 247 "grammar.y" // lalr1.cc:859
    {
        symbol_t * res;
        assert (yystack_[0].value.as< symbol_t* > () && "Did not find variable");
        res = make_temp (symtab, yystack_[0].value.as< symbol_t* > ()->datatype);
        itab_instruction_add (itab, OP_LOAD, res->addr, yystack_[0].value.as< symbol_t* > ()->datatype, yystack_[0].value.as< symbol_t* > ()->addr);
        yylhs.value.as< symbol_t* > () = res;
      }
#line 799 "simple.cc" // lalr1.cc:859
    break;

  case 24:
#line 255 "grammar.y" // lalr1.cc:859
    {
        symbol_t * res;
        res = make_temp (symtab, DTYPE_INT);
        *(int*)(static_mem+stptr) = yystack_[0].value.as< int > ();
        itab_instruction_add (itab, OP_LOADCST, res->addr, res->datatype, stptr);
        stptr+=4;
        yylhs.value.as< symbol_t* > () = res;
      }
#line 812 "simple.cc" // lalr1.cc:859
    break;

  case 25:
#line 264 "grammar.y" // lalr1.cc:859
    { 
        // TASK: Complete implementation in a fashion similar to the rule a_fact -> T_INTEGER. 
        symbol_t * res;
        res = make_temp (symtab, DTYPE_FLOAT);
        *(float*)(static_mem+stptr) = yystack_[0].value.as< float > ();
        itab_instruction_add (itab, OP_LOADCST, res->addr, res->datatype, stptr);
        stptr+=4;
        yylhs.value.as< symbol_t* > () = res;
      }
#line 826 "simple.cc" // lalr1.cc:859
    break;

  case 26:
#line 273 "grammar.y" // lalr1.cc:859
    { yylhs.value.as< symbol_t* > () = yystack_[1].value.as< symbol_t* > (); }
#line 832 "simple.cc" // lalr1.cc:859
    break;

  case 27:
#line 275 "grammar.y" // lalr1.cc:859
    {
        symbol_t * res;
        res = make_temp (symtab, yystack_[0].value.as< symbol_t* > ()->datatype);
        itab_instruction_add (itab, OP_UMIN, res->addr, yystack_[0].value.as< symbol_t* > ()->datatype, yystack_[0].value.as< symbol_t* > ()->addr);
        yylhs.value.as< symbol_t* > () = res;
      }
#line 843 "simple.cc" // lalr1.cc:859
    break;

  case 28:
#line 282 "grammar.y" // lalr1.cc:859
    {
        yylhs.value.as< symbol_t* > () = NULL;
      }
#line 851 "simple.cc" // lalr1.cc:859
    break;

  case 29:
#line 288 "grammar.y" // lalr1.cc:859
    {
    symbol_t * sym = symbol_find (symtab, yystack_[1].value.as< string > ());
    assert (sym && "Ooops: Did not find variable!");
    yylhs.value.as< symbol_t* > () = sym;
  }
#line 861 "simple.cc" // lalr1.cc:859
    break;

  case 30:
#line 294 "grammar.y" // lalr1.cc:859
    { yylhs.value.as< symbol_t* > () = yystack_[1].value.as< symbol_t* > (); }
#line 867 "simple.cc" // lalr1.cc:859
    break;

  case 31:
#line 295 "grammar.y" // lalr1.cc:859
    { yylhs.value.as< symbol_t* > () = NULL; }
#line 873 "simple.cc" // lalr1.cc:859
    break;

  case 32:
#line 299 "grammar.y" // lalr1.cc:859
    {
      vector_itersym_t iter;
      int ii = 0;
      for (iter = yystack_[0].value.as< vector<symbol_t*>  > ().begin (); iter != yystack_[0].value.as< vector<symbol_t*>  > ().end (); iter++, ii++)
      {
        #ifdef _SMP_DEBUG_
        cout << "Symbol to read (" << ii << "):";
        symbol_show (*iter);
        #endif
        itab_instruction_add (itab, OP_READ, (*iter)->addr, (*iter)->datatype, NOARG);
      }
    }
#line 890 "simple.cc" // lalr1.cc:859
    break;

  case 33:
#line 314 "grammar.y" // lalr1.cc:859
    {
      vector_itersym_t iter;
      int ii = 0;
      for (iter = yystack_[0].value.as< vector<symbol_t*>  > ().begin (); iter != yystack_[0].value.as< vector<symbol_t*>  > ().end (); iter++, ii++)
      {
        #ifdef _SMP_DEBUG_
        cout << "Symbol to write(" << ii << "):";
        symbol_show (*iter);
        #endif
        itab_instruction_add (itab, OP_WRITE, (*iter)->addr, (*iter)->datatype, NOARG);
      }
    }
#line 907 "simple.cc" // lalr1.cc:859
    break;

  case 34:
#line 328 "grammar.y" // lalr1.cc:859
    { yystack_[2].value.as< vector<symbol_t*>  > ().push_back (yystack_[0].value.as< symbol_t* > ()); yylhs.value.as< vector<symbol_t*>  > () = yystack_[2].value.as< vector<symbol_t*>  > (); }
#line 913 "simple.cc" // lalr1.cc:859
    break;

  case 35:
#line 329 "grammar.y" // lalr1.cc:859
    { yylhs.value.as< vector<symbol_t*>  > ().push_back (yystack_[0].value.as< symbol_t* > ()); }
#line 919 "simple.cc" // lalr1.cc:859
    break;

  case 36:
#line 333 "grammar.y" // lalr1.cc:859
    { 
      yystack_[2].value.as< vector<symbol_t*>  > ().push_back (yystack_[0].value.as< symbol_t* > ()); yylhs.value.as< vector<symbol_t*>  > () = yystack_[2].value.as< vector<symbol_t*>  > (); 
      #ifdef _SMP_DEBUG_
      cout << "In expr_list (1)\n";
      #endif
    }
#line 930 "simple.cc" // lalr1.cc:859
    break;

  case 37:
#line 340 "grammar.y" // lalr1.cc:859
    { 
      yylhs.value.as< vector<symbol_t*>  > ().push_back (yystack_[0].value.as< symbol_t* > ()); 
      #ifdef _SMP_DEBUG_
      cout << "In expr_list (2)\n";
      #endif
    }
#line 941 "simple.cc" // lalr1.cc:859
    break;


#line 945 "simple.cc" // lalr1.cc:859
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
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
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
    yyerror_range[1].location = yystack_[yylen - 1].location;
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

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

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
  simple_parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what());
  }

  // Generate an error message.
  std::string
  simple_parser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
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


  const signed char simple_parser::yypact_ninf_ = -24;

  const signed char simple_parser::yytable_ninf_ = -1;

  const signed char
  simple_parser::yypact_[] =
  {
      32,   -24,   -24,    -7,     2,   -15,    32,    30,    21,   -24,
     -24,   -24,   -24,    35,    -8,   -24,   -24,   -24,    25,     2,
     -24,   -24,   -24,     2,    23,    24,   -24,   -24,    38,     2,
     -24,     7,   -24,    32,   -24,    31,     2,    -7,   -24,    -1,
       2,     2,     2,     2,     2,     6,    32,   -24,   -24,   -24,
      10,   -24,   -24,    24,    24,   -24,   -24,    23,   -24,    50,
       2,    23
  };

  const unsigned char
  simple_parser::yydefact_[] =
  {
       0,    15,    16,     0,     0,    31,     0,     0,     0,     4,
       9,     5,     8,    14,     0,     6,     7,    35,    32,     0,
      28,    24,    25,     0,    37,    19,    22,    23,    33,     0,
      29,     0,     1,     2,    13,     0,     0,     0,    27,     0,
       0,     0,     0,     0,     0,     0,     0,    10,     3,    12,
       0,    34,    26,    17,    18,    20,    21,    36,    30,     0,
       0,    11
  };

  const signed char
  simple_parser::yypgoto_[] =
  {
     -24,   -24,    49,   -23,   -24,   -24,   -24,   -24,   -24,   -22,
       9,   -17,     0,   -24,   -24,   -24,   -24,   -24
  };

  const signed char
  simple_parser::yydefgoto_[] =
  {
      -1,     7,     8,     9,    10,    11,    12,    35,    13,    24,
      25,    26,    27,    30,    15,    16,    18,    28
  };

  const unsigned char
  simple_parser::yytable_[] =
  {
      14,    39,    38,    17,    40,    41,    14,    45,    19,     5,
      48,    40,    41,    20,    50,    40,    41,    29,     5,    21,
      22,    46,    57,    48,    36,    55,    56,    47,    40,    41,
      32,    42,    43,    14,    52,    33,    23,    51,    61,    58,
      37,     1,     2,    59,     3,     4,    14,    49,     5,    53,
      54,     6,    34,    44,    60,    31
  };

  const unsigned char
  simple_parser::yycheck_[] =
  {
       0,    23,    19,     3,     5,     6,     6,    29,     6,    16,
      33,     5,     6,    11,    36,     5,     6,    32,    16,    17,
      18,    14,    44,    46,    32,    42,    43,    20,     5,     6,
       0,     7,     8,    33,    35,    14,    34,    37,    60,    33,
      15,     9,    10,    33,    12,    13,    46,    16,    16,    40,
      41,    19,    17,    15,     4,     6
  };

  const unsigned char
  simple_parser::yystos_[] =
  {
       0,     9,    10,    12,    13,    16,    19,    37,    38,    39,
      40,    41,    42,    44,    48,    50,    51,    48,    52,     6,
      11,    17,    18,    34,    45,    46,    47,    48,    53,    32,
      49,    38,     0,    14,    17,    43,    32,    15,    47,    45,
       5,     6,     7,     8,    15,    45,    14,    20,    39,    16,
      45,    48,    35,    46,    46,    47,    47,    45,    33,    33,
       4,    45
  };

  const unsigned char
  simple_parser::yyr1_[] =
  {
       0,    36,    37,    38,    38,    39,    39,    39,    39,    39,
      40,    41,    42,    43,    43,    44,    44,    45,    45,    45,
      46,    46,    46,    47,    47,    47,    47,    47,    47,    48,
      49,    49,    50,    51,    52,    52,    53,    53
  };

  const unsigned char
  simple_parser::yyr2_[] =
  {
       0,     2,     2,     3,     1,     1,     1,     1,     1,     1,
       3,     6,     3,     1,     0,     1,     1,     3,     3,     1,
       3,     3,     1,     1,     1,     1,     3,     2,     1,     2,
       3,     0,     2,     2,     3,     1,     3,     1
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const simple_parser::yytname_[] =
  {
  "T_EOF", "error", "$undefined", "T_NUM", "T_ASSIGN", "T_ADD", "T_SUB",
  "T_MUL", "T_DIV", "T_DT_INT", "T_DT_FLOAT", "T_LITERAL_STR", "T_READ",
  "T_WRITE", "T_SEMICOLON", "T_COMMA", "T_ID", "T_INTEGER", "T_FLOAT",
  "T_BEGIN", "T_END", "T_REPEAT", "T_UNTIL", "T_DO", "T_WHILE", "T_IF",
  "T_THEN", "T_ELSE", "T_LPAR", "T_RPAR", "T_LT", "T_GT", "'['", "']'",
  "'('", "')'", "$accept", "program", "stmt_list", "stmt", "block",
  "assignment", "declaration", "array_size", "datatype", "a_expr",
  "a_term", "a_fact", "varref", "index", "read", "write", "varlist",
  "expr_list", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short int
  simple_parser::yyrline_[] =
  {
       0,    93,    93,    96,    97,   100,   101,   102,   103,   104,
     107,   114,   121,   131,   132,   135,   136,   141,   167,   189,
     198,   217,   237,   246,   254,   263,   273,   274,   281,   287,
     294,   295,   298,   313,   328,   329,   332,   339
  };

  // Print the state stack on the debug stream.
  void
  simple_parser::yystack_print_ ()
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
  simple_parser::yy_reduce_print_ (int yyrule)
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



} // yy
#line 1354 "simple.cc" // lalr1.cc:1167
#line 348 "grammar.y" // lalr1.cc:1168


void yy::simple_parser::error (const yy::location & l, const std::string & s) {
	std::cerr << "Simple Parser error at " << l << " : " << s << std::endl;
}

