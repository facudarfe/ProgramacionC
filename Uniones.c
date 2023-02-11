#include <stdio.h>

typedef struct{
	char *nombre;
	int edad;
	union{
		long fijo, cel, fax;
	}telefono;
}tPersona;

int main(int argc, char *argv[]) {
	tPersona p1;
	
	p1.nombre = "Ricardo";
	p1.edad = 51;
	p1.telefono.fijo = 123456;
	p1.telefono.cel = 321654;
	
	printf("Nombre: %s, Edad: %d, Telefono: %ld", p1.nombre, p1.edad, p1.telefono.fijo);
	return 0;
}

