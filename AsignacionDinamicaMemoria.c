#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int x,y;
}tCoord;

int main(int argc, char *argv[]) {
	/*int *a, *b;
	
	a = (int *)malloc(sizeof(int));
	b = (int *)malloc(sizeof(int));
	
	*a = 5;
	*b = 10;
	
	printf("El valor de a es: %d", *a);
	printf("\nEl valor de b es: %d", *b);
	
	printf("El valor de la suma entre a y b es: %d", (*a + *b));
	
	free(a); a=NULL;
	free(b); b=NULL;*/
	
	/*tCoord *punto;
	
	punto = (tCoord *)malloc(sizeof(tCoord));
	
	printf("Ingrese x: "); scanf("%d", &punto->x);
	printf("Ingrese y: "); scanf("%d", &punto->y);
	
	printf("Valor de x: %d, valor de y: %d", punto->x, punto->y);
	
	free(punto); punto=NULL;*/
	
	int i, n, *lis;
	
	printf("Ingrese el tamanio de la lista: "); scanf("%d", &n);
	lis = (int *)calloc(n, sizeof(int));
	
	for(i=0; i<n; i++){
		printf("Ingrese el dato %d: ", i); 
		scanf("%d", &lis[i]);
	}
	
	for(i=0; i<n; i++){
		printf("\nEl dato %d: %d", i, lis[i]); 
	}
	
	free(lis); lis=NULL;
	
	return 0;
}

