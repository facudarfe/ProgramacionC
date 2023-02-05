/***
Ejercicio 10: Dada una nota en el rango (A-F), mostrar un mensaje si la nota es:
Muy mal (F), Mal (E), Bien (D), Muy bien (C), Excelente (A y B). 
***/

#include <stdio.h>

int main(int argc, char *argv[]) {
	char nota;
	
	printf("Ingrese la nota (A-F): ");
	scanf("%c", &nota);
	
	switch(nota){
		case 'A': case 'B':
			printf("Su nota es excelente\n");
			break;
		case 'C':
			printf("Su nota es muy buena\n");
			break;
		case 'D':
			printf("Su nota es buena\n");
			break;
		case 'E':
			printf("Su nota es mala\n");
			break;
		case 'F':
			printf("Su nota es muy mala\n");
			break;
		default:
			printf("La letra de la nota ingresada no es valida\n");
	}
	
	return 0;
}

