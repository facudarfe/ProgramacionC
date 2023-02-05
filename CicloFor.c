/***
Ejercicio 12a: Pedirle al usuario N numeros enteros positivos y mostrar su
raiz cuadrada.

Ejercicio 12b: Mostrar los numeros pares hasta el 50.

Ejercicio 12c: Mostrar los numeros impares y pares hasta el 50 de la forma:
"impar - par".
***/

#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[]) {
	int N, i, impar, par;
	unsigned int num;
	
	/*Ejercicio 12a*/
	/*scanf("%d", &N);
	for(i=1; i<=N; i++){
		scanf("%ud", &num);
		printf("%f\n", sqrt(num));
	}*/
	
	/*Ejercicio 12b*/
	/*for(i=2; i<=50; i+=2)
		printf("%d\n", i);*/
	
	/*Ejercicio 12c*/
	for(impar=1, par=2; par<=50; impar+=2, par+=2)
		printf("%d - %d\n", impar, par);
	
	return 0;
}

