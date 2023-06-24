#include "Funciones.h"
#include <stdlib.h>
#include <stdio.h>

int cargaArchivoBinarioLibros(const char *path, const char *mode, t_libro *libros, size_t tam){

    FILE *pf = fopen(path, mode);
    if(!pf)
        return 0;

    fwrite(libros, tam, 1, pf);

    fclose(pf);
    return 1;
}

int lecturaArchivoBinarioLibros(const char *path){

    FILE *pf = fopen(path, "rb");
    if(!pf)
        return 0;

    t_libro libro;
    while(fread(&libro, sizeof(t_libro), 1, pf)){
        printf("Titulo: %s, autor: %s, isbn: %s\n",
               libro.titulo,
               libro.autor,
               libro.isbn);
    }

    fclose(pf);
    return 1;
}

int cargaArchivoTextoLibros(const char *path, const char *mode, t_libro *libros, size_t cant){

    FILE *pf = fopen(path, mode);
    if(!pf)
        return 0;

    for(int i = 0; i < cant; i++){
        fprintf(pf, "%s|%s|%s\n",
                libros[i].titulo,
                libros[i].autor,
                libros[i].isbn);
    }

    fclose(pf);
    return 1;
}

int lecturaYValidacionArchivoTextoLibros(const char *path){

    FILE *pf = fopen(path, "rt");
    if(!pf)
        return 0;

    t_libro libro;
    char linea[100];

    while (fgets(linea, sizeof(linea), pf) != NULL) {
        if (sscanf(linea, "%[^|]|%[^|]|%[^|\n]\n", libro.titulo, libro.autor, libro.isbn) == 3) {
            if(validarISBN(libro.isbn)){
                cargaArchivoBinarioLibros("libros.dat", "ab", &libro, sizeof(t_libro));
            }
            else
                cargaArchivoTextoLibros("error.txt", "wb", &libro, 1);
        }
    }

    fclose(pf);
    return 1;
}

int reordenarArchivoBinarioLibros(const char *path, const char *mode){

    FILE *pf = fopen(path, mode);
    if(!pf)
        return 0;

    fseek(pf, 0, SEEK_END);
    size_t totalTam = ftell(pf);
    t_libro *libros = (t_libro*)malloc(totalTam);
    t_libro *inicio = libros;
    fseek(pf, 0, SEEK_SET);

    while(fread(libros, sizeof(t_libro), 1, pf)){
        libros++;
    }
    libros = inicio;
    ordenarPorSeleccion(libros, totalTam/sizeof(t_libro), sizeof(t_libro), comparaISBN);
    cargaArchivoBinarioLibros("libros.dat", "wb", libros, totalTam);

    fclose(pf);
    free(libros);
    return 1;
}

int validarISBN(const char *isbn){

    if(strlenPropio(isbn) != TAM_ISBN)
        return 0;

    char digitos[14];
    int j = 0;
    while(*isbn){
        if(*isbn != '-'){
            digitos[j] = *isbn;
            j++;
        }
        isbn++;
    }
    digitos[j] = '\0';

    int impares = 0,
        pares = 0,
        dig;

    for(int i = 0; i < strlenPropio(digitos); i++){
        dig = digitos[i] - '0';
        if(i % 2 == 0)
            impares += dig;
        else
            pares += dig;
    }
    int resul = pares + 3*impares;

    return resul % 10 == 0;
}

size_t strlenPropio(const char *cadena){

    size_t tam = 0;
    while(*cadena){
        tam++;
        cadena++;
    }
    return tam;
}

char *strcpyPropio (char *destino, char *origen){
    if(destino == NULL)
        return NULL;

    char *inicio = destino;

    while(*origen){
        *destino = *origen;
        destino++;
        origen++;
    }
    *destino = '\0';
    destino = inicio;
    return destino;
}

int toLowerPropio(int car){
    if(car >= 'A' && car <= 'Z'){
        car = car + ('a' - 'A');
    }
    return car;
}

int strcmpiPropio(const char *cadena1, const char *cadena2) {
    while (*cadena1 && *cadena2) {
        char c1 = toLowerPropio(*cadena1);
        char c2 = toLowerPropio(*cadena2);

        if (c1 < c2) {
            return -1;
        } else if (c1 > c2) {
            return 1;
        }

        cadena1++;
        cadena2++;
    }

    if (*cadena1) {
        return 1;
    } else if (*cadena2) {
        return -1;
    }

    return 0;
}

int comparaISBN(void *ptr1, void *ptr2){

    t_libro *libro1 = (t_libro*)ptr1;
    t_libro *libro2 = (t_libro*)ptr2;

    return strcmpiPropio(libro1->isbn, libro2->isbn);
}

void *memmovePropio(void *destino, void *origen, size_t tam){

    char *cDestino = (char*)destino;
    char *cOrigen = (char*)origen;
    char *temp = (char*)malloc(sizeof(char)*tam);

    for(int i = 0; i< tam; i++){
        temp[i] = cOrigen[i];
    }

    for(int i = 0; i < tam; i++){
        cDestino[i] = temp[i];
    }
    return cDestino;
}

void intercambiar(void *ptr1, void *ptr2, size_t tam){

    char *aux = (char*)malloc(sizeof(char)*tam);
    memmovePropio(aux, ptr1, tam);
    memmovePropio(ptr1, ptr2, tam);
    memmovePropio(ptr2, aux, tam);
    free(aux);
}

void *buscarMenor(void *vec, void *fin, size_t tam, int (*comparar)(void*, void*)){

    void *menor = vec;
    vec += tam;
    while(vec <= fin){
        if(comparar(vec, menor) < 0){
            menor = vec;
        }
        vec += tam;
    }
    return menor;
}
void *ordenarPorSeleccion(void *vec, size_t ce, size_t tam, int (*comparar)(void*, void*)){

    void *fin = vec + (ce - 1)*tam ;
    void *inicio = vec;
    void *men;

    while(vec < fin){
        men = buscarMenor(vec, fin, tam, comparar);
        if(men != vec)
            intercambiar(vec, men, tam);
        vec += tam;
    }
    return inicio;
}
