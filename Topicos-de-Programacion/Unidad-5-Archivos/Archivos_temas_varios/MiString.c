#include "MiString.h"
#include <stdio.h>
#include <stdlib.h>

size_t miStrlen(const char *cad){

    size_t tam = 0;
    char *cadCopy = cad;
    while(*cadCopy != '\0'){
        tam++;
        cadCopy++;
    }
    return tam;
}

char *miStrchr(const char *cad, int caracter){

     char *cadCopy = cad;
     while (cadCopy != NULL && *cadCopy != '\0') {
        if (*cadCopy == (char)caracter) {
            return cadCopy;
        }
        cadCopy++;
    }
    return NULL;
}

char *miStrrchr(const char *cad, int caracter){

    size_t longitud = miStrlen(cad);
    char *cadCopy = cad;
    char *aux = cadCopy + longitud - 1;

    while(aux >= cadCopy){
        if(*aux == (char)caracter)
            return aux;
        aux--;
    }
    return NULL;
}
