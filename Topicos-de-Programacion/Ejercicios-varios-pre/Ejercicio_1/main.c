#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"

int main()
{
    //Con isbn correctos:
    t_libro librosIniciales[] = {
                                    {"El cuervo", "Edgar A. Poe", "978-84-348-0004-1"},
                                    {"Blancanieves", "Los hermanos Grimm", "978-84-345-0002-1"},
                                    {"Rayuela", "Julio Cortazar", "978-84-349-0008-1"}
                                };

    t_libro librosAAgregar[] = {
                                    {"Alicia", "Lewis Carrol", " "},
                                    {"Sherlock Holmes", "Arthur C. Doyle", "978-84-340-0908-0"},
                                    {"El aleph", "Jorge Borges", "978-84-340-0502-0"},
                                    {"La sirenita", "Hans C. Andersen", "978-56-340-1234-1"},
                                    {"Mio Cid", "Leyendas populares", "978-23-340"}
                                };


    ordenarPorSeleccion(librosIniciales,
                        sizeof(librosIniciales)/sizeof(t_libro),
                        sizeof(t_libro),
                        comparaISBN);

    ordenarPorSeleccion(librosAAgregar,
                        sizeof(librosAAgregar)/sizeof(t_libro),
                        sizeof(t_libro),
                        comparaISBN);

    printf("Lectura antes de agregado: \n");
    if(!cargaArchivoBinarioLibros("libros.dat", "wb", librosIniciales, sizeof(librosIniciales))){
        printf("\nNo se ha podido realizar la carga inicial del archivo");
        return 1;
    }
    if(!lecturaArchivoBinarioLibros("libros.dat")){
        printf("\nNo se ha podido leer el contenido de libros.dat");
        return 1;
    }
    if(!cargaArchivoTextoLibros("nuevo_stock.txt", "wt", librosAAgregar, sizeof(librosAAgregar)/sizeof(t_libro))){
        printf("\nNo se ha podido realizar la carga del archivo");
        return 1;
    }
    if(!lecturaYValidacionArchivoTextoLibros("nuevo_stock.txt")){
        printf("\nNo se ha podido realizar la carga del archivo");
        return 1;
    }
    if(!reordenarArchivoBinarioLibros("libros.dat", "rb")){
        printf("\nNo se ha podido realizar la lectura y reorden del archivo");
        return 1;
    }
    printf("\nLectura despues de agregado: \n");
    if(!lecturaArchivoBinarioLibros("libros.dat")){
        printf("\nNo se ha podido leer el contenido de libros.dat");
        return 1;
    }


    printf("\n\n---------------------------------------------------\n");

    return 0;
}
