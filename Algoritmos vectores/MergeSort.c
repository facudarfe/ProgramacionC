#include <stdio.h>

void Mezcla(int L[], int ini, int m, int fin){
	int aux[20], i, j, k, t;
	
	k = 0;
	i = ini;
	j = m+1;
	
	// Ciclo que se va a encargar de hacer la mezcla
	while(i<= m && j<= fin){
		k++;
		if(L[i] < L[j]){
			aux[k] = L[i];
			i++;
		}
		else{
			aux[k] = L[j];
			j++;
		}
	}
	
	// Si quedaron elementos en la primera sublista se los pasa
	for(t=i; t<=m; t++){
		k++;
		aux[k] = L[t];
	}
	
	// Si quedaron elementos en la segunda lista se los pasa
	for(t=j; t<= fin; t++){
		k++;
		aux[k] = L[t];
	}
	
	// Ahora se copia lo de aux a la lista original
	for(t=1; t<=k; t++)
		L[ini+t-1] = aux[t];
}

void Merge_Sort(int L[], int ini, int fin){
	int m;
	
	m = (ini + fin)/2;
	if(ini < fin){
		Merge_Sort(L, ini, m);
		Merge_Sort(L, m+1, fin);
		Mezcla(L, ini, m, fin);
	}
}

int main(int argc, char *argv[]) {
	
	return 0;
}

