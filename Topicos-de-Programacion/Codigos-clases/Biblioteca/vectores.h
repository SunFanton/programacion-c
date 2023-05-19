#ifndef VECTORES_H_INCLUDED
#define VECTORES_H_INCLUDED

#include<stddef.h>

void intercambiar(void * e1, void * e2, size_t tam);

void * orenarSeleccion(void * vec,
                       size_t ce,
                       size_t tam,
                       int (*cmp)(const void*, const void*));


#endif // VECTORES_H_INCLUDED
