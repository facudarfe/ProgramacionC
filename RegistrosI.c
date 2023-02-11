#include <stdio.h>

int main(int argc, char *argv[]) {
	struct{
		char *nombre;
		int edad;
		float peso;
	} p1, p2;
	
	p1.nombre = "Juan";
	printf("Ingrese edad de p1: ");
	scanf("%d", &p1.edad);
	p1.peso = 80;
	
	p2.nombre = "Marcela";
	printf("Ingrese edad de p2: ");
	scanf("%d", &p2.edad);
	p2.peso = 60.5;
	
	printf("Nombre: %s, Edad: %d, Peso: %f", p1.nombre, p1.edad, p1.peso);
	printf("\nNombre: %s, Edad: %d, Peso: %f", p2.nombre, p2.edad, p2.peso);
	return 0;
}

