#ifndef TADELEMENTO_H
#define TADELEMENTO_H

typedef struct{
	float x, y;
}tElem;

tElem nuevoElem();
int comparaElem(tElem e1, tElem e2);
void mostrarElem(tElem e);

#endif
