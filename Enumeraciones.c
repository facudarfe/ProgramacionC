#include <stdio.h>

typedef enum {FALSE, TRUE} boolean;
typedef enum {LUNES, MARTES, MIERCOLES, JUEVES, VIERNES, SABADO, DOMINGO} dias;

int main(int argc, char *argv[]) {
	boolean b;
	dias d;
	
	b = TRUE;
	//printf("%d", b);
	for(d=LUNES; d<=DOMINGO; d++={
		printf("%d", d);
	}
	
	return 0;
}

