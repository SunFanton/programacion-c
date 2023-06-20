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
                            {"Angela Torres", 41378947, 3490, 23, {20,6,2022}, 4.5},
                            {"Tomas Gonzalez", 36847806, 5543, 33, {19,8,2019}, 6},
                            {"Analia Marcel", 40567322, 9865, 22, {2,3,2021}, 8.5},
                            {"Emilio Trevinio", 43578498, 8764, 19, {23,7,2022}, 7.5},
                        };

    t_alumno alumnos3[] = {
                            {"Sandra Gomez", 45678987, 3456, 18, {2,2,2022}, 8.5},
                            {"Matias Freire", 34562780, 4231, 34, {14,5,2009}, 6.5},
                            {"Tamara Diaz", 41567287, 2341, 23, {25,3,2019}, 5}
                        };

    //Ordenamos de antemano ambas estructuras en este caso por dni (para usar con el merge y los indices)
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

     printf("\n\nMostrando archivo de texto 1 con longitud variable usando MiString.h");
    if(!mostrarArchivoTextoLongVariableConStringH("ArchivoTexto1LongVariable.txt")){
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
    //Union
    printf("\nRealizamos el merge union de dos archivos binarios");
    if(!mergeArchivosBinAlumnoUnion("ArchivoBin1.dat", "ArchivoBin2.dat", "Alu-union.dat")){
        printf("\nNo se han podido abrir los archivos");
        return 1;
    }
     printf("\n\nMostrando archivo binario resultado");
    if(!mostrarArchivoBinarioAlumno("Alu-union.dat")){
        printf("\nNo se ha podido leer el archivo binario resultado");
        return 1;
    }

    printf("\n\n------------------------------------------------------\n");

     //Interseccion
    printf("\nRealizamos el merge interseccion de dos archivos binarios");
    if(!mergeArchivosBinAlumnoInterseccion("ArchivoBin1.dat", "ArchivoBin2.dat", "Alu-interseccion.dat")){
        printf("\nNo se han podido abrir los archivos");
        return 1;
    }
     printf("\n\nMostrando archivo binario resultado");
    if(!mostrarArchivoBinarioAlumno("Alu-interseccion.dat")){
        printf("\nNo se ha podido leer el archivo binario resultado");
        return 1;
    }

    printf("\n\n------------------------------------------------------\n");


    //Indices (usando archivos binarios)
    printf("\nGuardando archivo binario maestro para indices");
    if(!grabarArchivoBinario("ArchivoBinMaestro.dat", alumnos3, sizeof(alumnos3))){
        printf("\nNo se ha podido grabar el archivo binario maestro");
        return 1;
    }

    printf("\n\nGuardando archivo binario de indices");
    if(!construirIndice("ArchivoBinMaestro.dat", "ArchivoBinIndices.idx")){
        printf("\nNo se ha podido grabar el archivo binario de indices");
        return 1;
    }

    printf("\n\nOrdenando por clave el archivo binario de indices");
    if(!ordenarArchivoIndices("ArchivoBinIndices.idx")){
        printf("\nNo se ha podido ordenar el archivo de indices");
        return 1;
    }

    printf("\n\nMostrando el archivo maestro");
    if(!mostrarArchivoBinarioAlumno("ArchivoBinMaestro.dat")){
        printf("\nNo se ha podido mostrar el archivo binario maestro");
        return 1;
    }

    printf("\n\nMostrando el archivo de indices");
    if(!mostrarArchivoBinarioIndices("ArchivoBinIndices.idx")){
        printf("\nNo se ha podido mostrar el archivo binario de indices");
        return 1;
    }


    printf("\n\nBuscando alumno");
    if(!buscarAlumnoPorArchivoIndices("ArchivoBinIndices.idx", "ArchivoBinMaestro.dat", 34562780)){
        printf("\nNo se ha podido buscar el alumno");
        return 1;
    }

    printf("\n\nBuscando alumno");
    if(!buscarAlumnoPorArchivoIndices("ArchivoBinIndices.idx", "ArchivoBinMaestro.dat", 45678987)){
        printf("\nNo se ha podido buscar el alumno");
        return 1;
    }

    printf("\n\nBuscando alumno");
    if(!buscarAlumnoPorArchivoIndices("ArchivoBinIndices.idx", "ArchivoBinMaestro.dat", 1234)){
        printf("\nNo se ha podido buscar el alumno");
        return 1;
    }


    printf("\n\n------------------------------------------------------\n");


    return 0;
}



