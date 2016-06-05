#include "cola.h"


// void main() {

// 	t_info_sentencias a[10000];

// 	int i;

// 	t_cola * cola;
// 	crear_cola(&cola);
// 	for(i=0;i < 10000; i++) {
// 		a[i].a = i;
// 		insertar_en_cola(&cola,&a[i]);
// 	}
// 		printf("%d \n",frente_de_cola(&cola)->a);
// 		printf("%d \n",cola->p_primero->sig_nodo->info->a);

// 	puts("a");
// 	while(!cola_vacia(&cola))
// 	{
// 		printf("%d\n",sacar_de_cola(&cola)->a );
// 	}
// 	puts("b");
	
// vaciar_cola(&cola);
// 	puts("cola vaciada");
// printf("cola vacia: %d\n",cola_vacia(&cola) );

// 	puts("cola sacada");
// 	// for(i=0;i < 10000; i++) {

// 	// 	printf("%d \n",sacar_de_cola(&cola)->a);
// 	// }


// }


void crear_cola(t_cola ** p_cola) {
	*p_cola = NULL;
}

void insertar_en_cola(t_cola ** p_cola, t_info_sentencias * p_info) {

	t_nodo * nodo = (t_nodo*)malloc(sizeof(t_nodo));

	if(*p_cola == NULL) {
		*p_cola = (t_cola*) malloc(sizeof(t_cola));
	 	(*p_cola)->p_primero = (*p_cola)->p_ultimo = nodo;

	} else if ((*p_cola)->p_primero == (*p_cola)->p_ultimo)
	{
		(*p_cola)->p_primero->sig_nodo = nodo;
	 	(*p_cola)->p_ultimo->sig_nodo = nodo;
	 	(*p_cola)->p_ultimo = nodo;
	} else {
	 	(*p_cola)->p_ultimo->sig_nodo = nodo;
	 	(*p_cola)->p_ultimo = nodo;
	}

 	nodo->sig_nodo = NULL;
	nodo->info = p_info;

}

t_info_sentencias * sacar_de_cola(t_cola** p_cola) {
	if(*p_cola == NULL) return NULL;
	t_nodo * nodo_a_eliminar = (*p_cola)->p_primero;
	t_info_sentencias * ret_info = (*p_cola)->p_primero->info;
	(*p_cola)->p_primero = (*p_cola)->p_primero->sig_nodo;

	if((*p_cola)->p_primero == NULL) {
		free(*p_cola);
		*p_cola = NULL;
	}

	if(nodo_a_eliminar != NULL)
		free(nodo_a_eliminar);
	// printf("sacando de cola: %s \n",ret_info->a->info->a);
	// if(ret_info->a->nodo_izq)
	// printf("sacando de cola: %s \n",ret_info->a->nodo_izq->info->a);
	// if(ret_info->a->nodo_der)
	// printf("sacando de cola: %s \n",ret_info->a->nodo_der->info->a);

	return ret_info;
}


void vaciar_cola(t_cola ** p_cola) {
	while(cola_vacia(p_cola) == 0){
		sacar_de_cola(p_cola);
	}
}

int cola_vacia(t_cola ** p_cola) {
	return (*p_cola) == NULL;
}


t_info_sentencias * frente_de_cola(t_cola** p_cola) {
	if(*p_cola == NULL) return NULL;
	return (*p_cola)->p_primero->info;
}