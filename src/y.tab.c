
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "syntax.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"
#include "structs.h"
#include "defines.h"

#define DEBUG 1
extern YYSTYPE yylval;
char prefijo_id[2] = PREFIJO_ID;
char prefijo_int[2] = PREFIJO_INT;
char prefijo_float[2] = PREFIJO_FLOAT;
char prefijo_string[2] = PREFIJO_STRING;
char temp_variables[MAX_VARIABLES][30];
char temp_tipo_dato[MAX_VARIABLES][10];
int variables_a_agregar= 0;
char aux[30];
char aux2[30];
int cantidad_cte_string = 0;
void agregar_simbolo(char * nombre, int tipo, char * valor,char * alias,int lineNumber);
void agregar_variable_a_TS(char * nombre, char * tipo,int lineNumber);
void agregar_cte_a_TS(int tipo, char * valor_str, int valor_int,float valor_float,int lineNumber);
void agregar_cte_a_TS_sin_prefijo(int tipo, char * valor_str, int valor_int,float valor_float,int lineNumber);
void error_lexico(char * mensaje);
int tipos_iguales(char * nombre1, char * nombre2, char * mjs_error, int lineNumber);
int buscar_en_TS(char * nombre);
void poner_prefijo(char * str, char * prefijo);
extern int linecount;

int yylex();

FILE  *yyin; //Archivo de Entrada


/* Line 189 of yacc.c  */
#line 109 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TOKEN_ID = 258,
     CONST_INT = 259,
     CONST_STR = 260,
     CONST_FLOAT = 261,
     PR_MAIN = 262,
     PR_IGUALES = 263,
     PR_FILTER = 264,
     PR_WRITE = 265,
     PR_READ = 266,
     PR_IF = 267,
     PR_THEN = 268,
     PR_ENDIF = 269,
     PR_ELSE = 270,
     PR_NOT = 271,
     PR_WHILE = 272,
     PR_DO = 273,
     PR_ENDWHILE = 274,
     PAR_ABRE = 275,
     PAR_CIERRA = 276,
     COR_ABRE = 277,
     COR_CIERRA = 278,
     COMA = 279,
     OP_LOG_AND = 280,
     OP_LOG_OR = 281,
     OP_SUMA = 282,
     OP_RESTA = 283,
     OP_MUL = 284,
     OP_DIV = 285,
     OP_MAYOR = 286,
     OP_MAYOR_IGUAL = 287,
     OP_MENOR = 288,
     OP_MENOR_IGUAL = 289,
     OP_DISTINTO = 290,
     OP_IGUAL_IGUAL = 291,
     OP_IGUAL = 292,
     PR_AS = 293,
     PR_DIM = 294,
     OP_FILTER = 295,
     PR_FLOAT = 296,
     PR_INT = 297,
     PR_STRING = 298,
     OP_CONCAT = 299,
     PUNTO_Y_COMA = 300
   };
#endif
/* Tokens.  */
#define TOKEN_ID 258
#define CONST_INT 259
#define CONST_STR 260
#define CONST_FLOAT 261
#define PR_MAIN 262
#define PR_IGUALES 263
#define PR_FILTER 264
#define PR_WRITE 265
#define PR_READ 266
#define PR_IF 267
#define PR_THEN 268
#define PR_ENDIF 269
#define PR_ELSE 270
#define PR_NOT 271
#define PR_WHILE 272
#define PR_DO 273
#define PR_ENDWHILE 274
#define PAR_ABRE 275
#define PAR_CIERRA 276
#define COR_ABRE 277
#define COR_CIERRA 278
#define COMA 279
#define OP_LOG_AND 280
#define OP_LOG_OR 281
#define OP_SUMA 282
#define OP_RESTA 283
#define OP_MUL 284
#define OP_DIV 285
#define OP_MAYOR 286
#define OP_MAYOR_IGUAL 287
#define OP_MENOR 288
#define OP_MENOR_IGUAL 289
#define OP_DISTINTO 290
#define OP_IGUAL_IGUAL 291
#define OP_IGUAL 292
#define PR_AS 293
#define PR_DIM 294
#define OP_FILTER 295
#define PR_FLOAT 296
#define PR_INT 297
#define PR_STRING 298
#define OP_CONCAT 299
#define PUNTO_Y_COMA 300




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 37 "syntax.y"

int intval;
float val;
char *str_val;



/* Line 214 of yacc.c  */
#line 243 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 255 "y.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  23
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   138

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  64
/* YYNRULES -- Number of states.  */
#define YYNSTATES  134

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   300

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     9,    12,    14,    17,    19,    21,
      23,    26,    29,    32,    41,    45,    47,    56,    58,    62,
      66,    70,    75,    79,    81,    83,    85,    88,    91,    94,
     100,   108,   110,   114,   118,   122,   127,   133,   137,   139,
     143,   147,   149,   153,   157,   162,   166,   171,   173,   175,
     177,   179,   181,   187,   194,   200,   206,   208,   210,   212,
     214,   216,   218,   220,   222
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      47,     0,    -1,    48,    -1,     7,    70,    49,    -1,     7,
      49,    -1,    50,    -1,    50,    49,    -1,    60,    -1,    64,
      -1,    63,    -1,    57,    45,    -1,    51,    45,    -1,    53,
      45,    -1,     8,    20,    65,    24,    22,    52,    23,    21,
      -1,    65,    24,    52,    -1,    65,    -1,     9,    20,    54,
      24,    22,    56,    23,    21,    -1,    55,    -1,    55,    25,
      55,    -1,    55,    26,    55,    -1,    40,    73,    65,    -1,
      16,    40,    73,    65,    -1,     3,    24,    56,    -1,     3,
      -1,    58,    -1,    59,    -1,    11,     3,    -1,    10,     3,
      -1,    10,     5,    -1,    12,    61,    13,    49,    14,    -1,
      12,    61,    13,    49,    15,    49,    14,    -1,    62,    -1,
      62,    25,    62,    -1,    62,    26,    62,    -1,    65,    73,
      65,    -1,    16,    65,    73,    65,    -1,    17,    61,    18,
      49,    19,    -1,     3,    37,    65,    -1,    66,    -1,    65,
      27,    66,    -1,    65,    28,    66,    -1,    69,    -1,    66,
      30,    69,    -1,    66,    29,    69,    -1,     3,    37,    67,
      45,    -1,    68,    44,    68,    -1,     3,    37,    68,    45,
      -1,     5,    -1,     3,    -1,     4,    -1,     6,    -1,     3,
      -1,    39,    22,    71,    23,    45,    -1,    39,    22,    71,
      23,    45,    70,    -1,     3,    24,    71,    24,    72,    -1,
       3,    23,    38,    22,    72,    -1,    42,    -1,    41,    -1,
      43,    -1,    31,    -1,    33,    -1,    34,    -1,    32,    -1,
      36,    -1,    35,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    95,    95,   101,   110,   118,   126,   135,   144,   153,
     162,   171,   179,   187,   195,   203,   211,   219,   225,   231,
     237,   243,   249,   257,   265,   274,   282,   290,   298,   306,
     314,   322,   330,   338,   346,   354,   362,   370,   384,   394,
     408,   422,   431,   439,   460,   470,   479,   488,   500,   513,
     529,   544,   558,   577,   584,   598,   627,   636,   645,   655,
     663,   671,   679,   687,   695
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOKEN_ID", "CONST_INT", "CONST_STR",
  "CONST_FLOAT", "PR_MAIN", "PR_IGUALES", "PR_FILTER", "PR_WRITE",
  "PR_READ", "PR_IF", "PR_THEN", "PR_ENDIF", "PR_ELSE", "PR_NOT",
  "PR_WHILE", "PR_DO", "PR_ENDWHILE", "PAR_ABRE", "PAR_CIERRA", "COR_ABRE",
  "COR_CIERRA", "COMA", "OP_LOG_AND", "OP_LOG_OR", "OP_SUMA", "OP_RESTA",
  "OP_MUL", "OP_DIV", "OP_MAYOR", "OP_MAYOR_IGUAL", "OP_MENOR",
  "OP_MENOR_IGUAL", "OP_DISTINTO", "OP_IGUAL_IGUAL", "OP_IGUAL", "PR_AS",
  "PR_DIM", "OP_FILTER", "PR_FLOAT", "PR_INT", "PR_STRING", "OP_CONCAT",
  "PUNTO_Y_COMA", "$accept", "pgm", "programa", "lista_sentencias",
  "sentencia", "iguales", "lista_expresiones", "filter",
  "condicion_filter", "comparacion_filter", "lista_variables", "io",
  "entrada", "salida", "condicional", "condicion", "comparacion",
  "iteracion", "asignacion", "expresion", "termino", "expresion_str",
  "factor_str", "factor", "declaracion_variables",
  "declaracion_variables_interna", "tipo_dato", "comparador", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    48,    48,    49,    49,    50,    50,    50,
      50,    50,    50,    51,    52,    52,    53,    54,    54,    54,
      55,    55,    56,    56,    57,    57,    58,    59,    59,    60,
      60,    61,    61,    61,    62,    62,    63,    64,    65,    65,
      65,    66,    66,    66,    64,    67,    64,    68,    68,    69,
      69,    69,    70,    70,    71,    71,    72,    72,    72,    73,
      73,    73,    73,    73,    73
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     3,     2,     1,     2,     1,     1,     1,
       2,     2,     2,     8,     3,     1,     8,     1,     3,     3,
       3,     4,     3,     1,     1,     1,     2,     2,     2,     5,
       7,     1,     3,     3,     3,     4,     5,     3,     1,     3,
       3,     1,     3,     3,     4,     3,     4,     1,     1,     1,
       1,     1,     5,     6,     5,     5,     1,     1,     1,     1,
       1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     0,     0,     0,     0,     0,     0,
       0,     0,     4,     5,     0,     0,     0,    24,    25,     7,
       9,     8,     0,     1,     0,     0,     0,    27,    28,    26,
      51,    49,    50,     0,     0,    31,     0,    38,    41,     0,
       0,     6,    11,    12,    10,     3,    51,    47,    37,     0,
       0,     0,     0,     0,     0,    17,     0,     0,     0,     0,
       0,     0,    59,    62,    60,    61,    64,    63,     0,     0,
       0,     0,     0,     0,    44,     0,    46,     0,     0,     0,
       0,     0,     0,     0,     0,    32,    33,    39,    40,    34,
      43,    42,     0,     0,     0,     0,    48,    45,     0,     0,
      20,     0,    18,    19,    35,    29,     0,    36,     0,     0,
      52,     0,    15,    21,    23,     0,     0,     0,     0,    53,
       0,     0,     0,     0,    30,    57,    56,    58,    55,    54,
      13,    14,    22,    16
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    12,    13,    14,   111,    15,    54,    55,
     115,    16,    17,    18,    19,    34,    35,    20,    21,    36,
      37,    49,    50,    38,    22,    73,   128,    68
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -51
static const yytype_int8 yypact[] =
{
       3,     4,    33,   -51,    -7,    18,    25,    24,    79,    31,
      31,    72,   -51,    14,    53,    56,    62,   -51,   -51,   -51,
     -51,   -51,    14,   -51,    73,    77,    -8,   -51,   -51,   -51,
     -51,   -51,   -51,    77,    83,   -21,    30,    39,   -51,    88,
     105,   -51,   -51,   -51,   -51,   -51,    -3,   -51,    45,    64,
      40,    12,    70,    17,    87,    61,    30,    14,    31,    31,
      77,    77,   -51,   -51,   -51,   -51,   -51,   -51,    77,    77,
      77,    14,    65,    89,   -51,    51,   -51,    91,    17,    77,
      92,    -8,    -8,    77,    76,   -51,   -51,    39,    39,    45,
     -51,   -51,    96,    78,   105,    74,   -51,   -51,    77,    77,
      45,   114,   -51,   -51,    45,   -51,    14,   -51,    98,    94,
      82,    99,    43,    45,   100,   102,   109,   -23,   -23,   -51,
     106,    77,   114,   107,   -51,   -51,   -51,   -51,   -51,   -51,
     -51,   -51,   -51,   -51
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -51,   -51,   -51,   -11,   -51,   -51,     5,   -51,   -51,    11,
       7,   -51,   -51,   -51,   -51,   120,    41,   -51,   -51,   -24,
      42,   -51,    57,    35,    21,    44,    15,   -50
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -49
static const yytype_int16 yytable[] =
{
      48,    51,    41,    79,    58,    59,    83,     4,    52,    56,
       1,    45,     5,     6,     7,     8,     9,     4,   125,   126,
     127,    10,     5,     6,     7,     8,     9,    27,    99,    28,
      24,    10,    53,    23,    30,    31,    77,    32,    25,    60,
      61,   -48,   -48,    11,    89,    26,    84,    33,    62,    63,
      64,    65,    66,    67,    96,   100,    47,    60,    61,   104,
      92,    62,    63,    64,    65,    66,    67,   121,    69,    70,
      60,    61,    60,    61,   112,   113,    46,    31,    47,    32,
      30,    31,    29,    32,    75,    76,    81,    82,    93,    94,
     105,   106,   102,   103,    40,   116,    57,   112,    42,    85,
      86,    43,    87,    88,    90,    91,    71,    44,    72,    74,
      78,    80,    95,    98,   101,   107,   108,   114,   118,   110,
     117,    11,   120,   124,   122,   123,   131,   130,   133,   132,
      39,   119,    97,   129,     0,     0,     0,     0,   109
};

static const yytype_int8 yycheck[] =
{
      24,    25,    13,    53,    25,    26,    56,     3,    16,    33,
       7,    22,     8,     9,    10,    11,    12,     3,    41,    42,
      43,    17,     8,     9,    10,    11,    12,     3,    78,     5,
      37,    17,    40,     0,     3,     4,    24,     6,    20,    27,
      28,    44,    45,    39,    68,    20,    57,    16,    31,    32,
      33,    34,    35,    36,     3,    79,     5,    27,    28,    83,
      71,    31,    32,    33,    34,    35,    36,    24,    29,    30,
      27,    28,    27,    28,    98,    99,     3,     4,     5,     6,
       3,     4,     3,     6,    44,    45,    25,    26,    23,    24,
      14,    15,    81,    82,    22,   106,    13,   121,    45,    58,
      59,    45,    60,    61,    69,    70,    18,    45,     3,    45,
      40,    24,    23,    22,    22,    19,    38,     3,    24,    45,
      22,    39,    23,    14,    24,    23,   121,    21,    21,   122,
      10,   110,    75,   118,    -1,    -1,    -1,    -1,    94
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,    47,    48,     3,     8,     9,    10,    11,    12,
      17,    39,    49,    50,    51,    53,    57,    58,    59,    60,
      63,    64,    70,     0,    37,    20,    20,     3,     5,     3,
       3,     4,     6,    16,    61,    62,    65,    66,    69,    61,
      22,    49,    45,    45,    45,    49,     3,     5,    65,    67,
      68,    65,    16,    40,    54,    55,    65,    13,    25,    26,
      27,    28,    31,    32,    33,    34,    35,    36,    73,    29,
      30,    18,     3,    71,    45,    44,    45,    24,    40,    73,
      24,    25,    26,    73,    49,    62,    62,    66,    66,    65,
      69,    69,    49,    23,    24,    23,     3,    68,    22,    73,
      65,    22,    55,    55,    65,    14,    15,    19,    38,    71,
      45,    52,    65,    65,     3,    56,    49,    22,    24,    70,
      23,    24,    24,    23,    14,    41,    42,    43,    72,    72,
      21,    52,    56,    21
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

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

/* Line 1455 of yacc.c  */
#line 96 "syntax.y"
    {
	puts("COMPILACION EXITOSA\n");
	puts("-------------------\n");
}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 102 "syntax.y"
    {
	if(DEBUG){
		puts("Codigo con variables\n");
		puts("-------------------\n");
	}

}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 111 "syntax.y"
    {
	if(DEBUG){
		puts("Codigo sin variables\n");
		puts("-------------------\n");
	}
}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 119 "syntax.y"
    {
	if(DEBUG){
		puts("Una sola sentencia\n");
		puts("-------------------\n");
	}
}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 127 "syntax.y"
    {
	if(DEBUG) {
		puts("Varias sentencias\n");
		puts("-------------------\n");
	}

}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 136 "syntax.y"
    {
	if(DEBUG) {
		puts("Condicional\n");
		puts("-------------------\n");		
	}

}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 145 "syntax.y"
    {
	if(DEBUG) {
		puts("Asignacion\n");
		puts("-------------------\n");		
	}

}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 154 "syntax.y"
    {
	if(DEBUG) {
		puts("Iteracion\n");
		puts("-------------------\n");		
	}

}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 163 "syntax.y"
    {
	if(DEBUG) {
		puts("Operacion de entrada salidas\n");
		puts("-------------------\n");		
	}

}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 172 "syntax.y"
    {
	if(DEBUG) {
		puts("Operacion de iguales\n");
		puts("-------------------\n");	
	}
}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 180 "syntax.y"
    {
	if(DEBUG) {
		puts("Operacioon de filters\n");
		puts("-------------------\n");
	}
}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 188 "syntax.y"
    {
	if(DEBUG) {
		puts("iguales : PR_IGUALES PAR_ABRE expresion COMA COR_ABRElista_expresiones COR_CIERRA PAR_CIERRA\n");
		puts("-------------------\n");
	}
}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 196 "syntax.y"
    {
	if(DEBUG) {
		puts("Lista de expresiones\n");
		puts("-------------------\n");		
	}
}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 204 "syntax.y"
    {
	if(DEBUG) {
		puts("Última expresion\n");
		puts("-------------------\n");		
	}
}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 212 "syntax.y"
    {
	if(DEBUG) {
		puts("filter : PR_FILTER PAR_ABRE condicion COMA COR_ABRE lista_variables COR_CIERRA PAR_CIERRA\n");
		puts("-------------------\n");
	}
}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 220 "syntax.y"
    {
	puts("condicion_filter : comparacion_filter\n");
	puts("-------------------\n");
}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 226 "syntax.y"
    {
	puts("condicion_filter : comparacion_filter and comparacion_filter\n");
	puts("-------------------\n");
}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 232 "syntax.y"
    {
	puts("condicion_filter : comparacion_filter or comparacion_filter\n");
	puts("-------------------\n");
}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 238 "syntax.y"
    {
	puts("comparacion_filter : OP_FILTER comparador expresion\n");
	puts("-------------------\n");
}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 244 "syntax.y"
    {
	puts("comparacion_filter : PR_NOT OP_FILTER comparador expresion\n");
	puts("-------------------\n");
}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 250 "syntax.y"
    {
	if(DEBUG) {
		puts("Lista de variables\n");
		puts("-------------------\n");		
	}
}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 258 "syntax.y"
    {
	if(DEBUG) {
		puts("Última variable\n");
		puts("-------------------\n");
	}
}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 266 "syntax.y"
    {
	if(DEBUG) {
		puts("io : entrada\n");
		puts("-------------------\n");
	}

}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 275 "syntax.y"
    {
	if(DEBUG) {
		puts("io : salida\n");
		puts("-------------------\n");		
	}
}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 283 "syntax.y"
    {
	if(DEBUG) {
		puts("entrada : READ id\n");
		puts("-------------------\n");		
	}
}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 291 "syntax.y"
    {
	if(DEBUG) {
		puts("salida : PR_WRITE id\n");
		puts("-------------------\n");
	}
}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 299 "syntax.y"
    {
	if(DEBUG) {
		puts("salida : PR_WRITE cte\n");
		puts("-------------------\n");	
	}
}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 307 "syntax.y"
    {
	if(DEBUG) {
		puts("Condicional sin ELSE\n");
		puts("-------------------\n");
	}
}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 315 "syntax.y"
    {
	if(DEBUG) {
		puts("Condicional con ELSE\n");
		puts("-------------------\n");	
	}
}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 323 "syntax.y"
    {
	if(DEBUG) {
		puts("condicion : comparacion\n");
		puts("-------------------\n");
	}
}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 331 "syntax.y"
    {
	if(DEBUG) {
		puts("condicion : comparacion and comparacion\n");
		puts("-------------------\n");		
	}
}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 339 "syntax.y"
    {
	if(DEBUG) {
		puts("condicion : comparacion or comparacion\n");
		puts("-------------------\n");		
	}
}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 347 "syntax.y"
    {
	if(DEBUG) {
		puts("comparacion : expresion comparador expresion\n");
		puts("-------------------\n");
	}
}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 355 "syntax.y"
    {
	if(DEBUG) {
		puts("comparacion : PR_NOT expresion comparador expresion\n");
		puts("-------------------\n");
	}
}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 363 "syntax.y"
    {
	if(DEBUG) {
		puts("Iteracion\n");
		puts("-------------------\n");
	}
}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 371 "syntax.y"
    {
	printf("asignacion %s %s\n",(yyvsp[(1) - (3)].str_val),(yyvsp[(3) - (3)].str_val) );
	char mjs_error[60];
	if(!tipos_iguales((yyvsp[(1) - (3)].str_val),(yyvsp[(3) - (3)].str_val),mjs_error, linecount)) {
		puts(mjs_error);
		exit(1);
	}
	if(DEBUG) {
		puts("Asignacion -> Token_ID := expresion\n");
		puts("-------------------\n");
	}
}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 385 "syntax.y"
    {
	printf("%s\n",(yyvsp[(1) - (1)].str_val) );
	(yyval.str_val)=(yyvsp[(1) - (1)].str_val);
	if(DEBUG) {
		puts("Expresion -> termino\n");
		puts("-------------------\n");
	}
}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 395 "syntax.y"
    {
	char mjs_error[60];
	if(!tipos_iguales((yyvsp[(1) - (3)].str_val),(yyvsp[(3) - (3)].str_val),mjs_error, linecount)) {
		puts(mjs_error);
		exit(1);
	}
	if(DEBUG) {
		printf("%s %s\n", (yyvsp[(1) - (3)].str_val), (yyvsp[(3) - (3)].str_val));
		puts("expresion : expresion OP_SUMA termino\n");
		puts("-------------------\n");
	}
}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 409 "syntax.y"
    {
	char mjs_error[60];
	if(!tipos_iguales((yyvsp[(1) - (3)].str_val),(yyvsp[(3) - (3)].str_val),mjs_error, linecount)) {
		puts(mjs_error);
		exit(1);
	}
	if(DEBUG) {
		printf("%s %s\n", (yyvsp[(1) - (3)].str_val), (yyvsp[(3) - (3)].str_val));
		puts("Resta\n");
		puts("-------------------\n");
	}
}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 423 "syntax.y"
    {
	printf(" termino %s\n",(yyvsp[(1) - (1)].str_val) );
	if(DEBUG) {
		puts("termino : factor\n");
		puts("-------------------\n");
	}
}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 432 "syntax.y"
    {
	if(DEBUG) {
		puts("Division\n");
		puts("-------------------\n");
	}
}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 440 "syntax.y"
    {
	// printf("%s\n", $1);
	if(DEBUG) {
		puts("termino : termino OP_MUL factor\n");
		puts("-------------------\n");
	}
}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 461 "syntax.y"
    {
	if(DEBUG) {
		// printf("%s\n",$1);
		puts("asignacion : id := expresion_str \n");
		puts("-------------------\n");		
	}
}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 471 "syntax.y"
    {
	if(DEBUG) {
		// printf("%s\n",$1);
		puts("expresion_str : factor_str OP_CONCAT factor_str \n");
		puts("-------------------\n");		
	}
}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 480 "syntax.y"
    {
	if(DEBUG) {
		// printf("%s\n",$1);
		puts("expresion_str : factor_str\n");
		puts("-------------------\n");		
	}
}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 489 "syntax.y"
    {
	agregar_cte_a_TS(TIPO_STRING,(yyvsp[(1) - (1)].str_val), 0,0.0,linecount);
	puts((yyvsp[(1) - (1)].str_val));
	(yyval.str_val)=(yyvsp[(1) - (1)].str_val);
	if(DEBUG) {
		printf("%s\n",(yyvsp[(1) - (1)].str_val));
		puts("factor : cte\n");
		puts("-------------------\n");		
	}
}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 501 "syntax.y"
    {
	(yyval.str_val)=(yyvsp[(1) - (1)].str_val);
	if(DEBUG) {
		printf("%s\n",(yyvsp[(1) - (1)].str_val));
		puts("factor : cte\n");
		puts("-------------------\n");		
	}
}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 514 "syntax.y"
    {
	// $$ = "INT";
	char temp[10];
	sprintf(temp,"%d",(yyvsp[(1) - (1)].intval));
	(yyval.str_val) = temp;
	// $$=$1;
	agregar_cte_a_TS(TIPO_INT,NULL, (yyvsp[(1) - (1)].intval),0.0,linecount);
	if(DEBUG) {
		printf("%d\n",(yyvsp[(1) - (1)].intval));
		puts("factor : cte\n");
		puts("-------------------\n");		
	}

}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 530 "syntax.y"
    {
	char temp[10];
	sprintf(temp,"%.4f",(yyvsp[(1) - (1)].val));
	(yyval.str_val) = temp;
	// $$=$1;
	agregar_cte_a_TS(TIPO_FLOAT,NULL, 0,(yyvsp[(1) - (1)].val),linecount);
	if(DEBUG) {
		printf("%.4f\n",(yyvsp[(1) - (1)].val));
		puts("factor : cte\n");
		puts("-------------------\n");
	}

}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 545 "syntax.y"
    {
	if(DEBUG) {
		puts("factor : TOKEN_ID\n");
		puts("-------------------\n");
	}
}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 560 "syntax.y"
    {
	int i;
	puts("a");

	for (i = 0; i < variables_a_agregar; ++i)
	{
		printf("agregando %s %s\n", temp_variables[i],temp_tipo_dato[variables_a_agregar -1 - i]);
		agregar_variable_a_TS(temp_variables[i],temp_tipo_dato[variables_a_agregar - 1- i], linecount);
	}
	variables_a_agregar = 0;

	if(DEBUG) {
		puts("declaracion_variables : PR_DIM COR_ABRE declaracion_variables_interna COR_CIERRA\n");
		puts("-------------------\n");
	}
}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 578 "syntax.y"
    {
	puts("aa");

}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 585 "syntax.y"
    {
	puts("b");
	printf("leo %s %s\n", (yyvsp[(1) - (5)].str_val),(yyvsp[(5) - (5)].str_val));
	strcpy(temp_variables[variables_a_agregar],(yyvsp[(1) - (5)].str_val));
	strcpy(temp_tipo_dato[variables_a_agregar],(yyvsp[(5) - (5)].str_val));
	variables_a_agregar++;
	// agregar_variable_a_TS($1,$5,linecount);
	if(DEBUG) {
		puts("declaracion_variables_interna : TOKEN_ID COMA declaracion_variables_interna COMA tipo_dato\n");
		puts("-------------------\n");
	}
}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 599 "syntax.y"
    {


	int i;

	for (i = 0; i < variables_a_agregar; ++i)
	{
		printf("agregando %s %s\n", temp_variables[i],temp_tipo_dato[variables_a_agregar -1 - i]);
		agregar_variable_a_TS(temp_variables[i],temp_tipo_dato[variables_a_agregar - 1- i], linecount);
	}
	variables_a_agregar = 0;


	strcpy(temp_variables[variables_a_agregar],(yyvsp[(1) - (5)].str_val));
	strcpy(temp_tipo_dato[variables_a_agregar],(yyvsp[(5) - (5)].str_val));
	variables_a_agregar++;



	// agregar_variable_a_TS($1,$5,linecount);
	puts("c");
	printf("leo %s %s\n", (yyvsp[(1) - (5)].str_val),(yyvsp[(5) - (5)].str_val));
	if(DEBUG) {
		puts("declaracion_variables_interna : TOKEN_ID COR_CIERRA PR_AS COR_ABRE tipo_dato\n");
		puts("-------------------\n");
	}
}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 628 "syntax.y"
    {
	(yyval.str_val)=(yyvsp[(1) - (1)].str_val);
	if(DEBUG) {
		puts("PR_INT\n");
		puts("-------------------\n");	
	}
}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 637 "syntax.y"
    {
	(yyval.str_val)=(yyvsp[(1) - (1)].str_val);
	if(DEBUG) { 
		puts("PR_FLOAT\n");
		puts("-------------------\n");
	}
}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 646 "syntax.y"
    {

	(yyval.str_val)=(yyvsp[(1) - (1)].str_val);
	if(DEBUG) {
		puts("PR_STRING\n");
		puts("-------------------\n");
	}
}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 656 "syntax.y"
    {
	if(DEBUG) {
		puts("OP_MAYOR\n");
		puts("-------------------\n");
	}
}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 664 "syntax.y"
    {
	if(DEBUG) {
		puts("OP_MENOR\n");
		puts("-------------------\n");
	}
}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 672 "syntax.y"
    {
	if(DEBUG) {
		puts("OP_MENOR_IGUAL\n");
		puts("-------------------\n");
	}
}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 680 "syntax.y"
    {
	if(DEBUG) {
		puts("OP_MAYOR_IGUAL\n");
		puts("-------------------\n");
	}
}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 688 "syntax.y"
    {
	if(DEBUG) {
		puts("OP_IGUAL_IGUAL\n");
		puts("-------------------\n");
	}
}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 696 "syntax.y"
    {
	if(DEBUG) {
		puts("OP_DISTINTO\n");
		puts("-------------------\n");
	}
}
    break;



/* Line 1455 of yacc.c  */
#line 2405 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 703 "syntax.y"



t_simbolo tabla_simbolos[2000];
int cantidad_simbolos = 0;	
void imprimir_tabla_simbolos();
void vaciar_tabla_simbolos();
char * tipo_simbolo_to_string(int tipo);



//funcion para realizar todo lo que haga falta previo a terminar
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
	 imprimir_tabla_simbolos();


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
	printf("NOMBRE \t\t\t\t TIPO \t\t\t\t VALOR\t\t\t\t LINEA\n\n");
	for (i = 0; i < cantidad_simbolos; ++i)
	{
		if(tabla_simbolos[i].tipo == TIPO_STRING)
			printf("%s\t\t\t\t%s\t\t\t\t%s\t\t\t\t%d \n",tabla_simbolos[i].nombre,tipo_simbolo_to_string(tabla_simbolos[i].tipo),tabla_simbolos[i].valor_string == NULL ? "" : tabla_simbolos[i].valor_string,tabla_simbolos[i].lineNumber);
	
		if(tabla_simbolos[i].tipo == TIPO_INT)
			printf("%s\t\t\t\t%s\t\t\t\t%d\t\t\t\t%d\n",tabla_simbolos[i].nombre,tipo_simbolo_to_string(tabla_simbolos[i].tipo),tabla_simbolos[i].valor_int,tabla_simbolos[i].lineNumber);
		
		if(tabla_simbolos[i].tipo == TIPO_FLOAT)
			printf("%s\t\t\t\t%s\t\t\t\t%.4f\t\t\t\t%d\n",tabla_simbolos[i].nombre,tipo_simbolo_to_string(tabla_simbolos[i].tipo),tabla_simbolos[i].valor_float,tabla_simbolos[i].lineNumber);

		// if(tabla_simbolos[i].tipo == TIPO_PR)
		// 	printf("%s\t\t\t\t%s\t\t\t\t\n",tabla_simbolos[i].nombre,tipo_simbolo_to_string(tabla_simbolos[i].tipo));
				

	}
}

/** Esta funcion te permite agregar un simbolo a la tabla de simbolos.
	La idea es que se le envie el nombre del simbolo (Si es un id, el nombre
	de la variable con el  prefijo "_", el tipo de dato es un int definido
	 en las macro y el valor, en caso de que sea una constante)*/
void agregar_simbolo(char * nombre, int tipo, char * valor,char * alias, int lineNumber) {
	tabla_simbolos[cantidad_simbolos].nombre = malloc(sizeof(char) * strlen(nombre));
	strcpy(tabla_simbolos[cantidad_simbolos].nombre,nombre);


	if(alias != NULL) {
		tabla_simbolos[cantidad_simbolos].alias = malloc(sizeof(char) * strlen(alias));
		strcpy(tabla_simbolos[cantidad_simbolos].alias,alias);	
	}
	tabla_simbolos[cantidad_simbolos].tipo = tipo;
	tabla_simbolos[cantidad_simbolos].lineNumber = lineNumber;

	switch(tipo) {
		case TIPO_FLOAT:
			tabla_simbolos[cantidad_simbolos].valor_float = atof(valor);
		break;
		case TIPO_STRING:
			if(valor != NULL) {
				tabla_simbolos[cantidad_simbolos].valor_string = malloc(sizeof(char) * strlen(valor));
				strcpy(tabla_simbolos[cantidad_simbolos].valor_string,valor);	
			} else {
				tabla_simbolos[cantidad_simbolos].valor_string = NULL;
			}
		break;
		case TIPO_INT:
			tabla_simbolos[cantidad_simbolos].valor_int = atoi(valor);
		break;
		case TIPO_PR:
		break;
		default:
		puts("Tipo dato erroneo"); exit(1);
	}
	cantidad_simbolos++;


}


int buscar_en_TS_sin_prefijo(char * nombre) {
	char temp[30];
	int i;
	for (i = 0; i < cantidad_simbolos; ++i)
	{
		strcpy(temp,tabla_simbolos[i].nombre + 1);
		if(strcmp(temp,nombre) == 0) 
			return i;
	}
	return -1;
}

/* devuelve el indice del simbolo en la tabla. si no lo encuentra
devuelve -1
*/
int buscar_en_TS(char * nombre) {
	int i;
	for (i = 0; i < cantidad_simbolos; ++i)
	{
		if(strcmp(tabla_simbolos[i].nombre,nombre) == 0) 
			return i;
	}
	return -1;
}


/* Agrega una variable a la TS*/
void agregar_variable_a_TS(char * nombre, char * tipo_str, int lineNumber) {
	// printf("agrego %s en linea %d\n",nombre,linecount );
	strcpy(aux2,nombre);
	poner_prefijo(aux2,prefijo_id);
	int index;
	//si ya existe en TS, tiro error y cierro programa
	if((index = buscar_en_TS(aux2)) >= 0) {
		printf(VARIABLE_REPETIDA,nombre,tabla_simbolos[index].lineNumber);
		exit(1);
	}

	int tipo = strcmp(tipo_str, "FLOAT") == 0 ? TIPO_FLOAT : strcmp(tipo_str, "INT") == 0 ? TIPO_INT : TIPO_STRING;
	agregar_simbolo(aux2,tipo,NULL,NULL,lineNumber);
}

/*Agrega una constante a la TS*/
void agregar_cte_a_TS(int tipo, char * valor_str, int valor_int,float valor_float, int lineNumber) {

	if(tipo == TIPO_STRING) {
		strcpy(aux2,prefijo_string);
		strcat(aux2, valor_str);
		cantidad_cte_string++;
		agregar_simbolo(aux2,tipo,NULL,NULL,lineNumber);


	}else if(tipo == TIPO_INT) {
		strcpy(aux2,prefijo_int);
		sprintf(aux,"%d",valor_int);
		strcat(aux2,aux);
		agregar_simbolo(aux2,tipo,aux,NULL,lineNumber);
		
	}else if(tipo == TIPO_FLOAT) {
		strcpy(aux2,prefijo_float);
		snprintf(aux,30,"%.4f",valor_float);
		strcat(aux2,aux);
		agregar_simbolo(aux2,tipo,aux,NULL,lineNumber);
		
	}
}


/* 
Busca en la tabla de simbolos por nombre. Si los encuentra, devuelve 1 si son iguales,
o 1 si son distintos. Se le puede enviar un buffer de forma opcional para devolver
un mensaje de error
*/
int tipos_iguales(char * nombre1, char * nombre2, char * msj_error,int lineNumber) {

	int index1 = buscar_en_TS_sin_prefijo(nombre1);
	int index2 = buscar_en_TS_sin_prefijo(nombre2);

	if(index1 == -1) {
		printf(VARIABLE_INEXISTENTE, nombre1,linecount);
		imprimir_tabla_simbolos();
		exit(1);
	}
	if(index2 == -1) {
		printf(VARIABLE_INEXISTENTE, nombre2,linecount);
		imprimir_tabla_simbolos();
		exit(1);
	}

	int return_value = tabla_simbolos[index1].tipo == tabla_simbolos[index2].tipo;


	/* Si me pedian un mensaje de error, lo guardo en la variable*/
	if(!return_value && msj_error != NULL) {
		char tipo1[10];
		tabla_simbolos[index1].tipo == TIPO_STRING ? strcpy(tipo1,"STRING") : tabla_simbolos[index1].tipo == TIPO_FLOAT ? strcpy(tipo1,"FLOAT") : strcpy(tipo1,"INT");		
		char tipo2[10]; 
		tabla_simbolos[index2].tipo == TIPO_STRING ? strcpy(tipo2,"STRING") : tabla_simbolos[index2].tipo == TIPO_FLOAT ? strcpy(tipo2,"FLOAT") : strcpy(tipo2,"INT");		

		sprintf(msj_error,VARIABLE_ERROR_TIPOS,tipo1,tipo2, lineNumber);
	}
	// return 1;
	return tabla_simbolos[index1].tipo == tabla_simbolos[index2].tipo; 
}

void poner_prefijo(char * str, char * prefijo) {
	char pref[32];

	strcpy(pref, prefijo);
	strcat(pref,str);
	strcpy(str,pref);
}









