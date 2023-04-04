#ifndef MATEMATICA_H_INCLUDED
#define MATEMATICA_H_INCLUDED
#define FALSE 0
#define TRUE 1
#include <math.h>

typedef int BOOL;

typedef struct {
    int cociente;
    int resto;
}Division;

BOOL esNumeroNatural(int n);
long potencia(int n, int cant);
long factorial(int num);
long combinatorio(int n, int m);
BOOL estaEnFibonacci(int n);
double seno(float n, int cant);
void naturalPerfectoDeficienteOAbundante(int n);
int productoPorSumasSucesivas(int n, int m);
Division cocienteYResto(int a, int b);
int sumaPrimerosNNaturales(int n);
int sumaPrimerosNPares(int n);
int sumaParesMenoresAN(int n);
BOOL esPrimo(int n);



#endif // MATEMATICA_H_INCLUDED
