#include <stdio.h>

void Quick_Sort(int L[], int ini, int fin){
	int piv, izq, der, med;
	
	// Caso base
	if(ini < fin){
		piv = L[ini];	// Inicializamos el pivot con el primer elemento
		izq = ini;
		
		// Vamos a ubicar los elementos a la izquierda y derecha del pivot
		der = fin;
		while(izq < der){
			while(der > izq && L[der] > piv)
				der--;
			
			if(der > izq){
				L[izq] = L[der];
				izq++;
			}
			
			while(izq < der && L[izq] < piv)
			   izq++;
			
			if(izq < der){
				L[der] = L[izq];
				der--;
			}
		}
		L[der] = piv; // Se ubica el pivot en su posicion
		med = der;
		
		// Llamadas recursivas
		Quick_Sort(L, ini, med-1);
		Quick_Sort(L, med+1, fin);
	}
}

int main(int argc, char *argv[]) {
	
	return 0;
}

