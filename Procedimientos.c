#include <stdio.h>

void muestaMensaje(){
	printf("Bienvenidos al curso de C");
}

void cocienteYResto(int num1, int num2, int *coc, int *res){
	*coc = num1 / num2;
	*res = num1 % num2;
}

int main(int argc, char *argv[]) {
	int a = 15, b = 2;
	int coc, res;
	
	cocienteYresto(a, b, &coc, &res);
	printf("Cociente: %d, Resto: %d", coc, res);
	return 0;
}

