#include <stdio.h>
#include "TAD_Cola.h"

int main(){
	tCola cola;
	int elem;
	
	cola = inicializaCola();
	
	push(&cola, 2);
	push(&cola, 4);
	push(&cola, 6);
	
	elem = pop(&cola);
	printf("%d\n", elem);
	elem = pop(&cola);
	printf("%d\n", elem);
	elem = pop(&cola);
	printf("%d\n", elem);
	
	return 0;
}
