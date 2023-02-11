/**
Ejercicio TDE: 
Una libreria quiere mantener el registro de todos los libros que vende, para ello
almacena la siguiente informacion de cada libro: ISBN, nombre, autores, cantidad de
paginas y precio.
El encargado de la libreria desea tener un sistema con un menu que le permita:
1-Cargar un nuevo libro.
2-Actualizar el precio de un libro.
3-Eliminar un libro.
4-Mostrar los datos de un solo libro.
5-Mostrar los datos de todos los libros.
Se desea que los libros se almacenen alfabeticamente segun su nombre.
**/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TMAX 40

typedef char tCadena[TMAX];

typedef struct {
	long isbn;
	tCadena nombre;
	int cantAutores;
	tCadena autores[TMAX];
	int cantPaginas;
	float precio;
}tLibro;

typedef tLibro tListaLibros[TMAX];

/*Prototipos*/
int menu();
tLibro nuevoLibro();
void limpiarBuffer();
void scanString(tCadena s);
void insertarLibroOrdenado(tListaLibros libros, int *N, tLibro nuevo);
int busqBinaria(tListaLibros libros, int N, tCadena nombre);
void actualizarPrecioLibro(tLibro *libro);
void eliminarLibro(tListaLibros libros, int *N, int pos);
void mostrarLibro(tLibro libro);
void mostrarLibros(tListaLibros libros, int N);

int main(int argc, char *argv[]) {
	int opc, N=0, pos;
	tListaLibros libros;
	tLibro libro;
	tCadena nombreLibro;
	
	opc = menu();
	while(opc != 0){
		system("cls");
		switch(opc){
			case 1:
				if(N < TMAX){
					printf("----Insertar un nuevo libro----\n");
					libro = nuevoLibro();
					insertarLibroOrdenado(libros, &N, libro);
					printf("\nEl libro se ha insertado exitosamente.\n");
				}else{
					printf("Lo sentimos. No se puede insertar mas libros. Capacidad maxima alcanzada\n");
				}
				
				break;
			case 2:
				printf("----Actualizar precio de un libro----\n");
				printf("Ingrese el nombre del libro a actualizar: ");
				scanString(nombreLibro);
				pos = busqBinaria(libros, N, nombreLibro);
				
				if(pos != -1){
					actualizarPrecioLibro(&libros[pos]);
					printf("\nEl libro se ha actualizado exitosamente.\n");
				}else{
					printf("Lo sentimos. El libro que intenta actualizar no se encuentra\n");
				}
				break;
			case 3:
				if(N > 0){
					printf("----Borrar un libro----\n");
					printf("Ingrese el nombre del libro a borrar: ");
					scanString(nombreLibro);
					pos = busqBinaria(libros, N, nombreLibro);
					
					if(pos != -1){
						eliminarLibro(libros, &N, pos);
						printf("\nEl libro se ha eliminado exitosamente.\n");
					}else{
						printf("Lo sentimos. El libro que intenta actualizar no se encuentra\n");
					}
				}else{
					printf("Lo sentimos. No se puede eliminar libros. No hay libros\n");
				}
				
				break;
			case 4:
				printf("---Mostrar un libro---\n");
				printf("Ingrese el nombre del libro a mostrar: ");
				scanString(nombreLibro);
				pos = busqBinaria(libros, N, nombreLibro);
				
				if(pos != -1){
					mostrarLibro(libros[pos]);
				}else{
					printf("Lo sentimos. El libro que intenta mostrar no se encuentra\n");
				}
				break;
			case 5:
				if(N > 0){
					printf("---Mostrar libros---\n");
					mostrarLibros(libros, N);
				}else{
					printf("No hay libros por mostrar\n");
				}
				break;
		}
		system("pause");
		system("cls");
		opc = menu();
	}
	printf("\nMuchas gracias por usar nuestro sistema. Hasta la proxima\n");
	
	return 0;
}

int menu(){
	int opc;
	
	printf("1-Insertar un nuevo libro");
	printf("\n2-Actualizar precio de un libro");
	printf("\n3-Borrar un libro");
	printf("\n4-Mostrar un libro");
	printf("\n5-Mostrar todos los libros");
	printf("\n0-Salir\n");
	printf("\nIngrese una opción: ");
	do{
		scanf("%d", &opc);
	} while(opc < 0 || opc > 5);
	limpiarBuffer();
	
	return opc;
}

tLibro nuevoLibro(){
	tLibro libro;
	int i;
	
	printf("Ingrese el ISBN del libro: "); scanf("%ld", &libro.isbn);
	limpiarBuffer();
	printf("Ingrese el nombre del libro: "); scanString(libro.nombre);
	printf("Ingrese la cantidad de autores del libro: "); scanf("%d", &libro.cantAutores);
	limpiarBuffer();
	printf("\n");
	for(i=0; i<libro.cantAutores; i++){
		printf("Ingrese el nombre del autor %d: ", i);
		scanString(libro.autores[i]);
	}
	printf("\nIngrese la cantidad de paginas libro: "); scanf("%d", &libro.cantPaginas);
	limpiarBuffer();
	printf("Ingrese el precio del libro: $"); scanf("%f", &libro.precio);
	limpiarBuffer();
	
	return libro;
}

void limpiarBuffer(){
	char c;
	
	while(c!=EOF && c!='\n'){
		c=getchar();
	}
}

void scanString(tCadena s){
	char c;
	int j = 0;
	
	while(j < TMAX-1 && (c=getchar())!=EOF && c != '\n'){
		s[j] = c;
		j++;
	}
	s[j] = '\0';
	
	limpiarBuffer();
}

void insertarLibroOrdenado(tListaLibros libros, int *N, tLibro nuevo){
	int i=*N-1;
	
	while(i>=0 && strcmp(nuevo.nombre, libros[i].nombre)<0){
		libros[i+1] = libros[i];
		i--;
	}
	libros[i+1] = nuevo;
	*N = *N + 1;
}

int busqBinaria(tListaLibros libros, int N, tCadena nombre){
	int ini=0, fin=N-1;
	int med = (ini+fin)/2;
	
	while(ini<=fin && strcmp(nombre, libros[med].nombre)!=0){
		if(strcmp(nombre, libros[med].nombre) < 0)
			fin = med - 1;
		else
			ini = med + 1;
		
		med = (ini + fin)/2;
	}
	if(ini<=fin)
		return med;
	else
		return -1;
}

void actualizarPrecioLibro(tLibro *libro){
	printf("Ingrese el nuevo precio del libro: $"); 
	scanf("%f", &libro->precio);
	limpiarBuffer();
}

void eliminarLibro(tListaLibros libros, int *N, int pos){
	int i;
	
	for(i=pos; i<*N-1; i++){
		libros[i] = libros[i+1];
	}
	*N = *N - 1;
}

void mostrarLibro(tLibro libro){
	int i;
	
	printf("ISBN: %ld\n", libro.isbn);
	printf("Nombre libro: %s\n", libro.nombre);
	printf("Autores: ");
	for(i=0; i<libro.cantAutores; i++){
		printf("%s  ", libro.autores[i]);
	}
	printf("\n");
	printf("Cantidad de paginas: %d\n", libro.cantPaginas);
	printf("Precio: $%.2f\n", libro.precio);
}

void mostrarLibros(tListaLibros libros, int N){
	int i;
	
	for(i=0; i<N; i++){
		mostrarLibro(libros[i]);
		printf("\n");
	}
}
