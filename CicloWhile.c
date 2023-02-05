/***
Ejercicio 11: Solicitar al usuario el ingreso de varios numeros enteros. El ingreso
se detiene cuando se ingresen 5 numeros pares
***/

#include <stdio.h>

int main(int argc, char *argv[]) {
	int num, cont = 0;	
	
	while(cont < 5){
		scanf("%d", &num);
		if(num % 2 == 0)
			cont++;
	}
	
	return 0;
}

