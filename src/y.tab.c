
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
#include "arbol.h"
#include "pila.h"

#define DEBUG 1
extern YYSTYPE yylval;
char prefijo_id[2] = PREFIJO_ID;
char prefijo_int[2] = PREFIJO_INT;
char prefijo_float[2] = PREFIJO_FLOAT;
char prefijo_string[2] = PREFIJO_STRING;
char temp_variables[MAX_VARIABLES][30];
char temp_tipo_dato[MAX_VARIABLES][10];
t_info * crear_info(char *);
int variables_a_agregar= 0;
char aux[30];
char aux2[30];
int cantidad_cte_string = 0;
int buscar_en_TS_sin_prefijo(char * nombre, char * mjs_error , int lineNumber );
int buscar_en_TS(char * nombre, char * mjs_error, int lineNumber);
void agregar_simbolo(char * nombre, int tipo, char * valor,char * alias,int lineNumber);
void agregar_variable_a_TS(char * nombre, char * tipo,int lineNumber);
void agregar_cte_a_TS(int tipo, char * valor_str, int valor_int,float valor_float,int lineNumber);
void agregar_cte_a_TS_sin_prefijo(int tipo, char * valor_str, int valor_int,float valor_float,int lineNumber);
void error_lexico(char * mensaje);
int tipos_iguales(char * nombre1, char * nombre2, char * mjs_error, int lineNumber);
int traer_tipo(char * nombre);
void poner_prefijo(char * str, char * prefijo);
int print_t(t_nodo_arbol *tree);
int _print_t(t_nodo_arbol *tree, int is_left, int offset, int depth, char * s, int max);
void recorrer_asm(t_nodo_arbol *n);
void copiar_sin_finalizador(char * dest,char * orig); 
void reemplazar(char * cad, char old,char new, int size) ;
t_info_sentencias * crear_info_sentencias(t_nodo_arbol * p_nodo) ;
void crear_arbol_iguales(t_nodo_arbol ** raiz);
void crear_codigo_assembler(t_nodo_arbol *tree);
void crear_inicio_assembler();
int is_hoja(t_nodo_arbol *n);

extern int linecount;
static t_info_sentencias * p_info_iguales;
static FILE *a;

t_pila * pila_sentencias;
t_pila * pila_comparaciones;
t_pila * pila_condiciones;
t_pila * pila_expresiones;
t_pila * pila_factores;
t_pila * pila_terminos;
t_pila * pila_expresiones_iguales;
t_pila * pila_variables_filter;
t_pila * pila_comparacion_filter;

t_arbol * arbol_ejecucion;
t_nodo_arbol * nodo_factor;
t_nodo_arbol * nodo_termino;
t_nodo_arbol * nodo_expresion;
t_nodo_arbol * nodo_asignacion;
t_nodo_arbol * nodo_condicion;
t_nodo_arbol * nodo_comparacion;
t_nodo_arbol * nodo_pgm;
t_nodo_arbol * nodo_programa;
t_nodo_arbol * nodo_sentencia;
t_nodo_arbol * nodo_sentencias;
t_nodo_arbol * nodo_comparador;
t_nodo_arbol * nodo_condicional;
t_nodo_arbol * nodo_iteracion;
t_nodo_arbol * nodo_io;
t_nodo_arbol * nodo_entrada;
t_nodo_arbol * nodo_salida;
t_nodo_arbol * nodo_iguales;
t_nodo_arbol * nodo_filter;
t_nodo_arbol * nodo_declaracion_variable;
t_nodo_arbol * nodo_sentencias_then;
t_nodo_arbol * nodo_sentencias_else;
t_nodo_arbol * nodo_comparacion_filter;
t_nodo_arbol * nodo_condicion_filter;



t_nodo_arbol * nodo_then;


int yylex();

FILE  *yyin; //Archivo de Entrada


/* Line 189 of yacc.c  */
#line 167 "y.tab.c"

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
#line 95 "syntax.y"

int intval;
float val;
char *str_val;



/* Line 214 of yacc.c  */
#line 301 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 313 "y.tab.c"

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
#define YYLAST   144

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  64
/* YYNRULES -- Number of states.  */
#define YYNSTATES  132

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
       0,     0,     3,     5,     9,    12,    15,    17,    20,    22,
      24,    27,    30,    33,    42,    46,    48,    57,    59,    63,
      67,    71,    75,    77,    79,    81,    84,    87,    90,    97,
     105,   108,   111,   113,   117,   121,   125,   128,   136,   140,
     144,   146,   150,   154,   156,   160,   164,   166,   168,   170,
     172,   174,   176,   182,   189,   195,   201,   203,   205,   207,
     209,   211,   213,   215,   217
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      47,     0,    -1,    48,    -1,     7,    70,    50,    -1,     7,
      50,    -1,    66,    45,    -1,    49,    -1,    49,    50,    -1,
      60,    -1,    65,    -1,    57,    45,    -1,    51,    45,    -1,
      53,    45,    -1,     8,    20,    67,    24,    22,    52,    23,
      21,    -1,    67,    24,    52,    -1,    67,    -1,     9,    20,
      54,    24,    22,    56,    23,    21,    -1,    55,    -1,    55,
      25,    55,    -1,    55,    26,    55,    -1,    40,    73,    67,
      -1,     3,    24,    56,    -1,     3,    -1,    58,    -1,    59,
      -1,    11,     3,    -1,    10,     3,    -1,    10,     5,    -1,
      12,    20,    63,    21,    61,    14,    -1,    12,    20,    63,
      21,    61,    62,    14,    -1,    13,    50,    -1,    15,    50,
      -1,    64,    -1,    64,    25,    64,    -1,    64,    26,    64,
      -1,    67,    73,    67,    -1,    16,    67,    -1,    17,    20,
      63,    21,    18,    50,    19,    -1,     3,    37,    67,    -1,
      69,    44,    69,    -1,    68,    -1,    67,    27,    68,    -1,
      67,    28,    68,    -1,    69,    -1,    68,    30,    69,    -1,
      68,    29,    69,    -1,     5,    -1,     4,    -1,     6,    -1,
       3,    -1,    51,    -1,    53,    -1,    39,    22,    71,    23,
      45,    -1,    39,    22,    71,    23,    45,    70,    -1,     3,
      24,    71,    24,    72,    -1,     3,    23,    38,    22,    72,
      -1,    42,    -1,    41,    -1,    43,    -1,    31,    -1,    33,
      -1,    34,    -1,    32,    -1,    36,    -1,    35,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   160,   160,   167,   179,   187,   202,   213,   230,   246,
     259,   269,   279,   291,   304,   315,   325,   391,   400,   412,
     425,   445,   454,   463,   474,   483,   498,   515,   525,   538,
     553,   562,   571,   583,   599,   614,   638,   652,   667,   687,
     738,   755,   787,   820,   834,   868,   903,   924,   944,   964,
     977,   990,  1007,  1025,  1032,  1044,  1066,  1075,  1084,  1093,
    1102,  1111,  1122,  1131,  1140
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
  "PUNTO_Y_COMA", "$accept", "pgm", "programa", "sentencia",
  "lista_sentencias", "iguales", "lista_expresiones", "filter",
  "condicion_filter", "comparacion_filter", "lista_variables", "io",
  "entrada", "salida", "condicional", "then", "else", "condicion",
  "comparacion", "iteracion", "asignacion", "expresion", "termino",
  "factor", "declaracion_variables", "declaracion_variables_interna",
  "tipo_dato", "comparador", 0
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
       0,    46,    47,    48,    48,    49,    50,    50,    49,    49,
      49,    49,    49,    51,    52,    52,    53,    54,    54,    54,
      55,    56,    56,    57,    57,    58,    59,    59,    60,    60,
      61,    62,    63,    63,    63,    64,    64,    65,    66,    67,
      67,    67,    67,    68,    68,    68,    69,    69,    69,    69,
      69,    69,    70,    70,    71,    71,    72,    72,    72,    73,
      73,    73,    73,    73,    73
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     3,     2,     2,     1,     2,     1,     1,
       2,     2,     2,     8,     3,     1,     8,     1,     3,     3,
       3,     3,     1,     1,     1,     2,     2,     2,     6,     7,
       2,     2,     1,     3,     3,     3,     2,     7,     3,     3,
       1,     3,     3,     1,     3,     3,     1,     1,     1,     1,
       1,     1,     5,     6,     5,     5,     1,     1,     1,     1,
       1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     0,     0,     0,     0,     0,     0,
       0,     0,     6,     4,     0,     0,     0,    23,    24,     8,
       9,     0,     0,     1,     0,     0,     0,    26,    27,    25,
       0,     0,     0,     7,    11,    12,    10,     5,     3,    49,
      47,    46,    48,    50,    51,    38,    40,    43,     0,     0,
       0,    17,     0,     0,    32,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    59,    62,    60,    61,    64,
      63,     0,     0,     0,     0,    36,     0,     0,     0,     0,
       0,     0,     0,     0,    41,    43,    42,    45,    44,    39,
       0,    20,     0,    18,    19,     0,     0,    33,    34,    35,
       0,     0,     0,    52,     0,    15,    22,     0,    30,    28,
       0,     0,     0,     0,     0,    53,     0,     0,     0,     0,
      31,    29,    37,    57,    56,    58,    55,    54,    13,    14,
      21,    16
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,    12,    13,    43,   104,    44,    50,    51,
     107,    16,    17,    18,    19,    96,   111,    53,    54,    20,
      21,    55,    46,    47,    22,    58,   126,    71
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -36
static const yytype_int8 yypact[] =
{
      -5,     6,    10,   -36,   -17,    38,    44,    26,    27,    47,
      65,    24,    16,   -36,     5,    51,    59,   -36,   -36,   -36,
     -36,    68,    16,   -36,    57,    57,    58,   -36,   -36,   -36,
      31,    31,   111,   -36,   -36,   -36,   -36,   -36,   -36,   -36,
     -36,   -36,   -36,   -36,   -36,    41,    53,    71,    14,    40,
      92,    64,    57,    96,    67,    21,    97,    20,    98,    57,
      57,    57,    57,    57,   100,   -36,   -36,   -36,   -36,   -36,
     -36,    57,   101,    58,    58,    41,   106,    31,    31,    57,
     102,    86,   111,    80,    53,   -36,    53,   -36,   -36,   -36,
      57,    41,   123,   -36,   -36,    16,    88,   -36,   -36,    41,
      16,   105,   104,    90,   107,    60,   108,   110,   -36,   -36,
      16,   117,   115,   -35,   -35,   -36,   114,    57,   123,   116,
     -36,   -36,   -36,   -36,   -36,   -36,   -36,   -36,   -36,   -36,
     -36,   -36
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -36,   -36,   -36,   -36,    -9,    -1,    19,     0,   -36,    32,
      22,   -36,   -36,   -36,   -36,   -36,   -36,   112,    30,   -36,
     -36,   -20,    52,    18,    35,    62,    25,    87
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      14,    15,     1,    33,    45,    48,   123,   124,   125,     4,
      23,    14,    15,    38,     5,     6,     7,     8,     9,     4,
      24,    14,    15,    10,     5,     6,     7,     8,     9,    27,
      29,    28,    75,    10,    39,    40,    41,    42,    64,     5,
       6,    59,    60,    81,    82,    11,    32,    52,    59,    60,
      34,    91,    65,    66,    67,    68,    69,    70,    25,    99,
      39,    40,    41,    42,    26,     5,     6,    30,    59,    60,
     105,    65,    66,    67,    68,    69,    70,    85,    85,    87,
      88,    89,    61,    62,   117,    31,   108,    59,    60,    73,
      74,   112,    77,    78,    14,    15,    35,   105,    49,    14,
      15,   120,   109,   110,    36,    93,    94,    97,    98,    14,
      15,    84,    86,    37,    57,    63,    72,    76,    80,    95,
     100,    83,    90,    92,   101,   103,   106,   113,   114,    11,
     116,   121,   118,   119,   122,   128,   129,   131,   115,   127,
     130,     0,    79,    56,   102
};

static const yytype_int8 yycheck[] =
{
       1,     1,     7,    12,    24,    25,    41,    42,    43,     3,
       0,    12,    12,    22,     8,     9,    10,    11,    12,     3,
      37,    22,    22,    17,     8,     9,    10,    11,    12,     3,
       3,     5,    52,    17,     3,     4,     5,     6,    24,     8,
       9,    27,    28,    23,    24,    39,    22,    16,    27,    28,
      45,    71,    31,    32,    33,    34,    35,    36,    20,    79,
       3,     4,     5,     6,    20,     8,     9,    20,    27,    28,
      90,    31,    32,    33,    34,    35,    36,    59,    60,    61,
      62,    63,    29,    30,    24,    20,    95,    27,    28,    25,
      26,   100,    25,    26,    95,    95,    45,   117,    40,   100,
     100,   110,    14,    15,    45,    73,    74,    77,    78,   110,
     110,    59,    60,    45,     3,    44,    24,    21,    21,    13,
      18,    23,    22,    22,    38,    45,     3,    22,    24,    39,
      23,    14,    24,    23,    19,    21,   117,    21,   103,   114,
     118,    -1,    55,    31,    82
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,    47,    48,     3,     8,     9,    10,    11,    12,
      17,    39,    49,    50,    51,    53,    57,    58,    59,    60,
      65,    66,    70,     0,    37,    20,    20,     3,     5,     3,
      20,    20,    22,    50,    45,    45,    45,    45,    50,     3,
       4,     5,     6,    51,    53,    67,    68,    69,    67,    40,
      54,    55,    16,    63,    64,    67,    63,     3,    71,    27,
      28,    29,    30,    44,    24,    31,    32,    33,    34,    35,
      36,    73,    24,    25,    26,    67,    21,    25,    26,    73,
      21,    23,    24,    23,    68,    69,    68,    69,    69,    69,
      22,    67,    22,    55,    55,    13,    61,    64,    64,    67,
      18,    38,    71,    45,    52,    67,     3,    56,    50,    14,
      15,    62,    50,    22,    24,    70,    23,    24,    24,    23,
      50,    14,    19,    41,    42,    43,    72,    72,    21,    52,
      56,    21
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
#line 161 "syntax.y"
    {
	nodo_pgm = nodo_programa;
	puts("COMPILACION EXITOSA\n");
	puts("-------------------\n");
}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 168 "syntax.y"
    {

	// nodo_declaracion_variable = nodo_sentencias;

	if(DEBUG){
		puts("Codigo con variables\n");
		puts("-------------------\n");
	}

}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 180 "syntax.y"
    {
	if(DEBUG){
		puts("Codigo sin variables\n");
		puts("-------------------\n");
	}
}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 188 "syntax.y"
    {
	if(DEBUG) {
		puts("Asignacion\n");
		puts("-------------------\n");		
	}


	nodo_sentencia = crear_nodo_arbol(crear_info(";"),nodo_asignacion,NULL);
	insertar_en_pila(&pila_sentencias,crear_info_sentencias(nodo_sentencia));


}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 203 "syntax.y"
    {
	// if(DEBUG){
		puts("Una sola sentencia\n");
		puts("-------------------\n");
		// printf("la pila esta vacia? %d\n",pila_vacia(&pila_sentencias) );
	// }
		t_info_sentencias * sentencia_apilada = sacar_de_pila(&pila_sentencias);
		nodo_sentencias = sentencia_apilada->a;
}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 214 "syntax.y"
    {
	// if(DEBUG) {
		puts("Varias sentencias\n");
		puts("-------------------\n");
	// }
	// nodo_sentencias = nodo_sentencia;
	// nodo_sentencias->nodo_der = nodo_sentencia;
	t_info_sentencias * sentencia_apilada = sacar_de_pila(&pila_sentencias);
	nodo_sentencias->nodo_der = sentencia_apilada->a;
	nodo_sentencias->nodo_der->padre = nodo_sentencias;
	nodo_sentencias = sentencia_apilada->a;


	// nodo_sentencias = crear_nodo_arbol(crear_info("NUEVA"),nodo_sentencias,sentencia_apilada->a);
}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 231 "syntax.y"
    {

	// nodo_sentencia = nodo_condicional;
	if(DEBUG) {
		puts("sentencia : condicional \n");
		puts("-------------------\n");		
	}
	
	nodo_sentencia = crear_nodo_arbol(crear_info(";"),nodo_condicional,NULL);
	insertar_en_pila(&pila_sentencias,crear_info_sentencias(nodo_sentencia));


}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 247 "syntax.y"
    {
	if(DEBUG) {
		puts("sentencia : iteracion\n");
		puts("-------------------\n");		
	}

	nodo_sentencia = crear_nodo_arbol(crear_info(";"),nodo_iteracion,NULL);
	insertar_en_pila(&pila_sentencias,crear_info_sentencias(nodo_sentencia));
	// print_t(nodo_sentencia);
	// nodo_sentencia = nodo_iteracion;
}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 260 "syntax.y"
    {
	if(DEBUG) {
		puts("Operacion de entrada salidas\n");
		puts("-------------------\n");		
	}
	nodo_sentencia = crear_nodo_arbol(crear_info(";"),nodo_io,NULL);
	insertar_en_pila(&pila_sentencias,crear_info_sentencias(nodo_sentencia));
}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 270 "syntax.y"
    {
	if(DEBUG) {
		puts("Operacion de iguales\n");
		puts("-------------------\n");	
	}
	nodo_sentencia = crear_nodo_arbol(crear_info(";"),nodo_iguales,NULL);
	insertar_en_pila(&pila_sentencias,crear_info_sentencias(nodo_sentencia));
}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 280 "syntax.y"
    {
	if(DEBUG) {
		puts("Operacioon de filters\n");
		puts("-------------------\n");
	}

	nodo_sentencia = crear_nodo_arbol(crear_info(";"),nodo_filter,NULL);
	insertar_en_pila(&pila_sentencias,crear_info_sentencias(nodo_sentencia));
	
}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 292 "syntax.y"
    {
	if(DEBUG) {
		puts("iguales : PR_IGUALES PAR_ABRE expresion COMA COR_ABRE lista_expresiones COR_CIERRA PAR_CIERRA\n");
		puts("-------------------\n");
	}
	(yyval.str_val) = "IGUALES";
	
	p_info_iguales = sacar_de_pila(&pila_expresiones);	
	crear_arbol_iguales(&nodo_iguales);		
	free(p_info_iguales);	
}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 305 "syntax.y"
    {
	if(DEBUG) {
		puts("Lista de expresiones\n");
		puts("-------------------\n");		
	}
	
	t_info_sentencias * p_info = sacar_de_pila(&pila_expresiones);
	insertar_en_pila(&pila_expresiones_iguales,p_info);	
}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 316 "syntax.y"
    {
	if(DEBUG) {
		puts("Ãšltima expresion\n");
		puts("-------------------\n");		
	}
	t_info_sentencias * p_info = sacar_de_pila(&pila_expresiones);
	insertar_en_pila(&pila_expresiones_iguales,p_info);	
}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 326 "syntax.y"
    {
	if(DEBUG) {
		puts("filter : PR_FILTER PAR_ABRE condicion COMA COR_ABRE lista_variables COR_CIERRA PAR_CIERRA\n");
		puts("-------------------\n");
	}
	(yyval.str_val) = "FILTER";

	t_info * p_op_filter = crear_info("_");
	t_nodo_arbol * p_nodo_a_reemplazar;

	nodo_filter = crear_nodo_arbol(crear_info("FILTER"),NULL,NULL);
	t_nodo_arbol * p_nodo_then_filter;

	t_nodo_arbol * template_nodo_a_reemplazar = nodo_condicion_filter;

	while(!pila_vacia(&pila_variables_filter))
	{
		t_info_sentencias * p_variable = sacar_de_pila(&pila_variables_filter);
		// printf("La variable es %s\n",p_variable->a->info->a );
		t_nodo_arbol * p_nodo_clonado = clonar_arbol(template_nodo_a_reemplazar);
		p_nodo_a_reemplazar = buscar_etiqueta(p_nodo_clonado,p_op_filter);
		if(p_nodo_a_reemplazar == NULL)
		{
			puts("es nulo... me parece que algo no esta bien...");
			exit(1); 
		}else
		{
			// puts("Encontrado");
			free(p_nodo_a_reemplazar->info);
			p_nodo_a_reemplazar->info = p_variable->a->info;
			p_nodo_a_reemplazar = buscar_etiqueta(p_nodo_clonado,p_op_filter);
			while(p_nodo_a_reemplazar != NULL)
			{
				// puts("segunda vuelta");
				free(p_nodo_a_reemplazar->info);
				p_nodo_a_reemplazar->info = p_variable->a->info;
				p_nodo_a_reemplazar = buscar_etiqueta(p_nodo_clonado,p_op_filter);
			}


			t_nodo_arbol * p_nodo_if_filter = crear_nodo_arbol(crear_info("IF"),p_nodo_clonado,NULL);
			if(nodo_filter->nodo_izq == NULL)
			{
				nodo_filter->nodo_izq = p_nodo_if_filter;
				nodo_filter->nodo_izq->padre = nodo_filter;
			} else 
			{
				p_nodo_then_filter->nodo_der = p_nodo_if_filter;
				p_nodo_then_filter->nodo_der->padre = p_nodo_then_filter;
			}


			t_nodo_arbol * p_nodo_asignacion_filter = crear_nodo_arbol(crear_info(":="),crear_hoja(crear_info(NOMBRE_RETORNO_FILTER)),crear_hoja(crear_info(p_variable->a->info->a)));
			p_nodo_then_filter = crear_nodo_arbol(crear_info("<-true . false->"),p_nodo_asignacion_filter,NULL);
			p_nodo_if_filter->nodo_der = p_nodo_then_filter;
			p_nodo_if_filter->nodo_der->padre = p_nodo_if_filter;

		}
		free(p_variable);
	}

	free(p_op_filter);

}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 392 "syntax.y"
    {
	puts("condicion_filter : comparacion_filter\n");
	puts("-------------------\n");
	t_info_sentencias * p_nodo_comparacion_filter = sacar_de_pila(&pila_comparacion_filter);
	nodo_condicion_filter = p_nodo_comparacion_filter->a;
	free(p_nodo_comparacion_filter);
}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 401 "syntax.y"
    {
	puts("condicion_filter : comparacion_filter and comparacion_filter\n");
	puts("-------------------\n");
	t_info_sentencias * p_nodo_comparacion_filter1 = sacar_de_pila(&pila_comparacion_filter);
	t_info_sentencias * p_nodo_comparacion_filter2 = sacar_de_pila(&pila_comparacion_filter);
	nodo_condicion_filter = crear_nodo_arbol(crear_info("AND"),p_nodo_comparacion_filter1->a,p_nodo_comparacion_filter2->a);

	free(p_nodo_comparacion_filter1);
	free(p_nodo_comparacion_filter2);
}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 413 "syntax.y"
    {
	puts("condicion_filter : comparacion_filter or comparacion_filter\n");
	puts("-------------------\n");

	t_info_sentencias * p_nodo_comparacion_filter1 = sacar_de_pila(&pila_comparacion_filter);
	t_info_sentencias * p_nodo_comparacion_filter2 = sacar_de_pila(&pila_comparacion_filter);
	nodo_condicion_filter = crear_nodo_arbol(crear_info("OR"),p_nodo_comparacion_filter1->a,p_nodo_comparacion_filter2->a);

	free(p_nodo_comparacion_filter1);
	free(p_nodo_comparacion_filter2);
}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 426 "syntax.y"
    {
	puts("comparacion_filter : OP_FILTER comparador expresion\n");
	puts("-------------------\n");

	t_info_sentencias * p_nodo_expresion = sacar_de_pila(&pila_expresiones);

	nodo_comparacion_filter = crear_nodo_arbol(crear_info((yyvsp[(2) - (3)].str_val)),crear_hoja(crear_info("_")),p_nodo_expresion->a);
	insertar_en_pila(&pila_comparacion_filter , crear_info_sentencias(nodo_comparacion_filter));
	// t_info_sentencias * p_info1 = sacar_de_pila(&pila_expresiones);
	// t_info_sentencias * p_info2 = sacar_de_pila(&pila_expresiones);
	// nodo_comparacion = crear_nodo_arbol(crear_info($2),p_info1->a,p_info2->a);
}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 446 "syntax.y"
    {
	if(DEBUG) {
		puts("Lista de variables\n");
		puts("-------------------\n");		
	}
	insertar_en_pila(&pila_variables_filter,crear_info_sentencias(crear_hoja(crear_info((yyvsp[(1) - (3)].str_val)))));
}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 455 "syntax.y"
    {
	if(DEBUG) {
		puts("Ultima variable\n");
		puts("-------------------\n");
	}
	insertar_en_pila(&pila_variables_filter,crear_info_sentencias(crear_hoja(crear_info((yyvsp[(1) - (1)].str_val)))));
}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 464 "syntax.y"
    {
	if(DEBUG) {
		puts("io : entrada\n");
		puts("-------------------\n");
	}

	nodo_io = nodo_entrada;

}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 475 "syntax.y"
    {
	if(DEBUG) {
		puts("io : salida\n");
		puts("-------------------\n");		
	}
	nodo_io = nodo_salida;
}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 484 "syntax.y"
    {
	if(DEBUG) {
		puts("entrada : READ id\n");
		puts("-------------------\n");		
	}
	char mjs[50];
	if(buscar_en_TS_sin_prefijo((yyvsp[(2) - (2)].str_val),mjs,linecount) == -1)
	{
		puts(mjs);
		exit(1);
	}
	nodo_entrada = crear_nodo_arbol(crear_info("READ"),crear_hoja(crear_info((yyvsp[(2) - (2)].str_val))),NULL);
}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 499 "syntax.y"
    {
	if(DEBUG) {
		puts("salida : PR_WRITE id\n");
		puts("-------------------\n");
	}

	char mjs[50];
	if(buscar_en_TS_sin_prefijo((yyvsp[(2) - (2)].str_val),mjs,linecount) == -1)
	{
		puts(mjs);
		exit(1);
	}
	nodo_salida = crear_nodo_arbol(crear_info("WRITE"),crear_hoja(crear_info((yyvsp[(2) - (2)].str_val))),NULL);

}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 516 "syntax.y"
    {
	if(DEBUG) {
		puts("salida : PR_WRITE cte\n");
		puts("-------------------\n");	
	}
	nodo_salida = crear_nodo_arbol(crear_info("WRITE"),crear_hoja(crear_info((yyvsp[(2) - (2)].str_val))),NULL);

}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 526 "syntax.y"
    {
	if(DEBUG) {
		puts("Condicional sin ELSE\n");
		puts("-------------------\n");
	}

	t_info_sentencias * p_info = sacar_de_pila(&pila_condiciones);
	//le pongo null porque ahi iria el ELSE y no hay
	nodo_then = crear_nodo_arbol(crear_info("THEN"),nodo_sentencias_then,NULL);
	nodo_condicional = crear_nodo_arbol(crear_info("IF"),p_info->a,nodo_then);
}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 539 "syntax.y"
    {


	if(DEBUG) {
		puts("Condicional con ELSE\n");
		puts("-------------------\n");	
	}

	t_info_sentencias * p_info = sacar_de_pila(&pila_condiciones);
	nodo_then = crear_nodo_arbol(crear_info("<-true . false->"),nodo_sentencias_then,nodo_sentencias_else);
	nodo_condicional = crear_nodo_arbol(crear_info("IF"),p_info->a,nodo_then);

}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 554 "syntax.y"
    {
	if(DEBUG) {
		puts("PR_THEN lista_sentencias\n");
		puts("-------------------\n");	
	}
	nodo_sentencias_then = obtener_raiz(nodo_sentencias);
}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 563 "syntax.y"
    {
	if(DEBUG) {
		puts("PR_ELSE lista_sentencias\n");
		puts("-------------------\n");	
	}
	nodo_sentencias_else = obtener_raiz(nodo_sentencias);
}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 572 "syntax.y"
    {
	// if(DEBUG) {
		puts("condicion : comparacion\n");
		puts("-------------------\n");
	// }
	t_info_sentencias * p_info = sacar_de_pila(&pila_comparaciones);
	nodo_condicion = p_info->a;
	insertar_en_pila(&pila_condiciones,crear_info_sentencias(nodo_condicion));

}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 584 "syntax.y"
    {
	// if(DEBUG) {
		puts("condicion : comparacion and comparacion\n");
		puts("-------------------\n");		
	// }

	t_info_sentencias * p_info1 = sacar_de_pila(&pila_comparaciones);
	t_info_sentencias * p_info2 = sacar_de_pila(&pila_comparaciones);

	nodo_condicion = crear_nodo_arbol(crear_info("AND"),p_info1->a,p_info2->a);
	insertar_en_pila(&pila_condiciones,crear_info_sentencias(nodo_condicion));


}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 600 "syntax.y"
    {
	// if(DEBUG) {
		puts("condicion : comparacion or comparacion\n");
		puts("-------------------\n");		
	// }

	t_info_sentencias * p_info1 = sacar_de_pila(&pila_comparaciones);
	t_info_sentencias * p_info2 = sacar_de_pila(&pila_comparaciones);

	nodo_condicion = crear_nodo_arbol(crear_info("OR"),p_info1->a,p_info2->a);
	insertar_en_pila(&pila_condiciones,crear_info_sentencias(nodo_condicion));

}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 615 "syntax.y"
    {
	// if(DEBUG) {
	// puts($2);
		puts("comparacion : expresion comparador expresion\n");
		puts("-------------------\n");
	// }
	char mjs_error[60];
	/* comparo que para operar entre terminos, ambos tengan el mismo tipo de datos*/ 
	if(!tipos_iguales((yyvsp[(1) - (3)].str_val),(yyvsp[(3) - (3)].str_val),mjs_error,linecount)) 
	{
		puts(mjs_error);
		exit(1);
	}

	t_info_sentencias * p_info1 = sacar_de_pila(&pila_expresiones);
	t_info_sentencias * p_info2 = sacar_de_pila(&pila_expresiones);
	nodo_comparacion = crear_nodo_arbol(crear_info((yyvsp[(2) - (3)].str_val)),p_info1->a,p_info2->a);

	// puts("a ver esto ahora");
	// nodo_comparacion = crear_nodo_arbol(crear_info($2),nodo_expresion,nodo_termino);
	insertar_en_pila(&pila_comparaciones,crear_info_sentencias(nodo_comparacion));
}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 639 "syntax.y"
    {
	if(DEBUG) {
		puts("comparacion : PR_NOT expresion comparador expresion\n");
		puts("-------------------\n");
	}

	t_info_sentencias * p_info = sacar_de_pila(&pila_expresiones);

	nodo_comparacion = crear_nodo_arbol(crear_info("NOT"),p_info->a,NULL);
	insertar_en_pila(&pila_comparaciones,crear_info_sentencias(nodo_comparacion));

}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 653 "syntax.y"
    {
	if(DEBUG) {
		puts("iteracion : PR_WHILE PAR_ABRE condicion PAR_CIERRA PR_DO lista_sentencias PR_ENDWHILE\n");
		puts("-------------------\n");
	}

	t_info_sentencias * p_info = sacar_de_pila(&pila_condiciones);
	t_nodo_arbol * sentencias_del_do = obtener_raiz(nodo_sentencias);
	// nodo_do = crear_nodo_arbol(crear_info("DO"),sentencias_del_do,NULL);
	nodo_iteracion = crear_nodo_arbol(crear_info("WHILE"),p_info->a,sentencias_del_do);
	sentencias_del_do->padre = nodo_iteracion;

}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 668 "syntax.y"
    {
	if(DEBUG) {
		puts("Asignacion -> Token_ID := expresion\n");
		puts("-------------------\n");
	}

	// printf("asignacion %s %s\n",$1,$3 );
	/* comparo que para operar entre terminos, ambos tengan el mismo tipo de datos*/ 
	char mjs_error[60];
	if(!tipos_iguales((yyvsp[(1) - (3)].str_val),(yyvsp[(3) - (3)].str_val),mjs_error, linecount)) {
		puts(mjs_error);
		exit(1);
	}
	t_info_sentencias * p_info = sacar_de_pila(&pila_expresiones);
	/* guardo la asignacion en el arbol de ejecucion */
	nodo_asignacion = crear_nodo_arbol(crear_info(":="),crear_hoja(crear_info((yyvsp[(1) - (3)].str_val))),p_info->a);

}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 688 "syntax.y"
    {
	if(DEBUG) {
		printf("expresion %s %s\n",(yyvsp[(1) - (3)].str_val),(yyvsp[(3) - (3)].str_val) );
		puts("expresion : factor OP_CONCAT factor ");
		puts("-------------------\n");
	}

	/* comparo que para operar entre terminos, ambos tengan el mismo tipo de datos*/ 
	char mjs_error[60];
	if(!tipos_iguales((yyvsp[(1) - (3)].str_val),(yyvsp[(3) - (3)].str_val),mjs_error, linecount)) {
		puts(mjs_error);
		exit(1);
	}

	/* Verifico que no este concatenando flotantes*/
	int tipo = traer_tipo((yyvsp[(3) - (3)].str_val));
	if(tipo == TIPO_FLOAT) {
		char aux_float[10];
		char aux_float2[10];
		sprintf(aux_float,"%s",(yyvsp[(1) - (3)].str_val));
		sprintf(aux_float2,"%s",(yyvsp[(3) - (3)].str_val));
		sprintf(mjs_error,OPERACION_INVALIDA_TIPOS,"CONCATENACION",aux_float,aux_float2,"FLOAT",linecount);
		puts(mjs_error);
		exit(1);
	}

	/* Verifico que no este concatenando enteros*/
	if(tipo == TIPO_INT) {
		char aux_int[10];
		char aux_int2[10];
		sprintf(aux_int,"%s",(yyvsp[(1) - (3)].str_val));
		sprintf(aux_int2,"%s",(yyvsp[(3) - (3)].str_val));
		sprintf(mjs_error,OPERACION_INVALIDA_TIPOS,"CONCATENACION",aux_int,aux_int2,"INT",linecount);
		puts(mjs_error);
		exit(1);
	}


	/* guardo la expresion en el arbol de ejecucion */

	t_info_sentencias * p_nodo_factor1 = sacar_de_pila(&pila_factores);

	t_info_sentencias * p_nodo_factor2 = sacar_de_pila(&pila_factores);

	nodo_expresion = crear_nodo_arbol(crear_info("++"),p_nodo_factor1->a,p_nodo_factor2->a);

	insertar_en_pila(&pila_expresiones,crear_info_sentencias(nodo_expresion));

}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 739 "syntax.y"
    {
	if(DEBUG) {
	printf("%s\n",(yyvsp[(1) - (1)].str_val) );
		puts("Expresion -> termino\n");
		puts("-------------------\n");
	}

	(yyval.str_val)=(yyvsp[(1) - (1)].str_val);
	
	/* guardo la expresion en el arbol de ejecucion */
	t_info_sentencias * p_nodo_termino = sacar_de_pila(&pila_terminos);
	nodo_expresion = p_nodo_termino->a;
	insertar_en_pila(&pila_expresiones,p_nodo_termino);

}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 756 "syntax.y"
    {
	if(DEBUG) {
		printf("%s %s\n", (yyvsp[(1) - (3)].str_val), (yyvsp[(3) - (3)].str_val));
		puts("expresion : expresion OP_SUMA termino\n");
		puts("-------------------\n");
	}
	/* comparo que para operar entre terminos, ambos tengan el mismo tipo de datos*/ 
	char mjs_error[60];
	if(!tipos_iguales((yyvsp[(1) - (3)].str_val),(yyvsp[(3) - (3)].str_val),mjs_error, linecount)) {
		puts(mjs_error);
		exit(1);
	}
	/* Verifico que no este sumando strings*/
	int tipo = traer_tipo((yyvsp[(3) - (3)].str_val));
	if(tipo == TIPO_STRING) {
		sprintf(mjs_error,OPERACION_INVALIDA_TIPOS,"SUMA",(yyvsp[(1) - (3)].str_val),(yyvsp[(3) - (3)].str_val),"STRING",linecount);
		puts(mjs_error);
		exit(1);
	}

	/* guardo la expresion en el arbol de ejecucion */
	t_info_sentencias * p_nodo_expresion = sacar_de_pila(&pila_expresiones);
	t_info_sentencias * p_nodo_termino =  sacar_de_pila(&pila_terminos);
	nodo_expresion = crear_nodo_arbol(crear_info("+"),p_nodo_expresion->a,p_nodo_termino->a);
	insertar_en_pila(&pila_expresiones,crear_info_sentencias(nodo_expresion));

	free(p_nodo_expresion);
	free(p_nodo_termino);

}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 788 "syntax.y"
    {
	if(DEBUG) {
		printf("%s %s\n", (yyvsp[(1) - (3)].str_val), (yyvsp[(3) - (3)].str_val));
		puts("Resta\n");
		puts("-------------------\n");
	}

	/* comparo que para operar entre terminos, ambos tengan el mismo tipo de datos*/ 
	char mjs_error[60];
	if(!tipos_iguales((yyvsp[(1) - (3)].str_val),(yyvsp[(3) - (3)].str_val),mjs_error, linecount)) {
		puts(mjs_error);
		exit(1);
	}
	/* Verifico que no este restando strings*/
	int tipo = traer_tipo((yyvsp[(3) - (3)].str_val));
	if(tipo == TIPO_STRING) {
		sprintf(mjs_error,OPERACION_INVALIDA_TIPOS,"RESTA",(yyvsp[(1) - (3)].str_val),(yyvsp[(3) - (3)].str_val),"STRING",linecount);
		puts(mjs_error);
		exit(1);
	}

	/* guardo la expresion en el arbol de ejecucion */
	t_info_sentencias * p_nodo_expresion = sacar_de_pila(&pila_expresiones);
	t_info_sentencias * p_nodo_termino =  sacar_de_pila(&pila_terminos);
	nodo_expresion = crear_nodo_arbol(crear_info("-"),p_nodo_expresion->a,p_nodo_termino->a);
	insertar_en_pila(&pila_expresiones,crear_info_sentencias(nodo_expresion));

	free(p_nodo_expresion);
	free(p_nodo_termino);

}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 821 "syntax.y"
    {
	if(DEBUG) {
	printf("%s\n",(yyvsp[(1) - (1)].str_val) );
		puts("termino : factor\n");
		puts("-------------------\n");
	}
	/*guardo el termino en el arbol de ejecucion*/
	t_info_sentencias * p_nodo_factor = sacar_de_pila(&pila_factores);
	nodo_termino = p_nodo_factor->a;
	insertar_en_pila(&pila_terminos,p_nodo_factor);

}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 835 "syntax.y"
    {
	if(DEBUG) {
	printf("%s %s\n", (yyvsp[(1) - (3)].str_val),(yyvsp[(3) - (3)].str_val));
		puts("termino : termino OP_DIV factor\n");
		puts("-------------------\n");
	}
	/* comparo que para operar entre terminos, ambos tengan el mismo tipo de datos*/ 
	char mjs_error[60];
	if(!tipos_iguales((yyvsp[(1) - (3)].str_val),(yyvsp[(3) - (3)].str_val),mjs_error, linecount)) {
		puts(mjs_error);
		exit(1);
	}

	/* Verifico que no este dividiendo strings*/
	int tipo = traer_tipo((yyvsp[(3) - (3)].str_val));
	if(tipo == TIPO_STRING) {
		sprintf(mjs_error,OPERACION_INVALIDA_TIPOS,"DIVISION",(yyvsp[(1) - (3)].str_val),(yyvsp[(3) - (3)].str_val),"STRING",linecount);
		puts(mjs_error);
		exit(1);
	}

	/*guardo el termino en el arbol de ejecucion*/
	t_info_sentencias * p_nodo_factor = sacar_de_pila(&pila_factores);
	t_info_sentencias * p_nodo_termino = sacar_de_pila(&pila_terminos);

	nodo_termino = crear_nodo_arbol(crear_info("/"),p_nodo_termino->a,p_nodo_factor->a);
	insertar_en_pila(&pila_terminos,crear_info_sentencias(nodo_termino));

	free(p_nodo_factor);
	free(p_nodo_termino);

}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 869 "syntax.y"
    {
	if(DEBUG) {
	printf("%s %s\n", (yyvsp[(1) - (3)].str_val),(yyvsp[(3) - (3)].str_val));
		puts("termino : termino OP_MUL factor\n");
		puts("-------------------\n");
	}

	/* comparo que para operar entre terminos, ambos tengan el mismo tipo de datos*/ 
	char mjs_error[60];
	if(!tipos_iguales((yyvsp[(1) - (3)].str_val),(yyvsp[(3) - (3)].str_val),mjs_error, linecount)) {
		puts(mjs_error);
		exit(1);
	}

	/* Verifico que no este multiplicando strings*/
	int tipo = traer_tipo((yyvsp[(3) - (3)].str_val));
	if(tipo == TIPO_STRING) {
		sprintf(mjs_error,OPERACION_INVALIDA_TIPOS,"MULTIPLICACION",(yyvsp[(1) - (3)].str_val),(yyvsp[(3) - (3)].str_val),"STRING",linecount);
		puts(mjs_error);
		exit(1);
	}

	/*guardo el termino en el arbol de ejecucion*/
	t_info_sentencias * p_nodo_factor = sacar_de_pila(&pila_factores);
	t_info_sentencias * p_nodo_termino = sacar_de_pila(&pila_terminos);

	nodo_termino = crear_nodo_arbol(crear_info("*"),p_nodo_termino->a,p_nodo_factor->a);
	insertar_en_pila(&pila_terminos,crear_info_sentencias(nodo_termino));

	free(p_nodo_factor);
	free(p_nodo_termino);

}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 904 "syntax.y"
    {
	if(DEBUG) {
		// printf("%s\n",$1);
		puts("factor : cte\n");
		puts("-------------------\n");		
	}

	/* agrego la constante a la tabla de simbolos */
	agregar_cte_a_TS(TIPO_STRING,(yyvsp[(1) - (1)].str_val), 0,0.0,linecount);
	(yyval.str_val)=(yyvsp[(1) - (1)].str_val);

	/*guardo el termino en el arbol de ejecucion*/
	nodo_factor =  crear_hoja(crear_info((yyvsp[(1) - (1)].str_val)));
	insertar_en_pila(&pila_factores,crear_info_sentencias(nodo_factor));
	// nodo_factor = crear_hoja(crear_info($1));

	puts((yyvsp[(1) - (1)].str_val));

}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 925 "syntax.y"
    {
	if(DEBUG) {
		printf("%d\n",(yyvsp[(1) - (1)].intval));
		puts("factor : cte\n");
		puts("-------------------\n");		
	}
	/* agrego la constante a la tabla de simbolos, pero para hacerlo, primero
	tengo que castearla a string */
	char temp[10];
	sprintf(temp,"%d",(yyvsp[(1) - (1)].intval));
	(yyval.str_val) = temp;
	agregar_cte_a_TS(TIPO_INT,NULL, (yyvsp[(1) - (1)].intval),0.0,linecount);

	/*guardo el termino en el arbol de ejecucion*/
	nodo_factor =  crear_hoja(crear_info(temp));
	insertar_en_pila(&pila_factores,crear_info_sentencias(nodo_factor));
	// nodo_factor = crear_hoja(crear_info(temp));
}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 945 "syntax.y"
    {
	if(DEBUG) {
		printf("%.4f\n",(yyvsp[(1) - (1)].val));
		puts("factor : cte\n");
		puts("-------------------\n");
	}
	/* agrego la constante a la tabla de simbolos, pero para hacerlo, primero
	tengo que castearla a string */
	char temp[10];
	sprintf(temp,"%.4f",(yyvsp[(1) - (1)].val));
	(yyval.str_val) = temp;
	agregar_cte_a_TS(TIPO_FLOAT,NULL, 0,(yyvsp[(1) - (1)].val),linecount);

	/*guardo el termino en el arbol de ejecucion*/
	nodo_factor =  crear_hoja(crear_info(temp));
	insertar_en_pila(&pila_factores,crear_info_sentencias( nodo_factor));
	// nodo_factor = crear_hoja(crear_info(temp));
}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 965 "syntax.y"
    {
	if(DEBUG) {
		puts("factor : TOKEN_ID\n");
		puts("-------------------\n");
	}
	/*guardo el termino en el arbol de ejecucion*/
	nodo_factor =  crear_hoja(crear_info((yyvsp[(1) - (1)].str_val)));
	insertar_en_pila(&pila_factores,crear_info_sentencias(nodo_factor ));
	// nodo_factor = crear_hoja(crear_info(temp));
}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 978 "syntax.y"
    {
	if(DEBUG) {
		puts((yyvsp[(1) - (1)].str_val));
		puts("factor : iguales \n");
		puts("-------------------\n");	
	}
	insertar_en_pila(&pila_factores,crear_info_sentencias(crear_nodo_arbol(crear_info("IGUALES"),nodo_iguales,NULL)));
	// nodo_factor = crear_nodo_arbol(crear_info("IGUALES"),nodo_iguales,NULL);
	//nodo_sentencia = crear_nodo_arbol(crear_info(";"),nodo_iguales,NULL);
	//insertar_en_pila(&pila_sentencias,crear_info_sentencias(nodo_sentencia));
}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 991 "syntax.y"
    {
	if(DEBUG) {
		puts((yyvsp[(1) - (1)].str_val));
		puts("factor : filter\n");
		puts("-------------------\n");	
	}	
	insertar_en_pila(&pila_factores,crear_info_sentencias(nodo_filter));

}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 1009 "syntax.y"
    {
	if(DEBUG) {
		puts("declaracion_variables : PR_DIM COR_ABRE declaracion_variables_interna COR_CIERRA\n");
		puts("-------------------\n");
	}
	int i;
	/*agrego las variables a la tabla de simbolos, recorro en forma de cola y pila
	los vectores que cree anteriormente para invertir el orden de los tipos de datos*/
	for (i = 0; i < variables_a_agregar; ++i)
	{
		// printf("agregando %s %s\n", temp_variables[i],temp_tipo_dato[variables_a_agregar -1 - i]);
		agregar_variable_a_TS(temp_variables[i],temp_tipo_dato[variables_a_agregar - 1- i], linecount);
	}
	variables_a_agregar = 0;
}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 1026 "syntax.y"
    {
	puts("declaracion_variables : PR_DIM COR_ABRE declaracion_variables_interna COR_CIERRA\n");
	puts("-------------------\n");
}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 1033 "syntax.y"
    {
	if(DEBUG) {
		puts("declaracion_variables_interna : TOKEN_ID COMA declaracion_variables_interna COMA tipo_dato\n");
		puts("-------------------\n");
	}
	/* Agrego de forma temporal los datos leidos, para luego procesarlos */
	strcpy(temp_variables[variables_a_agregar],(yyvsp[(1) - (5)].str_val));
	strcpy(temp_tipo_dato[variables_a_agregar],(yyvsp[(5) - (5)].str_val));
	variables_a_agregar++;
}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 1045 "syntax.y"
    {
	if(DEBUG) {
		puts("declaracion_variables_interna : TOKEN_ID COR_CIERRA PR_AS COR_ABRE tipo_dato\n");
		puts("-------------------\n");
	}
	int i;
	/*agrego las variables a la tabla de simbolos, recorro en forma de cola y pila
	los vectores que cree anteriormente para invertir el orden de los tipos de datos*/
	for (i = 0; i < variables_a_agregar; ++i)
	{
		printf("agregando %s %s\n", temp_variables[i],temp_tipo_dato[variables_a_agregar -1 - i]);
		agregar_variable_a_TS(temp_variables[i],temp_tipo_dato[variables_a_agregar - 1 - i], linecount);
	}
	variables_a_agregar = 0;

	/* Agrego de forma temporal los datos leidos, para luego procesarlos */
	strcpy(temp_variables[variables_a_agregar],(yyvsp[(1) - (5)].str_val));
	strcpy(temp_tipo_dato[variables_a_agregar],(yyvsp[(5) - (5)].str_val));
	variables_a_agregar++;
}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 1067 "syntax.y"
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
#line 1076 "syntax.y"
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
#line 1085 "syntax.y"
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
#line 1094 "syntax.y"
    {
	// strcpy(nodo_comparador->info->a, ">");
	if(DEBUG) {
		puts("OP_MAYOR\n");
		puts("-------------------\n");
	}
}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 1103 "syntax.y"
    {
	// strcpy(nodo_comparador->info->a, "<");
	if(DEBUG) {
		puts("OP_MENOR\n");
		puts("-------------------\n");
	}
}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 1112 "syntax.y"
    {
	// strcpy(nodo_comparador->info->a, "<=");

	(yyval.str_val)=(yyvsp[(1) - (1)].str_val);
	if(DEBUG) {
		puts("OP_MENOR_IGUAL\n");
		puts("-------------------\n");
	}
}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 1123 "syntax.y"
    {
	// strcpy(nodo_comparador->info->a, ">=");
	if(DEBUG) {
		puts("OP_MAYOR_IGUAL\n");
		puts("-------------------\n");
	}
}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 1132 "syntax.y"
    {
	// strcpy(nodo_comparador->info->a, "==");
	if(DEBUG) {
		puts("OP_IGUAL_IGUAL\n");
		puts("-------------------\n");
	}
}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 1141 "syntax.y"
    {
	// strcpy(nodo_comparador->info->a, "!=");
	if(DEBUG) {
		puts("OP_DISTINTO\n");
		puts("-------------------\n");
	}
}
    break;



/* Line 1455 of yacc.c  */
#line 2852 "y.tab.c"
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
#line 1149 "syntax.y"



t_simbolo tabla_simbolos[2000];
int cantidad_simbolos = 0;	
void imprimir_tabla_simbolos();
void vaciar_tabla_simbolos();
char * tipo_simbolo_to_string(int tipo);



//funcion para realizar todo lo que haga falta previo a terminar
void finally(FILE *yyin){
	vaciar_tabla_simbolos();
	fclose(a);
	// vaciar_arbol(&arbol_ejecucion);
	fclose(yyin);
}



int main(int argc, char **argv ) {
	// puts("Corriendo el compilador...");
	crear_inicio_assembler();

	++argv, --argc; 

	if ( argc > 0 ) {
	    yyin = fopen( argv[0], "r" );
    }	else {
	    yyin = stdin;

    }
    crear_pila(&pila_sentencias);
    crear_pila(&pila_comparaciones);
    crear_pila(&pila_condiciones);
    crear_pila(&pila_factores);
    crear_pila(&pila_terminos);
    crear_pila(&pila_expresiones);
    crear_pila(&pila_expresiones_iguales);
    crear_pila(&pila_variables_filter);
    crear_pila(&pila_comparacion_filter);
    crear_arbol(&arbol_ejecucion);

    agregar_variable_a_TS("IGUALES","INT", 0);
    agregar_variable_a_TS("FILTER","INT", 0);

	yyparse();
	imprimir_tabla_simbolos();
	arbol_ejecucion->p_nodo = obtener_raiz(nodo_sentencia);

	// crear_codigo_assembler(arbol_ejecucion->p_nodo);
	// arbol_ejecucion->p_nodo = obtener_raiz(nodo_iguales);

	//recorrer_en_orden(arbol_ejecucion->p_nodo,&visitar);
	// puts("hola");
	print_t(arbol_ejecucion->p_nodo);
	
	// imprimir_arbol(arbol_ejecucion->p_nodo);

	// printf("la pila esta vacia? %d\n", pila_vacia(&pila_sentencias) );
	// if(!pila_vacia)
	// {
	// 	t_nodo_arbol
	// }
	
	crear_codigo_assembler(arbol_ejecucion->p_nodo);
	finally(yyin);
	puts("cerrando todoooo");
	return EXIT_SUCCESS;
}

int yyerror(void)
{
	printf("Syntax Error\n");
	system ("Pause");
	exit (1);
}

/* borra todo el contenido de la tabla de simbolos, generalmente para ser borrado */
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

/* le envias una de las constantes definidas en define.h y te devuelve un equivalente en string
seria como hacerle un toString al tipo de dato entero */
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

/* imprime la tabla de simbolos a un archivo txt*/
void imprimir_tabla_simbolos() {
	FILE *f = fopen(PATH_TABLA_SIMBOLOS, "w");
	if (f == NULL)
	{
	    puts(ERROR_ABRIR_TABLA_SIMBOLOS);
	    exit(1);
	}
	int i;
	fprintf(f, "NOMBRE \t\t\t\t TIPO \t\t\t\t VALOR\t\t\t\t LINEA\n\n");
	for (i = 0; i < cantidad_simbolos; ++i)
	{
		if(tabla_simbolos[i].tipo == TIPO_STRING)
		{
			fprintf(f, "%s\t\t\t\t%s\t\t\t\t%s\t\t\t\t%d \n",tabla_simbolos[i].nombre,tipo_simbolo_to_string(tabla_simbolos[i].tipo),tabla_simbolos[i].valor_string == NULL ? "" : tabla_simbolos[i].valor_string,tabla_simbolos[i].lineNumber);
			if(tabla_simbolos[i].nombre[0] == '_')
			{
				fprintf(a, "\n");
				fprintf(a, tabla_simbolos[i].nombre);			
				fprintf(a, " DW ?");
			}
		}
	
		if(tabla_simbolos[i].tipo == TIPO_INT)
		{
			fprintf(f, "%s\t\t\t\t%s\t\t\t\t%d\t\t\t\t%d\n",tabla_simbolos[i].nombre,tipo_simbolo_to_string(tabla_simbolos[i].tipo),tabla_simbolos[i].valor_int,tabla_simbolos[i].lineNumber);
			if(tabla_simbolos[i].nombre[0] == '_')
			{
				fprintf(a, "\n");
				fprintf(a, tabla_simbolos[i].nombre);			
				fprintf(a, " DW ?");
			}
		}
		
		if(tabla_simbolos[i].tipo == TIPO_FLOAT)
		{
			fprintf(f, "%s\t\t\t\t%s\t\t\t\t%.4f\t\t\t\t%d\n",tabla_simbolos[i].nombre,tipo_simbolo_to_string(tabla_simbolos[i].tipo),tabla_simbolos[i].valor_float,tabla_simbolos[i].lineNumber);
			if(tabla_simbolos[i].nombre[0] == '_')
			{
				fprintf(a, "\n");
				fprintf(a, tabla_simbolos[i].nombre);			
				fprintf(a, " DW ?");
			}
		}
		
		// if(tabla_simbolos[i].tipo == TIPO_PR)
		// 	fprintf(f, "%s\t\t\t\t%s\t\t\t\t\n",tabla_simbolos[i].nombre,tipo_simbolo_to_string(tabla_simbolos[i].tipo));
				

	}
	fclose(f);
}

/** Esta funcion te permite agregar un simbolo a la tabla de simbolos.
	La idea es que se le envie el nombre del simbolo (Si es un id, el nombre
	de la variable con el  prefijo "_", el tipo de dato es un int definido
	 en las macro y el valor, en caso de que sea una constante)*/
void agregar_simbolo(char * nombre, int tipo, char * valor,char * alias, int lineNumber) {
int n;
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
			valor="0";
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
			valor="0";
			tabla_simbolos[cantidad_simbolos].valor_int = atoi(valor);
		break;
		case TIPO_PR:
		break;
		default:
		puts("Tipo dato erroneo"); exit(1);
	}
	cantidad_simbolos++;


}

/* Busca una variable en la TS sin tener en cuenta sus prefijos y devuelve
el indice. si no lo encuentra, devuelve -1;*/
int buscar_en_TS_sin_prefijo(char * nombre, char * mjs_error, int lineNumber) {
	char temp[30];
	int i;
	for (i = 0; i < cantidad_simbolos; ++i)
	{
		strcpy(temp,tabla_simbolos[i].nombre + 1);
		if(strcmp(temp,nombre) == 0) 
			return i;
	}
	if(mjs_error != NULL) 
		sprintf(mjs_error,VARIABLE_INEXISTENTE,nombre, lineNumber);
	return -1;
}

/* devuelve el indice del simbolo en la tabla. si no lo encuentra
devuelve -1
*/
int buscar_en_TS(char * nombre, char * mjs_error, int lineNumber) {
	int i;
	for (i = 0; i < cantidad_simbolos; ++i)
	{
		if(strcmp(tabla_simbolos[i].nombre,nombre) == 0) 
			return i;
	}
	if(mjs_error != NULL) 
		sprintf(mjs_error,VARIABLE_INEXISTENTE,nombre, lineNumber);
	return -1;
}


/* Agrega una variable a la TS*/
void agregar_variable_a_TS(char * nombre, char * tipo_str, int lineNumber) {
	// printf("agrego %s en linea %d\n",nombre,linecount );
	strcpy(aux2,nombre);
	poner_prefijo(aux2,prefijo_id);
	int index;
	//si ya existe en TS, tiro error y cierro programa
	if((index = buscar_en_TS(aux2, NULL,0)) >= 0) {
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
		if(buscar_en_TS_sin_prefijo(valor_str,NULL,0) != -1)
		return;

		cantidad_cte_string++;
		agregar_simbolo(aux2,tipo,NULL,NULL,lineNumber);


	}else if(tipo == TIPO_INT) {
		strcpy(aux2,prefijo_int);
		sprintf(aux,"%d",valor_int);
		strcat(aux2,aux);
		if(buscar_en_TS_sin_prefijo(aux,NULL,0) != -1)
		return;

		agregar_simbolo(aux2,tipo,aux,NULL,lineNumber);
		
	}else if(tipo == TIPO_FLOAT) {
		strcpy(aux2,prefijo_float);
		snprintf(aux,30,"%.4f",valor_float);
		strcat(aux2,aux);
		if(buscar_en_TS_sin_prefijo(aux,NULL,0) != -1)
		return;
		agregar_simbolo(aux2,tipo,aux,NULL,lineNumber);
		
	}
}

/*Busca un simbolo en la TS por su nombre, y te devuelve su tipo */
int traer_tipo(char * nombre) {
	int index = buscar_en_TS_sin_prefijo(nombre, NULL,0);
	return tabla_simbolos[index].tipo;
}

/* 
Busca en la tabla de simbolos por nombre. Si los encuentra, devuelve 1 si son iguales,
o 0 si son distintos. Se le puede enviar un buffer de forma opcional para devolver
un mensaje de error
*/
int tipos_iguales(char * nombre1, char * nombre2, char * msj_error,int lineNumber) {

	int index1 = buscar_en_TS_sin_prefijo(nombre1,msj_error,lineNumber);
	int index2 = buscar_en_TS_sin_prefijo(nombre2,msj_error,lineNumber);

// printf("%s %s %d %d\n",nombre1,nombre2,index1,index2 );
	if(index1 == -1 || index2 == -1) {
		return 0;
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

/* Esta funcion le pone un prefijo a una string base*/
void poner_prefijo(char * str, char * prefijo) {
	char pref[32];

	strcpy(pref, prefijo);
	strcat(pref,str);
	strcpy(str,pref);
}

/* Esta funcion crea un t_info a partir de una string, para agregarla
directamente a un nodo de arbol */
t_info * crear_info(char * str) 
{
	t_info * p_info = (t_info *) malloc(sizeof(t_info));
	strcpy(p_info->a,str);
	return p_info;
}

t_info_sentencias * crear_info_sentencias(t_nodo_arbol * p_nodo) 
{
	t_info_sentencias * p_info = (t_info_sentencias *) malloc(sizeof(t_info_sentencias));
	p_info->a = p_nodo;
	return p_info;
}




int _print_t(t_nodo_arbol *tree, int is_left, int offset, int depth, char * s, int max)
{
    int i;
    char b[20];
    int width = 5;

    if (!tree) return 0;

    sprintf(b, "(%s)", tree->info->a);

    int left  = _print_t(tree->nodo_izq,  1, offset,                depth + 1, s,max);
    int right = _print_t(tree->nodo_der, 0, offset + left + width, depth + 1, s,max);


    // printf("%s is_left %d offset %d depth %d width %d b %s \n ", tree->info->a,
    //  is_left,offset,depth,width,b);

    	copiar_sin_finalizador(s + (2 * depth)*max + offset + left,b);

    if (depth && is_left) {

        for (i = 0; i < width + right; i++)
        	copiar_sin_finalizador(s + (2 * depth - 1)*max  + offset + left + width/2 + i,"-"); 
    	copiar_sin_finalizador(s + (2 * depth - 1)*max  + offset + left + width/2 ,"+"); 
    	copiar_sin_finalizador(s + (2 * depth - 1)*max  + offset + left + width + right + width/2 ,"+"); 

    } else if (depth && !is_left) {
        for (i = 0; i < left + width; i++)
    		copiar_sin_finalizador(s + (2 * depth - 1)*max  + offset - width/2 + i ,"-"); 
		copiar_sin_finalizador(s + (2 * depth - 1)*max  + offset + left + width/2 ,"+"); 
		// copiar_sin_finalizador(s + (2 * depth - 1)*max  + offset - width/2 ,"+"); 
    }

    return left + width + right;
}

int print_t(t_nodo_arbol *tree)
{
	FILE *f = fopen("intermedia.txt", "w+");
	if (f == NULL)
	{
	    puts("Error abriendo archivo de notación intermedia");
	    exit(1);
	}
	int i;
    char * s = (char *) malloc(sizeof(char) * RENGLONES_IMPRESION_ARBOL * CARACTERES_RENGLON_ARBOL);

    for (i = 0; i < RENGLONES_IMPRESION_ARBOL * CARACTERES_RENGLON_ARBOL; i++)
    {
    	if(i == 0 || i % (CARACTERES_RENGLON_ARBOL - 1))
    		sprintf(s + i, "%c", ' ');
    	else
    		sprintf(s + i, "%c", '\0');
    }


    _print_t(tree, 0, 0, 0, s,CARACTERES_RENGLON_ARBOL);


    for (i = 0; i < RENGLONES_IMPRESION_ARBOL; i++)
    {
       //printf("%s\n", s + i*CARACTERES_RENGLON_ARBOL);
        fprintf(f, "%s\n", s + i*CARACTERES_RENGLON_ARBOL);
    	
    }

   // for (i = 0; i < RENGLONES_IMPRESION_ARBOL; i++)
   //     printf("%s\n", s + i*CARACTERES_RENGLON_ARBOL);
    
    fclose(f);
}


void reemplazar(char * cad, char old,char new, int size) 
{
	int i;
	for(i = 0; i < size; i++)
	{
		if(*(cad + i) == old)
			*(cad + i) = new;
	}
}


void copiar_sin_finalizador(char * dest,char * orig) 
{
	
	while(*orig && *dest)
	{
		*dest = *orig;
		orig++;
		dest++;		
	}
}

void crear_arbol_iguales(t_nodo_arbol ** raiz)
{
		// puts("holu");
		t_nodo_arbol * nodo_aux_izq;
		t_nodo_arbol * nodo_aux_der;
		t_nodo_arbol * nodo_aux_pp;
		t_nodo_arbol * nodo_aux_if;
		t_nodo_arbol * nodo_aux_nuevo;
		t_nodo_arbol * nodo_aux_actual;

		t_info_sentencias * p_info = sacar_de_pila(&pila_expresiones_iguales);
		nodo_aux_izq = crear_nodo_arbol(crear_info("=="), p_info_iguales->a, p_info->a);
		nodo_aux_pp = crear_nodo_arbol(crear_info("+"), crear_hoja(crear_info("cont")), crear_hoja(crear_info("1")));
		nodo_aux_der = crear_nodo_arbol(crear_info(":="), crear_hoja(crear_info("cont")), nodo_aux_pp);	
		nodo_aux_if = crear_nodo_arbol(crear_info("IF"), nodo_aux_izq, nodo_aux_der);
		
		if(!pila_vacia(&pila_expresiones_iguales)){
			// puts("a");
			nodo_aux_nuevo = crear_nodo_arbol(crear_info("IF"), NULL, NULL);		
			t_nodo_arbol * aux = crear_nodo_arbol(crear_info(";"), nodo_aux_if, nodo_aux_nuevo);
			aux->padre = *raiz;
			*raiz = aux;
			crear_arbol_iguales(&((*raiz)->nodo_der));
		} else{		
			nodo_aux_if->padre = *raiz;
			// puts("b");
			*raiz = nodo_aux_if;
		}	
}

void crear_inicio_assembler()
{
	a = fopen("Final.txt", "w");
	if (a == NULL)
	{
	    puts("Error abriendo archivo assembler");
	    exit(1);
	}
	fprintf(a, "TITLE TP Compilador 2016");
	fprintf(a, "\n.MODEL	small");
	fprintf(a, "\n.386");
	fprintf(a, "\n.STACK	300h");
	fprintf(a, "\n");
	fprintf(a, "\n.DATA");
	fprintf(a, "\nmessage db	'-- EOF --', '$'");
	fprintf(a, "\noverflow db	'Overflow!', '$'");
	fprintf(a, "\ndiviz db	'Division by 0!', '$'");
	fprintf(a, "\nMAX_STRING_LENGTH equ 30 ;Longitud maxima de los string.");
	fprintf(a, "\nMAX_STRING_INT equ 65535 ;Tamaño maximo de ints.");
}

void crear_codigo_assembler(t_nodo_arbol *tree)
{
	fprintf(a, "\n");
	fprintf(a, "\n.CODE");
	fprintf(a, "\nMAIN:");
	recorrer_asm(tree);
	fprintf(a, "\nMOV AX, 4C00h");
	fprintf(a, "\nEND MAIN");
    
}

void recorrer_asm(t_nodo_arbol *n){
		if(strcmp(n->info->a,":=")==0 && is_hoja(n->nodo_der))		
		{	
			fprintf(a, "\nMOV ");
			fprintf(a, "_"); 
			fprintf(a, n->nodo_izq->info->a); 
			fprintf(a, ", ");
			fprintf(a, n->nodo_der->info->a);
		}
	if(n->nodo_izq != NULL)
		recorrer_asm(n->nodo_izq);
	if(n->nodo_der != NULL)
		recorrer_asm(n->nodo_der);
}

int is_hoja(t_nodo_arbol *n)
{
	if(n->nodo_izq != NULL || n->nodo_der != NULL)
		return 0;
		
	return 1;
}
