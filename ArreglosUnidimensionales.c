#include <stdio.h>

int sumaNumeros(int A[], int N);

int main(int argc, char *argv[]) {
	int A[100], N, suma, i;
	
	printf("Ingrese cantidad :");
	scanf("%d", &N);
	for(i=0; i<N; i++){
		printf("Ingrese el dato %d", i);
		scanf("%d", &A[i]);
	}
	
	suma = sumaNumeros(A, N);
	printf("La suma de los numeros es %d", suma);
	
	return 0;
}

int sumaNumeros(int A[], int N){
	int i; suma = 0;
	
	for(i=0; i<N; i++)
		suma += A[i];
	
	return suma;
}

