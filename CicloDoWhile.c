/***
Ejercicio 13: Dadas las edades de N personas (0-100) se desea saber 
la edad promedio.
***/

#include <stdio.h>

int main(int argc, char *argv[]) {
	int N, i, edad, sum=0;
	float prom;
	
	printf("Ingrese la cantidad de edades: ");
	scanf("%d", &N);
	
	for(i=1; i<=N; i++){
		do{
			printf("Ingrese la edad numero %d: ", i);
			scanf("%d", &edad);
		} while(edad < 0 || edad > 100);
		sum += edad;
	}
	prom = sum/N;
	printf("La edad promedio es %f", prom);
	
	return 0;
}

