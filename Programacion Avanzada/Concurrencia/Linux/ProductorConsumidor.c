#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <time.h>

#define TAMDEPOSITO 3

sem_t lugaresLlenos, lugaresVacios;

void *producirProducto(void *arg);
void *consumirProducto(void *arg);

int main(int argc, char *argv[]){
	int semilla_productor, semilla_consumidor;
	pthread_t productor, consumidor;
	srand(time(NULL));
	
	// Inicializacion de los semaforos
	sem_init(&lugaresLlenos, 0, 0);
	sem_init(&lugaresVacios, 0, TAMDEPOSITO);
	
	// Inicializar semilla para cada uno de los hilos
	semilla_productor = rand();
	semilla_consumidor = rand();
	
	// Creacion del productor y el consumidor
	pthread_create(&productor, NULL, producirProducto, &semilla_productor);
	pthread_create(&consumidor, NULL, consumirProducto, &semilla_consumidor);
	
	// Esperar a los hilos
	pthread_join(productor, NULL);
	pthread_join(consumidor, NULL);
	
	// Destruimos los semaforos
	sem_destroy(&lugaresLlenos);
	sem_destroy(&lugaresVacios);
	
	return 0;
}
	
void *producirProducto(void *arg){
	float tiempoProduccion;
	int semilla = *((int*)arg);
	struct timespec ts;
	
	srand(semilla);
	clock_gettime(CLOCK_REALTIME, &ts);
	ts.tv_sec += 1;
	
	while(1){
		tiempoProduccion = 2 + rand() % (5 - 2 + 1);
		
		while(sem_timedwait(&lugaresVacios, &ts) != 0){
			printf("Productor esperando a que se liberen huecos...\n");
			clock_gettime(CLOCK_REALTIME, &ts);
			ts.tv_sec += 1;
		}
		
		printf("El productor acaba de empezar a producir\n");
		sleep(tiempoProduccion);
		printf("El productor termino de producir en %.2f segundos\n", tiempoProduccion);
		sem_post(&lugaresLlenos);
	}
	
	pthread_exit(NULL);
}
	
void *consumirProducto(void *arg){
	float tiempoConsumir;
	int semilla = *((int*)arg);
	struct timespec ts;
	
	srand(semilla);
	clock_gettime(CLOCK_REALTIME, &ts);
	ts.tv_sec += 1;
	
	while(1){
		tiempoConsumir = 4 + rand() % (7 - 4 + 1);
		
		while(sem_timedwait(&lugaresLlenos, &ts) != 0){
			printf("Consumidor esperando a que haya productos...\n");
			clock_gettime(CLOCK_REALTIME, &ts);
			ts.tv_sec += 1;
		}
		
		printf("El consumidor acaba de empezar a consumir\n");
		sleep(tiempoConsumir);
		printf("El consumidor termino de consumir del deposito en %.2f segundos\n", tiempoConsumir);
		sem_post(&lugaresVacios);
	}
	
	pthread_exit(NULL);
}
