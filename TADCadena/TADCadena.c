#include "TADCadena.h"
#include <string.h>
#include <stdio.h>

void scanString(tCadena s){
	char c;
	int j = 0;
	
	while(j < TMAX-1 && (c=getchar())!=EOF && c != '\n'){
		s[j] = c;
		j++;
	}
	s[j] = '\0';
	
	while(c!=EOF && c!='\n')
		c=getchar();
}
	
int comparaCadena(tCadena s1, tCadena s2){
	return strcmp(s1, s2);
}
	
char devolverCaracter(tCadena s1, int p){
	if(p >= 0 && p < strlen(s1))
		return s1[p];
	else
		return '\0';
}
	
void mostrarCadena(tCadena s){
	printf("%s", s);
}
