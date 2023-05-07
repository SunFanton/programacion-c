#include <stdio.h>
#include <stdlib.h>
#include "Fecha.h"

int mostrarMenu();
void ejercicio4_1();
void ejercicio4_2();
void ejercicio4_3();
void ejercicio4_4();
void ejercicio4_5();
void ejercicio4_6();

int main()
{
    int eleccion;
    eleccion = mostrarMenu();

    while(eleccion != 0){

        switch(eleccion){
            case 1:
                ejercicio4_1();
                break;
            case 2:
                ejercicio4_2();
                break;
            case 3:
                ejercicio4_3();
                break;
            case 4:
                ejercicio4_4();
                break;
            case 5:
                ejercicio4_5();
                break;
            case 6:
                ejercicio4_6();
                break;
            default:
                printf("No existe esa opcion, intente nuevamente");
                break;

        }
        eleccion = mostrarMenu();
    }

}

int mostrarMenu(){

    int eleccion;
    printf("\n\n*************** FUNCIONES CON FECHAS ***************\n\n");
    printf("Ingrese una opcion: \n");
    printf("\t1. Validar una fecha.\n");
    printf("\t2. Sumarle un dia a una fecha.\n");
    printf("\t3. Sumarle N dias a una fecha y obtener la nueva fecha.\n");
    printf("\t4. Restarle N dias a una fecha y obtener la nueva fecha.\n");
    printf("\t5. Obtener la diferencia en dias entre dos fechas.\n");
    printf("\t6. Obtener dia de la semana segun fecha.\n");
    printf("\t0. Salir.\n");
    printf("Opcion: ");
    scanf("%d", &eleccion);
    printf("\n\n");

    return eleccion;
}

void ejercicio4_1(){

    printf("\n\n----- VALIDAR FECHA -----\n\n");

    tFecha *ptrFecha = (tFecha*)malloc(1 * sizeof(tFecha));

    if(ptrFecha == NULL){
        printf("Memoria insuficiente para asginar dinamicamente");
        exit(0);
    }

    printf("Ingrese el dia: ");
    scanf("%d", &ptrFecha->dia);
    printf("Ingrese el mes: ");
    scanf("%d", &ptrFecha->mes);
    printf("Ingrese el anio: ");
    scanf("%d", &ptrFecha->anio);

    esFechaValida(ptrFecha) ?
        printf("\nLa fecha ingresada es valida") :
        printf("\nLa fecha ingresada NO es valida");

    free(ptrFecha);
}

void ejercicio4_2(){

    printf("\n\n----- SUMAR UN DIA A UNA FECHA -----\n\n");

    tFecha *ptrFecha = (tFecha*)malloc(1 * sizeof(tFecha));

    if(ptrFecha == NULL){
        printf("Memoria insuficiente para asginar dinamicamente");
        exit(0);
    }

    printf("Ingrese el dia: ");
    scanf("%d", &ptrFecha->dia);
    printf("Ingrese el mes: ");
    scanf("%d", &ptrFecha->mes);
    printf("Ingrese el anio: ");
    scanf("%d", &ptrFecha->anio);

    while(!esFechaValida(ptrFecha)){
        printf("\nNo has ingresado una fecha valida. Intenta nuevamente\n");
        printf("Ingrese el dia: ");
        scanf("%d", &ptrFecha->dia);
        printf("Ingrese el mes: ");
        scanf("%d", &ptrFecha->mes);
        printf("Ingrese el anio: ");
        scanf("%d", &ptrFecha->anio);
    }

    sumarUnDia(ptrFecha);

    printf("\nLa nueva fecha es: %d - %d - %d", ptrFecha->dia, ptrFecha->mes, ptrFecha->anio);

    free(ptrFecha);
}

void ejercicio4_3(){

    printf("\n\n----- SUMAR N DIAS A UNA FECHA -----\n\n");

    tFecha *ptrFecha = (tFecha*)malloc(1 * sizeof(tFecha));
    int n;

    if(ptrFecha == NULL){
        printf("Memoria insuficiente para asginar dinamicamente");
        exit(0);
    }

    printf("Ingrese el dia: ");
    scanf("%d", &ptrFecha->dia);
    printf("Ingrese el mes: ");
    scanf("%d", &ptrFecha->mes);
    printf("Ingrese el anio: ");
    scanf("%d", &ptrFecha->anio);
    printf("Ingrese la cantidad de dias a sumar a la fecha ingresada: ");
    scanf("%d", &n);

    while(!esFechaValida(ptrFecha)){
        printf("\nNo has ingresado una fecha valida. Intenta nuevamente\n");
        printf("Ingrese el dia: ");
        scanf("%d", &ptrFecha->dia);
        printf("Ingrese el mes: ");
        scanf("%d", &ptrFecha->mes);
        printf("Ingrese el anio: ");
        scanf("%d", &ptrFecha->anio);
        printf("Ingrese la cantidad de dias a sumar a la fecha ingresada: ");
        scanf("%d", &n);
    }

    sumarNDias(ptrFecha, n);

    printf("\nLa nueva fecha es: %d - %d - %d", ptrFecha->dia, ptrFecha->mes, ptrFecha->anio);

    free(ptrFecha);
}

void ejercicio4_4(){

    printf("\n\n----- RESTAR N DIAS A UNA FECHA -----\n\n");

    tFecha *ptrFecha = (tFecha*)malloc(1 * sizeof(tFecha));
    int n;

    if(ptrFecha == NULL){
        printf("Memoria insuficiente para asginar dinamicamente");
        exit(0);
    }

    printf("Ingrese el dia: ");
    scanf("%d", &ptrFecha->dia);
    printf("Ingrese el mes: ");
    scanf("%d", &ptrFecha->mes);
    printf("Ingrese el anio: ");
    scanf("%d", &ptrFecha->anio);
    printf("Ingrese la cantidad de dias a restar a la fecha ingresada: ");
    scanf("%d", &n);

    while(!esFechaValida(ptrFecha)){
        printf("\nNo has ingresado una fecha valida. Intenta nuevamente\n");
        printf("Ingrese el dia: ");
        scanf("%d", &ptrFecha->dia);
        printf("Ingrese el mes: ");
        scanf("%d", &ptrFecha->mes);
        printf("Ingrese el anio: ");
        scanf("%d", &ptrFecha->anio);
        printf("Ingrese la cantidad de dias a restar a la fecha ingresada: ");
        scanf("%d", &n);
    }

    restarNDias(ptrFecha, n);

    printf("\nLa nueva fecha es: %d - %d - %d", ptrFecha->dia, ptrFecha->mes, ptrFecha->anio);

    free(ptrFecha);
}

void ejercicio4_5(){

    printf("\n\n----- RESTAR N DIAS A UNA FECHA -----\n\n");

    tFecha *ptrFecha1 = (tFecha*)malloc(1 * sizeof(tFecha));
    tFecha *ptrFecha2 = (tFecha*)malloc(1 * sizeof(tFecha));

    if(ptrFecha1 == NULL || ptrFecha2 == NULL){
        printf("Memoria insuficiente para asginar dinamicamente");
        exit(0);
    }

    printf("Fecha 1: \n");
    printf("Ingrese el dia: ");
    scanf("%d", &ptrFecha1->dia);
    printf("Ingrese el mes: ");
    scanf("%d", &ptrFecha1->mes);
    printf("Ingrese el anio: ");
    scanf("%d", &ptrFecha1->anio);

    while(!esFechaValida(ptrFecha1)){
        printf("\nNo has ingresado una fecha valida. Intenta nuevamente\n");
        printf("Ingrese el dia: ");
        scanf("%d", &ptrFecha1->dia);
        printf("Ingrese el mes: ");
        scanf("%d", &ptrFecha1->mes);
        printf("Ingrese el anio: ");
        scanf("%d", &ptrFecha1->anio);
    }

    printf("\nFecha 2: \n");
    printf("Ingrese el dia: ");
    scanf("%d", &ptrFecha2->dia);
    printf("Ingrese el mes: ");
    scanf("%d", &ptrFecha2->mes);
    printf("Ingrese el anio: ");
    scanf("%d", &ptrFecha2->anio);

    while(!esFechaValida(ptrFecha2)){
        printf("\nNo has ingresado una fecha valida. Intenta nuevamente\n");
        printf("Ingrese el dia: ");
        scanf("%d", &ptrFecha2->dia);
        printf("Ingrese el mes: ");
        scanf("%d", &ptrFecha2->mes);
        printf("Ingrese el anio: ");
        scanf("%d", &ptrFecha2->anio);
    }

    printf("\nLa diferencia de dias entre ambas fechas es de: %d", diasDiferenciaEntreFechas(ptrFecha1, ptrFecha2));

    free(ptrFecha1);
    free(ptrFecha2);
}

void ejercicio4_6(){

    printf("\n\n----- OBTENER DIA DE LA SEMANA -----\n\n");

    tFecha *ptrFecha = (tFecha*)malloc(1 * sizeof(tFecha));

    if(ptrFecha == NULL){
        printf("Memoria insuficiente para asginar dinamicamente");
        exit(0);
    }

    printf("Ingrese el dia: ");
    scanf("%d", &ptrFecha->dia);
    printf("Ingrese el mes: ");
    scanf("%d", &ptrFecha->mes);
    printf("Ingrese el anio: ");
    scanf("%d", &ptrFecha->anio);

    while(!esFechaValida(ptrFecha)){
        printf("\nNo has ingresado una fecha valida. Intenta nuevamente\n");
        printf("Ingrese el dia: ");
        scanf("%d", &ptrFecha->dia);
        printf("Ingrese el mes: ");
        scanf("%d", &ptrFecha->mes);
        printf("Ingrese el anio: ");
        scanf("%d", &ptrFecha->anio);
    }

    tDiaSemana dias[7] = {{0, "Domingo"},
                          {1, "Lunes"},
                          {2, "Martes"},
                          {3, "Miercoles"},
                          {4, "Jueves"},
                          {5, "Viernes"},
                          {6, "Sabado"}};
    printf("\nEl dia de la semana es: %s", dias[obtenerDiaSemana(ptrFecha)].dia);

    free(ptrFecha);
}
