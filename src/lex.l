%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "y.tab.h"
#include "defines.h"

FILE  *yyin;
char aux[COTA_STR],aux2[COTA_STR];
double f;
%}

	int linecount = 1;
%option noyywrap  
%option yylineno 


KEYWORD				["if"]
ID					{LETRA}({LETRA}|{DIGITO}|_|-)*
LETRA				[a-zA-Z]
CAR_ESPECIAL		[�,?,�,!]
OPMULTI				["*"]
OPDIV				["/"]
OPMAS				["+"]
OPMENOS				["-"]
OPCONCAT			["++"]
MAYOR				[">"]
MENOR				["<"]
MAYOR_IGUAL			[">="]
MENOR_IGUAL			["<="]
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


"DIM"			{ return PR_DIM;}
"AS"			{ return PR_AS;}
"BEGIN"			{ return PR_BEGIN;}
"FLOAT"			{ return PR_FLOAT;}
"INT"			{ return PR_INT;}
"STRING"		{ return PR_STRING;}
"IF"			{ return PR_IF;}
"THEN"   		{ return PR_THEN;}
"ELSE"   		{ return PR_ELSE;}
"ENDIF"	      	{ return PR_ENDIF;}
"WHILE"	      	{ return PR_WHILE;}
"DO"	        { return PR_DO;}
"ENDWHILE"  	{ return PR_ENDWHILE;}
"+"				{ return OPMAS;}
"-"				{ return OPMENOS;}
"*"				{ return OPMULTI;}
"/"				{ return OPDIV;}
">"             { return MAYOR;}
">="            { return MAYOR_IGUAL;}
"<"             { return MENOR;}
"<="            { return MENOR_IGUAL;}
"!="            { return DISTINTO;}
"=="            { return IGUAL;}
"AND"           { return OP_AND;}
"OR"            { return OP_OR;}
"NOT"           { return OP_NEGADO;}
"="				{ return ASIGNA;}
"("				{ return P_ABRE;}
")"				{ return P_CIERRA;}
"["				{ return COR_ABRE;}
"]"				{ return COR_CIERRA;}
"READ"			{ return PR_GET;}
"WRITE"			{ return PR_PUT;}
","				{ return COMA;}
";"				{ return PUNTO_Y_COMA;}
"++"			{ return OPCONCAT;}
"-/"{COMENTARIO}*"/-"  printf ("comentario \n");
"//"({COMENTARIO})* printf("comentario \n");

{ID}			{

						//yylval.str_val = yytext;
						if(strlen(yytext)>COTA_ID) {
								printf("VARIABLE SUPERA MAXIMO CARACTERES\n\t***ERROR - FINALIZANDO LEXICO***\n");
								exit(1);
							}
						else {	
							strcpy(aux,"_");
							strcat(aux,yytext);
							//printf( "Genero aux para TS: (%s)\n",aux);
							//printf( "Identificador en lexico: %s (%s)\n", yytext,yylval.str_val);
							//agregarATS(aux,"-",VRBL,0,0);//hay que mandar el id y los datos necesarios para agregar
							return TOKEN_ID;
						}
				}


{CONST_INT}		{ 		
					//yylval.str_val = yytext;
					if(atoi(yytext)>COTA_ID)
						{
							printf("CONST ENTERA SUPERA COTA\n\t***ERROR - FINALIZANDO LEXICO***\n");
							exit(1);
						}
					else
						{
							strcpy(aux,"&");
							strcat(aux,yytext);
							//printf( "Genero aux para TS: (%s)\n",aux);
					//		printf( "Identificador en lexico: %s (%s)\n", yytext,yylval.str_val);
					//		agregarATS(aux,"-",CTE_INT,0,atoi(yytext));
							return CONST_INT;
						}
				}
				
"\""{CADENA}*"\""	{ 		
					//yylval.str_val = yytext;
					strcpy(aux2,yytext);
					if(strlen(aux2)>COTA_STR)
						{	
							printf("STRING SUPERA COTA\n\t***ERROR - FINALIZANDO LEXICO***\n");
							exit(1);
					
						}
					else
						{
							//setearString(aux2,yytext);
							strcpy(aux,"@");
							strcat(aux,aux2);
							//printf( "Genero aux para TS: (%s)\n",aux);
							//printf( "Identificador en lexico: %s (%s)\n", yytext,yylval.str_val);
							//agregarATS(aux,yytext,CTE_STR,strlen(aux2),0);
							return CONST_STR;
						}
				}
				
{CONST_FLOAT}	{ 		
						//yylval.str_val = yytext;
						f=atof(yytext);
						if(f>COTA_REAL)
							{
								printf("CONST REAL SUPERA COTA\n\t***ERROR - FINALIZANDO LEXICO***\n");
								exit(1);
							}
						else
							{
								strcpy(aux,"$");
								strcat(aux,yytext);
								//printf( "Genero aux para TS: (%s)\n",aux);
						//		printf( "Identificador en lexico: %s (%s)\n", yytext,yylval.str_val);
						//		agregarATS(aux,"-",CTE_FLT,0,f);
								return CONST_FLOAT;
							}
				}

\n 				++linecount;
[ /t] 

%%
/*

int main( int argc, char **argv )
{

++argv, --argc; 
if ( argc > 0 )
     yyin = fopen( argv[0], "r" );
else
     yyin = stdin;

     int algo;
     while(algo = yylex()) {
		printf("%d ", algo);
     }


}
*/