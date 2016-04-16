#ifndef PILA_H
#define PILA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int a;
} t_info;

typedef struct  t_nodo_arbol{
	t_info * info;
	struct t_nodo_arbol * nodo_der;
	struct t_nodo_arbol * nodo_izq;
} t_nodo_arbol;

typedef struct {
	t_nodo_arbol * p_nodo;
} t_arbol;

// typedef t_func ;

void crear_arbol(t_arbol **);
t_nodo_arbol * crear_nodo_arbol(t_info*);
void insertar_hijo_izquierdo(t_nodo_arbol * p_nodo, t_info * info);
void insertar_hijo_derecho(t_nodo_arbol * p_nodo, t_info * info);
void visitar(t_nodo_arbol *);
void recorrer_en_preorden(t_nodo_arbol * p_nodo,void (*f)(t_nodo_arbol*));
void recorrer_en_orden(t_nodo_arbol * p_nodo,void (*f)(t_nodo_arbol*));
void recorrer_en_postorden(t_nodo_arbol * p_nodo,void (*f)(t_nodo_arbol*));
void borrar_nodo_arbol(t_nodo_arbol *);
void vaciar_arbol(t_arbol**);
// t_info * sacar_de_pila(t_pila **);
// t_info * frente_de_pila(t_pila **);
// void vaciar_pila();
// void delete_pila();
// int pila_vacia();

#endif
