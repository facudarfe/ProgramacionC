#include <stdio.h>

int main(int argc, char *argv[]) {
	int a, b;
	
	a = 15;
	/*1) b = a;
	2) a = a + 1;
	b = a++;
	printf("%d, %d\n", b, a);*/
	printf("%d\n", a--);
	printf("%d\n", a);
	
	a = 15;
	a++;
	++a;
	/*1) a = a + 1;
	2) b = a;
	b = ++a;
	printf("%d, %d", b, a);*/
	printf("%d\n", --a);
	printf("%d\n", a);
	
	return 0;
}

