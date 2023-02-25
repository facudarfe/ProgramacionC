#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#define TAMDEPOSITO 3

HANDLE lugaresLlenos, lugaresVacios, mutex;

DWORD WINAPI producirProducto(LPVOID arg);
DWORD WINAPI consumirProducto(LPVOID arg);

int main(int argc, char *argv[]) {
	HANDLE hProductor, hConsumidor;
	DWORD dwProductor, dwConsumidor;
	srand(time(NULL));
	
	lugaresLlenos = CreateSemaphore(NULL, 0, TAMDEPOSITO, NULL);
	lugaresVacios = CreateSemaphore(NULL, TAMDEPOSITO, TAMDEPOSITO, NULL);
	mutex = CreateMutex(NULL, FALSE, NULL);
	
	hProductor = CreateThread(NULL, 0, producirProducto, (LPVOID)rand(), 0, &dwProductor);
	hConsumidor = CreateThread(NULL, 0, consumirProducto, (LPVOID)rand(), 0, &dwConsumidor);
	
	WaitForSingleObject(hProductor, INFINITE);
	WaitForSingleObject(hConsumidor, INFINITE);
	
	CloseHandle(hProductor);
	CloseHandle(hConsumidor);
	CloseHandle(lugaresLlenos);
	CloseHandle(lugaresVacios);
	CloseHandle(mutex);
	
	return 0;
}

DWORD WINAPI producirProducto(LPVOID arg){
	float tiempoProduccion;
	srand((int)arg);
	
	while(1){
		tiempoProduccion = 2000 + rand() % (5000 - 2000 + 1);
		
		while(WaitForSingleObject(lugaresVacios, 1000) == WAIT_TIMEOUT)
			printf("Productor esperando a que se liberen huecos...\n");
		
		printf("El productor acaba de empezar a producir\n");
		Sleep(tiempoProduccion);
		printf("El productor termino de producir en %.2f segundos\n", tiempoProduccion/1000);
		ReleaseSemaphore(lugaresLlenos, 1, NULL);
	}
	
	return 0;
}

DWORD WINAPI consumirProducto(LPVOID arg){
	float tiempoConsumir;
	srand((int)arg);
	
	while(1){
		tiempoConsumir = 4000 + rand() % (7000 - 4000 + 1);
		
		while(WaitForSingleObject(lugaresLlenos, 1000) == WAIT_TIMEOUT)
			printf("Consumidor esperando a que haya productos...\n");
		
		printf("El consumidor acaba de empezar a consumir\n");
		Sleep(tiempoConsumir);
		printf("El consumidor termino de consumir del deposito en %.2f segundos\n", tiempoConsumir/1000);
		ReleaseSemaphore(lugaresVacios, 1, NULL);
	}
	
	return 0;
}
