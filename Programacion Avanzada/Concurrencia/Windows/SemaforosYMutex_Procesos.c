#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#define NUMPROC 10
#define NUMTHREADS 20

HANDLE mutex;
HANDLE semaforos[NUMPROC];
float procesadores[NUMPROC] = {0};

DWORD WINAPI initProcess(LPVOID arg);

int main(int argc, char *argv[]) {
	int i;
	HANDLE hThreads[NUMTHREADS];
	DWORD dwThreads[NUMTHREADS];
	
	mutex = CreateMutex(NULL, FALSE, NULL);
	
	for(i=0; i<NUMPROC; i++)
		semaforos[i] = CreateSemaphore(NULL, 1, 1, NULL);
	
	for(i=0; i<NUMPROC; i++)
		hThreads[i] = CreateThread(NULL, 0, initProcess, (LPVOID)i, 0, &dwThreads[i]);
	
	WaitForMultipleObjects(NUMPROC, hThreads, TRUE, INFINITE);
	
	for(i=0; i<NUMTHREADS; i++)
		CloseHandle(hThreads[i]);
	
	for(i=0; i<NUMPROC; i++)
		CloseHandle(semaforos[i]);
	
	return 0;
}

void simularTrabajo(int numProceso, int numProcesador, float tiempoUso){
	/********** Inicio zona critica para acceder al procesador **********/
	WaitForSingleObject(semaforos[numProcesador], INFINITE);
	printf("El proceso %d comienza a trabajar en el procesador %d\n", numProceso, numProcesador);
	Sleep(tiempoUso);
	procesadores[numProcesador] += tiempoUso;
	ReleaseSemaphore(semaforos[numProcesador], 1, NULL);
	/********** Fin zona critica para acceder al procesador **********/
	
	printf("El proceso %d deja de usar el procesador %d luego de %f segundos\n", numProceso, numProcesador, (tiempoUso / 1000));
}

DWORD WINAPI initProcess(LPVOID arg){
	int i = (int)arg, numProcesador;
	float tiempoUso, tiempoEspera;
	
	/********** Inicio zona critica para generar numeros aleatorios **********/
	WaitForSingleObject(mutex, INFINITE);		
	srand(time(NULL)+i);
	tiempoEspera = 2000 + rand() % (4000 - 2000 + 1); // Determino el tiempo hasta que arranque el proceso
	numProcesador = rand() % NUMPROC;
	tiempoUso = 1000 + rand() % (5000 - 1000 + 1);	// Determino el tiempo de uso del procesador
	ReleaseMutex(mutex);
	/********** Fin zona critica para generar numeros aleatorios **********/
	
	Sleep(tiempoEspera); 
	printf("El proceso %d ingreso al sistema a usar el procesador %d\n", i, numProcesador);
	
	simularTrabajo(i, numProcesador, tiempoUso);
	
	return 0;
}
	
