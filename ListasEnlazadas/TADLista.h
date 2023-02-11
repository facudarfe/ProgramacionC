#ifndef TADLISTA_H
#define TADLISTA_H
#include "TADElemento.h"
//Estructura del nodo
typedef struct Nodo{
	tElem dato;
	struct Nodo *sig;
}tNodo;

//Estructura de la lista
typedef tNodo* tLista;

//Prototipos
tLista nuevaLista();
void agregarFinal(tLista *lis, tElem e);
void agregarInicio(tLista *lis, tElem e);
void agregarOrdenado(tLista *lis, tElem e);
void eliminarElem(tLista *lis, tElem e);
void mostrarLista(tLista lis);

#endif
