/*
 * pila_asm.h
 *
 *  Created on: 1 de jun. de 2016
 *      Author: Igno
 */

#ifndef PILA_ASM_H_
#define PILA_ASM_H_

#include <stdio.h>
#include <stdlib.h>

loods1 *init(void);
int empty(loods1 *loods) ;
void push(loods1 *loods, char *name);
char *pop(loods1 *loods);
int delete(loods1 *loods);

#endif /* PILA_ASM_H_ */
