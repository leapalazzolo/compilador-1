%{
#include <stdio.h>
#include <stdlib.h>
#include "y.tab.h"

FILE  *yyin; //Archivo de Entrada
%}

/* PARA OBTENER LOS VALORES Y PASAR A TS*/
%union {
int intval;
double val;
char *str_val;
}

%token <int>TOKEN_ID
%%

factor: TOKEN_ID			
{                    
};
%%

//función para realizar todo lo que haga falta previo a terminar
void finally(FILE *yyin){
	fclose(yyin);
}

int main(int argc, char **argv ) {
	puts("Corriendo el compilador...");

	++argv, --argc; 


	if ( argc > 0 ) {
	     puts("true");
	     yyin = fopen( argv[0], "r" );
     }	else {
	     puts("false");
	     yyin = stdin;

     }


     int algo;
     while(algo = yylex()) {
		printf("%d ", algo);
     }


	finally(yyin);
	return EXIT_SUCCESS;
}

int yyerror(void)
{
	printf("Syntax Error\n");
	system ("Pause");
	exit (1);
}

