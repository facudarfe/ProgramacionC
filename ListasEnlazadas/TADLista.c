#include "TADLista.h"
#include <stdlib.h>
#include <stdio.h>

//Modulos privados
tLista crearNodo(tElem e){
	tLista nodo;
	
	nodo = (tLista)malloc(sizeof(tNodo));
	nodo->dato = e;
	nodo->sig = NULL;
	
	return nodo;
}

tLista nuevaLista(){
	return NULL;
}

void agregarFinal(tLista *lis, tElem e){
	tLista aux;
	
	if(*lis != NULL){
		aux = *lis;
		while(aux->sig != NULL){
			aux = aux->sig;
		}
		aux->sig = crearNodo(e);
	}
	else{
		*lis = crearNodo(e);
	}
}

void agregarInicio(tLista *lis, tElem e){
	tLista nodo;
	
	nodo = crearNodo(e);
	
	nodo->sig = *lis;
	*lis = nodo;
}

void agregarOrdenado(tLista *lis, tElem e){
	tLista ant, aux, nodo;
	
	nodo = crearNodo(e);
	if(*lis != NULL){
		ant = NULL;
		aux = *lis;
		while(aux != NULL && comparaElem(aux->dato, e) < 0){
			ant = aux;
			aux = aux->sig;
		}
		if(ant != NULL){
			ant->sig = nodo;
			nodo->sig = aux;
		}
		else{
			nodo->sig = *lis;
			*lis = nodo;
		}
	}
	else{
		*lis = nodo;
	}
}

void eliminarElem(tLista *lis, tElem e){
	tLista ant, aux;
	
	if(*lis != NULL){
		ant = NULL;
		aux = *lis;
		while(aux != NULL && comparaElem(aux->dato, e) != 0){
			ant = aux;
			aux = aux->sig;
		}
		if(aux != NULL){
			if(ant != NULL){
				ant->sig = aux->sig;
			}
			else{
				*lis = aux->sig;
			}
			free(aux);
		}
		else{
			printf("No se encontro el elemento");
		}
	}
	else{
		printf("No se puede eliminar\n");
	}
}

void mostrarLista(tLista lis){
	if(lis != NULL){
		while(lis != NULL){
			mostrarElem(lis->dato);
			lis = lis->sig;
		}
	}
	else{
		printf("Lista vacia.\n");
	}
	
}
