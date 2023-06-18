#ifndef ARCHIVOS_H_INCLUDED
#define ARCHIVOS_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>

typedef struct{
    unsigned int dia;
    unsigned int mes;
    unsigned int anio;
}t_fecha;

typedef struct{
    char apeNom[31];
    unsigned int dni;
    unsigned int legajo;
    unsigned int edad;
    t_fecha fechaIngreso;
    float prom;
}t_alumno;

int grabarArchivoBinario(const char *path, void *data, size_t tam);
int mostrarArchivoBinarioAlumno(const char *path);
int guardarArchivoTextoLongVariable(const char *path, t_alumno *alumno, size_t cant);
int guardarArchivoTextoLongFija(const char *path, t_alumno *alumno, size_t cant);
int mostrarArchivoTextoLongVariable(const char *path);
int mostrarArchivoTextoLongFija(const char *path);
int archivoAlumnoBinarioATextoLongVariable(const char *path);
int archivoAlumnoTextoLongVariableABinario(const char *path);
int compararDni(void *ptr1, void *ptr2);
int mergeArchivosBinAlumnoUnion(const char *path1, const char *path2, const char *pathRes);
int mergeArchivosBinAlumnoInterseccion(const char *path1, const char *path2, const char *pathRes);

#endif // ARCHIVOS_H_INCLUDED
