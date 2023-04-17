#include <stdio.h>
#include <stdlib.h>
#include "vectores.h"

int mostrarMenu();
void ejercicio1_1();
void ejercicio1_2();


int main()
{
    int eleccion;
    eleccion = mostrarMenu();

    while(eleccion != 0){

        switch(eleccion){
            case 1:
                ejercicio1_1();
                break;
             case 2:
                ejercicio1_2();
                break;
            default:
                printf("No existe esa opcion, intente nuevamente");
                break;

        }
        eleccion = mostrarMenu();
    }
    return 0;
}

//Mostrar menu
int mostrarMenu(){

    int eleccion;
    printf("\n\n******************** VECTORES *******************\n\n");
    printf("Opciones: \n");
    printf("\t1. Insertar un elemento en un arreglo de enteros, segun posicion dada.\n");
    printf("\t2. Insertar un elemento en un arreglo de enteros, manteniendo el orden ascendente de dicho arreglo.\n");
    printf("\t0. Salir\n\n");
    printf("Opcion elegida: ");
    scanf("%d", &eleccion);
    printf("\n\n");
    fflush(stdin);

    return eleccion;
}

//Ejercicio 1.1
void ejercicio1_1(){

    printf("EJERCICIO 1.1\n");

    int tam;
    printf("\nIngrese el tamano deseado del vector: ");
    scanf("%d", &tam);
    int vec[tam];
    llenarVector(vec,tam);
    int pos,
        elem,
        vecLeng = sizeof vec / sizeof vec[0];

        printf("\n\nIngrese el elemento que desea insertar en el vector: ");
        scanf("%d", &elem);
    do{
        printf("Ingrese la posicion donde desea que se inserte dicho elemento (posicion 1 a %d): ", vecLeng);
        scanf("%d", &pos);
    }while(pos < 1 || pos > vecLeng);

    printf("\nVector antes de insertar el elemento: \n");
    for(int i = 0; i < vecLeng; i++){
        printf("Pos %d: %d\n", (i+1), vec[i]);
    }

    insertarElementoSegunPos(vec, pos, elem);

     printf("\nVector despues de insertar el elemento en la posicion dada: \n");
    for(int i = 0; i < vecLeng; i++){
        printf("Pos %d: %d\n", (i+1), vec[i]);
    }
}

//Ejercicio 1.2
void ejercicio1_2(){

     printf("EJERCICIO 1.2\n");

    int tam;
    printf("\nIngrese el tamano deseado del vector: ");
    scanf("%d", &tam);
    int vec[tam];
    int ce = llenarVector(vec,tam);
    ordenamientoBurbuja(vec,ce);
    int elem,
        vecLeng = sizeof vec / sizeof vec[0];

    printf("\n\nIngrese el elemento que desea insertar en el vector: ");
    scanf("%d", &elem);

    printf("\nVector antes de insertar el elemento: \n");
    for(int i = 0; i < vecLeng; i++){
        printf("Pos %d: %d\n", (i+1), vec[i]);
    }

    BOOL resul = insertarElementoManteniendoOrden(vec, elem, ce, vecLeng);

    if(resul){
        printf("\nVector despues de insertar el elemento: \n");
        for(int i = 0; i < vecLeng; i++){
            printf("Pos %d: %d\n", (i+1), vec[i]);
        }
    }
    else{
        printf("Lo sentimos, no se ha podido insertar el elemento");
    }

}
