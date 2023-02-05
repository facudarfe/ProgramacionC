#include <stdio.h>

int main(int argc, char *argv[]) {
	int a = 4, b = 7, c;
	char *s = "numero";
	
	c = a + b;
	printf("El resultado de la suma entre %d y %d es: %d", a, b, c);
	printf("El caracter del numero %d es: %c", c, c);
	printf("El %s es %d", s, a);
	
	return 0;
}

