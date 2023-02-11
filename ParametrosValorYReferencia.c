#include <stdio.h>

void cocYResto(int num1, int num2, int *coc, int *res);

int main(int argc, char *argv[]) {
	int a = 15, b = 2, coc, res;
	
	printf("\nValor de a en el main: %d", a);
	printf("\nValor de b en el main: %d", b);
	printf("\nDireccion de a en el main: %p", &a);
	printf("\nDireccion de b en el main: %p", &b);
	printf("\nValor de coc en el main: %d", coc);
	printf("\nValor de res en el main: %d", res);
	printf("\nDireccion de coc en el main: %p", &coc);
	printf("\nDireccion de res en el main: %p", &res);
	cocYResto(a, b, &coc, &res);
	printf("\nValor de coc en el main: %d", coc);
	printf("\nValor de res en el main: %d", res);
	return 0;
}

void cocYResto(int num1, int num2, int *coc, int *res){
	*coc = num1 / num2;
	*res = num1 % num2;
	printf("\nValor de num1 en el procedimiento: %d", num1);
	printf("\nValor de num2 en el procedimiento: %d", num2);
	printf("\nDireccion de num1 en el procedimiento: %p", &num1);
	printf("\nDireccion de num2 en el procedimiento: %p", &num2);
	printf("\nValor de coc en el procedimiento: %p", coc);
	printf("\nValor de res en el procedimiento: %p", res);
	printf("\nValor de *coc en el procedimiento: %d", *coc);
	printf("\nValor de *res en el procedimiento: %d", *res);
	printf("\nDireccion de coc en el procedimiento: %p", &coc);
	printf("\nDireccion de res en el procedimiento: %p", &res);
	
}

