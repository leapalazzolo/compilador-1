%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "y.tab.h"
#include "defines.h"
#include "structs.h"
void agregar_simbolo(char * nombre, int tipo, char * valor,char * alias);
FILE  *yyin;
char aux[COTA_STR],aux2[COTA_STR];
int procesar_keyword(char *);
int procesar_operador(char *);
int procesar_comparador(char *);
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

"MAIN"			{ return procesar_keyword(yytext);}
"DIM"			{ return procesar_keyword(yytext);}
"AS"			{ return procesar_keyword(yytext);}
"BEGIN"			{ return procesar_keyword(yytext);}
"FLOAT"			{ return procesar_keyword(yytext);}
"INT"			{ return procesar_keyword(yytext);}
"STRING"		{ return procesar_keyword(yytext);}
"IF"			{ return procesar_keyword(yytext);}
"THEN"   		{ return procesar_keyword(yytext);}
"ELSE"   		{ return procesar_keyword(yytext);}
"ENDIF"	      	{ return procesar_keyword(yytext);}
"WHILE"	      	{ return procesar_keyword(yytext);}
"DO"	        { return procesar_keyword(yytext);}
"ENDWHILE"  	{ return procesar_keyword(yytext);}
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
"AND"           { return OP_AND;}
"OR"            { return OP_OR;}
"NOT"           { return OP_NEGADO;}
":="			{ return ASIGNA;}
"("				{ return P_ABRE;}
")"				{ return P_CIERRA;}
"["				{ return COR_ABRE;}
"]"				{ return COR_CIERRA;}
"READ"			{ return PR_GET;}
"WRITE"			{ return PR_PUT;}
","				{ return COMA;}
";"				{ return PUNTO_Y_COMA;}
"++"			{ return OPCONCAT;}
"-/"{COMENTARIO}*"/-" // printf ("comentario \n");
"//"({COMENTARIO})* //printf("comentario \n");

{ID}			{

		//yylval.str_val = yytext;
		if(strlen(yytext)>COTA_ID) {
				printf("VARIABLE SUPERA MAXIMO CARACTERES\n\t***ERROR - FINALIZANDO LEXICO***\n");
				exit(1);
			}
		else {	
			strcpy(aux,yytext);
			agregar_simbolo("_ID",TIPO_STRING,aux,NULL);	
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
							strcpy(aux,yytext);
							//printf( "Genero aux para TS: (%s)\n",aux);
					//		printf( "Identificador en lexico: %s (%s)\n", yytext,yylval.str_val);
							agregar_simbolo("&cte",TIPO_INT,aux,NULL);
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
							agregar_simbolo("@cte",TIPO_STRING,aux2,NULL);
							return CONST_STR;
						}
				}
				
{CONST_FLOAT}	{ 		
						//yylval.str_val = yytext;
						strcpy(aux,yytext);
						if(f>COTA_REAL)
							{
								printf("CONST REAL SUPERA COTA\n\t***ERROR - FINALIZANDO LEXICO***\n");
								exit(1);
							}
						else
							{
								agregar_simbolo("$cte",TIPO_FLOAT,aux,NULL);
								return CONST_FLOAT;
							}
				}

\n 				++linecount;
[ /t] 


.				{ puts("\nCARACTER NO RECONOCIDO"); exit(1);}

%%

// void agregar_simbolo()
t_simbolo tabla_simbolos[2000];
int cantidad_simbolos = 0;	


int procesar_keyword(char * str) {
	agregar_simbolo(str,TIPO_PR,NULL,NULL);

	if(!strcmp(str,"IF"))
		return PR_IF;
	if(!strcmp(str,"MAIN"))
		return PR_MAIN;
	if(!strcmp(str,"DIM"))
		return PR_DIM;
	if(!strcmp(str,"AS"))
		return PR_AS;
	if(!strcmp(str,"BEGIN"))
		return PR_BEGIN;
	if(!strcmp(str,"FLOAT"))
		return PR_FLOAT;
	if(!strcmp(str,"INT"))
		return PR_INT;
	if(!strcmp(str,"STRING"))
		return PR_STRING;
	if(!strcmp(str,"THEN"))
		return PR_THEN;
	if(!strcmp(str,"ELSE"))
		return PR_ELSE;
	if(!strcmp(str,"ENDIF"))
		return PR_ENDIF;
	if(!strcmp(str,"WHILE"))
		return PR_WHILE;
	if(!strcmp(str,"DO"))
		return PR_DO;
	if(!strcmp(str,"ENDWHILE"))
		return PR_ENDWHILE;

	return 0;
}

int procesar_operador(char * str) {
}


/** Esta funcion te permite agregar un simbolo a la tabla de simbolos.
	La idea es que se le envie el nombre del simbolo (Si es un id, el nombre
	de la variable con el  prefijo "_", el tipo de dato es un int definido
	 en las macro y el valor, en caso de que sea una constante)*/
void agregar_simbolo(char * nombre, int tipo, char * valor,char * alias) {
	tabla_simbolos[cantidad_simbolos].nombre = malloc(sizeof(char) * strlen(nombre));
	strcpy(tabla_simbolos[cantidad_simbolos].nombre,nombre);


	if(alias != NULL) {
		tabla_simbolos[cantidad_simbolos].alias = malloc(sizeof(char) * strlen(alias));
		strcpy(tabla_simbolos[cantidad_simbolos].alias,alias);	
	}
	tabla_simbolos[cantidad_simbolos].tipo = tipo;

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
