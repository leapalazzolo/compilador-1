#ifndef PILA_H
#define PILA_H
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int a;
} t_info;

typedef struct  t_nodo{
	t_info * info;
	struct t_nodo * sig_nodo;
} t_nodo;

typedef struct {
	t_nodo * p_nodo;
} t_pila;


void crear_pila(t_pila **);
void insertar_en_pila(t_pila**,t_info*);
t_info * sacar_de_pila(t_pila **);
t_info * frente_de_pila(t_pila **);
void vaciar_pila();
void delete_pila();
int pila_vacia();


#endif