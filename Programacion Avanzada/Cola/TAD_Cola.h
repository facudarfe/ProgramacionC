#ifndef TAD_COLA_H
#define TAD_COLA_H
#define TAMMAX 100

typedef struct{
	int lis[TAMMAX];
	int tam;
}tCola;

tCola inicializaCola();
int estaVacia(tCola cola);
int estaLlena(tCola cola);
void push(tCola *cola, int elem);
int pop(tCola *cola);

#endif
