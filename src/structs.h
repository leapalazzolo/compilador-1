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


typedef struct {
	char a[20];
} t_info;

typedef struct  t_nodo_arbol{
	t_info * info;
	struct t_nodo_arbol * padre;
	struct t_nodo_arbol * nodo_der;
	struct t_nodo_arbol * nodo_izq;
} t_nodo_arbol;

typedef struct {
	t_nodo_arbol * p_nodo;
} t_arbol;




typedef struct {
	t_nodo_arbol * a;
} t_info_sentencias;

typedef struct  t_nodo{
	t_info_sentencias * info;
	struct t_nodo * sig_nodo;
} t_nodo;

typedef struct {
	t_nodo * p_nodo;
} t_pila;



#define TIPO_FLOAT 1
#define TIPO_INT 2
#define TIPO_STRING 3
#define TIPO_PR 4

#endif
