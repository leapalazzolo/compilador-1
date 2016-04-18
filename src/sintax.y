%{
#include <stdio.h>
#include <stdlib.h>
#include "y.tab.h"
#include "lex.yy.h"

FILE  *yyin; //Archivo de Entrada

%}
%token <str_val>TOKEN_ID
%%

factor: TOKEN_ID			
{
 printf ("Factor = ID\n");                        
};

%%

