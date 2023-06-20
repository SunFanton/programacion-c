#ifndef MISTRING_H_INCLUDED
#define MISTRING_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>

size_t miStrlen(const char *cad);
char *miStrchr(const char* cad, int caracter);
char *miStrrchr(const char* cad, int caracter);

#endif // MISTRING_H_INCLUDED
