#include <stdio.h>
#include <stdlib.h>
#include "Archivos.h"

int main()
{
    t_alumno alumnos1[] = {
                            {"Matias Gomez", 39789506, 1234, 26, {1,11,2019}, 7},
                            {"Luciana Martinez", 42456789, 5435, 20, {12,9,2021}, 6.5},
                            {"Julian Perez", 40567899, 3452, 22, {15,6,2020}, 5.5},
                            {"Analia Marcel", 40567322, 9865, 22, {2,3,2021}, 8.5},
                            {"Silvia Garcia", 34567321, 2345, 35, {12,5,2017}, 9},
                        };
    t_alumno alumnos2[] = {
                            {"Matias Gomez", 39789506, 1234, 26, {1,11,2019}, 7},
                            {"Angela Torres", 41378947, 3452, 23, {20,6,2022}, 4.5},
                            {"Tomas Gonzalez", 36847806, 5543, 33, {19,8,2019}, 6},
                            {"Analia Marcel", 40567322, 9865, 22, {2,3,2021}, 8.5},
                            {"Emilio Trevinio", 43578498, 8764, 19, {23,7,2022}, 7.5},
                        };

    //Guardar en archivo binario y mostrar
    printf("\nGuardando archivo binario 1");
    if(!grabarArchivoBinario("ArchivoBin1.dat", alumnos1, sizeof(alumnos1))){
        printf("\nNo se ha podido grabar el archivo binario 1");
        return 1;
    }

    printf("\nGuardando archivo binario 2");
    if(!grabarArchivoBinario("ArchivoBin2.dat", alumnos2, sizeof(alumnos2))){
        printf("\nNo se ha podido grabar el archivo binario 1");
        return 1;
    }

    printf("\n\nMostrando archivo binario 1");
    if(!mostrarArchivoBinarioAlumno("ArchivoBin1.dat")){
        printf("\nNo se ha podido leer el archivo binario 1");
        return 1;
    }

    printf("\n\nMostrando archivo binario 2");
    if(!mostrarArchivoBinarioAlumno("ArchivoBin2.dat")){
        printf("\nNo se ha podido leer el archivo binario 2");
        return 1;
    }

    printf("\n\n------------------------------------------------------\n");

    //Guardar en archivo de texto con longitud variabe y fija, y mostrar
    printf("\nGuardando archivo de texto 1 con longitud variable");
    if(!guardarArchivoTextoLongVariable("ArchivoTexto1LongVariable.txt", alumnos1, sizeof(alumnos1)/sizeof(t_alumno))){
        printf("\nNo se ha podido grabar el archivo de texto 1");
        return 1;
    }

     printf("\nGuardando archivo de texto 1 con longitud fija");
    if(!guardarArchivoTextoLongFija("ArchivoTexto1LongFija.txt", alumnos1, sizeof(alumnos1)/sizeof(t_alumno))){
        printf("\nNo se ha podido grabar el archivo de texto 1");
        return 1;
    }

    //Archivo binario a texto


    //Archivo texto a binario


    //Merge (union e interseccion) con dos archivos binarios


    //Indices (usando archivos binarios)


    return 0;
}

