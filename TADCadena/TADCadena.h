#ifndef TADCADENA_H
#define TADCADENA_H
#define TMAX 30

/*Estructura del TAD*/
typedef char tCadena[TMAX];

/*Operaciones del TAD*/
void scanString(tCadena s);
int comparaCadena(tCadena s1, tCadena s2);
char devolverCaracter(tCadena s1, int p);
void mostrarCadena(tCadena s);

#endif
