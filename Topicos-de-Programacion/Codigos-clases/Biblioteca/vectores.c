#include "vectores.h"
#include<string.h>
#include<stdlib.h>
/**
    Metodo Seleccion
    Para cada posicion del vector
    1. Seleccionar el menor
    2. Intercambiarel menor con el actual
    3. Avanzar

*/

void * buscarMenor(const void * vec,
                   const void * fin,
                   size_t tam,
                   int (*cmp)(const void*, const void*));

void * orenarSeleccion(void * vec,
                     size_t ce,
                     size_t tam,
                     int (*cmp)(const void*, const void*))
{
    void * ini = vec,
         * fin = vec + (ce - 1) * tam,
         * men;

    while(vec < fin)
    {
        men = buscarMenor(vec, fin, tam, cmp);
        if (vec!=men)
        {
            intercambiar(vec, men, tam);
        }
        vec+=tam;
    }
    return ini;
}
/// >0 1ero mayor
/// <0 1ero menor
/// =0 iguales

void * buscarMenor(const void * vec,
                   const void * fin,
                   size_t tam,
                   int (*cmp)(const void*, const void*)
                   )
{
    const void * men = vec;
    vec+=tam;
    while(vec <= fin)
    {
        if (cmp(vec, men)<0)
        {
            men = vec;
        }
        vec+=tam;
    }
    return (void *) men;
}

//void intercambiar(void * e1, void * e2, size_t tam)
//{
//    static char aux[1000];
//    memcpy(aux, e1, tam);
//    memcpy(e1, e2, tam);
//    memcpy(e2, aux, tam);
//}


void intercambiar(void * e1, void * e2, size_t tam)
{
    void * aux = malloc(tam);
    if (!aux)
        return;

    memcpy(aux, e1, tam);
    memcpy(e1, e2, tam);
    memcpy(e2, aux, tam);

    free(aux);
}
