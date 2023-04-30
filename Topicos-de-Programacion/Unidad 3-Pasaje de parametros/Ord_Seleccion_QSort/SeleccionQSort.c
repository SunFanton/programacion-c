#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SeleccionQSort.h"


///FUNCIONES DE COMPARACION QUE SE REESCRIBEN SEGUN EL TIPO DE DATO A COMPARAR

int compararEntero(const void *p1, const void *p2){
    const int *pInt1 = (const int *)p1;
    const int *pInt2 = (const int *)p2;
    return *pInt1 - *pInt2;
}

int compararPersonaDni(const void *p1, const void *p2){
    const tPersona *pPers1 = (const tPersona *)p1;
    const tPersona *pPers2 = (const tPersona *)p2;
    return pPers1->dni - pPers2->dni;
}

int compararPersonaApellidoYNombre(const void *p1, const void *p2){
    const tPersona *pPers1 = (const tPersona *)p1;
    const tPersona *pPers2 = (const tPersona *)p2;
    int comparacionAp = strcmpi(pPers1->apellido, pPers2->apellido);
    int comparacionNom = strcmpi(pPers1->nombres, pPers2->nombres);

    if(comparacionAp != 0)
        return comparacionAp;
    else
        return comparacionNom;
}

int compararPersonaPeso(const void *p1, const void *p2){
    const tPersona *pPers1 = (const tPersona *)p1;
    const tPersona *pPers2 = (const tPersona *)p2;
    return pPers1->peso - pPers2->peso;
}
