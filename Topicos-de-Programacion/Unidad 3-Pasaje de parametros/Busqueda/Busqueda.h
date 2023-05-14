#ifndef BUSQUEDA_H_INCLUDED
#define BUSQUEDA_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void* buscar(const void *vec, size_t ce, size_t tam, void *elem,
             int (*cmp)(const void *e, const void *v));

#endif // BUSQUEDA_H_INCLUDED
