#include <stdio.h>
#define MAX 40

typedef struct {
	float x, y;
} tPunto;

typedef int tEntero;
typedef tPunto tListaPuntos[MAX];
typedef tPunto *tPtroPunto;

tPunto sumarPuntos(tListaPuntos lista, int N);

int main(int argc, char *argv[]) {
	tPunto p;
	tPtroPunto ptro;
	tEntero a, b;
	tListaPuntos lista; /*Esto es equivalente a hacer tPunto lista[MAX]*/
	int N, i;
	
	/*scanf("%d, %d", &a, &b);
	printf("%d, %d", a, b);*/
	ptro = &p;
	printf("Ingrese N: "); scanf("%d", &N);
	for(i=0; i<N; i++){
		printf("Ingrese un punto (x,y): "); 
		scanf("%f, %f", &lista[i].x, &lista[i].y);
	}
	
	p = sumarPuntos(lista, N);
	/*printf("Suma de x: %f\n", p.x);
	printf("Suma de y: %f", p.y);*/
	printf("Suma de x: %f\n", ptro->x);
	printf("Suma de y: %f", ptro->y);
	return 0;
}

tPunto sumarPuntos(tListaPuntos lista, int N){
	int i;
	tPunto p;
	
	p.x = 0; p.y = 0;
	for(i=0; i<N; i++){
		p.x += lista[i].x;
		p.y += lista[i].y;
	}
	return p;
}
