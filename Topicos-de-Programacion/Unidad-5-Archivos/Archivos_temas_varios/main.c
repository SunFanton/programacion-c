#include <stdio.h>
#include <stdlib.h>
#include "Archivos.h"
#include "OrdSeleccion.h"

int compararDni(void*, void*);

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

    ordenarSeleccionGenerico(alumnos1, sizeof(alumnos1)/sizeof(t_alumno), sizeof(t_alumno), compararDni);
    ordenarSeleccionGenerico(alumnos2, sizeof(alumnos2)/sizeof(t_alumno), sizeof(t_alumno), compararDni);

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

    printf("\n\nMostrando archivo de texto 1 con longitud variable");
    if(!mostrarArchivoTextoLongVariable("ArchivoTexto1LongVariable.txt")){
         printf("\nNo se ha podido mostrar el archivo de texto 1");
        return 1;
    }

    printf("\n\nMostrando archivo de texto 1 con longitud fija");
    if(!mostrarArchivoTextoLongFija("ArchivoTexto1LongFija.txt")){
         printf("\nNo se ha podido mostrar el archivo de texto 1");
        return 1;
    }

    printf("\n\n------------------------------------------------------\n");

    //Archivo binario a texto
    printf("\nConvertir archivo binario 1 a archivo de texto con longitud variable");
    if(!archivoAlumnoBinarioATextoLongVariable("ArchivoBin1.dat")){
         printf("\nNo se han podido abrir los archivos");
        return 1;
    }

    printf("\n\n------------------------------------------------------\n");

    //Archivo texto a binario
    printf("\nConvertir archivo texto 1 con longitud variable a archivo binario");
    if(!archivoAlumnoTextoLongVariableABinario("ArchivoTexto1LongVariable.txt")){
         printf("\nNo se han podido abrir los archivos");
        return 1;
    }

    printf("\n\n------------------------------------------------------\n");

    //Merge (union e interseccion) con dos archivos binarios


    //Indices (usando archivos binarios)


    return 0;
}

int compararDni(void *ptr1, void *ptr2){

    t_alumno *alumno1 = (t_alumno*)ptr1;
    t_alumno *alumno2 = (t_alumno*)ptr2;

    return alumno1->dni-alumno2->dni;
}

