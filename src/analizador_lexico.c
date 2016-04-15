	int linecount = 1;


DIGITO    [0-9]
ID       [a-zA-Z]([a-zA-Z]|[0-9]|_|-)*
CADENA      .
COMENTARIO      .

%%


{DIGITO}+    {
         printf( "An integer: %s (%d)\n", yytext,
                 atoi( yytext ) );
         }

{DIGITO}+"."{DIGITO}*|"."{DIGITO}+     printf( "A float: %s (%g)\n", yytext,atof( yytext ) );

if|else|while|DIM|AS|DEFINE|WRITE|READ|ENDIF|BEGIN|END        printf( "A keyword: %s\n", yytext );

"+"|"-"|"*"|"/"|":="|"++"   printf( "An operator: %s\n", yytext );

"=="|">"|">="|"<"|"<="|"NOT"|"!="|"AND"|"OR"   printf( "A comparator: %s\n", yytext );

char|int|float        printf( "A type: %s\n", yytext );

         
;	printf("semicolon \n")		;
"[" printf("abro corchete \n");
"]" printf ("cierra corchete \n");
"("	printf("abre parentesis \n");
")"	printf("cierro parentesis \n");
, printf("coma \n");

[ /t] 


{ID}        printf( "An identifier: %s\n", yytext );



"{"[\^{}}\n]*"}"     /* eat up one-line comments */

"\""{CADENA}*"\""  printf ("cadena \n");

"-/"{COMENTARIO}*"/-"  printf ("comentario \n");

"//"({COMENTARIO})* printf("comentario \n");

.           printf( "Unrecognized character: %s in line %d \n", yytext , linecount);

\n	++linecount;

%%

int yywrap()
{
}


 
int main( int argc, char **argv )
{
yylex();

	printf("linecount %d", linecount);
++argv, --argc; 
if ( argc > 0 )
     yyin = fopen( argv[0], "r" );
else
     yyin = stdin;
	    //  {
     // yylex();
     // printf( "# of lines = %d\n",
     //         linecount  );
     // }

}
