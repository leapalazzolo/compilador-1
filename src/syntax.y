%{
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
void imprimir_arbol(t_nodo_arbol *n);
void copiar_sin_finalizador(char * dest,char * orig); 
void reemplazar(char * cad, char old,char new, int size) ;
t_info_sentencias * crear_info_sentencias(t_nodo_arbol * p_nodo) ;


extern int linecount;

t_pila * pila_sentencias;
t_pila * pila_comparaciones;
t_pila * pila_condiciones;
t_pila * pila_expresiones;

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
t_nodo_arbol * nodo_iguales;
t_nodo_arbol * nodo_filter;
t_nodo_arbol * nodo_declaracion_variable;

t_nodo_arbol * nodo_sentencias_then;
t_nodo_arbol * nodo_sentencias_else;
t_nodo_arbol * nodo_do;



t_nodo_arbol * nodo_then;


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
%type <str_val> comparador
%type <str_val> sentencia
// %type <str_val> factor_str

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
%token<str_val> OP_MAYOR
%token<str_val> OP_MAYOR_IGUAL
%token<str_val> OP_MENOR
%token<str_val> OP_MENOR_IGUAL
%token<str_val> OP_DISTINTO
%token<str_val> OP_IGUAL_IGUAL
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
	nodo_pgm = nodo_programa;
	puts("COMPILACION EXITOSA\n");
	puts("-------------------\n");
};

programa : PR_MAIN declaracion_variables lista_sentencias
{

	// nodo_declaracion_variable = nodo_sentencias;

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

sentencia : asignacion PUNTO_Y_COMA
{
	if(DEBUG) {
		puts("Asignacion\n");
		puts("-------------------\n");		
	}


	nodo_sentencia = crear_nodo_arbol(crear_info(";"),nodo_asignacion,NULL);
	insertar_en_pila(&pila_sentencias,crear_info_sentencias(nodo_sentencia));


};


lista_sentencias : sentencia
{
	// if(DEBUG){
		puts("Una sola sentencia\n");
		puts("-------------------\n");
		// printf("la pila esta vacia? %d\n",pila_vacia(&pila_sentencias) );
	// }
		t_info_sentencias * sentencia_apilada = sacar_de_pila(&pila_sentencias);
		nodo_sentencias = sentencia_apilada->a;
};

lista_sentencias : sentencia lista_sentencias
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
};

sentencia : condicional 
{

	// nodo_sentencia = nodo_condicional;
	if(DEBUG) {
		puts("sentencia : condicional \n");
		puts("-------------------\n");		
	}
	
	nodo_sentencia = crear_nodo_arbol(crear_info(";"),nodo_condicional,NULL);
	insertar_en_pila(&pila_sentencias,crear_info_sentencias(nodo_sentencia));


};


sentencia : iteracion
{
	if(DEBUG) {
		puts("sentencia : iteracion\n");
		puts("-------------------\n");		
	}

	nodo_sentencia = crear_nodo_arbol(crear_info(";"),nodo_iteracion,NULL);
	insertar_en_pila(&pila_sentencias,crear_info_sentencias(nodo_sentencia));
	// print_t(nodo_sentencia);
	// nodo_sentencia = nodo_iteracion;
};

sentencia : io
{
	if(DEBUG) {
		puts("Operacion de entrada salidas\n");
		puts("-------------------\n");		
	}
	nodo_sentencia = nodo_io;

};

sentencia : iguales PUNTO_Y_COMA
{
	if(DEBUG) {
		puts("Operacion de iguales\n");
		puts("-------------------\n");	
	}
	nodo_sentencia = nodo_iguales;
}

sentencia : filter PUNTO_Y_COMA
{
	if(DEBUG) {
		puts("Operacioon de filters\n");
		puts("-------------------\n");
	}
	nodo_sentencia = nodo_filter;
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

condicional : PR_IF PAR_ABRE condicion PAR_CIERRA then PR_ENDIF
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

condicional : PR_IF PAR_ABRE condicion PAR_CIERRA then else PR_ENDIF
{


	if(DEBUG) {
		puts("Condicional con ELSE\n");
		puts("-------------------\n");	
	}

	t_info_sentencias * p_info = sacar_de_pila(&pila_condiciones);
	nodo_then = crear_nodo_arbol(crear_info("<-true . false->"),nodo_sentencias_then,nodo_sentencias_else);
	nodo_condicional = crear_nodo_arbol(crear_info("IF"),p_info->a,nodo_then);

}

then : PR_THEN lista_sentencias
{
	if(DEBUG) {
		puts("PR_THEN lista_sentencias\n");
		puts("-------------------\n");	
	}
	nodo_sentencias_then = obtener_raiz(nodo_sentencias);
}

else : PR_ELSE lista_sentencias
{
	if(DEBUG) {
		puts("PR_ELSE lista_sentencias\n");
		puts("-------------------\n");	
	}
	nodo_sentencias_else = obtener_raiz(nodo_sentencias);
}

condicion : comparacion
{
	// if(DEBUG) {
		puts("condicion : comparacion\n");
		puts("-------------------\n");
	// }
	t_info_sentencias * p_info = sacar_de_pila(&pila_comparaciones);
	nodo_condicion = p_info->a;
	insertar_en_pila(&pila_condiciones,crear_info_sentencias(nodo_condicion));

}

condicion : comparacion OP_LOG_AND comparacion
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

condicion : comparacion OP_LOG_OR comparacion
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

comparacion : expresion comparador expresion
{
	// if(DEBUG) {
	// puts($2);
		puts("comparacion : expresion comparador termino\n");
		puts("-------------------\n");
	// }
	char mjs_error[60];
	/* comparo que para operar entre terminos, ambos tengan el mismo tipo de datos*/ 
	if(!tipos_iguales($1,$3,mjs_error,linecount)) 
	{
		puts(mjs_error);
		exit(1);
	}

	t_info_sentencias * p_info1 = sacar_de_pila(&pila_expresiones);
	t_info_sentencias * p_info2 = sacar_de_pila(&pila_expresiones);
	nodo_comparacion = crear_nodo_arbol(crear_info($2),p_info1->a,p_info1->a);

	// puts("a ver esto ahora");
	// nodo_comparacion = crear_nodo_arbol(crear_info($2),nodo_expresion,nodo_termino);
	insertar_en_pila(&pila_comparaciones,crear_info_sentencias(nodo_comparacion));
}

comparacion : PR_NOT expresion
{
	if(DEBUG) {
		puts("comparacion : PR_NOT expresion comparador expresion\n");
		puts("-------------------\n");
	}

	t_info_sentencias * p_info = sacar_de_pila(&pila_expresiones);

	nodo_comparacion = crear_nodo_arbol(crear_info("NOT"),p_info->a,NULL);
	insertar_en_pila(&pila_comparaciones,crear_info_sentencias(nodo_comparacion));

}

iteracion : PR_WHILE PAR_ABRE condicion PAR_CIERRA PR_DO lista_sentencias PR_ENDWHILE
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

asignacion : TOKEN_ID OP_IGUAL expresion 
{
	if(DEBUG) {
		puts("Asignacion -> Token_ID := expresion\n");
		puts("-------------------\n");
	}

	// printf("asignacion %s %s\n",$1,$3 );
	/* comparo que para operar entre terminos, ambos tengan el mismo tipo de datos*/ 
	char mjs_error[60];
	if(!tipos_iguales($1,$3,mjs_error, linecount)) {
		puts(mjs_error);
		exit(1);
	}
	t_info_sentencias * p_info = sacar_de_pila(&pila_expresiones);
	/* guardo la asignacion en el arbol de ejecucion */
	nodo_asignacion = crear_nodo_arbol(crear_info(":="),crear_hoja(crear_info($1)),p_info->a);

}

expresion :termino OP_CONCAT factor 
{
	if(DEBUG) {
		printf("expresion %s %s\n",$1,$3 );
		puts("expresion : factor OP_CONCAT factor ");
		puts("-------------------\n");
	}

	/* comparo que para operar entre terminos, ambos tengan el mismo tipo de datos*/ 
	char mjs_error[60];
	if(!tipos_iguales($1,$3,mjs_error, linecount)) {
		puts(mjs_error);
		exit(1);
	}

	/* Verifico que no este concatenando flotantes*/
	int tipo = traer_tipo($3);
	if(tipo == TIPO_FLOAT) {
		char aux_float[10];
		char aux_float2[10];
		sprintf(aux_float,"%s",$1);
		sprintf(aux_float2,"%s",$3);
		sprintf(mjs_error,OPERACION_INVALIDA_TIPOS,"CONCATENACION",aux_float,aux_float2,"FLOAT",linecount);
		puts(mjs_error);
		exit(1);
	}

	/* Verifico que no este concatenando enteros*/
	if(tipo == TIPO_INT) {
		char aux_int[10];
		char aux_int2[10];
		sprintf(aux_int,"%s",$1);
		sprintf(aux_int2,"%s",$3);
		sprintf(mjs_error,OPERACION_INVALIDA_TIPOS,"CONCATENACION",aux_int,aux_int2,"INT",linecount);
		puts(mjs_error);
		exit(1);
	}
	// puts(nodo_termino->info->a);
	// puts(nodo_factor->info->a);

	// printf("%d %d\n", nodo_termino,nodo_factor );

	/* guardo la expresion en el arbol de ejecucion */

	nodo_expresion = crear_nodo_arbol(crear_info("++"),nodo_termino,nodo_factor);

	insertar_en_pila(&pila_expresiones,crear_info_sentencias(nodo_expresion));

}

expresion : termino
{
	if(DEBUG) {
	printf("%s\n",$1 );
		puts("Expresion -> termino\n");
		puts("-------------------\n");
	}

	$$=$1;
	
	/* guardo la expresion en el arbol de ejecucion */
	nodo_expresion = nodo_termino;
	insertar_en_pila(&pila_expresiones,crear_info_sentencias(nodo_expresion));

}

expresion : expresion OP_SUMA termino  
{
	if(DEBUG) {
		printf("%s %s\n", $1, $3);
		puts("expresion : expresion OP_SUMA termino\n");
		puts("-------------------\n");
	}
	/* comparo que para operar entre terminos, ambos tengan el mismo tipo de datos*/ 
	char mjs_error[60];
	if(!tipos_iguales($1,$3,mjs_error, linecount)) {
		puts(mjs_error);
		exit(1);
	}
	/* Verifico que no este sumando strings*/
	int tipo = traer_tipo($3);
	if(tipo == TIPO_STRING) {
		sprintf(mjs_error,OPERACION_INVALIDA_TIPOS,"SUMA",$1,$3,"STRING",linecount);
		puts(mjs_error);
		exit(1);
	}

	/* guardo la expresion en el arbol de ejecucion */
	t_info_sentencias * p_info = sacar_de_pila(&pila_expresiones);
	nodo_expresion = crear_nodo_arbol(crear_info("+"),p_info->a,nodo_termino);
	insertar_en_pila(&pila_expresiones,crear_info_sentencias(nodo_expresion));

} 

expresion : expresion OP_RESTA termino 
{
	if(DEBUG) {
		printf("%s %s\n", $1, $3);
		puts("Resta\n");
		puts("-------------------\n");
	}

	/* comparo que para operar entre terminos, ambos tengan el mismo tipo de datos*/ 
	char mjs_error[60];
	if(!tipos_iguales($1,$3,mjs_error, linecount)) {
		puts(mjs_error);
		exit(1);
	}
	/* Verifico que no este restando strings*/
	int tipo = traer_tipo($3);
	if(tipo == TIPO_STRING) {
		sprintf(mjs_error,OPERACION_INVALIDA_TIPOS,"RESTA",$1,$3,"STRING",linecount);
		puts(mjs_error);
		exit(1);
	}

	/* guardo la expresion en el arbol de ejecucion */
	t_info_sentencias * p_info = sacar_de_pila(&pila_expresiones);
	nodo_expresion = crear_nodo_arbol(crear_info("-"),p_info->a,nodo_termino);
	insertar_en_pila(&pila_expresiones,crear_info_sentencias(nodo_expresion));

}

termino : factor
{
	if(DEBUG) {
	printf("%s\n",$1 );
		puts("termino : factor\n");
		puts("-------------------\n");
	}
	/*guardo el termino en el arbol de ejecucion*/
	nodo_termino = nodo_factor;

}

termino : termino OP_DIV factor
{
	if(DEBUG) {
	printf("%s %s\n", $1,$3);
		puts("termino : termino OP_DIV factor\n");
		puts("-------------------\n");
	}
	/* comparo que para operar entre terminos, ambos tengan el mismo tipo de datos*/ 
	char mjs_error[60];
	if(!tipos_iguales($1,$3,mjs_error, linecount)) {
		puts(mjs_error);
		exit(1);
	}

	/* Verifico que no este dividiendo strings*/
	int tipo = traer_tipo($3);
	if(tipo == TIPO_STRING) {
		sprintf(mjs_error,OPERACION_INVALIDA_TIPOS,"DIVISION",$1,$3,"STRING",linecount);
		puts(mjs_error);
		exit(1);
	}

	/*guardo el termino en el arbol de ejecucion*/
	nodo_termino = crear_nodo_arbol(crear_info("/"),nodo_termino,nodo_factor);
}

termino : termino OP_MUL factor
{
	if(DEBUG) {
	printf("%s %s\n", $1,$3);
		puts("termino : termino OP_MUL factor\n");
		puts("-------------------\n");
	}

	/* comparo que para operar entre terminos, ambos tengan el mismo tipo de datos*/ 
	char mjs_error[60];
	if(!tipos_iguales($1,$3,mjs_error, linecount)) {
		puts(mjs_error);
		exit(1);
	}

	/* Verifico que no este multiplicando strings*/
	int tipo = traer_tipo($3);
	if(tipo == TIPO_STRING) {
		sprintf(mjs_error,OPERACION_INVALIDA_TIPOS,"MULTIPLICACION",$1,$3,"STRING",linecount);
		puts(mjs_error);
		exit(1);
	}

	/*guardo el termino en el arbol de ejecucion*/
	nodo_termino = crear_nodo_arbol(crear_info("*"),nodo_termino,nodo_factor);

}

factor : CONST_STR
{
	if(DEBUG) {
		// printf("%s\n",$1);
		puts("factor : cte\n");
		puts("-------------------\n");		
	}
	/* agrego la constante a la tabla de simbolos */
	agregar_cte_a_TS(TIPO_STRING,$1, 0,0.0,linecount);
	$$=$1;

	/*guardo el termino en el arbol de ejecucion*/
	nodo_factor = crear_hoja(crear_info($1));

	puts($1);

}

factor : CONST_INT
{
	if(DEBUG) {
		printf("%d\n",$1);
		puts("factor : cte\n");
		puts("-------------------\n");		
	}
	/* agrego la constante a la tabla de simbolos, pero para hacerlo, primero
	tengo que castearla a string */
	char temp[10];
	sprintf(temp,"%d",$1);
	$$ = temp;
	agregar_cte_a_TS(TIPO_INT,NULL, $1,0.0,linecount);

	/*guardo el termino en el arbol de ejecucion*/
	nodo_factor = crear_hoja(crear_info(temp));
}

factor : CONST_FLOAT
{
	if(DEBUG) {
		printf("%.4f\n",$1);
		puts("factor : cte\n");
		puts("-------------------\n");
	}
	/* agrego la constante a la tabla de simbolos, pero para hacerlo, primero
	tengo que castearla a string */
	char temp[10];
	sprintf(temp,"%.4f",$1);
	$$ = temp;
	agregar_cte_a_TS(TIPO_FLOAT,NULL, 0,$1,linecount);

	/*guardo el termino en el arbol de ejecucion*/
	nodo_factor = crear_hoja(crear_info(temp));
}

factor : TOKEN_ID
{
	if(DEBUG) {
		puts("factor : TOKEN_ID\n");
		puts("-------------------\n");
	}
	/*guardo el termino en el arbol de ejecucion*/
	nodo_factor = crear_hoja(crear_info($1));
} 
     
// factor : expresion
// {
// 	puts("factor : expresion\n");
// 	puts("-------------------\n");
// }

declaracion_variables : PR_DIM COR_ABRE declaracion_variables_interna COR_CIERRA PUNTO_Y_COMA 

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

declaracion_variables : PR_DIM COR_ABRE declaracion_variables_interna COR_CIERRA PUNTO_Y_COMA declaracion_variables 
{
	puts("declaracion_variables : PR_DIM COR_ABRE declaracion_variables_interna COR_CIERRA\n");
	puts("-------------------\n");
}


declaracion_variables_interna : TOKEN_ID COMA declaracion_variables_interna COMA tipo_dato
{
	if(DEBUG) {
		puts("declaracion_variables_interna : TOKEN_ID COMA declaracion_variables_interna COMA tipo_dato\n");
		puts("-------------------\n");
	}
	/* Agrego de forma temporal los datos leidos, para luego procesarlos */
	strcpy(temp_variables[variables_a_agregar],$1);
	strcpy(temp_tipo_dato[variables_a_agregar],$5);
	variables_a_agregar++;
} 

declaracion_variables_interna : TOKEN_ID COR_CIERRA PR_AS COR_ABRE tipo_dato
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
	strcpy(temp_variables[variables_a_agregar],$1);
	strcpy(temp_tipo_dato[variables_a_agregar],$5);
	variables_a_agregar++;
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
	// strcpy(nodo_comparador->info->a, ">");
	if(DEBUG) {
		puts("OP_MAYOR\n");
		puts("-------------------\n");
	}
}   

comparador : OP_MENOR
{
	// strcpy(nodo_comparador->info->a, "<");
	if(DEBUG) {
		puts("OP_MENOR\n");
		puts("-------------------\n");
	}
}   

comparador : OP_MENOR_IGUAL
{
	// strcpy(nodo_comparador->info->a, "<=");

	$$=$1;
	if(DEBUG) {
		puts("OP_MENOR_IGUAL\n");
		puts("-------------------\n");
	}
}      

comparador : OP_MAYOR_IGUAL
{
	// strcpy(nodo_comparador->info->a, ">=");
	if(DEBUG) {
		puts("OP_MAYOR_IGUAL\n");
		puts("-------------------\n");
	}
}    

comparador : OP_IGUAL_IGUAL
{
	// strcpy(nodo_comparador->info->a, "==");
	if(DEBUG) {
		puts("OP_IGUAL_IGUAL\n");
		puts("-------------------\n");
	}
}

comparador : OP_DISTINTO
{
	// strcpy(nodo_comparador->info->a, "!=");
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
	// vaciar_arbol(&arbol_ejecucion);
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
    crear_pila(&pila_sentencias);
    crear_pila(&pila_comparaciones);
    crear_pila(&pila_condiciones);
    crear_pila(&pila_expresiones);
    crear_arbol(&arbol_ejecucion);

	yyparse();
	imprimir_tabla_simbolos();
	// arbol_ejecucion->p_nodo = obtener_raiz(nodo_sentencias);
	arbol_ejecucion->p_nodo = obtener_raiz(nodo_factor);

	recorrer_en_orden(arbol_ejecucion->p_nodo,&visitar);
	
	print_t(arbol_ejecucion->p_nodo);
	
	// imprimir_arbol(arbol_ejecucion->p_nodo);

	// printf("la pila esta vacia? %d\n", pila_vacia(&pila_sentencias) );
	// if(!pila_vacia)
	// {
	// 	t_nodo_arbol
	// }

	finally(yyin);
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
			fprintf(f, "%s\t\t\t\t%s\t\t\t\t%s\t\t\t\t%d \n",tabla_simbolos[i].nombre,tipo_simbolo_to_string(tabla_simbolos[i].tipo),tabla_simbolos[i].valor_string == NULL ? "" : tabla_simbolos[i].valor_string,tabla_simbolos[i].lineNumber);
	
		if(tabla_simbolos[i].tipo == TIPO_INT)
			fprintf(f, "%s\t\t\t\t%s\t\t\t\t%d\t\t\t\t%d\n",tabla_simbolos[i].nombre,tipo_simbolo_to_string(tabla_simbolos[i].tipo),tabla_simbolos[i].valor_int,tabla_simbolos[i].lineNumber);
		
		if(tabla_simbolos[i].tipo == TIPO_FLOAT)
			fprintf(f, "%s\t\t\t\t%s\t\t\t\t%.4f\t\t\t\t%d\n",tabla_simbolos[i].nombre,tipo_simbolo_to_string(tabla_simbolos[i].tipo),tabla_simbolos[i].valor_float,tabla_simbolos[i].lineNumber);

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
        printf("%s\n", s + i*CARACTERES_RENGLON_ARBOL);
}

void imprimir_arbol(t_nodo_arbol *n){
	printf("%s\n", n->info->a);
	if(n->nodo_izq != NULL)
		imprimir_arbol(n->nodo_izq);
	if(n->nodo_der != NULL)
		imprimir_arbol(n->nodo_der);
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