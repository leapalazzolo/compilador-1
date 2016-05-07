%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"
#include "defines.h"
#include "structs.h"
extern YYSTYPE yylval;

FILE  *yyin;
char aux[COTA_STR],aux2[COTA_STR];
int procesar_operador(char *);
double f;

%}

	int linecount = 1;
%option noyywrap  
%option yylineno 


KEYWORD				["if"]
ID					{LETRA}({LETRA}|{DIGITO}|_|-)*
LETRA				[a-zA-Z]
CAR_ESPECIAL		[�,?,�,!]
OP_MUL				["*"]
OP_DIV				["/"]
OP_SUMA				["+"]
OP_RESTA				["-"]
OPCONCAT			["++"]
OP_MAYOR				[">"]
OP_MENOR				["<"]
OP_MAYOR_IGUAL			[">="]
OP_MENOR_IGUAL			["<="]
OP_FILTER			["_"]
ASIGNA				[":="]
IGUAL				["=="]
DISTINTO			["!="]
NEGADO				["NOT"]
OP_AND				["AND"]
OP_OR				["OR"]
P_ABRE				["("]
P_CIERRA			[")"]
COR_ABRE			["["]
COR_CIERRA			["]"]
COMA				[","]
PUNTO_COMA			[";"]
PUNTO				["."]
ESPACIO 			[" "]
ENTER 				["\n"]
TAB 				["\t"]
CONST_FLOAT    		{DIGITO}+"."{DIGITO}*|"."{DIGITO}+
CONST_INT       	{DIGITO}+
DIGITO				[0-9]
COMILLA				["\""]
CADENA              .
COMENTARIO          .


%%

"MAIN"			{ return PR_MAIN;}
"DIM"			{ return PR_DIM;}
"AS"			{ return PR_AS;}
"BEGIN"			{ return PR_DO;}
"FLOAT"			{ yylval.str_val = strdup(yytext);return PR_FLOAT;}
"INT"			{ yylval.str_val = strdup(yytext);return PR_INT;}
"STRING"		{ yylval.str_val = strdup(yytext);return PR_STRING;}
"IF"			{ return PR_IF;}
"THEN"   		{ return PR_THEN;}
"ELSE"   		{ return PR_ELSE;}
"ENDIF"	      	{ return PR_ENDIF;}
"WHILE"	      	{ return PR_WHILE;}
"DO"	        { return PR_DO;}
"ENDWHILE"  	{ return PR_ENDWHILE;}
"IGUALES"		{ return PR_IGUALES;}
"FILTER"		{ return PR_FILTER;}
"+"				{ return OP_SUMA;}
"-"				{ return OP_RESTA;}
"*"				{ return OP_MUL;}
"/"				{ return OP_DIV;}
">"             { return OP_MAYOR;}
">="            { return OP_MAYOR_IGUAL;}
"<"             { return OP_MENOR;}
"<="            { return OP_MENOR_IGUAL;}
"!="            { return OP_DISTINTO;}
"=="            { return OP_IGUAL_IGUAL;}
"AND"           { return OP_LOG_AND;}
"OR"            { return OP_LOG_OR;}
"NOT"           { return PR_NOT;}
":="			{ return OP_IGUAL;}
"("				{ return PAR_ABRE;}
")"				{ return PAR_CIERRA;}
"["				{ return COR_ABRE;}
"]"				{ return COR_CIERRA;}
"READ"			{ return PR_READ;}
"WRITE"			{ return PR_WRITE;}
","				{ return COMA;}
"_"				{ return OP_FILTER;} 
";"				{ return PUNTO_Y_COMA;}
"++"			{ return OP_CONCAT;}
"-/"{COMENTARIO}*"/-" // printf ("comentario \n");
"//"({COMENTARIO})* //printf("comentario \n");

{ID}			{

		yylval.str_val =  strdup(yytext);;
		if(strlen(yytext)>COTA_ID) {
				printf("VARIABLE SUPERA MAXIMO CARACTERES\n\t***ERROR - FINALIZANDO LEXICO***\n");
				exit(1);
			}
		else {	
			return TOKEN_ID;
		}
}


{CONST_INT}		{ 		
					yylval.intval = atoi(yytext);
					if(atoi(yytext)>MAX_INT)
						{
							printf("CONST ENTERA SUPERA COTA\n\t***ERROR - FINALIZANDO LEXICO***\n");
							exit(1);
						}
					else
						{
							return CONST_INT;
						}
				}
				
"\""{CADENA}*"\""	{ 		
					yylval.str_val = strdup(yytext);
					if(strlen(aux2)>COTA_STR)
						{	
							printf("STRING SUPERA COTA\n\t***ERROR - FINALIZANDO LEXICO***\n");
							exit(1);
						}
					else
						{
							return CONST_STR;
						}
				}
				
{CONST_FLOAT}	{ 		
						yylval.val = atof(yytext);
						if(f>COTA_REAL)
							{
								printf("CONST REAL SUPERA COTA\n\t***ERROR - FINALIZANDO LEXICO***\n");
								exit(1);
							}
						else
							{
								return CONST_FLOAT;
							}
				}

\n 				++linecount;
[ /t] 


.				{ printf("\nCARACTER NO RECONOCIDO: '%s' en la linea %d", strdup(yytext), linecount); exit(1);}

%%

// void agregar_simbolo()




