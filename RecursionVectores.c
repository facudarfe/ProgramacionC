#include <stdio.h>

void muestraRec(int L[], int n);
void muestraRec_inv(int L[], int n);

int main(int argc, char *argv[]) {
	int L[5] = {0, 2, 4, 6, 8};
	
	muestraRec(L, 4);
	printf("\n");
	muestraRec_inv(L, 4);
	
	return 0;
}

void muestraRec(int L[], int n){
	if(n > 0){
		muestraRec(L, n-1);
		printf("%d\n", L[n]);
	}
}

void muestraRec_inv(int L[], int n){
	if(n > 0){
		printf("%d\n", L[n]);
		muestraRec_inv(L, n-1);
	}
}

