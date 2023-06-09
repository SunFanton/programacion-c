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
        printf("Ingrese el apellido y nombre del alumno, separados por coma: ");
        gets(vec_alu->apNom);
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
        else{
            ingresar = 'N';
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

    //Impresion en pantalla usando campos de longitud fija
    for(int i = 0; i < ce; i++){
        printf("\n%2d %-20s %5.2f %5.2f %5.2f",
               vec_alu->numAlu,
               vec_alu->apNom,
               vec_alu->parciales[0],
               vec_alu->parciales[1],
               vec_alu->promedio);

        vec_alu++;
    }
     vec_alu = inicio;
     printf("\n");
}

int cargarArchivoTextoAlumnosLongitudFija(char *path, t_alumno *vec_alu, int cantIngresada){

    FILE *pf = fopen(path, "wt");
    if(!pf){
        return 0;
    }

    float sumaParciales1 = 0,
          sumaParciales2 = 0,
          sumaPromedios = 0,
          promParciales1,
          promParciales2,
          promGeneral;

    //Escritura usando campos de longitud fija
    fprintf(pf, "   Apellido/s, Nombre/s    P. 1  P. 2 Prome\n");
    fprintf(pf, "   ====================   ===== ===== =====\n");
    fprintf(pf, "                                           \n");

    for(int i = 0; i < cantIngresada; i++){
        fprintf(pf, "%2d %-20s   %5.2f %5.2f %5.2f\n",
                    vec_alu[i].numAlu,
                    vec_alu[i].apNom,
                    vec_alu[i].parciales[0],
                    vec_alu[i].parciales[1],
                    vec_alu[i].promedio);

        sumaParciales1 += vec_alu[i].parciales[0];
        sumaParciales2 += vec_alu[i].parciales[1];
        sumaPromedios += vec_alu[i].promedio;

        if(vec_alu[i].numAlu % 2 == 0){
            fprintf(pf, "                                           \n");
            fprintf(pf, "   Apellido/s, Nombre/s    P. 1  P. 2 Prome\n");
            fprintf(pf, "   ====================   ===== ===== =====\n");
            fprintf(pf, "                                           \n");
        }
    }

    promParciales1 = sumaParciales1/cantIngresada;
    promParciales2 = sumaParciales2/cantIngresada;
    promGeneral = sumaPromedios/cantIngresada;

    fprintf(pf, "                                           \n");
    fprintf(pf, "                          ===== ===== =====\n");
    fprintf(pf, "                                           \n");
    fprintf(pf, "                          %5.2f %5.2f %5.2f",
                promParciales1,
                promParciales2,
                promGeneral);

    fclose(pf);

    return 1;
}
