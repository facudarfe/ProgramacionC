#include <stdio.h>

int fact_it(int n);
int fact_rec(int n);

int main(int argc, char *argv[]) {
	int n = 5;
	
	printf("Factorial iterativo: %d\n", fact_it(n));
	printf("Factorial recursivo: %d\n", fact_rec(n));
	return 0;
}

int fact_it(int n){
	int i, f = 1;
	
	for(i=1; i<=n; i++){
		f = f * i;
	}
	return f;
}
	
int fact_rec(int n){
	if(n > 0)
		return n * fact_rec(n-1);
	else
		return 1;
}
