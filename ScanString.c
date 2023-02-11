#include <stdio.h>
#define TMAX 40

typedef char tCadena[TMAX];

void scanString(tCadena s);

int main(int argc, char *argv[]) {
	tCadena s;
	scanString(s);
	
	printf("%s", s);
	return 0;
}

void scanString(tCadena s){
	char c;
	int j = 0;
	
	m = getchar();
	while(j < TMAX-1 && (m=getchar()) != EOF && m != '\n'){
		s[j] = c;
		j++;
	}
	s[j] = '\0';
	
	while(c != EOF && c != '\n')
		c = getchar();
}
