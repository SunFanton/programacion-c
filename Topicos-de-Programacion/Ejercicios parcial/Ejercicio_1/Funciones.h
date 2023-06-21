#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#define TAM_ISBN 17

typedef struct {
    char titulo[31];
    char autor[31];
    char isbn[TAM_ISBN + 1];
}t_libro;

int cargaArchivoBinarioLibros(const char *path, const char *mode, t_libro *libros, size_t tam);
int lecturaArchivoBinarioLibros(const char *path);
int cargaArchivoTextoLibros(const char *path, const char *mode, t_libro *libros, size_t cant);
int lecturaYValidacionArchivoTextoLibros(const char *path);
int validarISBN(const char *isbn);
size_t strlenPropio(const char *cadena);
char *strcpyPropio (char *destino, char *origen);
int toLowerPropio(int car);
int strcmpiPropio(const char *cadena1, const char *cadena2);
int comparaISBN(void *ptr1, void *ptr2);
void *memmovePropio(void *destino, void *origen, size_t tam);
void intercambiar(void *ptr1, void *ptr2, size_t tam);
void *buscarMenor(void *vec, void *fin, size_t tam, int (*comparar)(void*, void*));
void *ordenarPorSeleccion(void *vec, size_t ce, size_t tam, int (*comparar)(void*, void*));

#endif // FUNCIONES_H_INCLUDED
