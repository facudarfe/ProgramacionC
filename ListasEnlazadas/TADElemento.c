#include "TADElemento.h"
#include <stdio.h>
#include <math.h>

tElem nuevoElem(){
	tElem e;
	
	printf("Ingrese coordenada x: "); scanf("%f", &e.x);
	printf("Ingrese coordenada y: "); scanf("%f", &e.y);
	
	return e;
}

int comparaElem(tElem e1, tElem e2){
	int d1, d2;
	
	d1 = sqrt(e1.x * e1.x + e1.y * e1.y);
	d2 = sqrt(e2.x * e2.x + e2.y * e2.y);
	
	if(d1 < d2)
		return -1;
	else{
		if(d1 > d2)
			return 1;
		else
			return 0;
	}
}

void mostrarElem(tElem e){
	printf("(%.2f, %.2f)\n", e.x, e.y); 
}
