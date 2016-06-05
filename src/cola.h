#ifndef COLA_H
#define COLA_H
#include <stdio.h>
#include <stdlib.h>
#include "structs.h"

void crear_cola(t_cola **);
void insertar_en_cola(t_cola**,t_info_sentencias*);
t_info_sentencias * sacar_de_cola(t_cola **);
t_info_sentencias * frente_de_cola(t_cola **);
void vaciar_cola();
void delete_cola();
int pila_cola();

#endif
