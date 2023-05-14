#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Busqueda.h"

int compararPorDni(const void *v1, const void *v2);
int compararPorNombreYApellido(const void *v1, const void *v2);

typedef struct {

    char nombreApellido[30];
    int dni;
}t_alumno;

int main()
{
    t_alumno alumnos[] = {
                            {"Juan Perez", 34567983},
                            {"Emilia Martinez", 43567899},
                            {"Andrez Gomez", 42345667},
                            {"Luciana Torres", 39876544},
                            {"Esteban Fuentes", 32456554},
                         };
    size_t ce = sizeof(alumnos)/sizeof(alumnos[0]);
    size_t tam = sizeof(alumnos[0]);
    int dniBuscado;
    char nomApBuscado[30];

    printf("Ingrese el dni del alumno buscado: ");
    scanf("%d", &dniBuscado);
    fflush(stdin);
    printf("\nIngrese el nombre y apellido del alumno buscado: ");
    gets(nomApBuscado);
    fflush(stdin);

    t_alumno alumBuscado;
    alumBuscado.dni = dniBuscado;
    strcpy(alumBuscado.nombreApellido, nomApBuscado);

    t_alumno *ptr = buscar(alumnos,ce,tam,&alumBuscado,compararPorDni);
    if(ptr != NULL)
        printf("\n\nPor dni, se encontro el alumno: %s, DNI: %d", ptr->nombreApellido, ptr->dni);
    else
         printf("\n\nNo se encontro el alumno con el dni ingresado");



    ptr = buscar(alumnos,ce,tam,&alumBuscado,compararPorNombreYApellido);
    if(ptr != NULL)
        printf("\nPor nombre y apellido, se encontro el alumno: %s, DNI: %d", ptr->nombreApellido, ptr->dni);
    else
         printf("\nNo se encontro el alumno con el nombre y apellido ingresado");



    printf("\n\n");
    return 0;
}

int compararPorDni(const void *v1, const void *v2){

    t_alumno *a1 = (t_alumno*)v1;
    t_alumno *a2 = (t_alumno*)v2;

    return a1->dni - a2->dni;
}

int compararPorNombreYApellido(const void *v1, const void *v2){

    t_alumno *a1 = (t_alumno*)v1;
    t_alumno *a2 = (t_alumno*)v2;

    return strcmpi(a1->nombreApellido, a2->nombreApellido);

}
