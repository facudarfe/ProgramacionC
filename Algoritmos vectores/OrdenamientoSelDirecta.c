#include <stdio.h>

int main(int argc, char *argv[]) {
	
	return 0;
}

void ordenamientoSelDirecta(int A[], int N){
	int i, j, aux;
	
	for(i=0; i<N-1; i++){
		for(j=i+1; j<N; j++){
			if(A[j] < A[i]){
				aux = A[j];
				A[j] = A[i];
				A[i] = aux;
			}
		}
	}
}
