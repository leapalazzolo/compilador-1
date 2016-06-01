#ifndef PILA_H
#define PILA_H
#include <stdio.h>
#include <stdlib.h>
#include "structs.h"

void crear_pila(t_pila **);
void insertar_en_pila(t_pila**,t_info_sentencias*);
t_info_sentencias * sacar_de_pila(t_pila **);
t_info_sentencias * frente_de_pila(t_pila **);
void vaciar_pila();
void delete_pila();
int pila_vacia();

void insertar_en_pila_asm(t_pila_asm ** p_pila_asm, char * data);
char * sacar_de_pila_asm(t_pila_asm** p_pila_asm);
int pila_vacia_asm(t_pila_asm ** p_pila_asm);


#endif
