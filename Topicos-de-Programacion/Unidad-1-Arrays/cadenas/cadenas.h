#ifndef CADENAS_H_INCLUDED
#define CADENAS_H_INCLUDED
#define TRUE 1
#define FALSE 0
#include <string.h>

typedef int BOOL;

BOOL esLetra(char caracter);
int contarPalabras(char *cad);
char* substringPropio(char *destination, const char *source, int beg, int n);
int strlenPropio(const char *cad);
int strcmpiPropio(char *cadena1, char *cadena2);
void toLowerPropio(char* str);
///EJERCICIO 1.6
int cadenaEsPalindromo(char *cadena);
///EJERCICIO 1.7
int valorNumericoEnteroDeCadena(char *cadena);
///EJERCICIO 1.8
int cantidadOcurrenciasPalabra(char *cadena, char *buscada);
///EJERCICIO 1.9
void normalizarCadenaYQuitarEspaciosExcedentes(char *cadena);

#endif // CADENAS_H_INCLUDED
