#include "TAD_Pila.h"
#include <stdio.h>

tPila inicializaPila(){
	tPila pila;
	
	pila.tam = 0;
	
	return pila;
}

int estaVacia(tPila pila){
	return pila.tam == 0;
}

int estaLlena(tPila pila){
	return pila.tam == TAMMAX - 1;
}

void push(tPila *pila, int elem){
	if(!estaLlena(*pila)){
		pila->tam = pila->tam + 1;
		pila->lis[pila->tam] = elem;
	}
	else
		printf("Pila llena\n");
}

int pop(tPila *pila){
	int elem;
	
	if(!estaVacia(*pila)){
		elem = pila->lis[pila->tam];
		pila->tam = pila->tam - 1;
		
		return elem;
	}
	else{
		printf("Pila vacia\n");
		
		return -1;
	}
}
