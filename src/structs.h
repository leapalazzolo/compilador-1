#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct
{
 char * nombre;
 int tipo;
 char * valor_string;
 int valor_int;
 float valor_float;
 int esConstante;
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
	// t_cola * cola;
	// int a;
} t_info_sentencias;

typedef struct  t_nodo{
	t_info_sentencias * info;
	struct t_nodo * sig_nodo;
} t_nodo;

typedef struct {
	t_nodo * p_nodo;
} t_pila;

typedef struct {
	t_nodo * p_primero;
	t_nodo * p_ultimo;
} t_cola;

typedef struct  t_nodo_asm{
	char * data;
	struct t_nodo_asm * sig_nodo;
} t_nodo_asm;

typedef struct {
	t_nodo_asm * p_nodo_asm;
} t_pila_asm;

typedef struct  t_nodo_pila_de_colas{
	t_cola * info;
	struct t_nodo_pila_de_colas * sig_nodo;
} t_nodo_pila_de_colas;

typedef struct {
	t_nodo_pila_de_colas * p_nodo;
} t_pila_de_colas;

#define TIPO_FLOAT 1
#define TIPO_INT 2
#define TIPO_STRING 3
#define TIPO_PR 4

#endif
