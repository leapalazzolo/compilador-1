#include <stdio.h>
#include <stdlib.h>
#include "lex.yy.c"

//función para realizar todo lo que haga falta previo a terminar
void finally(FILE *yyin);

int main(int argc, char **argv ) {
	puts("Corriendo el compilador...");

	FILE *yyin;
	if ( argc > 0 ){
		if ((yyin = fopen(argv[0], "r")) == NULL)
		{
			printf("\nNo se puede abrir el archivo: %s\n", argv[1]);
			return -1;
		}
	} else{
		puts("\nNo especificó el archivo como parámetro\n");
		return -1;
	}

	yylex();

	finally(yyin);
	return EXIT_SUCCESS;
}

void finally(FILE *codigo){
	fclose(codigo);
}
