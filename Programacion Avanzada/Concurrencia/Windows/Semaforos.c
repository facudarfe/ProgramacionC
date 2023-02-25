#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

HANDLE semaforo;
int recurso_compartido = 0;

DWORD WINAPI incrementarRecurso(LPVOID arg);
DWORD WINAPI decrementarRecurso(LPVOID arg);

int main(int argc, char *argv[]) {
	HANDLE hThread1, hThread2;
	DWORD dwThread1, dwThread2;
	srand(time(NULL));
	
	semaforo = CreateSemaphore(NULL, 1, 1, NULL);
	hThread1 = CreateThread(NULL, 0, incrementarRecurso, NULL, 0, &dwThread1);
	hThread2 = CreateThread(NULL, 0, decrementarRecurso, NULL, 0, &dwThread2);
	
	WaitForSingleObject(hThread1, INFINITE);
	WaitForSingleObject(hThread2, INFINITE);
	
	CloseHandle(hThread1);
	CloseHandle(hThread2);
	CloseHandle(semaforo);
	
	printf("Recurso compartido: %d", recurso_compartido);
	
	return 0;
}

DWORD WINAPI incrementarRecurso(LPVOID arg){
	int i;
	
	for(i=0; i<10; i++){
		WaitForSingleObject(semaforo, INFINITE); // Aca inicia la zona critica
		Sleep(rand() % 200);
		recurso_compartido++;
		ReleaseSemaphore(semaforo, 1, NULL);	// Aca finaliza la zona critica
	}
	
	return 0;
}

DWORD WINAPI decrementarRecurso(LPVOID arg){
	int i;
	
	for(i=0; i<10; i++){
		WaitForSingleObject(semaforo, INFINITE); // Aca inicia la zona critica
		Sleep(rand() % 200);
		recurso_compartido--;
		ReleaseSemaphore(semaforo, 1, NULL);	// Aca finaliza la zona critica
	}
	
	return 0;
}
