%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"
#include "structs.h"
#include "defines.h"
#include "arbol.h"
#include "pila.h"
#include "cola.h"

#define DEBUG 1
extern YYSTYPE yylval;
char prefijo_id[10] = PREFIJO_ID;
char prefijo_int[10] = PREFIJO_INT;
char prefijo_float[10] = PREFIJO_FLOAT;
char prefijo_string[10] = PREFIJO_STRING;
char temp_variables[MAX_VARIABLES][30];
char temp_tipo_dato[MAX_VARIABLES][10];
t_info * crear_info(char *);
int variables_a_agregar= 0;
char aux[30];
char aux2[30];
int cantidad_cte_string = 0;
int buscar_en_TS_sin_prefijo(char * nombre, char * mjs_error , int lineNumber );
int buscar_en_TS(char * nombre, char * mjs_error, int lineNumber);
void agregar_simbolo(char * nombre, int tipo, char * valor,char * alias,int lineNumber,int esConstante);
void agregar_variable_a_TS(char * nombre, char * tipo,int lineNumber);
void agregar_cte_a_TS(int tipo, char * valor_str, int valor_int,float valor_float,int lineNumber);
void agregar_cte_a_TS_sin_prefijo(int tipo, char * valor_str, int valor_int,float valor_float,int lineNumber);
void error_lexico(char * mensaje);
int tipos_iguales(char * nombre1, char * nombre2, char * mjs_error, int lineNumber);
int traer_tipo(char * nombre);
void poner_prefijo(char * str, char * prefijo);
int print_t(t_nodo_arbol *tree);
int _print_t(t_nodo_arbol *tree, int is_left, int offset, int depth, char * s, int max);
void recorrer_asm(t_nodo_arbol *n, int usar_aux2);
void copiar_sin_finalizador(char * dest,char * orig); 
void reemplazar(char * cad, char old,char new, int size) ;
t_info_sentencias * crear_info_sentencias(t_nodo_arbol * p_nodo) ;
void crear_arbol_iguales(t_nodo_arbol ** raiz);
void crear_codigo_assembler(t_nodo_arbol *tree);
void crear_inicio_assembler();
void reemplazar_etiqueta_por_valor_TS(t_nodo_arbol*);
int is_hoja(t_nodo_arbol *n);
char *newStr (char *charBuffer);
char * substring(char * str , int start, int end);
char * get_nombre_sin_prefijo(t_simbolo *);
void recorrer_asm_2(t_nodo_arbol *n, int usar_aux2);

extern int linecount;
static t_info_sentencias * p_info_iguales;
static FILE *a;
static int usar_aux2 = 0, ifs=0, whiles=0;
static char asig_final[80];
static char asig_iguales[80];
static char sent_final[80];
static char string_saltos[1];
static char string_cond[5];

t_pila_de_colas * pila_de_colas;
t_pila * pila_bloques;
t_cola * cola_sentencias;
t_pila * pila_comparaciones;
t_pila * pila_condiciones;
t_pila * pila_expresiones;
t_pila * pila_factores;
t_pila * pila_terminos;
t_pila * pila_expresiones_iguales;
t_pila * pila_variables_filter;
t_pila * pila_comparacion_filter;
t_pila_asm * pila_whiles;

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
t_nodo_arbol * nodo_asm_while;


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
%type <str_val> iguales
%type <str_val> filter
%type <str_val> salida
%type <str_val> entrada
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
		puts("sentencia : asignacion PUNTO_Y_COMA\n");
		puts("-------------------\n");		
	}


	nodo_sentencia = crear_nodo_arbol(crear_info(";"),nodo_asignacion,NULL);
	insertar_en_cola(&cola_sentencias,crear_info_sentencias(nodo_sentencia));
	// puts("insertando en cola");
	// recorrer_en_orden(nodo_sentencia,&visitar);


};


lista_sentencias : sentencia
{
	// if(DEBUG){
		puts("Una sola sentencia\n");
		puts("-------------------\n");
		// printf("la pila esta vacia? %d\n",pila_vacia(&cola_sentencias) );
	// }
		t_info_sentencias * sentencia_apilada = sacar_de_cola(&cola_sentencias);
		nodo_sentencias = sentencia_apilada->a;
		// puts("sacando de cola");
		// recorrer_en_orden(sentencia_apilada->a,&visitar);
};

lista_sentencias : sentencia lista_sentencias
{
	// if(DEBUG) {
		puts("Varias sentencias\n");
		puts("-------------------\n");
	// }
	// nodo_sentencias = nodo_sentencia;
	// nodo_sentencias->nodo_der = nodo_sentencia;
	t_info_sentencias * sentencia_apilada = sacar_de_cola(&cola_sentencias);
	nodo_sentencias->nodo_der = sentencia_apilada->a;
	nodo_sentencias->nodo_der->padre = nodo_sentencias;
	nodo_sentencias = sentencia_apilada->a;
		// puts("sacando de cola");
		// recorrer_en_orden(sentencia_apilada->a,&visitar);



	// nodo_sentencias = crear_nodo_arbol(crear_info("NUEVA"),nodo_sentencias,sentencia_apilada->a);
};

sentencia : condicional 
{

	// nodo_sentencia = nodo_condicional;
	if(DEBUG) {
		puts("sentencia : condicional \n");
		puts("-------------------\n");		
	}
	
	//para esta altura todas las sentencias del bloque deberian haber sido desencoladas
	printf("La cola de sentencias esta vacia? %d\n",cola_vacia(&cola_sentencias));
	cola_sentencias = sacar_de_pila_de_colas(&pila_de_colas);

	nodo_sentencia = crear_nodo_arbol(crear_info(";"),nodo_condicional,NULL);
	insertar_en_cola(&cola_sentencias,crear_info_sentencias(nodo_sentencia));
	// puts("insertando en cola");
	// recorrer_en_orden(nodo_sentencia,&visitar);

};


sentencia : iteracion
{
	if(DEBUG) {
		puts("sentencia : iteracion\n");
		puts("-------------------\n");		
	}

	//para esta altura todas las sentencias del bloque deberian haber sido desencoladas
	printf("La cola de sentencias esta vacia? %d\n",cola_vacia(&cola_sentencias));
	cola_sentencias = sacar_de_pila_de_colas(&pila_de_colas);

	nodo_sentencia = crear_nodo_arbol(crear_info(";"),nodo_iteracion,NULL);
	insertar_en_cola(&cola_sentencias,crear_info_sentencias(nodo_sentencia));
		// puts("insertando en cola");
	// recorrer_en_orden(nodo_sentencia,&visitar);
	// print_t(nodo_sentencia);
	// nodo_sentencia = nodo_iteracion;
};

sentencia : io PUNTO_Y_COMA
{
	if(DEBUG) {
		puts("Operacion de entrada salidas\n");
		puts("-------------------\n");		
	}
	nodo_sentencia = crear_nodo_arbol(crear_info(";"),nodo_io,NULL);
	insertar_en_cola(&cola_sentencias,crear_info_sentencias(nodo_sentencia));
		// puts("insertando en cola");
	// recorrer_en_orden(nodo_sentencia,&visitar);
};

sentencia : iguales PUNTO_Y_COMA
{
	if(DEBUG) {
		puts("Operacion de iguales\n");
		puts("-------------------\n");	
	}
	nodo_sentencia = crear_nodo_arbol(crear_info(";"),nodo_iguales,NULL);
	insertar_en_cola(&cola_sentencias,crear_info_sentencias(nodo_sentencia));
		// puts("insertando en cola");
	// recorrer_en_orden(nodo_sentencia,&visitar);
}

sentencia : filter PUNTO_Y_COMA
{
	if(DEBUG) {
		puts("Operacioon de filters\n");
		puts("-------------------\n");
	}

	nodo_sentencia = crear_nodo_arbol(crear_info(";"),nodo_filter,NULL);
	insertar_en_cola(&cola_sentencias,crear_info_sentencias(nodo_sentencia));
		// puts("insertando en cola");
	// recorrer_en_orden(nodo_sentencia,&visitar);
	
}

iguales : PR_IGUALES PAR_ABRE expresion COMA COR_ABRE lista_expresiones COR_CIERRA PAR_CIERRA 
{
	if(DEBUG) {
		puts("iguales : PR_IGUALES PAR_ABRE expresion COMA COR_ABRE lista_expresiones COR_CIERRA PAR_CIERRA\n");
		puts("-------------------\n");
	}
	$$ = "IGUALES";
	
	p_info_iguales = sacar_de_pila(&pila_expresiones);	
	crear_arbol_iguales(&nodo_iguales);		
	free(p_info_iguales);	
}

lista_expresiones : expresion COMA lista_expresiones
{
	if(DEBUG) {
		puts("Lista de expresiones\n");
		puts("-------------------\n");		
	}
	
	t_info_sentencias * p_info = sacar_de_pila(&pila_expresiones);
	insertar_en_pila(&pila_expresiones_iguales,p_info);	
}

lista_expresiones : expresion
{
	if(DEBUG) {
		puts("Última expresion\n");
		puts("-------------------\n");		
	}
	t_info_sentencias * p_info = sacar_de_pila(&pila_expresiones);
	insertar_en_pila(&pila_expresiones_iguales,p_info);	
}

filter : PR_FILTER PAR_ABRE condicion_filter COMA COR_ABRE lista_variables COR_CIERRA PAR_CIERRA
{
	if(DEBUG) {
		puts("filter : PR_FILTER PAR_ABRE condicion COMA COR_ABRE lista_variables COR_CIERRA PAR_CIERRA\n");
		puts("-------------------\n");
	}
	$$ = "FILTER";

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

condicion_filter : comparacion_filter
{
	puts("condicion_filter : comparacion_filter\n");
	puts("-------------------\n");
	t_info_sentencias * p_nodo_comparacion_filter = sacar_de_pila(&pila_comparacion_filter);
	nodo_condicion_filter = p_nodo_comparacion_filter->a;
	free(p_nodo_comparacion_filter);
}

condicion_filter : comparacion_filter OP_LOG_AND comparacion_filter
{
	puts("condicion_filter : comparacion_filter and comparacion_filter\n");
	puts("-------------------\n");
	t_info_sentencias * p_nodo_comparacion_filter1 = sacar_de_pila(&pila_comparacion_filter);
	t_info_sentencias * p_nodo_comparacion_filter2 = sacar_de_pila(&pila_comparacion_filter);
	nodo_condicion_filter = crear_nodo_arbol(crear_info("AND"),p_nodo_comparacion_filter1->a,p_nodo_comparacion_filter2->a);

	free(p_nodo_comparacion_filter1);
	free(p_nodo_comparacion_filter2);
}

condicion_filter : comparacion_filter OP_LOG_OR comparacion_filter
{
	puts("condicion_filter : comparacion_filter or comparacion_filter\n");
	puts("-------------------\n");

	t_info_sentencias * p_nodo_comparacion_filter1 = sacar_de_pila(&pila_comparacion_filter);
	t_info_sentencias * p_nodo_comparacion_filter2 = sacar_de_pila(&pila_comparacion_filter);
	nodo_condicion_filter = crear_nodo_arbol(crear_info("OR"),p_nodo_comparacion_filter1->a,p_nodo_comparacion_filter2->a);

	free(p_nodo_comparacion_filter1);
	free(p_nodo_comparacion_filter2);
}

comparacion_filter : OP_FILTER comparador expresion
{
	puts("comparacion_filter : OP_FILTER comparador expresion\n");
	puts("-------------------\n");

	t_info_sentencias * p_nodo_expresion = sacar_de_pila(&pila_expresiones);

	nodo_comparacion_filter = crear_nodo_arbol(crear_info($2),crear_hoja(crear_info("_")),p_nodo_expresion->a);
	insertar_en_pila(&pila_comparacion_filter , crear_info_sentencias(nodo_comparacion_filter));
	// t_info_sentencias * p_info1 = sacar_de_pila(&pila_expresiones);
	// t_info_sentencias * p_info2 = sacar_de_pila(&pila_expresiones);
	// nodo_comparacion = crear_nodo_arbol(crear_info($2),p_info1->a,p_info2->a);
}

// comparacion_filter : PR_NOT OP_FILTER comparador expresion
// {
// 	puts("comparacion_filter : PR_NOT OP_FILTER comparador expresion\n");
// 	puts("-------------------\n");
// }

lista_variables : TOKEN_ID COMA lista_variables
{
	if(DEBUG) {
		puts("Lista de variables\n");
		puts("-------------------\n");		
	}
	insertar_en_pila(&pila_variables_filter,crear_info_sentencias(crear_hoja(crear_info($1))));
}

lista_variables : TOKEN_ID
{
	if(DEBUG) {
		puts("Ultima variable\n");
		puts("-------------------\n");
	}
	insertar_en_pila(&pila_variables_filter,crear_info_sentencias(crear_hoja(crear_info($1))));
}

io : entrada
{
	if(DEBUG) {
		puts("io : entrada\n");
		puts("-------------------\n");
	}

	nodo_io = nodo_entrada;

}

io : salida
{
	if(DEBUG) {
		puts("io : salida\n");
		puts("-------------------\n");		
	}
	nodo_io = nodo_salida;
}

entrada : PR_READ TOKEN_ID
{
	if(DEBUG) {
		puts("entrada : READ id\n");
		puts("-------------------\n");		
	}
	char mjs[50];
	if(buscar_en_TS_sin_prefijo($2,mjs,linecount) == -1)
	{
		puts(mjs);
		exit(1);
	}
	nodo_entrada = crear_nodo_arbol(crear_info("READ"),crear_hoja(crear_info($2)),crear_hoja(crear_info("READ")));
}

salida : PR_WRITE TOKEN_ID
{
	if(DEBUG) {
		puts("salida : PR_WRITE id\n");
		puts("-------------------\n");
	}

	char mjs[50];
	if(buscar_en_TS_sin_prefijo($2,mjs,linecount) == -1)
	{
		puts(mjs);
		exit(1);
	}
	nodo_salida = crear_nodo_arbol(crear_info("WRITE"),crear_hoja(crear_info($2)),crear_hoja(crear_info("WRITE")));

}

salida : PR_WRITE CONST_STR
{
	if(DEBUG) {
		puts("salida : PR_WRITE cte\n");
		puts("-------------------\n");	
	}
	nodo_salida = crear_nodo_arbol(crear_info("WRITE"),crear_hoja(crear_info($2)),crear_hoja(crear_info("WRITE")));

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
	nodo_then = crear_nodo_arbol(crear_info("<V.F>"),nodo_sentencias_then,nodo_sentencias_else);
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

	insertar_en_pila_de_colas(&pila_de_colas,cola_sentencias);
	crear_cola(&cola_sentencias);

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

	insertar_en_pila_de_colas(&pila_de_colas,cola_sentencias);
	crear_cola(&cola_sentencias);

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

	insertar_en_pila_de_colas(&pila_de_colas,cola_sentencias);
	crear_cola(&cola_sentencias);

	t_info_sentencias * p_info1 = sacar_de_pila(&pila_comparaciones);
	t_info_sentencias * p_info2 = sacar_de_pila(&pila_comparaciones);

	nodo_condicion = crear_nodo_arbol(crear_info("OR"),p_info1->a,p_info2->a);
	insertar_en_pila(&pila_condiciones,crear_info_sentencias(nodo_condicion));

}

comparacion : expresion comparador expresion
{
	// if(DEBUG) {
	// puts($2);
		puts("comparacion : expresion comparador expresion\n");
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
	nodo_comparacion = crear_nodo_arbol(crear_info($2),p_info1->a,p_info2->a);

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
		puts($1);
		puts("Asignacion -> Token_ID := expresion\n");
		puts("-------------------\n");
	}

	// printf("asignacion %s %s\n",$1,$3 );
	/* comparo que para operar entre terminos, ambos tengan el mismo tipo de datos*/ 
	puts("asignacion comprobacion tipos iguales");
	char mjs_error[60];
	if(!tipos_iguales($1,$3,mjs_error, linecount)) {
		puts(mjs_error);
		exit(1);
	}
	t_info_sentencias * p_info = sacar_de_pila(&pila_expresiones);
	/* guardo la asignacion en el arbol de ejecucion */
	nodo_asignacion = crear_nodo_arbol(crear_info(":="),crear_hoja(crear_info($1)),p_info->a);

}

expresion :factor OP_CONCAT factor 
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


	/* guardo la expresion en el arbol de ejecucion */

	t_info_sentencias * p_nodo_factor1 = sacar_de_pila(&pila_factores);

	t_info_sentencias * p_nodo_factor2 = sacar_de_pila(&pila_factores);

	nodo_expresion = crear_nodo_arbol(crear_info("++"),p_nodo_factor1->a,p_nodo_factor2->a);

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
	t_info_sentencias * p_nodo_termino = sacar_de_pila(&pila_terminos);
	nodo_expresion = p_nodo_termino->a;
	insertar_en_pila(&pila_expresiones,p_nodo_termino);

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
	t_info_sentencias * p_nodo_expresion = sacar_de_pila(&pila_expresiones);
	t_info_sentencias * p_nodo_termino =  sacar_de_pila(&pila_terminos);
	nodo_expresion = crear_nodo_arbol(crear_info("+"),p_nodo_expresion->a,p_nodo_termino->a);
	insertar_en_pila(&pila_expresiones,crear_info_sentencias(nodo_expresion));

	free(p_nodo_expresion);
	free(p_nodo_termino);

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
	t_info_sentencias * p_nodo_expresion = sacar_de_pila(&pila_expresiones);
	t_info_sentencias * p_nodo_termino =  sacar_de_pila(&pila_terminos);
	nodo_expresion = crear_nodo_arbol(crear_info("-"),p_nodo_expresion->a,p_nodo_termino->a);
	insertar_en_pila(&pila_expresiones,crear_info_sentencias(nodo_expresion));

	free(p_nodo_expresion);
	free(p_nodo_termino);

}

termino : factor
{
	if(DEBUG) {
	printf("%s\n",$1 );
		puts("termino : factor\n");
		puts("-------------------\n");
	}
	/*guardo el termino en el arbol de ejecucion*/
	t_info_sentencias * p_nodo_factor = sacar_de_pila(&pila_factores);
	nodo_termino = p_nodo_factor->a;
	insertar_en_pila(&pila_terminos,p_nodo_factor);

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
	t_info_sentencias * p_nodo_factor = sacar_de_pila(&pila_factores);
	t_info_sentencias * p_nodo_termino = sacar_de_pila(&pila_terminos);

	nodo_termino = crear_nodo_arbol(crear_info("/"),p_nodo_termino->a,p_nodo_factor->a);
	insertar_en_pila(&pila_terminos,crear_info_sentencias(nodo_termino));

	free(p_nodo_factor);
	free(p_nodo_termino);

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
	t_info_sentencias * p_nodo_factor = sacar_de_pila(&pila_factores);
	t_info_sentencias * p_nodo_termino = sacar_de_pila(&pila_terminos);

	nodo_termino = crear_nodo_arbol(crear_info("*"),p_nodo_termino->a,p_nodo_factor->a);
	insertar_en_pila(&pila_terminos,crear_info_sentencias(nodo_termino));

	free(p_nodo_factor);
	free(p_nodo_termino);

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
	nodo_factor =  crear_hoja(crear_info($1));
	insertar_en_pila(&pila_factores,crear_info_sentencias(nodo_factor));
	// nodo_factor = crear_hoja(crear_info($1));

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

	puts("agregando a factooooor intttttttttttttttttttttttttttttt");
	puts(temp);
	/*guardo el termino en el arbol de ejecucion*/
	nodo_factor =  crear_hoja(crear_info(temp));
	insertar_en_pila(&pila_factores,crear_info_sentencias(nodo_factor));
	// nodo_factor = crear_hoja(crear_info(temp));
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
	nodo_factor =  crear_hoja(crear_info(temp));
	insertar_en_pila(&pila_factores,crear_info_sentencias( nodo_factor));
	// nodo_factor = crear_hoja(crear_info(temp));
}

factor : TOKEN_ID
{
	if(DEBUG) {
		puts("factor : TOKEN_ID\n");
		puts("-------------------\n");
	}
	/*guardo el termino en el arbol de ejecucion*/
	nodo_factor =  crear_hoja(crear_info($1));
	insertar_en_pila(&pila_factores,crear_info_sentencias(nodo_factor ));
	// nodo_factor = crear_hoja(crear_info(temp));
} 
     
     
factor : iguales 
{
	if(DEBUG) {
		puts($1);
		puts("factor : iguales \n");
		puts("-------------------\n");	
	}
	insertar_en_pila(&pila_factores,crear_info_sentencias(crear_nodo_arbol(crear_info("IGUALES"),nodo_iguales,NULL)));
	// nodo_factor = crear_nodo_arbol(crear_info("IGUALES"),nodo_iguales,NULL);
	//nodo_sentencia = crear_nodo_arbol(crear_info(";"),nodo_iguales,NULL);
	//insertar_en_pila(&cola_sentencias,crear_info_sentencias(nodo_sentencia));
}

factor : filter
{
	if(DEBUG) {
		puts($1);
		puts("factor : filter\n");
		puts("-------------------\n");	
	}	
	insertar_en_pila(&pila_factores,crear_info_sentencias(nodo_filter));

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



    crear_pila_de_colas(&pila_de_colas);
    // crear_pila(&cola_sentencias);
    crear_cola(&cola_sentencias);
    crear_pila(&pila_bloques);
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

	refactorizar_nodo(&arbol_ejecucion->p_nodo);
	recorrer_en_orden(arbol_ejecucion->p_nodo,&reemplazar_etiqueta_por_valor_TS);

	// crear_codigo_assembler(arbol_ejecucion->p_nodo);
	// arbol_ejecucion->p_nodo = obtener_raiz(nodo_iguales);

	// recorrer_en_orden(arbol_ejecucion->p_nodo,&visitar);
	// puts("hola");
	print_t(arbol_ejecucion->p_nodo);
	
	// imprimir_arbol(arbol_ejecucion->p_nodo);

	// printf("la pila esta vacia? %d\n", pila_vacia(&cola_sentencias) );
	// if(!pila_vacia)
	// {
	// 	t_nodo_arbol
	// }
	
	crear_codigo_assembler(arbol_ejecucion->p_nodo);
	finally(yyin); 
	puts("\nFinalizando compilacion...");
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
	fprintf(f, "NOMBRE \t\t\t\t TIPO \t\t\t\t CONST\t\t\t\t LINEA\n\n");
	for (i = 0; i < cantidad_simbolos; ++i)
	{
		if(tabla_simbolos[i].tipo == TIPO_STRING)
		{
			fprintf(f, "%s\t\t\t\t%s\t\t\t\t%d\t\t\t\t%d \n",tabla_simbolos[i].nombre,tipo_simbolo_to_string(tabla_simbolos[i].tipo),tabla_simbolos[i].esConstante,tabla_simbolos[i].lineNumber);
			if(tabla_simbolos[i].nombre[0] == '_')
			{
				fprintf(a, "\n");
				fprintf(a, tabla_simbolos[i].nombre);			
				fprintf(a, " db ?");
			}
		}
	
		if(tabla_simbolos[i].tipo == TIPO_INT)
		{
			fprintf(f, "%s\t\t\t\t%s\t\t\t\t%d\t\t\t\t%d\n",tabla_simbolos[i].nombre,tipo_simbolo_to_string(tabla_simbolos[i].tipo),tabla_simbolos[i].esConstante,tabla_simbolos[i].lineNumber);
			fprintf(a, "\n");
			if(tabla_simbolos[i].nombre[1] == 'c' && tabla_simbolos[i].nombre[2] == 't' && tabla_simbolos[i].nombre[3] == 'e')
			{
				char *aux = newStr(tabla_simbolos[i].nombre);
				fprintf(a, "_");
				fprintf(a, aux);		
				fprintf(a, " dd ");
				char subbuff[5];
				memcpy( subbuff, &aux[4], 1 );
				subbuff[1] = '\0';
				fprintf(a, subbuff);
				fprintf(a, ".000000");
			} else
			{
				fprintf(a, "\n");
				fprintf(a, tabla_simbolos[i].nombre);			
				fprintf(a, " dd ?");
			}
		}
		
		if(tabla_simbolos[i].tipo == TIPO_FLOAT)
		{
			fprintf(f, "%s\t\t\t\t%s\t\t\t\t%d\t\t\t\t%d\n",tabla_simbolos[i].nombre,tipo_simbolo_to_string(tabla_simbolos[i].tipo),tabla_simbolos[i].esConstante,tabla_simbolos[i].lineNumber);
			fprintf(a, "\n");
			if(tabla_simbolos[i].nombre[1] == 'c' && tabla_simbolos[i].nombre[2] == 't' && tabla_simbolos[i].nombre[3] == 'e')
			{
				char *aux = newStr(tabla_simbolos[i].nombre);
				fprintf(a, "_");
				fprintf(a, aux);		
				fprintf(a, " dd ");
				char subbuff[5];
				memcpy( subbuff, &aux[4], 6 );
				subbuff[6] = '\0';
				fprintf(a, subbuff);
			} else
			{
				fprintf(a, "\n");
				fprintf(a, tabla_simbolos[i].nombre);			
				fprintf(a, " dd ?");
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
void agregar_simbolo(char * nombre, int tipo, char * valor,char * alias, int lineNumber,int esConstante) {
int n;
	tabla_simbolos[cantidad_simbolos].nombre = malloc(sizeof(char) * strlen(nombre));
	strcpy(tabla_simbolos[cantidad_simbolos].nombre,nombre);


	if(alias != NULL) {
		tabla_simbolos[cantidad_simbolos].alias = malloc(sizeof(char) * strlen(alias));
		strcpy(tabla_simbolos[cantidad_simbolos].alias,alias);	
	}
	tabla_simbolos[cantidad_simbolos].tipo = tipo;
	tabla_simbolos[cantidad_simbolos].esConstante = esConstante;
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

char * substring(char * str , int start, int end)
{
	char * ret = (char*) malloc(sizeof(char) * (end - start + 1));
	memcpy( ret, str + start, end - start +1);
	*(ret + (end - start+1)) = '\0';
	return ret;
}

char * get_nombre_sin_prefijo(t_simbolo * p_simbolo)
{
	// printf("Prefijo int : %d\n",);
	if(!p_simbolo->esConstante)
		return p_simbolo->nombre + strlen(PREFIJO_ID);

	if(p_simbolo->tipo == TIPO_INT)
		return p_simbolo->nombre + strlen(PREFIJO_INT);

	if(p_simbolo->tipo == TIPO_STRING)
		return p_simbolo->nombre + strlen(PREFIJO_STRING);
	
	if(p_simbolo->tipo == TIPO_FLOAT)
		return p_simbolo->nombre + strlen(PREFIJO_FLOAT);
}

/* Busca una variable en la TS sin tener en cuenta sus prefijos y devuelve
el indice. si no lo encuentra, devuelve -1;*/
int buscar_en_TS_sin_prefijo(char * nombre, char * mjs_error, int lineNumber) {
	char * temp;
	int i;
	for (i = 0; i < cantidad_simbolos; ++i)
	{
		temp = get_nombre_sin_prefijo(&tabla_simbolos[i]	);
		// strcpy(temp,tabla_simbolos[i].nombre + 1);
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
	agregar_simbolo(aux2,tipo,NULL,NULL,lineNumber,0);
}

/*Agrega una constante a la TS*/
void agregar_cte_a_TS(int tipo, char * valor_str, int valor_int,float valor_float, int lineNumber) {


	if(tipo == TIPO_STRING) {
		strcpy(aux2,prefijo_string);
		strcat(aux2, valor_str);
		if(buscar_en_TS_sin_prefijo(valor_str,NULL,0) != -1)
		return;

		cantidad_cte_string++;
		agregar_simbolo(aux2,tipo,NULL,NULL,lineNumber,1);


	}else if(tipo == TIPO_INT) {
		strcpy(aux2,prefijo_int);
		sprintf(aux,"%d",valor_int);
		strcat(aux2,aux);
		if(buscar_en_TS_sin_prefijo(aux,NULL,0) != -1)
		return;

		agregar_simbolo(aux2,tipo,aux,NULL,lineNumber,1);
		
	}else if(tipo == TIPO_FLOAT) {
		strcpy(aux2,prefijo_float);
		snprintf(aux,30,"%.4f",valor_float);
		strcat(aux2,aux);
		if(buscar_en_TS_sin_prefijo(aux,NULL,0) != -1)
		return;
		agregar_simbolo(aux2,tipo,aux,NULL,lineNumber,1);
		
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
	    puts("Error abriendo archivo de notaci�n intermedia");
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

void reemplazar_etiqueta_por_valor_TS(t_nodo_arbol * p_nodo)
{
	if(!p_nodo) return;

	int indice = buscar_en_TS_sin_prefijo(p_nodo->info->a,NULL,0);
	if(indice >= 0 && *tabla_simbolos[indice].nombre == '_')
		strcpy(p_nodo->info->a,tabla_simbolos[indice].nombre);
}

void crear_inicio_assembler()
{
	a = fopen("asm.asm", "w");
	if (a == NULL)
	{
	    puts("Error abriendo archivo assembler");
	    exit(1);
	}
	fprintf(a, ";TITLE TP Compilador 2016");
	fprintf(a, "\ninclude macros2.asm\t\t ;incluye macros\n");
	fprintf(a, "\ninclude number.asm\t\t ;incluye el asm para impresion de numeros\n");
	fprintf(a, "\n.model small");
	fprintf(a, "\n.386");
	fprintf(a, "\n.stack 200h");
	fprintf(a, "\n");
	fprintf(a, "\n.data");
	fprintf(a, "\nmessage db	'-- EOF --', '$'");
	fprintf(a, "\noverflow db	'Overflow!', '$'");
	fprintf(a, "\ndiviz db	'Division by 0!', '$'");
	fprintf(a, "\nread db	'Ingrese valor por teclado...', '$'");
	fprintf(a, "\nMAX_STRING_LENGTH equ 30 ;Longitud maxima de los string.");
	fprintf(a, "\nMAX_STRING_INT equ 65535 ;Tama�o maximo de ints.");
	fprintf(a, "\naux1 dd ?");
	fprintf(a, "\naux2 dd ?");
	fprintf(a, "\ncont dd 0.000000");
	fprintf(a, "\nfilt dd 0.000000");
}

void crear_codigo_assembler(t_nodo_arbol *tree)
{
	fprintf(a, "\n");
	fprintf(a, "\n.code");
	fprintf(a, "\nmain:");
	fprintf(a, "\nmov AX,@DATA ;");
	fprintf(a, "\nmov DS,AX ;");
	fprintf(a, "\nfinit ;\n");
	recorrer_asm(tree, 0);
	
	if(strcmp(sent_final, "")!=0){
		fprintf(a, sent_final);
		strcpy(sent_final,"");
	}
	if(strcmp(asig_final, "")!=0){
		fprintf(a, asig_final);
		strcpy(asig_final,"");
	}	
	if(ifs>0 && ifs%10!=0){
		fprintf(a, "\nend_if");
		char buf[2];
		sprintf(buf, "%d", ifs);
		fprintf(a, buf);
		fprintf(a, ":");
		ifs--;
		if(ifs==0)
					ifs+=10;
	}
	if(whiles>0){
				recorrer_asm_2(nodo_asm_while, 0);
				fprintf(a, "\nend_while");
				char buf[2];
				sprintf(buf, "%d", whiles);
				fprintf(a, buf);
				fprintf(a, ":");
				whiles--;
			}

	if(strcmp(asig_iguales, "")!=0){
		fprintf(a, asig_iguales);
		strcpy(asig_iguales,"");
	}	
	fprintf(a, "\n\nmov AX, 4C00h");
	fprintf(a, "\nend main");
    
}

void recorrer_asm(t_nodo_arbol *n, int usar_aux2){
		
		if(n->nodo_izq != NULL)
			recorrer_asm(n->nodo_izq, usar_aux2);

		printf("\n%s", n->info->a);
		if(strcmp(n->info->a,":=")==0)		
		{	
			if(is_hoja(n->nodo_der)){
				fprintf(a, "\nfld ");
				fprintf(a, n->nodo_der->info->a);
				fprintf(a, "\nfstp ");
				fprintf(a, n->nodo_izq->info->a);
			} else if(!is_hoja(n->nodo_der)){
					strcpy(asig_final, "\nfld ");
					strcat(asig_final, "aux1");
					strcat(asig_final, "\nfstp ");
					strcat(asig_final, n->nodo_izq->info->a);
			} 
		} else if(strcmp(n->info->a,"+")==0)
		{
			if(is_hoja(n->nodo_izq) && is_hoja(n->nodo_der)){
				fprintf(a, "\nfld ");
				fprintf(a, n->nodo_der->info->a);
				fprintf(a, "\nfld ");
				fprintf(a, n->nodo_izq->info->a);
				fprintf(a, "\nfadd");
				fprintf(a, "\nfstp ");
				if(!usar_aux2)
				{
					fprintf(a, "aux1");
				} else{
					fprintf(a, "aux2");
				}				
			} else if(!is_hoja(n->nodo_izq) && is_hoja(n->nodo_der)){
				fprintf(a, "\nfld ");
				fprintf(a, n->nodo_der->info->a);
				fprintf(a, "\nfld ");
				fprintf(a, "aux1");
				fprintf(a, "\nfadd");
				fprintf(a, "\nfstp ");
				if(!usar_aux2)
				{
					fprintf(a, "aux1");
				} else{
					fprintf(a, "aux2");
				}	
			} else{
				strcpy(sent_final, "\nfld ");
				strcat(sent_final, "aux2");
				strcat(sent_final, "\nfld ");
				strcat(sent_final, "aux1");
				strcat(sent_final, "\nfadd ");
				strcat(sent_final, "\nfstp ");
				strcat(sent_final, "aux1");
				usar_aux2 = 1;
			}				
		} else if(strcmp(n->info->a,";")==0)
		{
			if(strcmp(sent_final, "")!=0){
				fprintf(a, sent_final);
				strcpy(sent_final,"");
			}
			if(strcmp(asig_final, "")!=0){
				fprintf(a, asig_final);
				strcpy(asig_final,"");		
			}		
			if(ifs>0 && strcmp(n->padre->info->a, "IF")!=0){
				fprintf(a, "\nend_if");
				char buf[2];
				sprintf(buf, "%d", ifs);
				fprintf(a, buf);
				fprintf(a, ":");
				ifs--;
				if(ifs==0)
					ifs+=10;
			}
			if(strcmp(asig_iguales, "")!=0 && strcmp(n->nodo_izq->info->a, "IF")!=0){
				fprintf(a, asig_iguales);
				strcpy(asig_iguales,"");
			}	
			if(whiles>0 && strcmp(n->padre->info->a, "WHILE")!=0){
				recorrer_asm_2(nodo_asm_while, 0);
				fprintf(a, "\nend_while");
				char buf[2];
				sprintf(buf, "%d", whiles);
				fprintf(a, buf);
				fprintf(a, ":");
				whiles--;
			}	
				
		} else if(strcmp(n->info->a,"-")==0)
		{
			if(is_hoja(n->nodo_izq) && is_hoja(n->nodo_der)){
				fprintf(a, "\nfld ");
				fprintf(a, n->nodo_der->info->a);
				fprintf(a, "\nfld ");
				fprintf(a, n->nodo_izq->info->a);
				fprintf(a, "\nfsub");
				fprintf(a, "\nfstp ");
				fprintf(a, "aux1");
			} else if(!is_hoja(n->nodo_izq) && is_hoja(n->nodo_der)){
				fprintf(a, "\nfld ");
				fprintf(a, n->nodo_der->info->a);
				fprintf(a, "\nfld ");
				fprintf(a, "aux1");
				fprintf(a, "\nfsub");
				fprintf(a, "\nfstp ");
				fprintf(a, "aux1");
			} else{
				strcpy(sent_final, "\nfld ");
				strcat(sent_final, "aux2");
				strcat(sent_final, "\nfld ");
				strcat(sent_final, "aux1");
				strcat(sent_final, "\nfsub ");
				strcat(sent_final, "\nfstp ");
				strcat(sent_final, "aux1");
				usar_aux2 = 1;
			}		
		} else if(strcmp(n->info->a,"*")==0)
		{
			if(is_hoja(n->nodo_izq) && is_hoja(n->nodo_der)){
				fprintf(a, "\nfld ");
				fprintf(a, n->nodo_der->info->a);
				fprintf(a, "\nfld ");
				fprintf(a, n->nodo_izq->info->a);
				fprintf(a, "\nfmul");
				fprintf(a, "\nfstp ");
				if(!usar_aux2)
				{
					fprintf(a, "aux1");
					fprintf(a, sent_final);
					strcpy(sent_final,"");
				} else{
					fprintf(a, "aux2");
				}
			} else if(!is_hoja(n->nodo_izq) && is_hoja(n->nodo_der)){
				fprintf(a, "\nfld ");
				fprintf(a, n->nodo_der->info->a);
				fprintf(a, "\nfld ");
				if(!usar_aux2){
					fprintf(a, "aux1");
				} else{
					fprintf(a, "aux2");
				}
				fprintf(a, "\nfmul");
				fprintf(a, "\nfstp ");
				if(!usar_aux2){
					fprintf(a, "aux1");
				} else{
					fprintf(a, "aux2");
				}
			}		
		} else if(strcmp(n->info->a,"/")==0)
		{
			if(is_hoja(n->nodo_izq) && is_hoja(n->nodo_der)){
				fprintf(a, "\nfld ");
				fprintf(a, n->nodo_der->info->a);
				fprintf(a, "\nfld ");
				fprintf(a, n->nodo_izq->info->a);
				fprintf(a, "\nfdiv");
				fprintf(a, "\nfstp ");
				if(!usar_aux2)
				{
					fprintf(a, "aux1");
					fprintf(a, sent_final);
					strcpy(sent_final,"");
				} else{
					fprintf(a, "aux2");
				}
			} else if(!is_hoja(n->nodo_izq) && is_hoja(n->nodo_der)){
				fprintf(a, "\nfld ");
				fprintf(a, n->nodo_der->info->a);
				fprintf(a, "\nfld ");
				if(!usar_aux2){
					fprintf(a, "aux1");
				} else{
					fprintf(a, "aux2");
				}
				fprintf(a, "\nfdiv");
				fprintf(a, "\nfstp ");
				if(!usar_aux2){
					fprintf(a, "aux1");
				} else{
					fprintf(a, "aux2");
				}
			}		
		} else if(strcmp(n->info->a,"==")==0)
		{
			usar_aux2=1;
			strcpy(string_cond, "\njne ");
			if(strcmp(n->padre->info->a, "WHILE")==0){
			} else if(is_hoja(n->nodo_izq) && is_hoja(n->nodo_der)){
				fprintf(a, "\nfld ");
				fprintf(a, n->nodo_izq->info->a);
				fprintf(a, "\nfstp aux1");
				fprintf(a, "\nfld ");
				fprintf(a, n->nodo_der->info->a);
				fprintf(a, "\nfstp aux2");
			}
		} else if(strcmp(n->info->a,"!=")==0)
		{
			usar_aux2=1;
			strcpy(string_cond, "\nje ");
			if(strcmp(n->padre->info->a, "WHILE")==0){
			} else if(is_hoja(n->nodo_izq) && is_hoja(n->nodo_der)){
				fprintf(a, "\nfld ");
				fprintf(a, n->nodo_izq->info->a);
				fprintf(a, "\nfstp aux1");
				fprintf(a, "\nfld ");
				fprintf(a, n->nodo_der->info->a);
				fprintf(a, "\nfstp aux2");
			}
		} else if(strcmp(n->info->a,">")==0)
		{
			usar_aux2=1;
			strcpy(string_cond, "\njle ");
			if(strcmp(n->padre->info->a, "WHILE")==0){
			} else if(is_hoja(n->nodo_izq) && is_hoja(n->nodo_der)){
				fprintf(a, "\nfld ");
				fprintf(a, n->nodo_izq->info->a);
				fprintf(a, "\nfstp aux1");
				fprintf(a, "\nfld ");
				fprintf(a, n->nodo_der->info->a);
				fprintf(a, "\nfstp aux2");
			}
		} else if(strcmp(n->info->a,">=")==0)
		{
			usar_aux2=1;
			strcpy(string_cond, "\njl ");
			if(strcmp(n->padre->info->a, "WHILE")==0){
			} else if(is_hoja(n->nodo_izq) && is_hoja(n->nodo_der)){
				fprintf(a, "\nfld ");
				fprintf(a, n->nodo_izq->info->a);
				fprintf(a, "\nfstp aux1");
				fprintf(a, "\nfld ");
				fprintf(a, n->nodo_der->info->a);
				fprintf(a, "\nfstp aux2");
			}
		} else if(strcmp(n->info->a,"<")==0)
		{
			usar_aux2=1;
			strcpy(string_cond, "\njge ");
			if(strcmp(n->padre->info->a, "WHILE")==0){
			} else if(is_hoja(n->nodo_izq) && is_hoja(n->nodo_der)){
				fprintf(a, "\nfld ");
				fprintf(a, n->nodo_izq->info->a);
				fprintf(a, "\nfstp aux1");
				fprintf(a, "\nfld ");
				fprintf(a, n->nodo_der->info->a);
				fprintf(a, "\nfstp aux2");
			}
		} else if(strcmp(n->info->a,"<=")==0)
		{
			usar_aux2=1;
			strcpy(string_cond, "\njg ");
			if(strcmp(n->padre->info->a, "WHILE")==0){
			} else if(is_hoja(n->nodo_izq) && is_hoja(n->nodo_der)){
				fprintf(a, "\nfld ");
				fprintf(a, n->nodo_izq->info->a);
				fprintf(a, "\nfstp aux1");
				fprintf(a, "\nfld ");
				fprintf(a, n->nodo_der->info->a);
				fprintf(a, "\nfstp aux2");
			}
		} else if(strcmp(n->info->a,"IF")==0)
		{
		    ifs++;
			if(strcmp(n->nodo_der->info->a, "<V.F>")!=0 || strcmp(n->nodo_der->info->a, "<-true . false->")==0){
				fprintf(a, "\nfld ");
				fprintf(a, "aux2");
				fprintf(a, "\nfld ");
				fprintf(a, "aux1");
				fprintf(a, "\nfcomp");
				fprintf(a, string_cond);
				fprintf(a, "end_if");
				char buf[2];
	 			sprintf(buf, "%d", ifs);
				fprintf(a, buf);
			} else{
				fprintf(a, "\nfld ");
				fprintf(a, "aux2");
				fprintf(a, "\nfld ");
				fprintf(a, "aux1");
				fprintf(a, "\nfcomp");
				fprintf(a, string_cond);
				fprintf(a, "else_if");
				char buf[2];
	 			sprintf(buf, "%d", ifs);
				fprintf(a, buf);
			}
			if(strcmp(n->nodo_izq->info->a, "==")==0 && strcmp(n->nodo_der->nodo_izq->info->a, "cont")==0){
					strcpy(asig_iguales, "\nfld ");
					strcat(asig_iguales, "cont");
					strcat(asig_iguales, "\nfstp ");
					strcat(asig_iguales, n->nodo_izq->nodo_izq->info->a);				
				}
		} else if(strcmp(n->info->a,"READ")==0 && strcmp(n->padre->info->a, "READ")!=0){ 
			fprintf(a, "\nmov dx, OFFSET read");
			fprintf(a, "\nmov ah, 9");
			fprintf(a, "\nint 21h");
		} else if(strcmp(n->info->a,"WRITE")==0 && strcmp(n->padre->info->a, "WRITE")!=0){
			fprintf(a, "\nDisplayInteger ");
			fprintf(a, n->nodo_izq->info->a);
		} else if(strcmp(n->info->a,"<V.F>")==0 || strcmp(n->info->a, "<-true . false->")==0){
				char buf[2];
	 			sprintf(buf, "%d", ifs);
				fprintf(a, "\njmp ");
				fprintf(a, "end_if");
				fprintf(a, buf);
				fprintf(a, "\nelse_if");
				fprintf(a, buf);
				fprintf(a, ":");
		} else if(strcmp(n->info->a,"WHILE")==0){
			nodo_asm_while = n;
			whiles++;
			fprintf(a, "\nfld ");
			fprintf(a, "aux2");
			fprintf(a, "\nfld ");
			fprintf(a, "aux1");
			fprintf(a, "\nfcomp");
			fprintf(a, string_cond);
			fprintf(a, "end_while");
			char buf[2];
	 		sprintf(buf, "%d", whiles);
			fprintf(a, buf);
			fprintf(a, "\nwhile");
			fprintf(a, buf);
			fprintf(a, ":");
		}
		
	if(n->nodo_der != NULL)
		recorrer_asm(n->nodo_der, usar_aux2);
}

void recorrer_asm_2(t_nodo_arbol *n, int usar_aux2){
		
		if(n->nodo_izq != NULL)
			recorrer_asm_2(n->nodo_izq, usar_aux2);

		printf("\n%s", n->info->a);
		if(strcmp(n->info->a,":=")==0)		
		{	
			if(is_hoja(n->nodo_der)){
				fprintf(a, "\nfld ");
				fprintf(a, n->nodo_der->info->a);
				fprintf(a, "\nfstp ");
				fprintf(a, n->nodo_izq->info->a);
			} else if(!is_hoja(n->nodo_der)){
				strcpy(asig_final, "\nfld ");
				strcat(asig_final, "aux1");
				strcat(asig_final, "\nfstp ");
				strcat(asig_final, n->nodo_izq->info->a);
			} 
		} else if(strcmp(n->info->a,"+")==0)
		{
			if(is_hoja(n->nodo_izq) && is_hoja(n->nodo_der)){
				fprintf(a, "\nfld ");
				fprintf(a, n->nodo_der->info->a);
				fprintf(a, "\nfld ");
				fprintf(a, n->nodo_izq->info->a);
				fprintf(a, "\nfadd");
				fprintf(a, "\nfstp ");
				if(!usar_aux2)
				{
					fprintf(a, "aux1");
				} else{
					fprintf(a, "aux2");
				}				
			} else if(!is_hoja(n->nodo_izq) && is_hoja(n->nodo_der)){
				fprintf(a, "\nfld ");
				fprintf(a, n->nodo_der->info->a);
				fprintf(a, "\nfld ");
				fprintf(a, "aux1");
				fprintf(a, "\nfadd");
				fprintf(a, "\nfstp ");
				if(!usar_aux2)
				{
					fprintf(a, "aux1");
				} else{
					fprintf(a, "aux2");
				}	
			} else{
				strcpy(sent_final, "\nfld ");
				strcat(sent_final, "aux2");
				strcat(sent_final, "\nfld ");
				strcat(sent_final, "aux1");
				strcat(sent_final, "\nfadd ");
				strcat(sent_final, "\nfstp ");
				strcat(sent_final, "aux1");
				usar_aux2 = 1;
			}				
		} else if(strcmp(n->info->a,";")==0)
		{
			if(strcmp(sent_final, "")!=0){
				fprintf(a, sent_final);
				strcpy(sent_final,"");
			}
			if(strcmp(asig_final, "")!=0){
				fprintf(a, asig_final);
				strcpy(asig_final,"");		
			}
			if(ifs>0 && strcmp(n->padre->info->a, "IF")!=0){
				fprintf(a, "\nend_if");
				char buf[2];
				sprintf(buf, "%d", ifs);
				fprintf(a, buf);
				fprintf(a, ":");
				ifs--;
				if(ifs==0)
					ifs+=10;
			}
			if(whiles>0 && strcmp(n->padre->info->a, "WHILE")!=0){
				fprintf(a, "\nend_while");
				char buf[2];
				sprintf(buf, "%d", whiles);
				fprintf(a, buf);
				fprintf(a, ":");
				whiles--;
			}			
		} else if(strcmp(n->info->a,"-")==0)
		{
			if(is_hoja(n->nodo_izq) && is_hoja(n->nodo_der)){
				fprintf(a, "\nfld ");
				fprintf(a, n->nodo_der->info->a);
				fprintf(a, "\nfld ");
				fprintf(a, n->nodo_izq->info->a);
				fprintf(a, "\nfsub");
				fprintf(a, "\nfstp ");
				fprintf(a, "aux1");
			} else if(!is_hoja(n->nodo_izq) && is_hoja(n->nodo_der)){
				fprintf(a, "\nfld ");
				fprintf(a, n->nodo_der->info->a);
				fprintf(a, "\nfld ");
				fprintf(a, "aux1");
				fprintf(a, "\nfsub");
				fprintf(a, "\nfstp ");
				fprintf(a, "aux1");
			} else{
				strcpy(sent_final, "\nfld ");
				strcat(sent_final, "aux2");
				strcat(sent_final, "\nfld ");
				strcat(sent_final, "aux1");
				strcat(sent_final, "\nfsub ");
				strcat(sent_final, "\nfstp ");
				strcat(sent_final, "aux1");
				usar_aux2 = 1;
			}		
		} else if(strcmp(n->info->a,"*")==0)
		{
			if(is_hoja(n->nodo_izq) && is_hoja(n->nodo_der)){
				fprintf(a, "\nfld ");
				fprintf(a, n->nodo_der->info->a);
				fprintf(a, "\nfld ");
				fprintf(a, n->nodo_izq->info->a);
				fprintf(a, "\nfmul");
				fprintf(a, "\nfstp ");
				if(!usar_aux2)
				{
					fprintf(a, "aux1");
					fprintf(a, sent_final);
					strcpy(sent_final,"");
				} else{
					fprintf(a, "aux2");
				}
			} else if(!is_hoja(n->nodo_izq) && is_hoja(n->nodo_der)){
				fprintf(a, "\nfld ");
				fprintf(a, n->nodo_der->info->a);
				fprintf(a, "\nfld ");
				if(!usar_aux2){
					fprintf(a, "aux1");
				} else{
					fprintf(a, "aux2");
				}
				fprintf(a, "\nfmul");
				fprintf(a, "\nfstp ");
				if(!usar_aux2){
					fprintf(a, "aux1");
				} else{
					fprintf(a, "aux2");
				}
			}		
		} else if(strcmp(n->info->a,"/")==0)
		{
			if(is_hoja(n->nodo_izq) && is_hoja(n->nodo_der)){
				fprintf(a, "\nfld ");
				fprintf(a, n->nodo_der->info->a);
				fprintf(a, "\nfld ");
				fprintf(a, n->nodo_izq->info->a);
				fprintf(a, "\nfdiv");
				fprintf(a, "\nfstp ");
				if(!usar_aux2)
				{
					fprintf(a, "aux1");
					fprintf(a, sent_final);
					strcpy(sent_final,"");
				} else{
					fprintf(a, "aux2");
				}
			} else if(!is_hoja(n->nodo_izq) && is_hoja(n->nodo_der)){
				fprintf(a, "\nfld ");
				fprintf(a, n->nodo_der->info->a);
				fprintf(a, "\nfld ");
				if(!usar_aux2){
					fprintf(a, "aux1");
				} else{
					fprintf(a, "aux2");
				}
				fprintf(a, "\nfdiv");
				fprintf(a, "\nfstp ");
				if(!usar_aux2){
					fprintf(a, "aux1");
				} else{
					fprintf(a, "aux2");
				}
			}		
		} else if(strcmp(n->info->a,"==")==0)
		{
			usar_aux2=1;
			strcpy(string_cond, "\nje ");
			if(strcmp(n->padre->info->a, "WHILE")==0){
			} else if(is_hoja(n->nodo_izq) && is_hoja(n->nodo_der)){
				fprintf(a, "\nfld ");
				fprintf(a, n->nodo_izq->info->a);
				fprintf(a, "\nfstp aux1");
				fprintf(a, "\nfld ");
				fprintf(a, n->nodo_der->info->a);
				fprintf(a, "\nfstp aux2");
			}
		} else if(strcmp(n->info->a,"!=")==0)
		{
			usar_aux2=1;
			strcpy(string_cond, "\njne ");
			if(strcmp(n->padre->info->a, "WHILE")==0){
			} else if(is_hoja(n->nodo_izq) && is_hoja(n->nodo_der)){
				fprintf(a, "\nfld ");
				fprintf(a, n->nodo_izq->info->a);
				fprintf(a, "\nfstp aux1");
				fprintf(a, "\nfld ");
				fprintf(a, n->nodo_der->info->a);
				fprintf(a, "\nfstp aux2");
			}
		} else if(strcmp(n->info->a,">")==0)
		{
			usar_aux2=1;
			strcpy(string_cond, "\njg ");
			if(strcmp(n->padre->info->a, "WHILE")==0){
			} else if(is_hoja(n->nodo_izq) && is_hoja(n->nodo_der)){
				fprintf(a, "\nfld ");
				fprintf(a, n->nodo_izq->info->a);
				fprintf(a, "\nfstp aux1");
				fprintf(a, "\nfld ");
				fprintf(a, n->nodo_der->info->a);
				fprintf(a, "\nfstp aux2");
			}
		} else if(strcmp(n->info->a,">=")==0)
		{
			usar_aux2=1;
			strcpy(string_cond, "\njge ");
			if(strcmp(n->padre->info->a, "WHILE")==0){
			} else if(is_hoja(n->nodo_izq) && is_hoja(n->nodo_der)){
				fprintf(a, "\nfld ");
				fprintf(a, n->nodo_izq->info->a);
				fprintf(a, "\nfstp aux1");
				fprintf(a, "\nfld ");
				fprintf(a, n->nodo_der->info->a);
				fprintf(a, "\nfstp aux2");
			}
		} else if(strcmp(n->info->a,"<")==0)
		{
			usar_aux2=1;
			strcpy(string_cond, "\njl ");
			if(strcmp(n->padre->info->a, "WHILE")==0){
			} else if(is_hoja(n->nodo_izq) && is_hoja(n->nodo_der)){
				fprintf(a, "\nfld ");
				fprintf(a, n->nodo_izq->info->a);
				fprintf(a, "\nfstp aux1");
				fprintf(a, "\nfld ");
				fprintf(a, n->nodo_der->info->a);
				fprintf(a, "\nfstp aux2");
			}
		}else if(strcmp(n->info->a,"<=")==0)
		{
			usar_aux2=1;
			strcpy(string_cond, "\njle ");
			if(strcmp(n->padre->info->a, "WHILE")==0){
			} else if(is_hoja(n->nodo_izq) && is_hoja(n->nodo_der)){
				fprintf(a, "\nfld ");
				fprintf(a, n->nodo_izq->info->a);
				fprintf(a, "\nfstp aux1");
				fprintf(a, "\nfld ");
				fprintf(a, n->nodo_der->info->a);
				fprintf(a, "\nfstp aux2");
			}
		} else if(strcmp(n->info->a,"IF")==0)
		{
		    ifs++;
			if(strcmp(n->nodo_der->info->a, "<V.F>")!=0){
				fprintf(a, "\nfld ");
				fprintf(a, "aux2");
				fprintf(a, "\nfld ");
				fprintf(a, "aux1");
				fprintf(a, "\nfcomp");
				fprintf(a, string_cond);
				fprintf(a, "end_if");
				char buf[2];
	 			sprintf(buf, "%d", ifs);
				fprintf(a, buf);
			} else{
				fprintf(a, "\nfld ");
				fprintf(a, "aux2");
				fprintf(a, "\nfld ");
				fprintf(a, "aux1");
				fprintf(a, "\nfcomp");
				fprintf(a, string_cond);
				fprintf(a, "else_if");
				char buf[2];
	 			sprintf(buf, "%d", ifs);
				fprintf(a, buf);
			}
		} else if(strcmp(n->info->a,"<V.F>")==0){
				char buf[2];
	 			sprintf(buf, "%d", ifs);
				fprintf(a, "\njmp ");
				fprintf(a, "end_if");
				fprintf(a, buf);
				fprintf(a, "\nelse_if");
				fprintf(a, buf);
				fprintf(a, ":");
		} else if(strcmp(n->info->a,"WHILE")==0){
			fprintf(a, "\nfld ");
			fprintf(a, "aux2");
			fprintf(a, "\nfld ");
			fprintf(a, "aux1");
			fprintf(a, "\nfcomp");
			fprintf(a, string_cond);
			fprintf(a, "while");
			char buf[2];
	 		sprintf(buf, "%d", whiles);
			fprintf(a, buf);
		}
		
	if(n->nodo_der != NULL && strcmp(n->info->a, "WHILE")!=0)
		recorrer_asm_2(n->nodo_der, usar_aux2);
}

int is_hoja(t_nodo_arbol *n)
{
	if(n->nodo_izq != NULL || n->nodo_der != NULL)
		return 0;
		
	return 1;
}

char *newStr (char *charBuffer) {
  int length = strlen(charBuffer);
  char *str;
  if (length <= 1) {
    str = (char *) malloc(1);
    str[0] = '\0';
  } else {
    str = (char *) malloc(length);
    strcpy(str, &charBuffer[1]);
  }
  return str;
}
