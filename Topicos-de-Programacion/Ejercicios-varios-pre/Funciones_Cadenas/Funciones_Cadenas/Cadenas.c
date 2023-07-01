#include "Cadenas.h"
#include <stdlib.h>
#include <stdio.h>

size_t miStrlen(const char *s){

    size_t tam = 0;
    while(*s){
        tam++;
        s++;
    }
    return tam;
}

char *strchr(char *s, int c){

    size_t tam = miStrlen(s) + 1;
    for(int i = 0; i < tam; i++){
        if(*s == (char)c)
            return s;
        s++;
    }
    return NULL;
}

char *miStrrchr(char *s, int c){

    size_t tam = miStrlen(s) + 1;
    s = s + tam - 1;
    for(int i = 0; i < tam; i++){
        if(*s == (char)c)
            return s;
        s--;
    }
    return NULL;
}

char *miStrcpy(char *dest, const char *src){

    char* originalDest = dest;
    size_t tamSrc = miStrlen(src);

    while (*src && dest - originalDest <= tamSrc) {
        *dest = *src;
        dest++;
        src++;
    }

    *dest = '\0';
    dest = originalDest;
    return dest;
}

char *miStrcat(char*s1, const char *s2){

    size_t tam = miStrlen(s1) + miStrlen(s2) + 1;
    char *temp = (char*)malloc(sizeof(char)*tam);
    char *inicioS1 = s1,
         *inicioS2 = s2;

    if(temp == NULL)
        return NULL;

    size_t i = 0;

    while(*s1){
        temp[i] = *s1;
        i++;
        s1++;
    }
    while(*s2){
        temp[i] = *s2;
        i++;
        s2++;
    }
    temp[i] = '\0';
    s1 = inicioS1;
    s2 = inicioS2;
    miStrcpy(s1, temp);
    free(temp);
    return s1;
}

int miStrcmp(const char *s1, const char *s2){

    while(*s1 && *s2){
        if(*s1 < *s2)
            return -1;
        else if(*s1 > *s2)
            return 1;
    }
    if(*s1)
        return 1;
    else if(*s2)
        return -1;

    return 0;
}

int miStrcmpi(const char *s1, const char *s2){

    int c1,
        c2;
    while(*s1 && *s2){
        c1 = MI_TO_LOWER(*s1);
        c2 = MI_TO_LOWER(*s2);

        if(c1 < c2)
            return -1;
        else if(c1 > c2)
            return 1;
        s1++;
        s2++;
    }

    if(*s1)
        return 1;
    else if(*s2)
        return -1;

    return 0;
}

char *miStrstr(const char *s1, const char *s2){

    if(*s2 == '\0')
        return NULL;

    char *cadenaPrinc = s1;

     while(*cadenaPrinc){
        char *c1 = cadenaPrinc;
        char *c2 = s2;

        while(*c1 && *c2 && *c1 == *c2){
            c1++;
            c2++;
        }

        if(*c2 == '\0'){
            return (char*)cadenaPrinc;
        }
        cadenaPrinc++;
     }
     return NULL;
}

void *miMemcpy(void *s1, const void *s2, size_t n){

    char *dest = (char*)s1;
    char *src = (char*)s2;

    for(int i = 0; i < n; i++){
        dest[i] = src[i];
    }
    return dest;
}

void *miMemmove(void *s1, const void *s2, size_t n){

    char *dest = (char*)s1;
    char *src = (char*)s2;
    char *temp = (char*)malloc(sizeof(char)*n);

    for(int i = 0; i < n; i++){
        temp[i] = src[i];
    }
    for(int i = 0; i < n; i++){
        dest[i] = temp[i];
    }

    free(temp);
    return dest;
}

/*
void normalizeString(char *str) {
    int i, j;
    int wordStart = 1; // Variable para indicar si el siguiente carácter debe ser una letra mayúscula
    int wordEnd = 0; // Variable para indicar si se encontró un espacio o tabulación al final de una palabra

    // Eliminar espacios o tabulaciones al inicio de la cadena
    while (*str == ' ' || *str == '\t') {
        for (i = 0; str[i] != '\0'; i++) {
            str[i] = str[i + 1];
        }
    }

    // Iterar a través de la cadena para normalizar los caracteres
    for (i = 0, j = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ' || str[i] == '\t') {
            wordEnd = 1; // Marcar el final de una palabra
        } else {
            if (wordEnd) {
                // Eliminar espacios o tabulaciones entre palabras
                if (j > 0) {
                    str[j++] = ' ';
                }
                wordEnd = 0;
                wordStart = 1;
            }

            // Normalizar las letras de cada palabra
            if (wordStart) {
                if (str[i] >= 'a' && str[i] <= 'z') {
                    str[j++] = str[i] - 32; // Convertir a mayúscula
                } else {
                    str[j++] = str[i]; // Mantener el carácter original
                }
                wordStart = 0;
            } else {
                if (str[i] >= 'A' && str[i] <= 'Z') {
                    str[j++] = str[i] + 32; // Convertir a minúscula
                } else {
                    str[j++] = str[i]; // Mantener el carácter original
                }
            }
        }
    }

    // Eliminar espacios o tabulaciones al final de la cadena
    while (j > 0 && (str[j - 1] == ' ' || str[j - 1] == '\t')) {
        j--;
    }

    // Agregar el carácter nulo al final de la cadena
    str[j] = '\0';
}
*/

void normalizeString(char *str){

    int i = 0,
        j = 0,
        wordEnd = 0,
        wordStart = 1;

    while(*str == ' ' || *str == '\t'){
        for(i = 0; str[i] != '\0'; i++){
            str[i] = str[i+1];
        }
    }

    for(i = 0, j = 0; str[i] != '\0'; i++){
        if(str[i] == ' ' || str[i] == '\t'){
            wordEnd = 1;
        }
        else{
            if(wordEnd){
                if(j > 0){
                    str[j++] = ' ';
                }
                wordEnd = 0;
                wordStart = 1;
            }
            if(wordStart){
                if(str[i] >= 'a' && str[i] <= 'z'){
                    str[j++] = str[i] - 32;
                }
                else{
                    str[j++] = str[i];
                }
                wordStart = 0;
            }
            else{
                if(str[i] >= 'A' && str[i] <= 'Z'){
                    str[j++] = str[i] + 32;
                }
                else{
                    str[j++] = str[i];
                }
            }
        }
    }

    while(j > 0 && (str[j - 1] == ' ' || str[j - 1]== '\t')){
        j--;
    }

    str[j] = '\0';
}

int miAtoi(const char *numPtr){

    int num = 0;
    int i = 0;

    while(numPtr[i] && (numPtr[i]>='0' && numPtr[i]<='9')){
        num = num * 10 + (numPtr[i] - '0');
        i++;
    }
    return num;
}
