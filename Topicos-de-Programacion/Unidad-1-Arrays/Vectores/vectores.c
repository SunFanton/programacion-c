#include "vectores.h"

int llenarVector(int *vec, int cant){

    int ingresados = 0,
        pos = 0,
        continuar = TRUE;

    do{
        printf("Ingrese un numero para la posicion %d del vector: ", (pos + 1));
        scanf("%d", vec);
        pos++;
        ingresados++;
        vec++;
        if(ingresados < cant){
            printf("Desea seguir ingresando datos? 1 para si, 0 para no: ");
            scanf("%d", &continuar);
        }
    }while(continuar && ingresados < cant);

    if(ingresados < cant){
        for(int i = pos; i < cant; i++){
            *vec = 0;
            vec++;
        }
    }
    return ingresados;

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
