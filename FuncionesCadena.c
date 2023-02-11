#include <stdio.h>
#include <string.h>
#define TMAX 40

typedef char tCadena[TMAX];

int main(int argc, char *argv[]) {
	tCadena s1 = "Hola", s2 = "hola";
	
	printf("%d", strcmp(s1, s1));
	return 0;
}

