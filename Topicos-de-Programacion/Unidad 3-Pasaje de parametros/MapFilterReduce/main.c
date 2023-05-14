#include <stdio.h>
#include <stdlib.h>
#include "MapFilterReduce.h"

void sumarUno(void*);
void acumularEntero(void*, const void*);
int esPar(const void*);

int main()
{
    //---------------------------------------------------------

    ///FUNCION MAP
    printf("FUNCION MAP\n");
    int vec[] = {1,2,3,4};
    int ce = sizeof(vec)/sizeof(vec[0]);
    int tam = sizeof(vec[0]);

    printf("Antes de map\n");
    for(int i = 0; i < ce; i++){
      printf("Vec[%d]: %d\n", i, vec[i]);
    }

    mi_map(vec,ce,tam,sumarUno);

    printf("Despues de map\n");
    for(int i = 0; i < ce; i++){
      printf("Vec[%d]: %d\n", i, vec[i]);
    }

    printf("\n\n");

    //---------------------------------------------------------

    ///FUNCION REDUCE
    printf("FUNCION REDUCE\n");
    int r = 0;
    int *resul = &r;
    //Tener en cuenta que en este caso estoy utilizando vec con los ultimos valores
    //que contiene despues de aplicar la funcion map
    mi_reduce(vec,ce,tam,resul,acumularEntero);

    printf("Despues de reduce\n");
    printf("Resultado de reduce: %d", *resul);

    printf("\n\n");

    //---------------------------------------------------------

    ///FUNCION FILTER
    printf("FUNCION FILTER\n");
    int vec2[] = {1,2,3,4,5,6};
    size_t ce2 = sizeof(vec2)/sizeof(vec2[0]);
    int tam2 = sizeof(vec2[0]);

    printf("Antes de filter\n");
    for(int i = 0; i < ce2; i++){
      printf("Vec[%d]: %d\n", i, vec2[i]);
    }

    mi_filter(vec2,&ce2,tam2,esPar);

    printf("Despues de filter\n");
    for(int i = 0; i < ce2; i++){
      printf("Vec[%d]: %d\n", i, vec2[i]);
    }

    return 0;
}

void sumarUno(void* vec){
  int *v_ent = (int*)vec;
  *v_ent += 1;
}

void acumularEntero(void* vr, const void* e){
  int *vrInt = (int*)vr;
  int *eInt = (int*) e;
  *vrInt += *eInt;
}

int esPar(const void* v){
  int *vInt = (int*)v;
  return *vInt % 2 == 0;
}
