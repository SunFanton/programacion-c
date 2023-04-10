#ifndef MATEMATICA_H_INCLUDED
#define MATEMATICA_H_INCLUDED
#define FALSE 0
#define TRUE 1
#define TOL 0.001
#include <math.h>
#include <stdlib.h>

typedef int BOOL;

typedef struct {
    int cociente;
    int resto;
}Division;

BOOL esNumeroNatural(int n);
long double potencia(double n, int cant);
long factorial(int num);
double combinatorio(int n, int m);
double eALaX(double x);
double raizCuadrada(double a);
BOOL estaEnFibonacci(int n);
double seno(float n, int cant);
void naturalPerfectoDeficienteOAbundante(int n);
int productoPorSumasSucesivas(int n, int m);
Division cocienteYResto(int a, int b);
int sumaPrimerosNNaturales(int n);
int sumaPrimerosNPares(int n);
int sumaParesMenoresAN(int n);
BOOL *esPrimo(int *ptrN); //Ejemplo usando punteros



#endif // MATEMATICA_H_INCLUDED
