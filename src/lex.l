%{
#include <stdio.h>
#include <stdlib.h>
#include "y.tab.h"
#include "defines.h"

FILE  *yyin;
%}


%option noyywrap  
%option yylineno 


ID					{LETRA}({LETRA}|{DIGITO}|_)*
LETRA				[a-zA-Z]
CAR_ESPECIAL		[�,?,�,!]
OPMULTI				["*"]
OP_ESP_MUL			["*="]
OPDIV				["/"]
OP_ESP_DIV			["/="]
OPMAS				["+"]
OP_ESP_MAS			["+="]
OPMENOS				["-"]
OP_ESP_MEN			["-="]
MAYOR				[">"]
MENOR				["<"]
MAYOR_IGUAL			[">="]
MENOR_IGUAL			["<="]
ASIGNA				["="]
IGUAL				["=="]
DISTINTO			["!="]
NEGADO				["!"]
OP_AND				["&&"]
OP_OR				["||"]
P_ABRE				["("]
P_CIERRA			[")"]
COR_ABRE			["["]
COR_CIERRA			["]"]
COMA				[","]
PUNTO_COMA			[";"]
PUNTO				["."]
CONST_FLOAT    		{DIGITO}+"."{DIGITO}+
CONST_INT       	{DIGITO}+
DIGITO				[0-9]
COMILLA				["\""]
CONST_STR			{COMILLA}({CONST_STR2})+{COMILLA}
CONST_STR2			{CONST_STR2}({CAR_TODO})*
CAR_TODO			{DIGITO}|{LETRA}|{CAR_ESPECIAL}
LL_ABRE 			[{]
LL_CIERRA 			[}]

%%