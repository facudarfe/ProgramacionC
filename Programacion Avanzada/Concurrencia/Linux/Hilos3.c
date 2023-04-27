#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *funcion_muestra(void *arg);

int main(int argc, char *argv[]) {
	pthread_t hilo1, hilo2;
	int res1, res2, ini_hilo1 = 1, ini_hilo2 = 11, *suma_hilo1, *suma_hilo2;
	
	res1 = pthread_create(&hilo1, NULL, funcion_muestra, &ini_hilo1);
	res2 = pthread_create(&hilo2, NULL, funcion_muestra, &ini_hilo2);
	
	if(res1 != 0 || res2 != 0){
		printf("Error al crear algun hilo");
		exit(-1);
	}
	
	pthread_join(hilo1, (void**)&suma_hilo1);
	pthread_join(hilo2, (void**)&suma_hilo2);
	
	printf("Suma hilo 1: %d\n", *suma_hilo1);
	printf("Suma hilo 2: %d\n", *suma_hilo2);
	
	free(suma_hilo1);
	free(suma_hilo2);
	
	return 0;
}

void *funcion_muestra(void *arg){
	int i, ini, *suma;
	
	ini = *((int*)arg);
	suma = malloc(sizeof(int));
	*suma = 0;
	
	for(i=ini; i<ini+10; i++)
		*suma = *suma + i;
	
	pthread_exit(suma); // Prototipo: pthread_exit(void*)
}

