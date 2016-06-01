#ifndef PILA_ASM_H
#define PILA_ASM_H

#include <stdlib.h>
#include <string.h>

struct stack_t *newStack(void);
char *copyString(char *str);
void push(struct stack_t *theStack, char *value);
char *top(struct stack_t *theStack);
void pop(struct stack_t *theStack);
void clear (struct stack_t *theStack);
void destroyStack(struct stack_t **theStack);

#endif
