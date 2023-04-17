#ifndef VECTORES_H_INCLUDED
#define VECTORES_H_INCLUDED
#include <stdio.h>
#define TRUE 1
#define FALSE 0

typedef int BOOL;

void ordenamientoBurbuja(int *vec, int cant);
int llenarVector(int *vec, int cant);
void insertarElementoSegunPos(int *vec, int pos, int elem);
BOOL insertarElementoManteniendoOrden(int *vec, int elem, int cantElem, int tam);

#endif // VECTORES_H_INCLUDED
