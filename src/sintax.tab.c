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
#line 1 "sintax.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include "y.tab.h"
#include "structs.h"
// #include "defines.h"

FILE  *yyin; //Archivo de Entrada

#line 76 "sintax.tab.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 0
#endif


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
    TOKEN_ID = 258,
    CONST_INT = 259,
    CONST_STR = 260,
    CONST_FLOAT = 261,
    PR_MAIN = 262,
    PR_DIM = 263,
    PR_ENDIM = 264,
    PR_IGUALES = 265,
    PR_FILTER = 266,
    PR_WRITE = 267,
    PR_READ = 268,
    PR_IF = 269,
    PR_THEN = 270,
    PR_ENDIF = 271,
    PR_ELSE = 272,
    PR_NOT = 273,
    PR_WHILE = 274,
    PR_BEGIN = 275,
    PR_END = 276,
    PAR_ABRE = 277,
    PAR_CIERRA = 278,
    COR_ABRE = 279,
    COR_CIERRA = 280,
    COMA = 281,
    OP_LOG_AND = 282,
    OP_LOG_OR = 283,
    OP_LOG_NOT = 284,
    OP_SUMA = 285,
    OP_RESTA = 286,
    OP_MUL = 287,
    OP_DIV = 288,
    OP_MAYOR = 289,
    OP_MAYOR_IGUAL = 290,
    OP_MENOR = 291,
    OP_MENOR_IGUAL = 292,
    OP_DISTINTO = 293,
    OP_IGUAL_IGUAL = 294,
    OP_IGUAL = 295,
    OP_AS = 296,
    OP_DIM = 297,
    PR_FLOAT = 298,
    PR_INT = 299,
    PR_STRING = 300
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 12 "sintax.y" /* yacc.c:355  */

int intval;
double val;
char *str_val;

#line 165 "sintax.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 182 "sintax.tab.c" /* yacc.c:358  */

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
#define YYFINAL  40
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   113

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  56
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  111

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   300

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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    64,    64,    70,    76,    82,    88,    94,   100,   106,
     112,   118,   124,   130,   136,   142,   148,   154,   160,   166,
     172,   178,   184,   190,   196,   202,   208,   214,   220,   226,
     232,   238,   244,   250,   256,   262,   268,   274,   280,   286,
     292,   298,   304,   310,   316,   328,   334,   340,   360,   366,
     372,   378,   384,   390,   396,   402,   408
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOKEN_ID", "CONST_INT", "CONST_STR",
  "CONST_FLOAT", "PR_MAIN", "PR_DIM", "PR_ENDIM", "PR_IGUALES",
  "PR_FILTER", "PR_WRITE", "PR_READ", "PR_IF", "PR_THEN", "PR_ENDIF",
  "PR_ELSE", "PR_NOT", "PR_WHILE", "PR_BEGIN", "PR_END", "PAR_ABRE",
  "PAR_CIERRA", "COR_ABRE", "COR_CIERRA", "COMA", "OP_LOG_AND",
  "OP_LOG_OR", "OP_LOG_NOT", "OP_SUMA", "OP_RESTA", "OP_MUL", "OP_DIV",
  "OP_MAYOR", "OP_MAYOR_IGUAL", "OP_MENOR", "OP_MENOR_IGUAL",
  "OP_DISTINTO", "OP_IGUAL_IGUAL", "OP_IGUAL", "OP_AS", "OP_DIM",
  "PR_FLOAT", "PR_INT", "PR_STRING", "$accept", "pgm", "programa",
  "lista_sentencias", "sentencia", "iguales", "lista_expresiones",
  "filter", "lista_variables", "io", "entrada", "salida", "condicional",
  "condicion", "comparacion", "iteracion", "asignacion", "expresion",
  "termino", "factor", "declaracion_variables", "lista_variables_tipos",
  "tipo_dato", "comparador", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300
};
# endif

#define YYPACT_NINF -33

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-33)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       9,   -32,    23,   -11,    -5,    22,    21,    47,    47,    14,
     -33,    35,   -33,   -33,   -33,   -33,   -33,   -33,   -33,   -33,
      74,   -10,   -33,    35,    74,    47,   -33,   -33,   -33,   -33,
     -33,   -33,   -33,    74,    24,     2,    32,    11,   -33,    41,
     -33,   -33,    28,    40,    76,   -33,   -24,    62,    28,    35,
      47,    47,    74,    74,   -33,   -33,   -33,   -33,   -33,   -33,
      74,    74,    74,    35,    53,    35,    69,    70,    65,   -33,
     -33,    11,    11,    28,   -33,   -33,    75,    58,    72,   -33,
      74,    92,   -33,    35,   -33,    57,    53,   -33,    77,   -21,
      73,    78,    84,    80,    79,    83,    74,    92,    85,   -33,
      29,    29,   -33,   -33,   -33,   -33,   -33,   -33,   -33,   -33,
     -33
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       2,     6,    13,    14,    12,    21,    22,     9,    11,    10,
       0,     0,     4,     7,     0,     0,    24,    25,    23,    44,
      42,    41,    43,     0,     0,    28,     0,    35,    38,     0,
       1,     5,    34,     0,     0,     8,     0,     0,    32,     0,
       0,     0,     0,     0,    51,    54,    52,    53,    56,    55,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    29,
      30,    36,    37,    31,    40,    39,     0,     0,     0,     3,
       0,     0,    26,     0,    33,     0,     0,    45,     0,    17,
      20,     0,     0,     0,     0,     0,     0,     0,     0,    27,
       0,     0,    15,    16,    19,    18,    49,    48,    50,    46,
      47
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -33,   -33,   -33,    -8,   101,   -33,    13,   -33,    10,   -33,
     -33,   -33,   -33,    -7,    36,   -33,   -33,   -20,    37,    30,
     -33,    25,    12,   -33
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     9,    10,    22,    23,    12,    88,    13,    91,    14,
      15,    16,    17,    34,    35,    18,    19,    36,    37,    38,
      44,    78,   109,    60
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      42,    39,    66,    41,    46,    96,    52,    53,    20,    52,
      53,    24,     1,    48,    40,    45,     2,    25,    47,     3,
       4,     5,     6,     7,    28,    26,     1,    27,     8,    50,
      51,    21,    43,     3,     4,     5,     6,     7,     1,    49,
      73,    68,     8,    61,    62,     3,     4,     5,     6,     7,
      29,    30,    31,    32,     8,    76,    77,    79,    52,    53,
      89,    63,    52,    53,    64,    33,    54,    55,    56,    57,
      58,    59,   106,   107,   108,    92,    89,    29,    30,    31,
      32,    82,    83,    85,    86,    65,    69,    70,    67,    71,
      72,    74,    75,    80,    81,    90,    84,    87,    93,    97,
      99,    11,    95,    98,   100,   101,   102,   104,   105,   103,
       0,    94,     0,   110
};

static const yytype_int8 yycheck[] =
{
      20,     8,    26,    11,    24,    26,    30,    31,    40,    30,
      31,    22,     3,    33,     0,    23,     7,    22,    25,    10,
      11,    12,    13,    14,     3,     3,     3,     5,    19,    27,
      28,     8,    42,    10,    11,    12,    13,    14,     3,    15,
      60,    49,    19,    32,    33,    10,    11,    12,    13,    14,
       3,     4,     5,     6,    19,    63,     3,    65,    30,    31,
      80,    20,    30,    31,    24,    18,    34,    35,    36,    37,
      38,    39,    43,    44,    45,    83,    96,     3,     4,     5,
       6,    16,    17,    25,    26,     9,    50,    51,    26,    52,
      53,    61,    62,    24,    24,     3,    21,    25,    41,    26,
      16,     0,    25,    25,    24,    26,    23,    97,    23,    96,
      -1,    86,    -1,   101
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     7,    10,    11,    12,    13,    14,    19,    47,
      48,    50,    51,    53,    55,    56,    57,    58,    61,    62,
      40,     8,    49,    50,    22,    22,     3,     5,     3,     3,
       4,     5,     6,    18,    59,    60,    63,    64,    65,    59,
       0,    49,    63,    42,    66,    49,    63,    59,    63,    15,
      27,    28,    30,    31,    34,    35,    36,    37,    38,    39,
      69,    32,    33,    20,    24,     9,    26,    26,    49,    60,
      60,    64,    64,    63,    65,    65,    49,     3,    67,    49,
      24,    24,    16,    17,    21,    25,    26,    25,    52,    63,
       3,    54,    49,    41,    67,    25,    26,    26,    25,    16,
      24,    26,    23,    52,    54,    23,    43,    44,    45,    68,
      68
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    48,    48,    48,    48,    49,    49,    50,
      50,    50,    50,    50,    50,    51,    52,    52,    53,    54,
      54,    55,    55,    56,    57,    57,    58,    58,    59,    59,
      59,    60,    60,    61,    62,    63,    63,    63,    64,    64,
      64,    65,    65,    65,    65,    66,    67,    67,    68,    68,
      68,    69,    69,    69,    69,    69,    69
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     5,     2,     2,     1,     1,     2,     1,
       1,     1,     1,     1,     1,     8,     3,     1,     8,     3,
       1,     1,     1,     2,     2,     2,     5,     7,     1,     3,
       3,     3,     2,     5,     3,     1,     3,     3,     1,     3,
       3,     1,     1,     1,     1,     4,     5,     5,     1,     1,
       1,     1,     1,     1,     1,     1,     1
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
#line 65 "sintax.y" /* yacc.c:1646  */
    {
	puts("COMPILACION EXITOSA\n");
	puts("-------------------\n");
}
#line 1345 "sintax.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 71 "sintax.y" /* yacc.c:1646  */
    {
	puts("Código con variables\n");
	puts("-------------------\n");
}
#line 1354 "sintax.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 77 "sintax.y" /* yacc.c:1646  */
    {
	puts("Código sin variables\n");
	puts("-------------------\n");
}
#line 1363 "sintax.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 83 "sintax.y" /* yacc.c:1646  */
    {
	puts("Varias sentencias\n");
	puts("-------------------\n");
}
#line 1372 "sintax.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 89 "sintax.y" /* yacc.c:1646  */
    {
	puts("Última sentencia\n");
	puts("-------------------\n");
}
#line 1381 "sintax.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 95 "sintax.y" /* yacc.c:1646  */
    {
	puts("Una sola sentencia\n");
	puts("-------------------\n");
}
#line 1390 "sintax.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 101 "sintax.y" /* yacc.c:1646  */
    {
	puts("Varias sentencias\n");
	puts("-------------------\n");
}
#line 1399 "sintax.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 107 "sintax.y" /* yacc.c:1646  */
    {
	puts("Condicional\n");
	puts("-------------------\n");
}
#line 1408 "sintax.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 113 "sintax.y" /* yacc.c:1646  */
    {
	puts("Asignación\n");
	puts("-------------------\n");
}
#line 1417 "sintax.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 119 "sintax.y" /* yacc.c:1646  */
    {
	puts("Iteración\n");
	puts("-------------------\n");
}
#line 1426 "sintax.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 125 "sintax.y" /* yacc.c:1646  */
    {
	puts("Operación de entrada salidas\n");
	puts("-------------------\n");
}
#line 1435 "sintax.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 131 "sintax.y" /* yacc.c:1646  */
    {
	puts("Operación de iguales\n");
	puts("-------------------\n");
}
#line 1444 "sintax.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 137 "sintax.y" /* yacc.c:1646  */
    {
	puts("Operación de filters\n");
	puts("-------------------\n");
}
#line 1453 "sintax.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 143 "sintax.y" /* yacc.c:1646  */
    {
	puts("iguales : PR_IGUALES PAR_ABRE expresion COMA COR_ABRElista_expresiones COR_CIERRA PAR_CIERRA\n");
	puts("-------------------\n");
}
#line 1462 "sintax.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 149 "sintax.y" /* yacc.c:1646  */
    {
	puts("Lista de expresiones\n");
	puts("-------------------\n");
}
#line 1471 "sintax.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 155 "sintax.y" /* yacc.c:1646  */
    {
	puts("Última expresión\n");
	puts("-------------------\n");
}
#line 1480 "sintax.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 161 "sintax.y" /* yacc.c:1646  */
    {
	puts("filter : PR_FILTER PAR_ABRE condicion COMA COR_ABRE lista_variables COR_CIERRA PAR_CIERRA\n");
	puts("-------------------\n");
}
#line 1489 "sintax.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 167 "sintax.y" /* yacc.c:1646  */
    {
	puts("Lista de variables\n");
	puts("-------------------\n");
}
#line 1498 "sintax.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 173 "sintax.y" /* yacc.c:1646  */
    {
	puts("Última variable\n");
	puts("-------------------\n");
}
#line 1507 "sintax.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 179 "sintax.y" /* yacc.c:1646  */
    {
	puts("io : entrada\n");
	puts("-------------------\n");
}
#line 1516 "sintax.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 185 "sintax.y" /* yacc.c:1646  */
    {
	puts("io : salida\n");
	puts("-------------------\n");
}
#line 1525 "sintax.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 191 "sintax.y" /* yacc.c:1646  */
    {
	puts("entrada : READ id\n");
	puts("-------------------\n");
}
#line 1534 "sintax.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 197 "sintax.y" /* yacc.c:1646  */
    {
	puts("salida : PR_WRITE id\n");
	puts("-------------------\n");
}
#line 1543 "sintax.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 203 "sintax.y" /* yacc.c:1646  */
    {
	puts("salida : PR_WRITE cte\n");
	puts("-------------------\n");
}
#line 1552 "sintax.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 209 "sintax.y" /* yacc.c:1646  */
    {
	puts("Condicional sin ELSE\n");
	puts("-------------------\n");
}
#line 1561 "sintax.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 215 "sintax.y" /* yacc.c:1646  */
    {
	puts("Condicional con ELSE\n");
	puts("-------------------\n");
}
#line 1570 "sintax.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 221 "sintax.y" /* yacc.c:1646  */
    {
	puts("condicion : comparacion\n");
	puts("-------------------\n");
}
#line 1579 "sintax.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 227 "sintax.y" /* yacc.c:1646  */
    {
	puts("condicion : comparacion and comparacion\n");
	puts("-------------------\n");
}
#line 1588 "sintax.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 233 "sintax.y" /* yacc.c:1646  */
    {
	puts("condicion : comparacion or comparacion\n");
	puts("-------------------\n");
}
#line 1597 "sintax.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 239 "sintax.y" /* yacc.c:1646  */
    {
	puts("comparacion : expresion comparador expresion\n");
	puts("-------------------\n");
}
#line 1606 "sintax.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 245 "sintax.y" /* yacc.c:1646  */
    {
	puts("comparacion : PR_NOT expresion\n");
	puts("-------------------\n");
}
#line 1615 "sintax.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 251 "sintax.y" /* yacc.c:1646  */
    {
	puts("Iteración\n");
	puts("-------------------\n");
}
#line 1624 "sintax.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 257 "sintax.y" /* yacc.c:1646  */
    {
	puts("Asignación\n");
	puts("-------------------\n");
}
#line 1633 "sintax.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 263 "sintax.y" /* yacc.c:1646  */
    {
	puts("Asignación\n");
	puts("-------------------\n");
}
#line 1642 "sintax.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 269 "sintax.y" /* yacc.c:1646  */
    {
	puts("Suma\n");
	puts("-------------------\n");
}
#line 1651 "sintax.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 275 "sintax.y" /* yacc.c:1646  */
    {
	puts("Resta\n");
	puts("-------------------\n");
}
#line 1660 "sintax.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 281 "sintax.y" /* yacc.c:1646  */
    {
	puts("termino : factor\n");
	puts("-------------------\n");
}
#line 1669 "sintax.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 287 "sintax.y" /* yacc.c:1646  */
    {
	puts("División\n");
	puts("-------------------\n");
}
#line 1678 "sintax.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 293 "sintax.y" /* yacc.c:1646  */
    {
	puts("Multiplicación\n");
	puts("-------------------\n");
}
#line 1687 "sintax.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 299 "sintax.y" /* yacc.c:1646  */
    {
	puts("factor : cte\n");
	puts("-------------------\n");
}
#line 1696 "sintax.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 305 "sintax.y" /* yacc.c:1646  */
    {
	puts("factor : cte\n");
	puts("-------------------\n");
}
#line 1705 "sintax.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 311 "sintax.y" /* yacc.c:1646  */
    {
	puts("factor : cte\n");
	puts("-------------------\n");
}
#line 1714 "sintax.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 317 "sintax.y" /* yacc.c:1646  */
    {
	puts("factor : TOKEN_ID\n");
	puts("-------------------\n");
}
#line 1723 "sintax.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 329 "sintax.y" /* yacc.c:1646  */
    {
	puts("Declaración de variables\n");
	puts("-------------------\n");
}
#line 1732 "sintax.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 335 "sintax.y" /* yacc.c:1646  */
    {
	puts("Lista de variables\n");
	puts("-------------------\n");
}
#line 1741 "sintax.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 341 "sintax.y" /* yacc.c:1646  */
    {
	puts("Lista de variables\n");
	puts("-------------------\n");
}
#line 1750 "sintax.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 361 "sintax.y" /* yacc.c:1646  */
    {
	puts("PR_INT\n");
	puts("-------------------\n");
}
#line 1759 "sintax.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 367 "sintax.y" /* yacc.c:1646  */
    {
	puts("PR_FLOAT\n");
	puts("-------------------\n");
}
#line 1768 "sintax.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 373 "sintax.y" /* yacc.c:1646  */
    {
	puts("PR_STRING\n");
	puts("-------------------\n");
}
#line 1777 "sintax.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 379 "sintax.y" /* yacc.c:1646  */
    {
	puts("OP_MAYOR\n");
	puts("-------------------\n");
}
#line 1786 "sintax.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 385 "sintax.y" /* yacc.c:1646  */
    {
	puts("OP_MENOR\n");
	puts("-------------------\n");
}
#line 1795 "sintax.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 391 "sintax.y" /* yacc.c:1646  */
    {
	puts("OP_MENOR_IGUAL\n");
	puts("-------------------\n");
}
#line 1804 "sintax.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 397 "sintax.y" /* yacc.c:1646  */
    {
	puts("OP_MAYOR_IGUAL\n");
	puts("-------------------\n");
}
#line 1813 "sintax.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 403 "sintax.y" /* yacc.c:1646  */
    {
	puts("OP_IGUAL_IGUAL\n");
	puts("-------------------\n");
}
#line 1822 "sintax.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 409 "sintax.y" /* yacc.c:1646  */
    {
	puts("OP_DISTINTO\n");
	puts("-------------------\n");
}
#line 1831 "sintax.tab.c" /* yacc.c:1646  */
    break;


#line 1835 "sintax.tab.c" /* yacc.c:1646  */
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
#line 414 "sintax.y" /* yacc.c:1906  */



extern t_simbolo tabla_simbolos[2000];

extern int cantidad_simbolos;
void imprimir_tabla_simbolos();
void vaciar_tabla_simbolos();
char * tipo_simbolo_to_string(int tipo);


//función para realizar todo lo que haga falta previo a terminar
void finally(FILE *yyin){
	vaciar_tabla_simbolos();
	fclose(yyin);
}



int main(int argc, char **argv ) {
	// puts("Corriendo el compilador...");

	++argv, --argc; 

	if ( argc > 0 ) {
	     yyin = fopen( argv[0], "r" );
     }	else {
	     yyin = stdin;

     }

	 yyparse();


	finally(yyin);
	return EXIT_SUCCESS;
}

int yyerror(void)
{
	printf("Syntax Error\n");
	system ("Pause");
	exit (1);
}

void vaciar_tabla_simbolos(){
	int i;
	for (i = 0; i < cantidad_simbolos; ++i)
	{
		free(tabla_simbolos[i].nombre);
		if(tabla_simbolos[i].valor_string != NULL)
			free(tabla_simbolos[i].valor_string);
		if(tabla_simbolos[i].alias != NULL)
			free(tabla_simbolos[i].alias);
	}
	cantidad_simbolos = 0;
}

char * tipo_simbolo_to_string(int tipo){
	// printf("\n\n\n%d\n\n\n", tipo);
	switch(tipo) {
		case TIPO_STRING:
			return "STRING";
		case TIPO_FLOAT:
			return "FLOAT";
		case TIPO_INT:
			return "INT";
		case TIPO_PR:
			return "PR";
		default:
			return "DESCONOCIDO";
	}
}


void imprimir_tabla_simbolos() {
	int i;
	printf("NOMBRE \t\t TIPO \t\t VALOR\n\n");
	for (i = 0; i < cantidad_simbolos; ++i)
	{
		if(tabla_simbolos[i].tipo == TIPO_STRING)
			printf("%s\t\t%s\t\t%s \n",tabla_simbolos[i].nombre,tipo_simbolo_to_string(tabla_simbolos[i].tipo),tabla_simbolos[i].valor_string == NULL ? "" : tabla_simbolos[i].valor_string);
	
		if(tabla_simbolos[i].tipo == TIPO_INT)
			printf("%s\t\t%s\t\t%d\n",tabla_simbolos[i].nombre,tipo_simbolo_to_string(tabla_simbolos[i].tipo),tabla_simbolos[i].valor_int);
		
		if(tabla_simbolos[i].tipo == TIPO_FLOAT)
			printf("%s\t\t%s\t\t%f\n",tabla_simbolos[i].nombre,tipo_simbolo_to_string(tabla_simbolos[i].tipo),tabla_simbolos[i].valor_float);

		if(tabla_simbolos[i].tipo == TIPO_PR)
			printf("%s\t\t%s\t\t\n",tabla_simbolos[i].nombre,tipo_simbolo_to_string(tabla_simbolos[i].tipo));
				

	}
}


