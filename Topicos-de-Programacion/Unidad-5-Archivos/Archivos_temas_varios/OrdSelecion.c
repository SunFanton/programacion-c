#include "OrdSeleccion.h"
#include <stdlib.h>

void *miMemcpy(void *destino, void *origen, size_t tam){

    char *dest = (char*)destino;
    char *ori = (char*)origen;

    for(size_t i = 0; i < tam; i++){
        dest[i] = ori[i];
    }
    return dest;
}

void intercambiar(void *ptr1, void *ptr2, size_t tam){
    char *aux = (char*)malloc(tam);
    miMemcpy(aux,ptr1,tam);
    miMemcpy(ptr1,ptr2,tam);
    miMemcpy(ptr2,aux,tam);
    free(aux);
}

void *buscarMenor(void *ptr, void *ptrFin, size_t tam, int(*compara)(void *, void *)){

    void *menor = ptr;
    ptr += tam;

    while(ptr <= ptrFin){
        if(compara(ptr, menor) < 0){
            menor = ptr;
        }
        ptr += tam;
    }
    return menor;
}

void *ordenarSeleccionGenerico(void *ptr, size_t ce, size_t tam, int(*compara)(void *, void *)){

    void *inicio = ptr,
         *fin = ptr + (ce - 1)*tam,
         *menor;

    while(ptr < fin){
        menor = buscarMenor(ptr,fin,tam,compara);
        if(menor != ptr)
            intercambiar(ptr,menor,tam);
        ptr += tam;
    }
    return inicio;
}
