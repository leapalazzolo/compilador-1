
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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
/* Tokens.  */
#define TOKEN_ID 258
#define CONST_INT 259
#define CONST_STR 260
#define CONST_FLOAT 261
#define PR_MAIN 262
#define PR_DIM 263
#define PR_ENDIM 264
#define PR_IGUALES 265
#define PR_FILTER 266
#define PR_WRITE 267
#define PR_READ 268
#define PR_IF 269
#define PR_THEN 270
#define PR_ENDIF 271
#define PR_ELSE 272
#define PR_NOT 273
#define PR_WHILE 274
#define PR_BEGIN 275
#define PR_END 276
#define PAR_ABRE 277
#define PAR_CIERRA 278
#define COR_ABRE 279
#define COR_CIERRA 280
#define COMA 281
#define OP_LOG_AND 282
#define OP_LOG_OR 283
#define OP_LOG_NOT 284
#define OP_SUMA 285
#define OP_RESTA 286
#define OP_MUL 287
#define OP_DIV 288
#define OP_MAYOR 289
#define OP_MAYOR_IGUAL 290
#define OP_MENOR 291
#define OP_MENOR_IGUAL 292
#define OP_DISTINTO 293
#define OP_IGUAL_IGUAL 294
#define OP_IGUAL 295
#define OP_AS 296
#define OP_DIM 297
#define PR_FLOAT 298
#define PR_INT 299
#define PR_STRING 300




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 11 "sintax.y"

int intval;
double val;
char *str_val;



/* Line 1676 of yacc.c  */
#line 150 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


