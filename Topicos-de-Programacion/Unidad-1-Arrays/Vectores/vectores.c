#include "vectores.h"

void ordenamientoBurbuja(int *vec, int cant){

    int i = 1,
        aux;

    int *fin;
    int *inicio = vec;

    while(i < cant){
        fin = vec + cant - i;

        while(vec < fin){
            if(*vec > *(vec+1)){
                aux = *vec;
                *vec = *(vec+1);
                *(vec+1) = aux;
            }
            vec++;
        }
        vec = inicio;
        i++;
    }
}

int llenarVector(int *vec, int cant){

    int cantAIngresar;
    int *fin = vec + cant - 1;

    printf("Ingrese cuantos elementos quiere insertar en el vector ahora mismo: ");
    scanf("%d", &cantAIngresar);

    while(cantAIngresar < 1 || cantAIngresar > cant){
        printf("\nLo sentimos, debe ingresar minimo 1 elementos y maximo %d elementos. Intente nuevamente: ", cant);
        scanf("%d", &cantAIngresar);
    }

    for(int i = 0; i < cantAIngresar; i++){
        printf("Elemento %d: ", (i+1));
        scanf("%d", vec);
        vec++;
    }

    if(cantAIngresar < cant){
        while(vec <= fin){
            *vec = 0;
            vec++;
        }
    }

    return cantAIngresar;
}


void insertarElementoSegunPos(int *vec, int pos, int elem){

    vec = vec + pos - 1;
    *vec = elem;
}

BOOL insertarElementoManteniendoOrden(int *vec, int elem, int cantElem, int tam){

    int *fin = vec + cantElem - 1;

    if(cantElem == tam)
        return FALSE;

    while(*vec < elem) {
        vec++;
    }

    while(fin >= vec){
        *(fin+1) = *fin;
        fin--;
    }
    *vec = elem;
    return TRUE;
}
