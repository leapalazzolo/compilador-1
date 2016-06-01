
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

/* Line 1676 of yacc.c  */
#line 98 "syntax.y"

int intval;
float val;
char *str_val;



/* Line 1676 of yacc.c  */
#line 150 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


