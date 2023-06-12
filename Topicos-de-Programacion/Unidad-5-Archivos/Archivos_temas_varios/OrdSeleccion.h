#ifndef ORDSELECCION_H_INCLUDED
#define ORDSELECCION_H_INCLUDED
#include <stdlib.h>

void *miMemcpy(void *destino, void *origen, size_t tam);
void intercambiar(void *ptr1, void *ptr2, size_t tam);
void *buscarMenor(void *ptrInicio, void *ptrFin, size_t tam, int(*compara)(void *, void *));
void *ordenarSeleccionGenerico(void *ptr, size_t ce, size_t tam, int(*compara)(void *, void *));

#endif // ORDSELECCION_H_INCLUDED
