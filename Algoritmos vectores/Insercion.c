#include <stdio.h>

int main(int argc, char *argv[]) {
	
	return 0;
}

// Tener en cuenta que si tengo 10 elementos, el vector va desde 0 a 9, por esta razon
// el ciclo comienza en N-1
void insertar(int A[], int *N, int elem, int pos){
	int i;
	
	for(i=*N-1; i>=pos; i--){
		A[i+1] = A[i];
	}
	A[pos] = elem;
	*N = *N + 1;
}
