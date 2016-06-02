#include "pila.h"

// void main() {

// 	t_info_sentencias a[10000];

// 	int i;

// 	t_pila * pila;
// 	crear_pila(&pila);
// 	for(i=0;i < 10000; i++) {
// 		a[i].a = i;
// 		insertar_en_pila(&pila,&a[i]);
// 	}
	
// 		printf("%d \n",frente_de_pila(&pila)->a);
// vaciar_pila(&pila);
// 	puts("pila vaciada");
// printf("pila vacia: %d\n",pila_vacia(&pila) );

// 	puts("pila sacada");
// 	// for(i=0;i < 10000; i++) {

// 	// 	printf("%d \n",sacar_de_pila(&pila)->a);
// 	// }


// }


void crear_pila(t_pila ** p_pila) {
	*p_pila = NULL;
}

void insertar_en_pila(t_pila ** p_pila, t_info_sentencias * p_info) {

	t_nodo * nodo = (t_nodo*)malloc(sizeof(t_nodo**));

	if(*p_pila == NULL) {
		*p_pila = (t_pila*) malloc(sizeof(t_pila**));
	 	(*p_pila)->p_nodo = NULL;
	} 
 	nodo->sig_nodo = (*p_pila)->p_nodo;
 	(*p_pila)->p_nodo = nodo;
	 

	nodo->info = p_info;

}

t_info_sentencias * sacar_de_pila(t_pila** p_pila) {
	if(*p_pila == NULL) return NULL;
	t_nodo * nodo_a_eliminar = (*p_pila)->p_nodo;
	t_info_sentencias * ret_info = (*p_pila)->p_nodo->info;
	(*p_pila)->p_nodo = (*p_pila)->p_nodo->sig_nodo;

	if((*p_pila)->p_nodo == NULL) {
		free(*p_pila);
		*p_pila = NULL;
	}

	if(nodo_a_eliminar != NULL)
		free(nodo_a_eliminar);

	return ret_info;
}


void vaciar_pila(t_pila ** p_pila) {
	while(pila_vacia(p_pila) == 0){
		sacar_de_pila(p_pila);
	}
}

int pila_vacia(t_pila ** p_pila) {
	return (*p_pila) == NULL;
}


t_info_sentencias * frente_de_pila(t_pila** p_pila) {
	if(*p_pila == NULL) return NULL;
	return (*p_pila)->p_nodo->info;
}

void insertar_en_pila_asm(t_pila_asm ** p_pila_asm, char * data) {

	t_nodo_asm * nodo_asm = (t_nodo_asm*)malloc(sizeof(t_nodo_asm**));

	if(*p_pila_asm == NULL) {
		*p_pila_asm = (t_pila_asm*) malloc(sizeof(t_pila_asm**));
	 	(*p_pila_asm)->p_nodo_asm = NULL;
	}
 	nodo_asm->sig_nodo = (*p_pila_asm)->p_nodo_asm;
 	(*p_pila_asm)->p_nodo_asm = nodo_asm;


	nodo_asm->data = data;

}

char * sacar_de_pila_asm(t_pila_asm** p_pila_asm) {
	if(*p_pila_asm == NULL) return NULL;
	t_nodo_asm * nodo_a_eliminar = (*p_pila_asm)->p_nodo_asm;
	char * data = (*p_pila_asm)->p_nodo_asm->data;
	(*p_pila_asm)->p_nodo_asm = (*p_pila_asm)->p_nodo_asm->sig_nodo;

	if((*p_pila_asm)->p_nodo_asm == NULL) {
		free(*p_pila_asm);
		*p_pila_asm = NULL;
	}

	if(nodo_a_eliminar != NULL)
		free(nodo_a_eliminar);

	return data;
}

int pila_vacia_asm(t_pila_asm ** p_pila_asm) {
	return (*p_pila_asm) == NULL;
}

char * frente_de_pila_asm(t_pila_asm** p_pila_asm) {
	if(*p_pila_asm == NULL) return NULL;
	return (*p_pila_asm)->p_nodo_asm->data;
}

