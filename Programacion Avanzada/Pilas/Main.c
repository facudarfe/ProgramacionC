#include "TAD_Pila.h"
#include <stdio.h>

int main(){
	tPila pila;
	int elem;
	
	pila = inicializaPila();
	
	push(&pila, 1);
	push(&pila, 2);
	push(&pila, 3);
	
	while(!estaVacia(pila)){
		elem = pop(&pila);
		printf("%d\n", elem);
	}
	
	return 0;
}
