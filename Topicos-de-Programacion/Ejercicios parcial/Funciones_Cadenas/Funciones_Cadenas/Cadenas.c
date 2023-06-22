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
    }
    return NULL;
}

char *miStrcpy(char *dest, const char *src){

    char* originalDest = dest;

    while (*src && dest - originalDest <= miStrlen(src)) {
        *dest = *src;
        dest++;
        src++;
    }

    *dest = '\0';

    return originalDest;
}

char *miStrcat(char*s1, const char *s2){

    size_t tam = miStrlen(s1) + miStrlen(s2) + 1;
    char *temp = (char*)malloc(sizeof(char)*tam);

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
    miStrcpy(s1, temp);
    free(temp);
    return s1;
}

int miToLower(char c){

    if(c >= 'A' && c <= 'Z')
        c = c + ('a' - 'A');

    return c;
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
        c1 = miToLower(*s1);
        c2 = miToLower(*s2);

        if(c1 < c2)
            return -1;
        else if(c1 > c2)
            return 1;
    }

    if(*s1)
        return 1;
    else if(*s2)
        return -1;

    return 0;
}

char *miStrstr(const char *s1, const char *s2){

    char *inicioS2 = s2;

    while(*s1){

        if(*s1 == *s2 && *s2)
            s2++;
        else if(*s1 != *s2 && *s2)
            s2 = inicioS2;
        else if(!*s2)
            break;

        s1++;
    }

    return *s2 == '\0' ? (char*)(s1 - miStrlen(s2)) : NULL;
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
