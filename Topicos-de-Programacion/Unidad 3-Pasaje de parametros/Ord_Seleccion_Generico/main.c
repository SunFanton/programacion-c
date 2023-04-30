#include <stdio.h>
#include <stdlib.h>
#include "SeleccionGenerico.h"

int main()
{

    tPersona personas[] = {
        {34567890, "Garcia", "Marina Ana", 54.5},
        {39098655, "Nunez", "Rodrigo Nahuel", 79.6},
        {43567894, "Fuentes", "Mateo Julian", 80.1},
        {41567389, "Mattos", "Emilia Tatiana", 56.9},
        {42345678, "Zoas", "Agustina Marta", 51.9},
        {40999578, "Diaz", "Martina Sofia", 60.7},
        {37896455, "Garcia", "Javier Franco", 83.4},
        {38123466, "Martinez", "Brenda Marcela", 55.7},
        {40567849, "Torres", "Joaquin Tadeo", 77.9},
        {42345677, "Merides", "Ignacio Matias", 75.3},
    };

    int numerosEnteros[] = {
        -456,
        73,
        908,
        378,
        -89,
        45874,
        234,
        73,
        10,
        -150,
        319,
        -1200
    };

    int ceEnteros = sizeof(numerosEnteros)/sizeof(numerosEnteros[0]);
    int cePersonas = sizeof(personas)/sizeof(personas[0]);

    printf("\n\nOrdenamiento por seleccion usando tipos genericos");

    printf("\n\n*************************************************");

    printf("\n\nVector de enteros antes de ordenar: \n");
    for(int i = 0; i < ceEnteros; i++){
        printf("Elemento[%d]: %d\n", i, numerosEnteros[i]);
    }

    ordSeleccion(numerosEnteros,ceEnteros,sizeof(numerosEnteros[0]),compararEntero);
    printf("\n\nVector de enteros despues de ordenar: \n");
    for(int i = 0; i < ceEnteros; i++){
        printf("Elemento[%d]: %d\n", i, numerosEnteros[i]);
    }

     printf("\n\n*************************************************");

     printf("\n\nVector de Personas antes de ordenar: \n");
     for(int i = 0; i < cePersonas; i++){
        printf("\nPersona[%d]: \n", i);
        printf("\tDni: %d\n", personas[i].dni);
        printf("\tApellido: %s\n", personas[i].apellido);
        printf("\tNombres: %s\n", personas[i].nombres);
        printf("\tPeso: %.1f\n", personas[i].peso);
     }

     ordSeleccion(personas, cePersonas, sizeof(personas[0]), compararPersonaDni);
     printf("\n\nVector de Personas despues de ordenar por Dni: \n");
     for(int i = 0; i < cePersonas; i++){
        printf("\nPersona[%d]: \n", i);
        printf("\tDni: %d\n", personas[i].dni);
        printf("\tApellido: %s\n", personas[i].apellido);
        printf("\tNombres: %s\n", personas[i].nombres);
        printf("\tPeso: %.1f\n", personas[i].peso);
     }

     ordSeleccion(personas, cePersonas, sizeof(personas[0]), compararPersonaApellidoYNombre);
     printf("\n\nVector de Personas despues de ordenar por Apellido y Nombre: \n");
     for(int i = 0; i < cePersonas; i++){
        printf("\nPersona[%d]: \n", i);
        printf("\tDni: %d\n", personas[i].dni);
        printf("\tApellido: %s\n", personas[i].apellido);
        printf("\tNombres: %s\n", personas[i].nombres);
        printf("\tPeso: %.1f\n", personas[i].peso);
     }

     ordSeleccion(personas, cePersonas, sizeof(personas[0]), compararPersonaPeso);
     printf("\n\nVector de Personas despues de ordenar por Peso: \n");
     for(int i = 0; i < cePersonas; i++){
        printf("\nPersona[%d]: \n", i);
        printf("\tDni: %d\n", personas[i].dni);
        printf("\tApellido: %s\n", personas[i].apellido);
        printf("\tNombres: %s\n", personas[i].nombres);
        printf("\tPeso: %.1f\n", personas[i].peso);
     }

     return 0;
}
