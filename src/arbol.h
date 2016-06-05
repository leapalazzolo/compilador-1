#ifndef ARBOL_H
#define ARBOL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "structs.h"





// typedef t_func ;

void unir_nodo_arbol(t_nodo_arbol * padre,  t_nodo_arbol * p_nodo_izq, t_nodo_arbol * p_nodo_der);
void crear_arbol(t_arbol **);
t_nodo_arbol * crear_nodo_arbol(t_info * info, t_nodo_arbol * p_nodo_izq, t_nodo_arbol * p_nodo_der);
t_nodo_arbol * crear_hoja(t_info*);
void insertar_hijo_izquierdo(t_nodo_arbol * p_nodo, t_info * info);
void insertar_hijo_derecho(t_nodo_arbol * p_nodo, t_info * info);
void visitar(t_nodo_arbol *);
void recorrer_en_preorden(t_nodo_arbol * p_nodo,void (*f)(t_nodo_arbol*));
void recorrer_en_orden(t_nodo_arbol * p_nodo,void (*f)(t_nodo_arbol*));
void recorrer_en_postorden(t_nodo_arbol * p_nodo,void (*f)(t_nodo_arbol*));
void borrar_nodo_arbol(t_nodo_arbol *);
void vaciar_arbol(t_arbol**);
t_nodo_arbol * obtener_raiz(t_nodo_arbol * p_nodo);
t_nodo_arbol * buscar_etiqueta(t_nodo_arbol * ,t_info *);
t_nodo_arbol * buscar_etiqueta_comparador(t_nodo_arbol * ,t_info *,int (*f)(t_nodo_arbol*,t_nodo_arbol*));
int comparar_etiquetas(t_info *,t_info *);
int comparar_nodos(t_nodo_arbol *,t_nodo_arbol *);
t_nodo_arbol * clonar_arbol(t_nodo_arbol *);
t_info * copiar_etiqueta(t_info*);
void refactorizar_nodo(t_nodo_arbol **);
// t_info * sacar_de_pila(t_pila **);
// t_info * frente_de_pila(t_pila **);
// void vaciar_pila();
// void delete_pila();
// int pila_vacia();

#endif
