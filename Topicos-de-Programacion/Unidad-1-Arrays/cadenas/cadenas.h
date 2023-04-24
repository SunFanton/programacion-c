#ifndef CADENAS_H_INCLUDED
#define CADENAS_H_INCLUDED
#define TRUE 1
#define FALSE 0
#include <string.h>

typedef int BOOL;

int contarPalabras(char *cad);
char* substring(char *destination, const char *source, int beg, int n);
int strlenPropio(const char *cad);
///EJERCICIO 1.6
int cadenaEsPalindromo(char *cadena);
///EJERCICIO 1.7
int valorNumericoEnteroDeCadena(char *cadena);
///EJERCICIO 1.8
int cantidadOcurrenciasPalabra(char *cadena, char *buscada);

#endif // CADENAS_H_INCLUDED
