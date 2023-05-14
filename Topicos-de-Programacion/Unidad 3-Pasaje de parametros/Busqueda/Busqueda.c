#include "Busqueda.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void* buscar(const void *vec, size_t ce, size_t tam, void *elem,
             int (*cmp)(const void *e, const void *v)){

    while(ce){
        if(cmp(elem, vec) == 0) //Si los dos elementos son iguales, el elemento fue encontrado
            return vec;
        ce--;
        vec += tam;
    }
    return NULL; //Si el elemento buscado no fue encontrado en el vector
}
