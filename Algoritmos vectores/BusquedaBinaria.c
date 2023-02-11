#include <stdio.h>

int main(int argc, char *argv[]) {
	
	return 0;
}

// Se devuelve la posicion donde se encontro, sino se devuelve -1.
int busquedaBinaria(int A[], int N, int elem){
	int ini=0, fin=N-1;
	int med = (ini+fin)/2;
	
	while(ini<=fin && elem <> A[med]){
		if(elem < A[med])
			fin = med - 1;
		else
			ini = med + 1;
		
		med = (ini + fin)/2;
	}
	if(ini<=fin)
		  return med;
	else
		return -1;
}

