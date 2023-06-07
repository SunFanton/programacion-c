#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ManejoArchivo.h"

int ingresarAlumnos(t_alumno *vec_alu, float *promGenerales){

    t_alumno *inicio = vec_alu;
    int cantIngresada = 0;
    char ingresar = 'S';
    do{
        fflush(stdin);
        printf("Ingrese el nombre del alumno: ");
        gets(vec_alu->nombre);
        fflush(stdin);
        printf("Ingrese el apellido del alumno: ");
        gets(vec_alu->apellido);
        fflush(stdin);
        ingresarParcialesYCalcularPromedio(vec_alu->parciales, &vec_alu->promedio);
        cantIngresada += 1;
        vec_alu->numAlu = cantIngresada;
        fflush(stdin);

        if(cantIngresada < 100){
            printf("\nDesea ingresar un nuevo alumno? S para si o N para no: ");
            scanf("%c", &ingresar);

            if(ingresar == 'S'){
                vec_alu++;
                printf("\n");
            }
        }

    }while(ingresar == 'S');

    vec_alu = inicio;
    return cantIngresada;
}

void ingresarParcialesYCalcularPromedio(float *parciales, float *promedio){

    float acumulador = 0;
    for(int i = 0; i < CANT_PARCIALES; i++){
        printf("Ingrese la nota del parcial %d: ", i+1);
        scanf("%f", parciales);
        acumulador += *parciales;
        parciales++;
    }
    *promedio = acumulador/(float)CANT_PARCIALES;
}

void mostrarAlumnosPorPantalla(t_alumno *vec_alu, int ce){

    t_alumno *inicio = vec_alu;
    for(int i = 0; i < ce; i++){
        printf("\n%2d %10s, %-10s %5.2f %5.2f %5.2f",
               vec_alu->numAlu,
               vec_alu->apellido,
               vec_alu->nombre,
               vec_alu->parciales[0],
               vec_alu->parciales[1],
               vec_alu->promedio);

        vec_alu++;
    }
     vec_alu = inicio;
     printf("\n");
}
