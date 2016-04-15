%{
#include <stdio.h>
#include <stdlib.h>
%}

%%

ID	{ID}+{LETRA}|{ID}+{DIGITO}|{LETRA}+
LETRA	[a-zA-Z]+
CAR_ESPECIAL	[¿,?,¡,!]+
OPMULTI	[*]+
OP_ESP_MUL	[*=]+
OPDIV	[/]+
OP_ESP_DIV	[/=]+
OPMAS	[+]+
OP_ESP_MAS	[+=]+
OPMENOS	[-]+
OP_ESP_MEN	[-=]+
MAYOR	[>]+
MENOR	[<]+
MAYOR_IGUAL	[>=]+
MENOR_IGUAL	[<=]+
ASIGNA [=]+
IGUAL	[==]+
DISTINTO	[!=]+
NEGADO	[!]+
OP_AND	[&&]+
OP_OR	[||]+
P_ABRE	[(]+
P_CIERRA	[)]+
COR_ABRE	[[]+
COR_CIERRA	[]]+
COMA	[,]+
PUNTO_COMA	[;]+
PUNTO	[.]+
CONST_FLOAT	{DIGITO2}+{PUNTO}+{DIGITO2}|{PUNTO}+{DIGITO2}+
CONST_ENT	{DIGITO2}+
DIGITO2	{DIGITO2}+{DIGITO}|{DIGITO}+
DIGITO	[0-9]+
COMILLA	[“]+
CONST_STR	{COMILLA}+{CONST_STR2}+{COMILLA}+
CONST_STR2	{CONST_STR2}+{CAR_TODO}|{CAR_TODO}+
CAR_TODO	{DIGITO}|{LETRA}|{CAR_ESPECIAL}+
LL_ABRE [{]+
LL_CIERRA [}]

%%

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