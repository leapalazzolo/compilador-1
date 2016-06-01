#include "pila_asm.h"

typedef struct {
  size_t size;
  char **data;
} loods1;

loods1 *init(void) {
  loods1 *loods = malloc(sizeof(loods1));
  loods->data = malloc(sizeof(char *) * 20);
  for (int i = 0; i < 20; i++) {
    *(loods->data + i) = malloc(50 * sizeof(char));
  }
  loods->size = 0;
  if (loods == NULL) {
    perror("malloc failed\n");
    return NULL;
  }
  return loods;
}

int empty(loods1 *loods) {
  return (loods->size == 0);
}
void push(loods1 *loods, char *name) {
  if (loods->size == 20) {
    perror("Stack is full\n");
    exit(0);
  }
  else {
    *((loods->data) + loods->size++) = name;
  }
}
char *pop(loods1 *loods) {
  if (loods->size == 0) {
    printf("size == 0\n");
    return NULL;
  }
  else {
    printf("%s \n", *(loods->data + 1));
    return *(loods->data + (--loods->size));
  }
}
int delete(loods1 *loods) {
  for (int i = 0; i < 20; i++) {
    free(*(loods->data + i));
  }
  free(loods->data);
  free(loods);
}
