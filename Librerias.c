/*Ejercicio video 24: Se desea ingresar un punto en el plano (X,Y) y N puntos
(Z,W) y mostrar la distancia de cada punto (Z,W) con respecto a (X,Y)*/

#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[]) {
	float x1, y1, x2, y2, d;
	int i, N;
	
	printf("Ingrese el punto X1,Y1: "); scanf("%f,%f", &x1, &y1);
	printf("Ingrese el N: "); scanf("%d", &N);
	
	for(i=1; i<=N; i++){
		printf("Ingrese el punto X2,Y2: "); scanf("%f,%f", &x2, &y2);
		d = sqrt(pow((x2-x1), 2) + pow((y2-y1), 2));
		printf("La distancia es %f", d);
	}
	
	return 0;
}

