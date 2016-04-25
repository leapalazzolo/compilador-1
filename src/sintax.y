%{
#include <stdio.h>
#include <stdlib.h>
#include "y.tab.h"
#include "structs.h"
// #include "defines.h"

FILE  *yyin; //Archivo de Entrada
%}

/* PARA OBTENER LOS VALORES Y PASAR A TS*/
%union {
int intval;
double val;
char *str_val;
}

%token <str_val>TOKEN_ID
%token <int>CONST_INT
%token <str_val>CONST_STR
%token <double>CONST_FLOAT

%token PR_MAIN
%token PR_DIM
%token PR_ENDIM
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
%token PR_BEGIN
%token PR_END
%token PAR_ABRE
%token PAR_CIERRA
%token COR_ABRE
%token COR_CIERRA
%token COMA
%token OP_LOG_AND
%token OP_LOG_OR
%token OP_LOG_NOT
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
%token OP_AS
%token OP_DIM
%token PR_FLOAT
%token PR_INT
%token PR_STRING
%%

pgm : programa 
{
	puts("COMPILACION EXITOSA\n");
	puts("-------------------\n");
};

programa : /*PR_MAIN*/ PR_DIM declaracion_variables PR_ENDIM lista_sentencias
{
	puts("Código con variables\n");
	puts("-------------------\n");
};

programa : PR_MAIN lista_sentencias
{
	puts("Código sin variables\n");
	puts("-------------------\n");
};

programa : sentencia lista_sentencias
{
	puts("Varias sentencias\n");
	puts("-------------------\n");
};

programa : sentencia
{
	puts("Última sentencia\n");
	puts("-------------------\n");
};

lista_sentencias : sentencia
{
	puts("Una sola sentencia\n");
	puts("-------------------\n");
};

lista_sentencias : sentencia lista_sentencias
{
	puts("Varias sentencias\n");
	puts("-------------------\n");
};

sentencia : condicional 
{
	puts("Condicional\n");
	puts("-------------------\n");
};

sentencia : asignacion
{
	puts("Asignación\n");
	puts("-------------------\n");
};

sentencia : iteracion
{
	puts("Iteración\n");
	puts("-------------------\n");
};

sentencia : io
{
	puts("Operación de entrada salidas\n");
	puts("-------------------\n");
};

sentencia : iguales
{
	puts("Operación de iguales\n");
	puts("-------------------\n");
}

sentencia : filter
{
	puts("Operación de filters\n");
	puts("-------------------\n");
}

iguales : PR_IGUALES PAR_ABRE expresion COMA COR_ABRE lista_expresiones COR_CIERRA PAR_CIERRA
{
	puts("iguales : PR_IGUALES PAR_ABRE expresion COMA COR_ABRElista_expresiones COR_CIERRA PAR_CIERRA\n");
	puts("-------------------\n");
}

lista_expresiones : expresion COMA lista_expresiones
{
	puts("Lista de expresiones\n");
	puts("-------------------\n");
}

lista_expresiones : expresion
{
	puts("Última expresión\n");
	puts("-------------------\n");
}

filter : PR_FILTER PAR_ABRE condicion COMA COR_ABRE lista_variables COR_CIERRA PAR_CIERRA
{
	puts("filter : PR_FILTER PAR_ABRE condicion COMA COR_ABRE lista_variables COR_CIERRA PAR_CIERRA\n");
	puts("-------------------\n");
}

lista_variables : TOKEN_ID COMA lista_variables
{
	puts("Lista de variables\n");
	puts("-------------------\n");
}

lista_variables : TOKEN_ID
{
	puts("Última variable\n");
	puts("-------------------\n");
}

io : entrada
{
	puts("io : entrada\n");
	puts("-------------------\n");
}

io : salida
{
	puts("io : salida\n");
	puts("-------------------\n");
}

entrada : PR_READ TOKEN_ID
{
	puts("entrada : READ id\n");
	puts("-------------------\n");
}

salida : PR_WRITE TOKEN_ID
{
	puts("salida : PR_WRITE id\n");
	puts("-------------------\n");
}

salida : PR_WRITE CONST_STR
{
	puts("salida : PR_WRITE cte\n");
	puts("-------------------\n");
}

condicional : PR_IF condicion PR_THEN lista_sentencias PR_ENDIF
{
	puts("Condicional sin ELSE\n");
	puts("-------------------\n");
}

condicional : PR_IF condicion PR_THEN lista_sentencias PR_ELSE lista_sentencias PR_ENDIF
{
	puts("Condicional con ELSE\n");
	puts("-------------------\n");
}

condicion : comparacion
{
	puts("condicion : comparacion\n");
	puts("-------------------\n");
}

condicion : comparacion OP_LOG_AND comparacion
{
	puts("condicion : comparacion and comparacion\n");
	puts("-------------------\n");
}

condicion : comparacion OP_LOG_OR comparacion
{
	puts("condicion : comparacion or comparacion\n");
	puts("-------------------\n");
}

comparacion : expresion comparador expresion
{
	puts("comparacion : expresion comparador expresion\n");
	puts("-------------------\n");
}

comparacion : PR_NOT expresion
{
	puts("comparacion : PR_NOT expresion\n");
	puts("-------------------\n");
}

iteracion : PR_WHILE condicion PR_BEGIN lista_sentencias PR_END
{
	puts("Iteración\n");
	puts("-------------------\n");
}

asignacion : TOKEN_ID OP_IGUAL expresion
{
	puts("Asignación\n");
	puts("-------------------\n");
}

expresion : termino
{
	puts("Asignación\n");
	puts("-------------------\n");
}

expresion : expresion OP_SUMA termino 
{
	puts("Suma\n");
	puts("-------------------\n");
} 

expresion : expresion OP_RESTA termino
{
	puts("Resta\n");
	puts("-------------------\n");
}

termino : factor
{
	puts("termino : factor\n");
	puts("-------------------\n");
}

termino : termino OP_DIV factor
{
	puts("División\n");
	puts("-------------------\n");
}

termino : termino OP_MUL factor
{
	puts("Multiplicación\n");
	puts("-------------------\n");
}

factor : CONST_STR
{
	puts("factor : cte\n");
	puts("-------------------\n");
}

factor : CONST_INT
{
	puts("factor : cte\n");
	puts("-------------------\n");
}

factor : CONST_FLOAT
{
	puts("factor : cte\n");
	puts("-------------------\n");
}

factor : TOKEN_ID
{
	puts("factor : TOKEN_ID\n");
	puts("-------------------\n");
} 
     
// factor : expresion
// {
// 	puts("factor : expresion\n");
// 	puts("-------------------\n");
// }         

declaracion_variables : OP_DIM COR_ABRE lista_variables_tipos COR_CIERRA
{
	puts("Declaración de variables\n");
	puts("-------------------\n");
}   

lista_variables_tipos : TOKEN_ID COR_CIERRA OP_AS COR_ABRE tipo_dato 
{
	puts("Lista de variables\n");
	puts("-------------------\n");
}

lista_variables_tipos : TOKEN_ID COMA lista_variables_tipos COMA tipo_dato
{
	puts("Lista de variables\n");
	puts("-------------------\n");
}

// variables : TOKEN_ID COMA variables
// {
// 	puts("variables : TOKEN_ID COMA variables\n");
// 	puts("-------------------\n");
// }


// variables : TOKEN_ID
// {
// 	puts("variables : TOKEN_ID\n");
// 	puts("-------------------\n");
// }


tipo_dato : PR_INT
{
	puts("PR_INT\n");
	puts("-------------------\n");
}   

tipo_dato : PR_FLOAT
{
	puts("PR_FLOAT\n");
	puts("-------------------\n");
}            

tipo_dato : PR_STRING
{
	puts("PR_STRING\n");
	puts("-------------------\n");
} 

comparador : OP_MAYOR
{
	puts("OP_MAYOR\n");
	puts("-------------------\n");
}   

comparador : OP_MENOR
{
	puts("OP_MENOR\n");
	puts("-------------------\n");
}   

comparador : OP_MENOR_IGUAL
{
	puts("OP_MENOR_IGUAL\n");
	puts("-------------------\n");
}      

comparador : OP_MAYOR_IGUAL
{
	puts("OP_MAYOR_IGUAL\n");
	puts("-------------------\n");
}    

comparador : OP_IGUAL_IGUAL
{
	puts("OP_IGUAL_IGUAL\n");
	puts("-------------------\n");
}

comparador : OP_DISTINTO
{
	puts("OP_DISTINTO\n");
	puts("-------------------\n");
}     

%%


extern t_simbolo tabla_simbolos[2000];

extern int cantidad_simbolos;
void imprimir_tabla_simbolos();
void vaciar_tabla_simbolos();
char * tipo_simbolo_to_string(int tipo);


//función para realizar todo lo que haga falta previo a terminar
void finally(FILE *yyin){
	fclose(yyin);
	vaciar_tabla_simbolos();
}



int main(int argc, char **argv ) {
	// puts("Corriendo el compilador...");

	++argv, --argc; 

	if ( argc > 0 ) {
	     yyin = fopen( argv[0], "r" );
     }	else {
	     yyin = stdin;

     }

     int algo;
     while(algo = yylex()) {
		// printf("%d ", algo);
     }

     // yylex();
     // yylex();

     printf("\ncantidad Simbolos: %d\n", cantidad_simbolos);
     // int i = 0;
     // for(i = 0 ; i < cantidad_simbolos ; i++) {
     // 	puts(tabla_simbolos[i].nombre);
     // }
     imprimir_tabla_simbolos();	
// yyparse();


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
	printf("NOMBRE \t\t TIPO \t\t VALOR\n\n");
	for (i = 0; i < cantidad_simbolos; ++i)
	{
		if(tabla_simbolos[i].tipo == TIPO_STRING)
			printf("%s\t\t%s\t\t%s \n",tabla_simbolos[i].nombre,tipo_simbolo_to_string(tabla_simbolos[i].tipo),tabla_simbolos[i].valor_string == NULL ? "" : tabla_simbolos[i].valor_string);
	
		if(tabla_simbolos[i].tipo == TIPO_INT)
			printf("%s\t\t%s\t\t%d\n",tabla_simbolos[i].nombre,tipo_simbolo_to_string(tabla_simbolos[i].tipo),tabla_simbolos[i].valor_int);
		
		if(tabla_simbolos[i].tipo == TIPO_FLOAT)
			printf("%s\t\t%s\t\t%f\n",tabla_simbolos[i].nombre,tipo_simbolo_to_string(tabla_simbolos[i].tipo),tabla_simbolos[i].valor_float);

		if(tabla_simbolos[i].tipo == TIPO_PR)
			printf("%s\t\t%s\t\t\n",tabla_simbolos[i].nombre,tipo_simbolo_to_string(tabla_simbolos[i].tipo));
				

	}
}


