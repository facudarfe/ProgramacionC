#include <stdio.h>

int main(int argc, char *argv[]) {
	int x, y;
	
	printf("Ingrese un punto en el plano de la forma x,y: ");
	scanf("%d,%d", &x, &y);
	printf("El punto ingresado (%d, %d)", x, y);
	return 0;
}

