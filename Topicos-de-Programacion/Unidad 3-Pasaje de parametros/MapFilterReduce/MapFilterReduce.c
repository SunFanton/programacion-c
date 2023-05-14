#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "MapFilterReduce.h"

//REFERENCIAS:
/*
Vec: puntero al inicio del vector a recorrer
ce: cantidad de elementos del vector
tam: tamanio de cada elemento del vector (en bytes)
*/

//Funcion MAP
/* La funcion map ejerce una transformacion sobre cada uno de los
elementos del vector.
Dicha transformacion se lleva a cabo mediante una funcion, la
cual se pasa como puntero a funcion en los parametros de map*/
void* mi_map(void* vec, size_t ce, size_t tam, void(*accion)(void*)){

  void *inicio = vec;

  while(ce){
    accion(vec);
    vec += tam;
    ce--;
  }

  return inicio;
}

//Funcion REDUCE
/*La funcion reduce lleva a cabo una transformacion (o no) en cada uno de
los elementos de un vector, y "junta" o acumula los elementos
en un unico resultado, que es el que se retorna*/
void* mi_reduce(void* vec, size_t ce, size_t tam, void* valorRetorno,
             void(*freduccion)(void* vr, const void* e)){

  while(ce){
    freduccion(valorRetorno, vec);
    vec += tam;
    ce--;
  }

  return valorRetorno;
}

//Funcion FILTER
/*La funcion filter recorre cada elemento del vector, verifica
si cumple con una determinada condicion, y devuelve el vector
unicamente con los elementos que satisfacieron dicha condicion.
La mima se evalua mediante otra funcion que se pasa como parametro*/
void* mi_filter(void* vec, size_t *ce, size_t tam,
             int(*ffilter)(const void*)){

  //pl: puntero de lectura (para recorrer el vector)
  //pe: puntero de escritura (para guardar los elementos que cumplen con la condicion de filtro)
  void *pl = vec, *pe = vec;
  int ciclos = *ce;
  while(ciclos--){
    if(ffilter(pl)){
      if(pe != pl)
        memmove(pe,pl,tam);
      pe += tam;
    }
    else{
      (*ce)--;//El valor del puntero ce se disminuye siempre que un elemento no cumple con la condicion de filtro
    }
    pl += tam;
  }

  return vec;
}
