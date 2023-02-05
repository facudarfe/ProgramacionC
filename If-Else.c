/***
Ejercicio 1: Dados dos numeros enteros A y B mostrar la suma entre A y B
y mostrar si A es mayor que B.

Ejercicio 2: Dados dos numeros enteros A y B mostrar cual de los dos es menor.

Ejercicio 3: Dados tres numeros enteros A, B y C mostrarlos en orden.
***/

#include <stdio.h>

int main(int argc, char *argv[]) {
	int a, b, c;
	
	/*Ejercicio 1 
	scanf("%d %d", &a, &b);
	printf("La suma es: %d", a+b);
	if(a > b)
		printf("Se cumple. A es mayor que B");
	*/
	
	/*Ejercicio 2
	scanf("%d %d", &a, &b);
	if(a < b)
		printf("%d es menor que %d", a, b);
	else
		printf("%d es menor que %d", b, a);
	*/
	
	/*Ejercicio 3
	scanf("%d %d %d", &a, &b, &c);
	if(a<b && a<c){
		if(b<c)
			printf("%d, %d, %d", a, b, c);
		else
			printf("%d, %d, %d", a, c, b);
	}
	else{
		if(b<c){
			if(a<c)
				printf("%d, %d, %d", b, a, c);
			else
				printf("%d, %d, %d", b, c, a);
		}
		else{
			if(a<b)
				printf("%d, %d, %d", c, a, b);
			else
				printf("%d, %d, %d", c, b, a);
		}
	}
	*/
	
	return 0;
}

