#include <stdio.h>
	
void cocYResto(int, int, int*, int*);	/*Prototipo, puedo obviar nombres de variables*/

int main(int argc, char *argv[]) {
	int a = 15, b = 2;
	int coc, res;
	
	cocYresto(a, b, &coc, &res);
	printf("Cociente: %d, Resto: %d", coc, res);
	return 0;
}

void cocYResto(int num1, int num2, int *coc, int *res){ /*No puedo obviar nombres de variables*/
	*coc = num1 / num2;
	*res = num1 % num2;
}
