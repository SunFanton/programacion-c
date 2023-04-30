#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SeleccionGenerico.h"

/*
Ejercicio de estudio e implementacion propia de la funcion qsort de la libreria stdlib.h

Se implementa algoritmo de ordenamiento por seleccion, cuyos pasos recordemos consta de los
siguientes:
1) Buscar el menor
2) Intercambiar valores entre el menor encontrado y el valor de la posicion actual
3) Repetir hasta terminar el recorrido en el vector

Estos pasos los encontramos en la funcion ordSeleccion, la cual recibe 4 parametros:
- el puntero a la primer posicion del vector a ordenar
- la cantidad de elementos del vector
- el tamaño en bytes de cada elemento del vector
- una funcion que se utilizara mas adelante al buscar el menor elemento, y se pasara como parametro
a otra funcion dentro de ordSeleccion. Tiene cierta similitud a una funcion callback de Javascript
Aclaracion: int significa que esa funcion devuelve un entero, (*comparar) es el nombre con el que
se reconocerá esa funcion dentro de ordSeleccion cuando se la invoque o se la pase como parametro
a otra funcion, (const void*, const void*) son los parametros especificados donde se encuentre definida comparar()

Notese que el puntero recibido es de tipo void, es decir, no es de ningun tipo en particular,
lo que permite aplicar de manera generica ordSeleccion para vectores de distinto tipo. De ahi que
se deba pasar la cantidad de elementos y el tamaño de cada elemento, para saber en cuantos bytes
se debe mover el puntero generico

La funcion ordSeleccion implementa a su vez dos funciones genericas: buscarMenor e intercambiar

La funcion buscarMenor recibe:
- Puntero generico al inicio de donde queremos empezar a buscar el menor
- Puntero generico al final del vector
- Tamaño en bytes que debera moverse el primer vector generico para buscar en cada posicion
- Funcion que se utilizara en el ciclo de recorrido para comparar el menor entre dos valores
Esta ultima funcion sera la UNICA que debera definirse para cada tipo de dato, pues si bien recibe
como parametros dos punteros genericos, en su implementacion para hacer la compararcion se lleva a cabo
un casteo de dichos punteros al tipo de dato correspondiente (por ej, compararEntero, donde se
castean los punteros genericos a punteros de tipo int)

La funcion intercambiar recibe:
- Dos punteros genericos
- Un parametro del tamaño en bytes del elemento correspondiente al que apuntan los punteros
En la funcion, se declara un vector auxiliar de char (1 char = 1 byte) de 10000 chars, lo que implica que se reserva
de manera estatica (en tiempo de compilacion, 1 sola vez, por eso static), un espacio en memoria
lo suficientemente grande para hacer el intercambio del contenido de ambos punteros

**/

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

///GENERICOS (ESTOS NO CAMBIAN)

void *buscarMenor(void *vec, void *fin, size_t tam, int (*comparar)(const void *p1, const void *p2)){
    void *men = vec;
    vec += tam;

    while(vec <= fin){
        if(comparar(vec,men) < 0){
            men = vec;
        }
        vec += tam;
    }
    return men;
}

void intercambiar(void *p1, void *p2, size_t tam){
    static char aux[10000];
    memcpy(aux,p1,tam);
    memcpy(p1,p2,tam);
    memcpy(p2,aux,tam);
}

void *ordSeleccion(void *vec, size_t ce, size_t tam, int (*comparar)(const void *p1, const void *p2)){
    void *inicio = vec,
         *fin = vec + (ce - 1)*tam,
         *men;

    while(vec < fin){
        men = buscarMenor(vec, fin, tam, comparar);
        if(vec != men){
            intercambiar(vec, men, tam);
        }
        vec += tam;
    }
    return inicio;
}
