#include <stdio.h>

int main(int argc, char *argv[]) {
	
	return 0;
}

// Se devuelve la posicion donde se encontro, sino se devuelve -1.
int busquedaSecuencial(int A[], int N, int elem){
	int i = 0;
	
	while(i<N && elem <> A[i])
		i++;
	
	if(i<N)
		return i;
	else
		return -1;
}

