%{
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
%}

/* PARA OBTENER LOS VALORES Y PASAR A TS*/
%union {
int intval;
float val;
char *str_val;
}
%start pgm

%token <str_val>TOKEN_ID
%token <intval>CONST_INT
%token <str_val>CONST_STR
%token <val>CONST_FLOAT
%type <str_val>tipo_dato
%type <str_val> expresion
%type <str_val> termino
%type <str_val> factor
%type <str_val> factor_str

%token PR_MAIN
%token PR_IGUALES
%token PR_FILTER
%token PR_WRITE
%token PR_READ
%token PR_IF
%token PR_THEN
%token PR_ENDIF
%token PR_ELSE
%token PR_NOT
%token PR_WHILE
%token PR_DO
%token PR_ENDWHILE
%token PAR_ABRE
%token PAR_CIERRA
%token COR_ABRE
%token COR_CIERRA
%token <str_val>COMA
%token OP_LOG_AND
%token OP_LOG_OR
%token OP_SUMA
%token OP_RESTA
%token OP_MUL
%token OP_DIV
%token OP_MAYOR
%token OP_MAYOR_IGUAL
%token OP_MENOR
%token OP_MENOR_IGUAL
%token OP_DISTINTO
%token OP_IGUAL_IGUAL
%token OP_IGUAL
%token PR_AS
%token PR_DIM
%token OP_FILTER
%token <str_val> PR_FLOAT
%token <str_val> PR_INT
%token <str_val> PR_STRING
%token OP_CONCAT
%token PUNTO_Y_COMA
%%

pgm : programa 
{
	puts("COMPILACION EXITOSA\n");
	puts("-------------------\n");
};

programa : PR_MAIN declaracion_variables lista_sentencias
{
	if(DEBUG){
		puts("Codigo con variables\n");
		puts("-------------------\n");
	}

};

programa : PR_MAIN lista_sentencias
{
	if(DEBUG){
		puts("Codigo sin variables\n");
		puts("-------------------\n");
	}
};

lista_sentencias : sentencia
{
	if(DEBUG){
		puts("Una sola sentencia\n");
		puts("-------------------\n");
	}
};

lista_sentencias : sentencia lista_sentencias
{
	if(DEBUG) {
		puts("Varias sentencias\n");
		puts("-------------------\n");
	}

};

sentencia : condicional 
{
	if(DEBUG) {
		puts("Condicional\n");
		puts("-------------------\n");		
	}

};

sentencia : asignacion 
{
	if(DEBUG) {
		puts("Asignacion\n");
		puts("-------------------\n");		
	}

};

sentencia : iteracion
{
	if(DEBUG) {
		puts("Iteracion\n");
		puts("-------------------\n");		
	}

};

sentencia : io PUNTO_Y_COMA
{
	if(DEBUG) {
		puts("Operacion de entrada salidas\n");
		puts("-------------------\n");		
	}

};

sentencia : iguales PUNTO_Y_COMA
{
	if(DEBUG) {
		puts("Operacion de iguales\n");
		puts("-------------------\n");	
	}
}

sentencia : filter PUNTO_Y_COMA
{
	if(DEBUG) {
		puts("Operacioon de filters\n");
		puts("-------------------\n");
	}
}

iguales : PR_IGUALES PAR_ABRE expresion COMA COR_ABRE lista_expresiones COR_CIERRA PAR_CIERRA 
{
	if(DEBUG) {
		puts("iguales : PR_IGUALES PAR_ABRE expresion COMA COR_ABRElista_expresiones COR_CIERRA PAR_CIERRA\n");
		puts("-------------------\n");
	}
}

lista_expresiones : expresion COMA lista_expresiones
{
	if(DEBUG) {
		puts("Lista de expresiones\n");
		puts("-------------------\n");		
	}
}

lista_expresiones : expresion
{
	if(DEBUG) {
		puts("Última expresion\n");
		puts("-------------------\n");		
	}
}

filter : PR_FILTER PAR_ABRE condicion_filter COMA COR_ABRE lista_variables COR_CIERRA PAR_CIERRA
{
	if(DEBUG) {
		puts("filter : PR_FILTER PAR_ABRE condicion COMA COR_ABRE lista_variables COR_CIERRA PAR_CIERRA\n");
		puts("-------------------\n");
	}
}

condicion_filter : comparacion_filter
{
	puts("condicion_filter : comparacion_filter\n");
	puts("-------------------\n");
}

condicion_filter : comparacion_filter OP_LOG_AND comparacion_filter
{
	puts("condicion_filter : comparacion_filter and comparacion_filter\n");
	puts("-------------------\n");
}

condicion_filter : comparacion_filter OP_LOG_OR comparacion_filter
{
	puts("condicion_filter : comparacion_filter or comparacion_filter\n");
	puts("-------------------\n");
}

comparacion_filter : OP_FILTER comparador expresion
{
	puts("comparacion_filter : OP_FILTER comparador expresion\n");
	puts("-------------------\n");
}

comparacion_filter : PR_NOT OP_FILTER comparador expresion
{
	puts("comparacion_filter : PR_NOT OP_FILTER comparador expresion\n");
	puts("-------------------\n");
}

lista_variables : TOKEN_ID COMA lista_variables
{
	if(DEBUG) {
		puts("Lista de variables\n");
		puts("-------------------\n");		
	}
}

lista_variables : TOKEN_ID
{
	if(DEBUG) {
		puts("Última variable\n");
		puts("-------------------\n");
	}
}

io : entrada
{
	if(DEBUG) {
		puts("io : entrada\n");
		puts("-------------------\n");
	}

}

io : salida
{
	if(DEBUG) {
		puts("io : salida\n");
		puts("-------------------\n");		
	}
}

entrada : PR_READ TOKEN_ID
{
	if(DEBUG) {
		puts("entrada : READ id\n");
		puts("-------------------\n");		
	}
}

salida : PR_WRITE TOKEN_ID
{
	if(DEBUG) {
		puts("salida : PR_WRITE id\n");
		puts("-------------------\n");
	}
}

salida : PR_WRITE CONST_STR
{
	if(DEBUG) {
		puts("salida : PR_WRITE cte\n");
		puts("-------------------\n");	
	}
}

condicional : PR_IF condicion PR_THEN lista_sentencias PR_ENDIF
{
	if(DEBUG) {
		puts("Condicional sin ELSE\n");
		puts("-------------------\n");
	}
}

condicional : PR_IF condicion PR_THEN lista_sentencias PR_ELSE lista_sentencias PR_ENDIF
{
	if(DEBUG) {
		puts("Condicional con ELSE\n");
		puts("-------------------\n");	
	}
}

condicion : comparacion
{
	if(DEBUG) {
		puts("condicion : comparacion\n");
		puts("-------------------\n");
	}
}

condicion : comparacion OP_LOG_AND comparacion
{
	if(DEBUG) {
		puts("condicion : comparacion and comparacion\n");
		puts("-------------------\n");		
	}
}

condicion : comparacion OP_LOG_OR comparacion
{
	if(DEBUG) {
		puts("condicion : comparacion or comparacion\n");
		puts("-------------------\n");		
	}
}

comparacion : expresion comparador expresion
{
	if(DEBUG) {
		puts("comparacion : expresion comparador expresion\n");
		puts("-------------------\n");
	}
}

comparacion : PR_NOT expresion comparador expresion
{
	if(DEBUG) {
		puts("comparacion : PR_NOT expresion comparador expresion\n");
		puts("-------------------\n");
	}
}

iteracion : PR_WHILE condicion PR_DO lista_sentencias PR_ENDWHILE
{
	if(DEBUG) {
		puts("Iteracion\n");
		puts("-------------------\n");
	}
}

asignacion : TOKEN_ID OP_IGUAL expresion
{
	printf("asignacion %s %s\n",$1,$3 );
	char mjs_error[60];
	if(!tipos_iguales($1,$3,mjs_error, linecount)) {
		puts(mjs_error);
		exit(1);
	}
	if(DEBUG) {
		puts("Asignacion -> Token_ID := expresion\n");
		puts("-------------------\n");
	}
}

expresion : termino
{
	printf("%s\n",$1 );
	$$=$1;
	if(DEBUG) {
		puts("Expresion -> termino\n");
		puts("-------------------\n");
	}
}

expresion : expresion OP_SUMA termino 
{
	char mjs_error[60];
	if(!tipos_iguales($1,$3,mjs_error, linecount)) {
		puts(mjs_error);
		exit(1);
	}
	if(DEBUG) {
		printf("%s %s\n", $1, $3);
		puts("expresion : expresion OP_SUMA termino\n");
		puts("-------------------\n");
	}
} 

expresion : expresion OP_RESTA termino
{
	char mjs_error[60];
	if(!tipos_iguales($1,$3,mjs_error, linecount)) {
		puts(mjs_error);
		exit(1);
	}
	if(DEBUG) {
		printf("%s %s\n", $1, $3);
		puts("Resta\n");
		puts("-------------------\n");
	}
}

termino : factor
{
	printf(" termino %s\n",$1 );
	if(DEBUG) {
		puts("termino : factor\n");
		puts("-------------------\n");
	}
}

termino : termino OP_DIV factor
{
	if(DEBUG) {
		puts("Division\n");
		puts("-------------------\n");
	}
}

termino : termino OP_MUL factor
{
	// printf("%s\n", $1);
	if(DEBUG) {
		puts("termino : termino OP_MUL factor\n");
		puts("-------------------\n");
	}
}

// factor : CONST_STR
// {
// 	agregar_cte_a_TS(TIPO_STRING,$1, 0,0.0,linecount);
// 	puts($1);
// 	$$=$1;
// 	if(DEBUG) {
// 		printf("%s\n",$1);
// 		puts("factor : cte\n");
// 		puts("-------------------\n");		
// 	}
// }

asignacion : TOKEN_ID OP_IGUAL expresion_str PUNTO_Y_COMA
{
	if(DEBUG) {
		// printf("%s\n",$1);
		puts("asignacion : id := expresion_str \n");
		puts("-------------------\n");		
	}
}


expresion_str : factor_str OP_CONCAT factor_str 
{
	if(DEBUG) {
		// printf("%s\n",$1);
		puts("expresion_str : factor_str OP_CONCAT factor_str \n");
		puts("-------------------\n");		
	}
}

asignacion : TOKEN_ID OP_IGUAL factor_str PUNTO_Y_COMA
{
	if(DEBUG) {
		// printf("%s\n",$1);
		puts("expresion_str : factor_str\n");
		puts("-------------------\n");		
	}
}

factor_str : CONST_STR
{
	agregar_cte_a_TS(TIPO_STRING,$1, 0,0.0,linecount);
	puts($1);
	$$=$1;
	if(DEBUG) {
		printf("%s\n",$1);
		puts("factor : cte\n");
		puts("-------------------\n");		
	}
} 

factor_str : TOKEN_ID
{
	$$=$1;
	if(DEBUG) {
		printf("%s\n",$1);
		puts("factor : cte\n");
		puts("-------------------\n");		
	}
} 




factor : CONST_INT
{
	// $$ = "INT";
	char temp[10];
	sprintf(temp,"%d",$1);
	$$ = temp;
	// $$=$1;
	agregar_cte_a_TS(TIPO_INT,NULL, $1,0.0,linecount);
	if(DEBUG) {
		printf("%d\n",$1);
		puts("factor : cte\n");
		puts("-------------------\n");		
	}

}

factor : CONST_FLOAT
{
	char temp[10];
	sprintf(temp,"%.4f",$1);
	$$ = temp;
	// $$=$1;
	agregar_cte_a_TS(TIPO_FLOAT,NULL, 0,$1,linecount);
	if(DEBUG) {
		printf("%.4f\n",$1);
		puts("factor : cte\n");
		puts("-------------------\n");
	}

}

factor : TOKEN_ID
{
	if(DEBUG) {
		puts("factor : TOKEN_ID\n");
		puts("-------------------\n");
	}
} 
     
// factor : expresion
// {
// 	puts("factor : expresion\n");
// 	puts("-------------------\n");
// }

declaracion_variables : PR_DIM COR_ABRE declaracion_variables_interna COR_CIERRA PUNTO_Y_COMA 

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

declaracion_variables : PR_DIM COR_ABRE declaracion_variables_interna COR_CIERRA PUNTO_Y_COMA declaracion_variables 
{
	puts("aa");

}


declaracion_variables_interna : TOKEN_ID COMA declaracion_variables_interna COMA tipo_dato
{
	puts("b");
	printf("leo %s %s\n", $1,$5);
	strcpy(temp_variables[variables_a_agregar],$1);
	strcpy(temp_tipo_dato[variables_a_agregar],$5);
	variables_a_agregar++;
	// agregar_variable_a_TS($1,$5,linecount);
	if(DEBUG) {
		puts("declaracion_variables_interna : TOKEN_ID COMA declaracion_variables_interna COMA tipo_dato\n");
		puts("-------------------\n");
	}
} 

declaracion_variables_interna : TOKEN_ID COR_CIERRA PR_AS COR_ABRE tipo_dato
{


	int i;

	for (i = 0; i < variables_a_agregar; ++i)
	{
		printf("agregando %s %s\n", temp_variables[i],temp_tipo_dato[variables_a_agregar -1 - i]);
		agregar_variable_a_TS(temp_variables[i],temp_tipo_dato[variables_a_agregar - 1- i], linecount);
	}
	variables_a_agregar = 0;


	strcpy(temp_variables[variables_a_agregar],$1);
	strcpy(temp_tipo_dato[variables_a_agregar],$5);
	variables_a_agregar++;



	// agregar_variable_a_TS($1,$5,linecount);
	puts("c");
	printf("leo %s %s\n", $1,$5);
	if(DEBUG) {
		puts("declaracion_variables_interna : TOKEN_ID COR_CIERRA PR_AS COR_ABRE tipo_dato\n");
		puts("-------------------\n");
	}
}

tipo_dato : PR_INT 
{
	$$=$1;
	if(DEBUG) {
		puts("PR_INT\n");
		puts("-------------------\n");	
	}
}   

tipo_dato : PR_FLOAT 
{
	$$=$1;
	if(DEBUG) { 
		puts("PR_FLOAT\n");
		puts("-------------------\n");
	}
}            

tipo_dato : PR_STRING 
{

	$$=$1;
	if(DEBUG) {
		puts("PR_STRING\n");
		puts("-------------------\n");
	}
} 

comparador : OP_MAYOR
{
	if(DEBUG) {
		puts("OP_MAYOR\n");
		puts("-------------------\n");
	}
}   

comparador : OP_MENOR
{
	if(DEBUG) {
		puts("OP_MENOR\n");
		puts("-------------------\n");
	}
}   

comparador : OP_MENOR_IGUAL
{
	if(DEBUG) {
		puts("OP_MENOR_IGUAL\n");
		puts("-------------------\n");
	}
}      

comparador : OP_MAYOR_IGUAL
{
	if(DEBUG) {
		puts("OP_MAYOR_IGUAL\n");
		puts("-------------------\n");
	}
}    

comparador : OP_IGUAL_IGUAL
{
	if(DEBUG) {
		puts("OP_IGUAL_IGUAL\n");
		puts("-------------------\n");
	}
}

comparador : OP_DISTINTO
{
	if(DEBUG) {
		puts("OP_DISTINTO\n");
		puts("-------------------\n");
	}
}     

%%


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








