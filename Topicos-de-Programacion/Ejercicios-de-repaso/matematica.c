#include "matematica.h"
#include <stdio.h>

//Numero es menor a cero
BOOL esNumeroNatural(int n){
    if(n < 0)
        return TRUE;
    else
        return FALSE;
}

//Obtener potencia de un numero
long double potencia(double n, int cant){

    long double resul = 1;

    for(int i = 1; i <= cant; i++){
        resul *= n;
    }

    return resul;
}

//01 Factorial
long factorial(int n) {
    long fact = 1;
    if(n < 0)
        return 0;
    for(int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

//02 Combinatorio
double combinatorio(int n, int m) {
    double result = (double)factorial(n)/(double)(factorial(m)*factorial(n-1));
    return result;
}

//03 E a la x:

double eALaX(double x) {
    double e = 1;
    double termino = 1;
    int iteracion = 1;

    do{
        termino = potencia(x,iteracion)/(double)factorial(iteracion);
        e = e + termino;
        iteracion++;
    }while(termino >= TOL);

    return e;
}

//04 Raiz cuadrada:
double raizCuadrada(double a){

    double termAnterior = 1;
    double termSiguiente = (termAnterior + (a/termAnterior))/2;

    while(fabs(termSiguiente - termAnterior) > TOL) {
        termAnterior = termSiguiente;
        termSiguiente = (termAnterior + (a/termAnterior))/2;
    }

    return termSiguiente;
}

//05 Entero esta en Fibonacci
BOOL estaEnFibonacci(int n){

    int anterior = 1;
    int siguiente = 1;
    int temp;

    while(siguiente <= n){
        if(siguiente == n){
            return TRUE;
        }
        temp = siguiente;
        siguiente = anterior + siguiente;
        anterior = temp;
    }
    return FALSE;
}

//06 Seno de x
double seno(float n, int cant){

    double seno=0;
	int cnt=1, cnt2=1;
	for(cnt=1; cnt<=cant; cnt++)
	{
		seno=seno+(double)potencia(-1,cnt+1)*potencia(n,cnt2)/(double)factorial(cnt2);
		cnt2= cnt2+2;
	}
	return seno;
}

//07 Natural perfecto, abundante, deficiente
void naturalPerfectoDeficienteOAbundante(int n) {

    int sumaDivisores = 0;
    for(int i = 1; i < n; i++) {
        if(n%i == 0){
            sumaDivisores += i;
        }
    }

    if(sumaDivisores < n) {
        printf("%d es deficiente", n);
    }
    else if(sumaDivisores == n) {
        printf("%d es perfecto", n);
    }
    else if(sumaDivisores > n) {
        printf("%d es abundante", n);
    }
}

//08 Producto de dos numeros por sumas sucesivas
int productoPorSumasSucesivas(int n, int m) {

    if(n == 0 || m == 0)
        return 0;

    int producto = 0;
    for(int i = 1; i <= m; i++){
        producto += n;
    }
    return producto;
}

//09 cociente y resto de dos numeros naturales
Division cocienteYResto(int a, int b){

    Division division = {0 , 0};

    division.cociente = a/b;
    division.resto = a%b;

    return division;
}

//10 Suma de los primeros n numeros naturales
int sumaPrimerosNNaturales(int n){

    int suma = 0;
    for(int i = 1; i <= n; i++){
        suma += i;
    }
    return suma;
}

//11 Suma de los primeros n pares
int sumaPrimerosNPares(int n) {

    int par = 2;
    int sumaPares = 0;

    for(int i = 1; i <= n; i++){
        sumaPares += par;
        par += 2;
    }
    return sumaPares;
}

//12 Suma de numeros pares menores que n
int sumaParesMenoresAN(int n){

    int sumaParesMenores = 0;

    for(int i = 1; i < n; i++){
        if(i%2 == 0){
            sumaParesMenores += i;
        }
    }
    return sumaParesMenores;
}

//13 Dererminar si el numero natural es primo
//Ejemplo usando punteros
BOOL *esPrimo(int *ptrN) {

    int cantDivisores = 0;

    /*
    Asigno una posicion de memoria de manera dinamica a traves de malloc
    Dicha posicion debe tener el espacio de una variable de tipo BOOL (int)
    Por ultimo (BOOL *) es para castear el puntero generico void * que retorna malloc
    a un puntero de tipo BOOL *
    */
    BOOL *prtResult = (BOOL *)malloc(sizeof(BOOL));

    for(int i = 1; i <= (*ptrN); i++) {
        if((*ptrN)%i == 0){
            cantDivisores++;
        }
        if(cantDivisores > 2)
            break;

    }
    if(cantDivisores == 2){
        *prtResult = TRUE;
    }
    else
        *prtResult = FALSE;

        return prtResult;
}
