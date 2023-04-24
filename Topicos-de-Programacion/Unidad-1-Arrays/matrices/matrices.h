#ifndef MATRICES_H_INCLUDED
#define MATRICES_H_INCLUDED
#define FILA 3
#define COL FILA
#define TRUE 1
#define FALSE 0

typedef int BOOL;

void llenarMatrizDeEnteros(int *matriz);
void recorrerMatrizDeEnteros(int *matriz);
void llenarMatrizDeDoubles(double *matriz);
void recorrerMatrizDeDoubles(double *matriz);

///EJERCICIO 1.10
double sumatoriaExclusivaSobreDgPrincipal(double matriz[][COL]);
double sumatoriaExclusivaSobreDgSecundaria(double matriz[][COL]);
double sumatoriaInclusivaSobreDgPrincipal(double matriz[][COL]);
double sumatoriaInclusivaSobreDgSecundaria(double matriz[][COL]);
double sumatoriaExclusivaDebajoDgPrincipal(double matriz[][COL]);
double sumatoriaExclusivaDebajoDgSecundaria(double matriz[][COL]);
double sumatoriaInclusivaDebajoDgPrincipal(double matriz[][COL]);
double sumatoriaInclusivaDebajoDgSecundaria(double matriz[][COL]);

///EJERCICIO 1.11
int obtenerTraza(int matriz[][COL]);
int obtenerSumaDgSecundaria(int matriz[][COL]);

///EJERCICIO 1.12
BOOL esMatrizDiagonal(int matriz[][COL]);

///EJERCICIO 1.13
BOOL esMatrizIdentidad(int matriz[][COL]);

///EJERCICIO 1.14
BOOL esMatrizSimetrica(int matriz[][COL]);

///EJERCICIO 1.16
void obtenerMatrizTraspuesta(int *matriz);

///EJERCICIO 1.17
void obtenerMatrizProducto(int *mProd, int *matriz1, int *matriz2, int filas1, int filas2);


#endif // MATRICES_H_INCLUDED
