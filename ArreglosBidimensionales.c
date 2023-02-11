#include <stdio.h>
#define FILAS 100
#define COLS 100

void muestra(int A[][COLS], int N, int M);

int main(int argc, char *argv[]) {
	int i, j, N, M, A[FILAS][COLS];
	
	printf("Ingrese cantidad de filas: "); scanf("%d", &N);
	printf("Ingrese cantidad de columnas: "); scanf("%d", &M);
	for(i=0; i<N; i++){
		for(j=0; j<M; j++){
			printf("Ingrese el valor de la celda %d, %d: ", i, j);
			scanf("%d", &A[i][j]):
		}
	}
	muestra(A, N, M);
	
	return 0;
}

void muestra(int A[][COLS], int N, int M){
	int i, j;
	for(i=0; i<N; i++){
		for(j=0; j<M; j++){
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}
}

