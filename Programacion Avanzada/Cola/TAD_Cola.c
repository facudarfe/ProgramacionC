#include "TAD_Cola.h"
#include <stdio.h>

tCola inicializaCola(){
	tCola cola;
	
	cola.tam = 0;
	
	return cola;
}

int estaVacia(tCola cola){
	return cola.tam == 0;
}

int estaLlena(tCola cola){
	return cola.tam == TAMMAX - 1;
}

void push(tCola *cola, int elem){
	if(!estaLlena(*cola)){
		cola->lis[cola->tam] = elem;
		cola->tam = cola->tam + 1;
	}
	else{
		printf("La cola esta llena\n");
	}
}

void elimina(tCola *cola, int p){
	int i;
	
	for(i=p; i<cola->tam-1; i++){
		cola->lis[i] = cola->lis[i+1];
	}
	cola->tam = cola->tam - 1;
}

int pop(tCola *cola){
	int elem;
	
	if(!estaVacia(*cola)){
		elem = cola->lis[0];
		elimina(cola, 0);
		
		return elem;
	}
	else{
		printf("La cola esta vacia\n");
		return -1;
	}
}
