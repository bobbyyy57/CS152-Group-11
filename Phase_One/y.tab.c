/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser_temp.y" /* yacc.c:339  */

extern int yyparse();
extern int yylex();

#include <stdio.h>
#include "Types.h"
#include <string.h>

extern FILE* yyin;
extern int row, col;

void yyerror(const char* msg) {
    printf("ERROR: Row %d, Col %d, %s\n", row, col, msg);
}

char *identToken;
int numberToken;
int  count_names = 0;

using namespace std;

struct Symbol {
  std::string name;
  Type type;
};
struct Function {
  std::string name;
  std::vector<Symbol> declarations;
  std::vector<Type> params;
  Type return_type;
};

std::vector <Function> symbol_table;


Function *get_function() {
  int last = symbol_table.size()-1;
  return &symbol_table[last];
}

bool find(std::string &value) {
  Function *f = get_function();
  for(int i=0; i < f->declarations.size(); i++) {
    Symbol *s = &f->declarations[i];
    if (s->name == value) {
      return true;
    }
  }
  return false;
}

bool find_function(std::string value, vector<Type> paramTypes) {
  for (int i = 0; i < symbol_table.size(); i++) {
      if (symbol_table[i].name == value && symbol_table[i].params == paramTypes) return true;
    }
    return false;
}

bool find_function_name(std::string value) {
    for (int i = 0; i < symbol_table.size(); i++) {
      if (symbol_table[i].name == value) return true;
    }
    return false;
}

void add_function_to_symbol_table(std::string &value, Type t) {
  Function f; 
  f.name = value; 
  f.return_type = t;
  symbol_table.push_back(f);
}

int add_param_to_function(Type type) {
    Function* f = get_function();
    f->params.push_back(type);
    return f->params.size() - 1;
}

void add_variable_to_symbol_table(std::string &value, Type t) {
  Symbol s;
  s.name = value;
  s.type = t;
  Function *f = get_function();
  f->declarations.push_back(s);
}

void print_symbol_table(void) {
  printf("symbol table:\n");
  printf("--------------------\n");
  for(int i=0; i<symbol_table.size(); i++) {
    printf("function: %s\n", symbol_table[i].name.c_str());
    for(int j=0; j<symbol_table[i].declarations.size(); j++) {
      printf("  locals: %s\n", symbol_table[i].declarations[j].name.c_str());
    }
  }
  printf("--------------------\n");
}



#line 167 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INTEGER = 258,
    STRING = 259,
    ARRAY = 260,
    FUNCTION = 261,
    IF = 262,
    ELSE = 263,
    WHILE = 264,
    READ = 265,
    WRITE = 266,
    ELSEIF = 267,
    GTE = 268,
    LTE = 269,
    ISEQ = 270,
    NOTEQ = 271,
    AND = 272,
    OR = 273,
    RETURN = 274,
    VAR = 275,
    INT = 276
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 102 "parser_temp.y" /* yacc.c:355  */

    int val;
    char* name;
    struct Node* cn;

#line 235 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 252 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   149

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  76
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  141

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   276

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      33,    34,    24,    22,    32,    23,     2,    25,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    26,
      36,    27,    35,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    28,     2,    29,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    30,     2,    31,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   130,   130,   134,   137,   142,   145,   146,   147,   148,
     149,   150,   151,   157,   158,   161,   162,   164,   175,   194,
     197,   200,   210,   213,   222,   225,   226,   231,   238,   248,
     256,   260,   263,   266,   285,   290,   293,   297,   305,   324,
     328,   334,   338,   344,   352,   355,   364,   368,   372,   376,
     380,   384,   390,   395,   404,   412,   421,   422,   423,   425,
     426,   433,   440,   445,   447,   460,   462,   463,   465,   466,
     468,   470,   474,   483,   484,   486,   487
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTEGER", "STRING", "ARRAY", "FUNCTION",
  "IF", "ELSE", "WHILE", "READ", "WRITE", "ELSEIF", "GTE", "LTE", "ISEQ",
  "NOTEQ", "AND", "OR", "RETURN", "VAR", "INT", "'+'", "'-'", "'*'", "'/'",
  "';'", "'='", "'['", "']'", "'{'", "'}'", "','", "'('", "')'", "'>'",
  "'<'", "$accept", "variable", "start", "func_decl", "statements",
  "statement", "var_decl", "cond", "loop", "io", "assignment", "return",
  "var_type", "arr_len", "value", "set_val", "exp", "as", "mult", "md",
  "factor", "p", "values", "params", "func_temp", "elseif", "else",
  "conditions", "condition", "conditional", "array", "func_params",
  "index", "arr_vals", "named_values", "params_temp", "func_params_temp", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,    43,    45,    42,    47,    59,    61,    91,    93,
     123,   125,    44,    40,    41,    62,    60
};
# endif

#define YYPACT_NINF -43

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-43)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      30,   -43,    30,     5,   -43,    16,   -16,    60,   -43,    34,
      30,   -43,   -43,   -43,   -43,   -43,   -43,    34,    19,     2,
     -43,    26,    30,    59,   -43,    39,    43,    34,    -3,    -3,
      14,    46,    59,    48,   -43,   -43,    57,    64,    68,    34,
      71,    74,    83,    83,   -43,   103,    -3,   -43,    28,    81,
     -43,   -43,   -43,   -43,   -43,   -43,    28,    91,    52,    30,
     -43,   -43,   -43,   -43,   -43,    71,    -3,   -43,   -43,    83,
      28,    73,    23,    90,   -43,    89,    94,    53,   -43,   -43,
      -3,   -43,   -43,    -3,    97,   -43,   -43,    88,   -43,   -43,
     -43,    28,    53,    10,    98,   -43,   -43,   -43,   -43,    83,
      83,   -43,   -43,    -3,   100,    -1,   -43,   -43,    81,   -43,
     -43,    52,   -43,    -3,    59,   -43,   -43,    28,    59,   -43,
     -43,    95,    96,   101,   -43,    41,   -43,   105,   108,   -43,
     -43,    59,    83,   106,   102,   -43,   109,    59,   107,    41,
     -43
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,    13,     0,     0,     2,     0,     0,     0,     1,     0,
      32,    70,    72,    15,    14,    16,    29,     0,     0,    31,
      33,     0,    32,     5,    30,     0,     0,     0,     0,     0,
      59,     0,     5,     0,     7,     8,     0,     0,     0,     0,
      20,     0,     0,     0,    52,     0,     0,    56,    53,    22,
      24,    25,    26,    57,    55,    58,    54,     0,     0,    27,
       4,     6,     9,    10,    11,    20,     0,    18,    12,     0,
      44,     0,    35,     0,    74,    76,     0,     0,    68,    69,
       0,    66,    67,     0,     0,    60,    63,     0,    64,    28,
      17,    19,    44,     0,     0,    48,    49,    50,    51,     0,
       0,    46,    47,     0,     0,     0,    73,    65,    21,    23,
      71,     0,    62,     0,     5,    36,    37,    43,     5,    75,
      61,    43,     0,     0,    45,    42,    34,     0,     0,    38,
      40,     5,     0,     0,     0,    41,     0,     5,     0,    42,
      39
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -43,     4,   -43,    82,   -30,   -43,   -43,   -43,   -43,   -43,
     -43,   -43,     6,   -43,     0,    75,   -14,   -43,    62,   -43,
      61,   -43,   -42,   121,   -43,     7,   -43,   -39,    76,    54,
     -43,    37,   -43,    44,   -23,   -43,   -22
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    30,     3,     4,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    14,    47,    67,    70,    80,    49,    83,
      50,    51,    52,    18,     6,   129,   130,    71,    72,   103,
      53,    88,    85,    76,    54,    19,    55
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      40,    41,    60,    75,    73,     8,     5,    15,     7,    40,
      41,    13,    10,    16,    48,    56,    17,    11,    12,    11,
      12,    20,     9,    95,    96,    97,    98,    45,    17,    45,
      46,    44,    77,     1,    22,     2,    95,    96,    97,    98,
      99,   100,    57,    65,    87,   101,   102,    58,    21,   127,
      78,    79,    91,   128,    11,    92,    23,    84,   101,   102,
     115,   116,     1,    75,     2,     5,    25,    42,    26,    27,
      28,    43,    11,    12,    61,    78,    79,    59,    29,    11,
      11,    12,    45,    62,   122,    46,    86,   107,   123,   117,
      63,    40,    41,   134,    64,    40,    41,    87,    66,   121,
      68,   133,    94,    11,    12,    81,    82,   138,    40,    41,
      78,    79,    12,    45,    40,    41,    69,    78,    79,   104,
     111,   105,   112,    11,    12,   106,   110,   125,   114,   124,
     118,   136,   126,    45,    74,   131,   132,   135,   139,   137,
      90,    89,   108,    24,   109,    93,   140,   113,   120,   119
};

static const yytype_uint8 yycheck[] =
{
      23,    23,    32,    45,    43,     0,     0,     7,     2,    32,
      32,     7,    28,     9,    28,    29,    10,    20,    21,    20,
      21,    17,     6,    13,    14,    15,    16,    30,    22,    30,
      33,    27,    46,     3,    32,     5,    13,    14,    15,    16,
      17,    18,    28,    39,    58,    35,    36,    33,    29,     8,
      22,    23,    66,    12,    20,    69,    30,    57,    35,    36,
      99,   100,     3,   105,     5,    59,     7,    28,     9,    10,
      11,    28,    20,    21,    26,    22,    23,    31,    19,    20,
      20,    21,    30,    26,   114,    33,    34,    34,   118,   103,
      26,   114,   114,   132,    26,   118,   118,   111,    27,   113,
      26,   131,    29,    20,    21,    24,    25,   137,   131,   131,
      22,    23,    21,    30,   137,   137,    33,    22,    23,    29,
      32,    32,    34,    20,    21,    31,    29,    31,    30,    34,
      30,    29,    31,    30,    31,    30,    28,    31,    31,    30,
      65,    59,    80,    22,    83,    69,   139,    93,   111,   105
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     5,    39,    40,    49,    61,    49,     0,     6,
      28,    20,    21,    38,    50,    51,    38,    49,    60,    72,
      38,    29,    32,    30,    60,     7,     9,    10,    11,    19,
      38,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      71,    73,    28,    28,    38,    30,    33,    51,    53,    55,
      57,    58,    59,    67,    71,    73,    53,    28,    33,    31,
      41,    26,    26,    26,    26,    38,    27,    52,    26,    33,
      53,    64,    65,    64,    31,    59,    70,    53,    22,    23,
      54,    24,    25,    56,    51,    69,    34,    53,    68,    40,
      52,    53,    53,    65,    29,    13,    14,    15,    16,    17,
      18,    35,    36,    66,    29,    32,    31,    34,    55,    57,
      29,    32,    34,    66,    30,    64,    64,    53,    30,    70,
      68,    53,    41,    41,    34,    31,    31,     8,    12,    62,
      63,    30,    28,    41,    64,    31,    29,    30,    41,    31,
      62
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    37,    39,    39,    41,    41,    42,    42,    42,    42,
      42,    42,    42,    49,    49,    50,    50,    43,    47,    52,
      52,    53,    53,    55,    55,    57,    57,    40,    40,    61,
      60,    60,    60,    72,    45,    64,    64,    64,    44,    62,
      62,    63,    63,    65,    65,    65,    66,    66,    66,    66,
      66,    66,    46,    46,    48,    59,    59,    59,    59,    71,
      71,    68,    68,    68,    73,    58,    56,    56,    54,    54,
      38,    69,    51,    67,    67,    70,    70
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,     0,     2,     1,     1,     2,
       2,     2,     2,     1,     3,     1,     1,     3,     2,     2,
       0,     3,     1,     3,     1,     1,     1,     7,     8,     3,
       3,     1,     0,     2,     7,     1,     3,     3,     8,     8,
       1,     4,     0,     3,     1,     5,     1,     1,     1,     1,
       1,     1,     2,     2,     2,     1,     1,     1,     1,     1,
       3,     3,     2,     1,     3,     3,     1,     1,     1,     1,
       1,     2,     1,     3,     2,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 130 "parser_temp.y" /* yacc.c:1646  */
    {
  (yyval.cn) = (yyvsp[0].cn);
  // print_symbol_table();
  printf("%s", (yyval.cn)->code.c_str());}
#line 1430 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 134 "parser_temp.y" /* yacc.c:1646  */
    {Node* node = new Node; node->name = node->code = ""; (yyval.cn) = node;}
#line 1436 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 137 "parser_temp.y" /* yacc.c:1646  */
    {
  Node* node = new Node;
  node->code = (yyvsp[-1].cn)->code + (yyvsp[0].cn)->code;
  (yyval.cn) = node;
}
#line 1446 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 142 "parser_temp.y" /* yacc.c:1646  */
    {(yyval.cn) = new Node;}
#line 1452 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 145 "parser_temp.y" /* yacc.c:1646  */
    {(yyval.cn) = (yyvsp[-1].cn);}
#line 1458 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 146 "parser_temp.y" /* yacc.c:1646  */
    {(yyval.cn) = (yyvsp[0].cn);}
#line 1464 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 147 "parser_temp.y" /* yacc.c:1646  */
    {(yyval.cn) = (yyvsp[0].cn);}
#line 1470 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 148 "parser_temp.y" /* yacc.c:1646  */
    {(yyval.cn) = (yyvsp[-1].cn);}
#line 1476 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 149 "parser_temp.y" /* yacc.c:1646  */
    {(yyval.cn) = (yyvsp[-1].cn);}
#line 1482 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 150 "parser_temp.y" /* yacc.c:1646  */
    {(yyval.cn) = (yyvsp[-1].cn);}
#line 1488 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 151 "parser_temp.y" /* yacc.c:1646  */
    {
    (yyval.cn) = (yyvsp[-1].cn);
  }
#line 1496 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 157 "parser_temp.y" /* yacc.c:1646  */
    {(yyval.cn) = new Node; (yyval.cn)->type = Integer;}
#line 1502 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 158 "parser_temp.y" /* yacc.c:1646  */
    {(yyval.cn) = new Node; (yyval.cn)->type = Array; (yyval.cn)->code = (yyvsp[0].cn)->code; (yyval.cn)->name = (yyvsp[0].cn)->name;}
#line 1508 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 161 "parser_temp.y" /* yacc.c:1646  */
    {(yyval.cn) = (yyvsp[0].cn);}
#line 1514 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 162 "parser_temp.y" /* yacc.c:1646  */
    {(yyval.cn) = (yyvsp[0].cn);}
#line 1520 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 164 "parser_temp.y" /* yacc.c:1646  */
    { // Set type
  (yyval.cn) = (yyvsp[-2].cn);
  if ((yyvsp[-2].cn)->type == Array) {
    (yyval.cn)->code += ".[] " + (yyvsp[-1].cn)->name + ", " + (yyvsp[-2].cn)->name + "\n";
  }
  else {(yyval.cn)->code += ". " + (yyvsp[-1].cn)->name + "\n";}
  (yyval.cn)->code += (yyvsp[0].cn)->code;
}
#line 1533 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 175 "parser_temp.y" /* yacc.c:1646  */
    {
  Node* node = new Node;
  // node->code = ". " + string($1->name);
  if (strlen((yyvsp[0].cn)->name.c_str()) > 0) {
    node->code = (yyvsp[0].cn)->code;
    node->code += (yyvsp[-1].cn)->code;

//node->code += "named_values-type: " + typeof($1) + " " + "set_val: " + $2->name + "\n";
    if ((yyvsp[-1].cn)->type == Array) {
      node->code += "[]= " + (yyvsp[-1].cn)->name + ", " + (yyvsp[-1].cn)->index + ", " + (yyvsp[0].cn)->name + "\n";
    }
    else {
      node->code += "= " + (yyvsp[-1].cn)->name + ", " + (yyvsp[0].cn)->name + "\n";
    }
  }
  (yyval.cn) = node; 
}
#line 1555 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 194 "parser_temp.y" /* yacc.c:1646  */
    {
  (yyval.cn) = (yyvsp[0].cn);
}
#line 1563 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 197 "parser_temp.y" /* yacc.c:1646  */
    {(yyval.cn) = new Node;}
#line 1569 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 200 "parser_temp.y" /* yacc.c:1646  */
    { // Type checking
  Node* res = new Node;
  res->name="addtemp";
  res->code = (yyvsp[0].cn)->code;
  res->code += (yyvsp[-2].cn)->code;
  res->code += ". " + res->name + " \n";	
  res->code += (yyvsp[-1].cn)->name + " " +  res->name + ", " + (yyvsp[-2].cn)->name + ", " + (yyvsp[0].cn)->name + " \n";
  (yyval.cn) = res;
  (yyval.cn)->type = Integer;
}
#line 1584 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 210 "parser_temp.y" /* yacc.c:1646  */
    {(yyval.cn) = (yyvsp[0].cn); (yyval.cn)->type = Integer; }
#line 1590 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 213 "parser_temp.y" /* yacc.c:1646  */
    {
  Node* res = new Node;
  res->name="multtemp";
  res->code = (yyvsp[0].cn)->code;
  res->code += (yyvsp[-2].cn)->code;
  res->code += ". multtemp\n";
  res->code += (yyvsp[-1].cn)->name + " " + res->name + ", " + (yyvsp[-2].cn)->name + ", " + (yyvsp[0].cn)->name + " \n";
  (yyval.cn) = res;
}
#line 1604 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 222 "parser_temp.y" /* yacc.c:1646  */
    {(yyval.cn) = (yyvsp[0].cn);}
#line 1610 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 225 "parser_temp.y" /* yacc.c:1646  */
    {(yyval.cn) = (yyvsp[0].cn);}
#line 1616 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 226 "parser_temp.y" /* yacc.c:1646  */
    {(yyval.cn) = (yyvsp[0].cn);}
#line 1622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 231 "parser_temp.y" /* yacc.c:1646  */
    {
  Node* node = (yyvsp[-6].cn);
  node->code += (yyvsp[-4].cn)->code;
  node->code += (yyvsp[-1].cn)->code;
  node->code += "endfunc\n";
  (yyval.cn) = node;
}
#line 1634 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 238 "parser_temp.y" /* yacc.c:1646  */
    {
  Node* node = (yyvsp[-7].cn);
  node->code += (yyvsp[-5].cn)->code;
  node->code += (yyvsp[-2].cn)->code;
  node->code += "endfunc\n";
  (yyval.cn) = node;
  (yyval.cn)->code += (yyvsp[0].cn)->code;
}
#line 1647 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 248 "parser_temp.y" /* yacc.c:1646  */
    {
  if (find_function_name((yyvsp[0].cn)->name)) exit(-1);
  add_function_to_symbol_table((yyvsp[0].cn)->name, (yyvsp[-2].cn)->type);
  (yyval.cn) = new Node;
  (yyval.cn)->code = "func " + (yyvsp[0].cn)->name + "\n";
}
#line 1658 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 256 "parser_temp.y" /* yacc.c:1646  */
    {
  (yyval.cn) = (yyvsp[-2].cn);
  (yyval.cn)->code += (yyvsp[0].cn)->code;
}
#line 1667 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 260 "parser_temp.y" /* yacc.c:1646  */
    {
  (yyval.cn) = (yyvsp[0].cn);
}
#line 1675 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 263 "parser_temp.y" /* yacc.c:1646  */
    {(yyval.cn) = new Node;}
#line 1681 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 266 "parser_temp.y" /* yacc.c:1646  */
    {
  if (find((yyvsp[0].cn)->name)) {
    printf("Variable redeclaration at row: %d, col: %d\n", row, col);
    exit(-1);
  };

  int paramInd = add_param_to_function((yyvsp[-1].cn)->type);
  add_variable_to_symbol_table((yyvsp[0].cn)->name, Integer);

  Node* node = new Node;
  node->code = ". " + (yyvsp[0].cn)->name + "\n";
  node->code += "= " + (yyvsp[0].cn)->name + ", $" + to_string(paramInd) + "\n";

  (yyval.cn) = node;
  (yyval.cn)->type = (yyvsp[-1].cn)->type;
}
#line 1702 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 285 "parser_temp.y" /* yacc.c:1646  */
    {
  Node* emp = new Node;
  (yyval.cn) = emp;
}
#line 1711 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 290 "parser_temp.y" /* yacc.c:1646  */
    { 
  (yyval.cn) = (yyvsp[0].cn);
}
#line 1719 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 293 "parser_temp.y" /* yacc.c:1646  */
    {
  Node* emp = new Node;
  (yyval.cn) = emp;
}
#line 1728 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 297 "parser_temp.y" /* yacc.c:1646  */
    {
  Node* emp = new Node;
  (yyval.cn) = emp;
}
#line 1737 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 305 "parser_temp.y" /* yacc.c:1646  */
    {
  Node* node = new Node;
  Node* cond = new Node;
  cond = (yyvsp[-5].cn);

  node->name = "if_true0";
  node->code = cond->code;
  node->code += "?:= " + node->name + ", " + cond->name + "\n"; 

  if (strlen((yyvsp[0].cn)->name.c_str()) <= 0) { 
    node->code += ": " + node->name + "\n";
  }

  node->code += (yyvsp[-2].cn)->code; //+ $8->code;
  node->code += ":= endif\n";
  (yyval.cn) = node;
}
#line 1759 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 324 "parser_temp.y" /* yacc.c:1646  */
    {
  Node* emp = new Node;
  (yyval.cn) = emp;
}
#line 1768 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 328 "parser_temp.y" /* yacc.c:1646  */
    {
  Node* emp = new Node;
  (yyval.cn) = emp;
}
#line 1777 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 334 "parser_temp.y" /* yacc.c:1646  */
    {
  Node* emp = new Node;
  (yyval.cn) = emp;
}
#line 1786 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 338 "parser_temp.y" /* yacc.c:1646  */
    {
  Node* emp = new Node;
  (yyval.cn) = emp;
}
#line 1795 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 344 "parser_temp.y" /* yacc.c:1646  */
    {
  Node* res = new Node;

  res->name = "iftemp";
  res->code += ". " + res->name + "\n";
  res->code += (yyvsp[-1].cn)->name + " " + res->name + ", " + (yyvsp[-2].cn)->name + ", " + (yyvsp[0].cn)->name + "\n";
  (yyval.cn) = res;
}
#line 1808 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 352 "parser_temp.y" /* yacc.c:1646  */
    {
  (yyval.cn) = (yyvsp[0].cn);
}
#line 1816 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 355 "parser_temp.y" /* yacc.c:1646  */
    {
  Node* emp = new Node;
  (yyval.cn) = emp;
}
#line 1825 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 364 "parser_temp.y" /* yacc.c:1646  */
    {
  (yyval.cn) = new Node;
  (yyval.cn)->name = ">";
}
#line 1834 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 368 "parser_temp.y" /* yacc.c:1646  */
    {
  (yyval.cn) = new Node;
  (yyval.cn)->name = "<";
}
#line 1843 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 372 "parser_temp.y" /* yacc.c:1646  */
    {
  (yyval.cn) = new Node;
  (yyval.cn)->name = ">=";
}
#line 1852 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 376 "parser_temp.y" /* yacc.c:1646  */
    {
  (yyval.cn) = new Node;
  (yyval.cn)->name = "<=";
}
#line 1861 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 380 "parser_temp.y" /* yacc.c:1646  */
    {
  (yyval.cn) = new Node;
  (yyval.cn)->name = "==";
}
#line 1870 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 384 "parser_temp.y" /* yacc.c:1646  */
    {
  (yyval.cn) = new Node;
  (yyval.cn)->name = "!=";
}
#line 1879 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 390 "parser_temp.y" /* yacc.c:1646  */
    {
  (yyval.cn) = new Node;
  (yyval.cn)->code = string((yyvsp[0].cn)->code);
  (yyval.cn)->code += ".< " + string((yyvsp[0].cn)->name) + "\n";
}
#line 1889 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 395 "parser_temp.y" /* yacc.c:1646  */
    {
  (yyval.cn) = new Node;
  (yyval.cn)->code = string((yyvsp[0].cn)->code);
  (yyval.cn)->code += ".> " + (yyvsp[0].cn)->name + "\n";
}
#line 1899 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 404 "parser_temp.y" /* yacc.c:1646  */
    {
  (yyval.cn) = (yyvsp[0].cn);
  (yyval.cn)->code += "ret " + (yyvsp[0].cn)->name + "\n";
}
#line 1908 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 412 "parser_temp.y" /* yacc.c:1646  */
    {
  (yyval.cn) = (yyvsp[0].cn);
  if ((yyvsp[0].cn)->type == Array) {
    (yyval.cn)->code += ". valtemp\n";
    (yyval.cn)->code += "=[] valtemp, " + (yyvsp[0].cn)->name + ", " + (yyvsp[0].cn)->index + "\n";
    (yyval.cn)->name = "valtemp";
    (yyval.cn)->type = Integer;
  }
}
#line 1922 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 421 "parser_temp.y" /* yacc.c:1646  */
    {(yyval.cn) = (yyvsp[0].cn);}
#line 1928 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 422 "parser_temp.y" /* yacc.c:1646  */
    {(yyval.cn) = (yyvsp[0].cn);}
#line 1934 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 423 "parser_temp.y" /* yacc.c:1646  */
    {(yyval.cn) = (yyvsp[0].cn);}
#line 1940 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 425 "parser_temp.y" /* yacc.c:1646  */
    {(yyval.cn) = (yyvsp[0].cn);}
#line 1946 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 426 "parser_temp.y" /* yacc.c:1646  */
    { // CHECK VAR IS THERE
  (yyval.cn) = (yyvsp[-2].cn);
  (yyval.cn)->type = Array;
  (yyval.cn)->index = (yyvsp[0].cn)->name;
}
#line 1956 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 433 "parser_temp.y" /* yacc.c:1646  */
    {
  (yyval.cn) = (yyvsp[-2].cn);
  (yyval.cn)->code += "param " + (yyvsp[-2].cn)->name + "\n";
  (yyval.cn)->code += (yyvsp[0].cn)->code;
  (yyval.cn)->paramTypes = (yyvsp[0].cn)->paramTypes;
  (yyval.cn)->paramTypes.insert((yyval.cn)->paramTypes.begin(), (yyvsp[-2].cn)->type);
}
#line 1968 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 440 "parser_temp.y" /* yacc.c:1646  */
    {
  (yyval.cn) = (yyvsp[-1].cn);
  (yyval.cn)->code += "param " + (yyvsp[-1].cn)->name + "\n";
  (yyval.cn)->paramTypes.push_back((yyvsp[-1].cn)->type);
}
#line 1978 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 445 "parser_temp.y" /* yacc.c:1646  */
    {(yyval.cn) = new Node; (yyval.cn)->code = "";}
#line 1984 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 447 "parser_temp.y" /* yacc.c:1646  */
    { // Check return types
  print_symbol_table();
  (yyval.cn) = new Node;
  (yyval.cn)->code = ". temp0\n";
  (yyval.cn)->code += (yyvsp[0].cn)->code;
  (yyval.cn)->code += "call " + (yyvsp[-2].cn)->name + ", temp0\n";
  (yyval.cn)->name = "temp0";
  if (!find_function((yyvsp[-2].cn)->name, (yyvsp[0].cn)->paramTypes)) {
    printf("No valid function with provided parameters row: %d, col: %d\n", row, col);
    exit(-1);
  }
}
#line 2001 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 460 "parser_temp.y" /* yacc.c:1646  */
    {(yyval.cn) = (yyvsp[-1].cn);}
#line 2007 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 462 "parser_temp.y" /* yacc.c:1646  */
    {(yyval.cn) = new Node; (yyval.cn)->name = "*";}
#line 2013 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 463 "parser_temp.y" /* yacc.c:1646  */
    {(yyval.cn) = new Node; (yyval.cn)->name = "/";}
#line 2019 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 465 "parser_temp.y" /* yacc.c:1646  */
    {(yyval.cn) = new Node; (yyval.cn)->name = "+";}
#line 2025 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 466 "parser_temp.y" /* yacc.c:1646  */
    {(yyval.cn) = new Node; (yyval.cn)->name = "-";}
#line 2031 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 468 "parser_temp.y" /* yacc.c:1646  */
    {(yyval.cn) = new Node; (yyval.cn)->name = (yyvsp[0].name);}
#line 2037 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 470 "parser_temp.y" /* yacc.c:1646  */
    {
  (yyval.cn) = (yyvsp[-1].cn);
}
#line 2045 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 474 "parser_temp.y" /* yacc.c:1646  */
    {
  (yyval.cn) = new Node;
  // $$->code = ". inttemp\n";
  // $$->name = "inttemp";
  // $$->code += "= inttemp, " + string($1) + "\n";
  (yyval.cn)->name = string((yyvsp[0].name));
  (yyval.cn)->type = Integer;
}
#line 2058 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 483 "parser_temp.y" /* yacc.c:1646  */
    {printf("array -> {arr_vals}\n");}
#line 2064 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 484 "parser_temp.y" /* yacc.c:1646  */
    {printf("array -> {}\n");}
#line 2070 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 486 "parser_temp.y" /* yacc.c:1646  */
    {printf("arr_vals -> values, arr_vals\n");}
#line 2076 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 487 "parser_temp.y" /* yacc.c:1646  */
    {printf("arr_vals -> values\n");}
#line 2082 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2086 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 489 "parser_temp.y" /* yacc.c:1906  */


int main(int argc, char *argv[]) {
    if (argc > 1) yyin = fopen(argv[1], "r");
    else yyin = stdin;

    yyparse();
    //printf("s\n", $$);
    return 0;
}
