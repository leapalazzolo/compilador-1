#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct
{
 char * nombre;
 int tipo;
 char * valor_string;
 int valor_int;
 float valor_float;
 int longitud;
 char *alias;
 int lineNumber;
} t_simbolo;

#define TIPO_FLOAT 1
#define TIPO_INT 2
#define TIPO_STRING 3
#define TIPO_PR 4

#endif
