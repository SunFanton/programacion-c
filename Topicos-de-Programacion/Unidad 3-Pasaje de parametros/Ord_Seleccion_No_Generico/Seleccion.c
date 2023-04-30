#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Seleccion.h"

///ALGORITMO DE ORDENAMIENTO (PASOS):
//1) Buscar menor
//2) Intercambiar menor encontrado con la posicion actual
//3) Avanzo
//4) Repito hasta terminar de recorrer todos los elementos

///ALGORITMO DE ORDENAMIENTO PARA ENTEROS

int *buscarMenorEntero(int *vec, int *fin){
    int *men = vec;
    vec++;

    while(vec <= fin){
        if(*vec < *men){
            men = vec;
        }
        vec++;
    }
    return men;
}

void intercambiarEnteros(int *vec1, int *vec2){
    int aux = *vec1;
    *vec1 = *vec2;
    *vec2 = aux;
}

void ordSeleccionEntero(int *vec, int ce){
    int *inicio = vec,
        *fin = vec + (ce - 1),
        *men;

    while(vec < fin){
        men = buscarMenorEntero(vec, fin);
        if(vec != men){
            intercambiarEnteros(vec, men);
        }
        vec++;
    }
}


///ALGORITMO DE ORDENAMIENTO PARA PERSONAS (STRUCT)

tPersona *buscarMenorPersonaPorDni(tPersona *vec, tPersona *fin){
    tPersona *menPorDni = vec;
    vec++;
    while(vec <= fin){
        if(vec->dni < menPorDni->dni){
            menPorDni = vec;
        }
        vec++;
    }
    return menPorDni;
}

tPersona *buscarMenorPersonaPorApellidoYNombre(tPersona *vec, tPersona *fin){
    tPersona *menPorApellidoYNombre = vec;
    vec++;
    int comparacionAp,
        comparacionNom;
    while(vec <= fin){
        comparacionAp = strcmpi(vec->apellido, menPorApellidoYNombre->apellido);
        comparacionNom =  strcmpi(vec->nombres, menPorApellidoYNombre->nombres);
        if(comparacionAp < 0 || (comparacionAp == 0 && comparacionNom < 0)){
            menPorApellidoYNombre = vec;
        }
        vec++;
    }
    return menPorApellidoYNombre;
}

tPersona *buscarMenorPersonaPorPeso(tPersona *vec, tPersona *fin){
    tPersona *menPorDni = vec;
    vec++;
    while(vec <= fin){
        if(vec->peso < menPorDni->peso){
            menPorDni = vec;
        }
        vec++;
    }
    return menPorDni;
}

void intercambiarPersonas(tPersona *vec1, tPersona *vec2){
    tPersona aux = *vec1;
    *vec1 = *vec2;
    *vec2 = aux;
}

void ordSeleccionPersonaPorDni(tPersona *vec, int ce){
    tPersona *inicio = vec,
        *fin = vec + (ce - 1),
        *men;

    while(vec < fin){
        men = buscarMenorPersonaPorDni(vec, fin);
        if(vec != men){
            intercambiarPersonas(vec, men);
        }
        vec++;
    }
}

void ordSeleccionPersonaPorApellidoYNombre(tPersona *vec, int ce){
    tPersona *inicio = vec,
        *fin = vec + (ce - 1),
        *men;

    while(vec < fin){
        men = buscarMenorPersonaPorApellidoYNombre(vec, fin);
        if(vec != men){
            intercambiarPersonas(vec, men);
        }
        vec++;
    }
}

void ordSeleccionPersonaPorPeso(tPersona *vec, int ce){
     tPersona *inicio = vec,
        *fin = vec + (ce - 1),
        *men;

    while(vec < fin){
        men = buscarMenorPersonaPorPeso(vec, fin);
        if(vec != men){
            intercambiarPersonas(vec, men);
        }
        vec++;
    }
}
