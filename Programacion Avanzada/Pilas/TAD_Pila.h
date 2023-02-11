#ifndef TAD_PILA_H
#define TAD_PILA_H
#define TAMMAX 100

typedef struct{
	int lis[TAMMAX];
	int tam;
}tPila;

tPila inicializaPila();
int estaVacia(tPila pila);
int estaLlena(tPila pila);
void push(tPila *pila, int elem);
int pop(tPila *pila);

#endif
