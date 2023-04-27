#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int recurso_compartido = 0;
pthread_mutex_t mutex;

void *incrementaRecurso(void *arg);
void *decrementaRecurso(void *arg);

int main(int argc, char *argv[]){
	pthread_t hilo1, hilo2;
	
	pthread_mutex_init(&mutex, NULL); // Inicializar el mutex
	
	// Creacion de los hilos
	pthread_create(&hilo1, NULL, incrementaRecurso, NULL);
	pthread_create(&hilo2, NULL, decrementaRecurso, NULL);
	
	// Esperar a los hilos
	pthread_join(hilo1, NULL);
	pthread_join(hilo2, NULL);
	
	// Mostrar el resultado
	printf("Valor del recurso: %d", recurso_compartido);
	
	// Destruimos el semaforo
	pthread_mutex_destroy(&mutex);
	
	return 0;
}
	
void *incrementaRecurso(void *arg){
	int i;
	
	for(i=0; i<10; i++){
		pthread_mutex_lock(&mutex);
		sleep(rand() % 1);
		recurso_compartido++;
		pthread_mutex_unlock(&mutex);
	}
	
	pthread_exit(NULL);
}
	
void *decrementaRecurso(void *arg){
	int i;
	
	for(i=0; i<10; i++){
		pthread_mutex_lock(&mutex);
		sleep(rand() % 1);
		recurso_compartido--;
		pthread_mutex_unlock(&mutex);
	}
	
	pthread_exit(NULL);
}	
