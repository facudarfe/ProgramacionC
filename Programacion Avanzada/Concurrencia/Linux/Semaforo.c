#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

int recurso_compartido = 0;
sem_t semaforo;

void *incrementaRecurso(void *arg);
void *decrementaRecurso(void *arg);

int main(int argc, char *argv[]){
	pthread_t hilo1, hilo2;
	
	sem_init(&semaforo, 0, 1); // Inicializar el semaforo
	
	// Creacion de los hilos
	pthread_create(&hilo1, NULL, incrementaRecurso, NULL);
	pthread_create(&hilo2, NULL, decrementaRecurso, NULL);
	
	// Esperar a los hilos
	pthread_join(hilo1, NULL);
	pthread_join(hilo2, NULL);
	
	// Mostrar el resultado
	printf("Valor del recurso: %d", recurso_compartido);
	
	// Destruimos el semaforo
	sem_destroy(&semaforo);
	
	return 0;
}

void *incrementaRecurso(void *arg){
	int i;
	
	for(i=0; i<10; i++){
		sem_wait(&semaforo);
		sleep(rand() % 1);
		recurso_compartido++;
		sem_post(&semaforo);
	}
	
	pthread_exit(NULL);
}

void *decrementaRecurso(void *arg){
	int i;
	
	for(i=0; i<10; i++){
		sem_wait(&semaforo);
		sleep(rand() % 1);
		recurso_compartido--;
		sem_post(&semaforo);
	}
	
	pthread_exit(NULL);
}
