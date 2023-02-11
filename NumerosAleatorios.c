#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generarNumeroAlea(int A, int B);

int main(int argc, char *argv[]) {
	int i, num;
	srand(time(NULL));
	
	for(i=1; i<=10; i++){
		num = generarNumerAlea(5, 93);
		printf("\nEl numero es %d", num);
	}
	return 0;
}

int generarNumeroAlea(int A, int B){
	int num;
	num = A + rand() % (B-A+1);
	return num;
}

