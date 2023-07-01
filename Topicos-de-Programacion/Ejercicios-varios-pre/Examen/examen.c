#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "examen.h"

void* _ordenarSeleccion(void* vec, int ce, unsigned tam, int cmp(const void*, const void*)){

    void *inicio = vec;
    void *fin = vec + (ce - 1) * tam;
    void *men;

     while (vec < fin) {
        men = vec;
        void *tmp = vec + tam;

        while (tmp <= fin) {
            if (cmp(tmp, men) < 0) {
                men = tmp;
            }
            tmp += tam;
        }

        if (vec != men) {
            char *aux = (char*)malloc(tam*sizeof(char));
            memmove(aux, vec, tam);
            memmove(vec, men, tam);
            memmove(men, aux, tam);
            free(aux);
        }

        vec += tam;
    }

    return inicio;
}
int _cmpEmpleadoNombre(const void* a, const void* b){
    tEmpleado *emp1 = (tEmpleado*)a;
    tEmpleado *emp2 = (tEmpleado*)b;

    return _cmp_str(emp1->nomYAp, emp2->nomYAp);
}

int _cmp_enteros(const void* a, const void* b){

    int *p1 = (int*)a;
    int *p2 = (int*)b;

    return *p1 - *p2;
}

int _cmp_str(const void* a, const void* b){

    char *cad1 = (char*)a;
    char *cad2 = (char*)b;
    char car1, car2;

    while(*cad1 && *cad2){
        car1 = *cad1;
        car2 = *cad2;

        if(car1 < car2)
            return -1;
        else if(car1 > car2)
            return 1;

        cad1++;
        cad2++;
    }
    if(*cad1)
        return 1;
    if(*cad2)
        return -1;

    return 0;
}

char* _mstrstr(const char *s1, const char *s2){
     if(*s2 == '\0')
        return NULL;

    char *cadenaPrinc = s1;

     while(*cadenaPrinc){
        char *c1 = cadenaPrinc;
        char *c2 = s2;

        while(*c1 && *c2 && *c1 == *c2){
            c1++;
            c2++;
        }

        if(*c2 == '\0'){
            return (char*)cadenaPrinc;
        }
        cadenaPrinc++;
     }
     return NULL;
}

int _contarCelulasVivasEnVecindario(int mat[][MAX_COL], int filas, int columnas, int fila, int columna){

    int contador = 0;
    for(int i = fila - 1; i <= fila + 1; i++){

        for(int j = columna - 1; j <= columna + 1; j++){

            if(i >= 0 && i < filas && j >= 0 && j < columnas){

                if(i != fila || j != columna){

                    if(mat[i][j] == 1)
                        contador++;
                }
            }
        }

    }
    return contador;
}
