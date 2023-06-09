#include <stdio.h>
#include <stdlib.h>
#include "ManejoArchivo.h"

int main()
{
    int cantAlumnos = 0;
    float promediosGenerales = 0;
    t_alumno alumnos[100] = {};

    cantAlumnos = ingresarAlumnos(alumnos, &promediosGenerales);
    mostrarAlumnosPorPantalla(alumnos, cantAlumnos);
    if(!cargarArchivoTextoAlumnosLongitudFija("alumnos-Long-Fija.txt", alumnos, cantAlumnos)){
        printf("\nLo sentimos, ha ocurrido un error al generar el archivo");
        return 1;
    }

    return 0;
}
