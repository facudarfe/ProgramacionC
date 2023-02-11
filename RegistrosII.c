#include <stdio.h>
#include <stdlib.h>

struct Direccion{
	char calle[30];
	char barrio[30];
	int nro;
};

struct Persona{
	char nombre[30];
	int edad;
	struct Direccion dir;
};

struct Libro{
	char nombre[30];
	int anio;
	int cantAutores;
	struct Persona autores[10];
};

int main(int argc, char *argv[]) {
	struct Libro libros[20];
	int i, j, N;
	
	printf("Ingrese cantidad de libros: "); scanf("%d", &N);
	for(i=0; i<N; i++){
		printf("Ingrese nombre del libro: "); scanf("%s", libros[i].nombre);
		printf("Ingrese anio de publicacion: "); scanf("%d", &libros[i].anio);
		printf("Ingrese cantidad de autores: "); scanf("%d", &libros[i].cantAutores);
		
		for(j=0; j<libros[i].cantAutores; j++){
			printf("Ingrese nombre del autor %d: ", j); 
			scanf("%s", libros[i].autores[j].nombre);
			printf("Ingrese edad del autor: "); scanf("%d", &libros[i].autores[j].edad);
			
			printf("Ingrese calle donde vive: ");
			scanf("%s", libros[i].autores[j].dir.calle);
			printf("Ingrese barrio donde vive: ");
			scanf("%s", libros[i].autores[j].dir.barrio);
			printf("Ingrese numero de casa: ");
			scanf("%d", &libros[i].autores[j].dir.nro);
		}
	}
	
	/*Muestra*/
	system("cls");
	for(i=0; i<N; i++){
		printf("Nombre del libro: %s\n", libros[i].nombre);
		printf("Anio del libro: %d\n", libros[i].anio);
		printf("Autores: \n");
		for(j=0; j<libros[i].cantAutores; j++){
			printf("Nombre: %s\n", libros[i].autores[j].nombre);
			printf("Edad: %d\n", libros[i].autores[j].edad);
			printf("Calle: %s\n", libros[i].autores[j].dir.calle);
			printf("Barrio: %s\n", libros[i].autores[j].dir.barrio);
			printf("Numero: %d\n\n", libros[i].autores[j].dir.nro);
		}
	}
	return 0;
}

