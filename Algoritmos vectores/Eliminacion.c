#include <stdio.h>

int main(int argc, char *argv[]) {
	
	return 0;
}

// Tener en cuenta que si tengo 10 elementos, el vector va desde 0 a 9, por esta razon
// el ciclo comienza va menor estricto que N-1, es decir, hasta N-2.
void eliminar(int A[], int *N, int pos){
	int i;
	
	for(i=pos; i<*N-1; i++){
		A[i] = A[i+1];
	}
	*N = *N - 1;
}
