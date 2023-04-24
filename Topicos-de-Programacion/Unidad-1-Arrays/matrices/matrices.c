#include <stdio.h>
#include <stdlib.h>
#include "matrices.h"

/*Ejemplos de ejercicios con matrices (en algunos casos, pasando parametro por copia
a la funcion, y en otros casos, experimentando con el uso de punteros en matrices)
Recordemos que las matrices son en realidad vectores de vectores (es como tener una gran vector,
donde en memoria se almacenan los vectores internos, uno al lado del otro en forma
consecutiva) */

void llenarMatrizDeEnteros(int *matriz){

     for(int i = 0; i < FILA; i++){

        for(int j = 0; j < COL; j++){

            printf("\nElemento[%d][%d] = ", i, j);
            /*Las matrices son consideradas vectores de vectores, pues en memoria
            cada fila queda consecutiva una al lado de la otra asi:
            {1,2,3}{4,5,6}{7,8,9}*/
            scanf("%d", matriz+i*COL+j); //puntero + ind. fila * cant. columnas + ind. columna
        }
    }
}

void recorrerMatrizDeEnteros(int *matriz){

    for(int i = 0; i < FILA; i++){

        for(int j = 0; j < COL; j++){
            printf(" %5d", *(matriz+i*COL+j));
        }
        printf("\n");
    }
    printf("\n");
}

void llenarMatrizDeDoubles(double *matriz){

    for(int i = 0; i < FILA; i++){

        for(int j = 0; j < COL; j++){

            printf("\nElemento[%d][%d] = ", i, j);
            scanf("%lf", matriz+i*COL+j); //puntero + ind. fila * cant. columnas + ind. columna
        }
    }

}
void recorrerMatrizDeDoubles(double *matriz){

    for(int i = 0; i < FILA; i++){

        for(int j = 0; j < COL; j++){
            printf(" %5.0lf", *(matriz+i*COL+j));
        }
        printf("\n");
    }
    printf("\n");
}


///EJERCICIO 1.10
double sumatoriaExclusivaSobreDgPrincipal(double matriz[][COL]){

    double resul = 0;

    for(int i = 0; i < FILA; i++){
        for(int j = (i+1); j < COL; j++){
            resul += matriz[i][j];
        }
    }
    return resul;
}

double sumatoriaExclusivaSobreDgSecundaria(double matriz[][COL]){

    double resul = 0;
    int colReducida = COL - 1;

    for(int i = 0; i < (FILA - 1); i++){
        for(int j = 0; j < colReducida; j++){
            resul += matriz[i][j];
        }
        colReducida--;
    }
    return resul;

}

double sumatoriaInclusivaSobreDgPrincipal(double matriz[][COL]){

    double resul = 0;

    for(int i = 0; i < FILA; i++){
        for(int j = i; j < COL; j++){
            resul += matriz[i][j];
        }
    }
    return resul;
}

double sumatoriaInclusivaSobreDgSecundaria(double matriz[][COL]){

    double resul = 0;
    int colReducida = COL;

    for(int i = 0; i < FILA; i++){
        for(int j = 0; j < colReducida; j++){
            resul += matriz[i][j];
        }
        colReducida--;
    }
    return resul;
}

double sumatoriaExclusivaDebajoDgPrincipal(double matriz[][COL]){

    double resul = 0;

    for(int i = 1; i < FILA; i++){
        for(int j = 0; j < i; j++){
            resul += matriz[i][j];
        }
    }
    return resul;
}

double sumatoriaExclusivaDebajoDgSecundaria(double matriz[][COL]){

    double resul = 0;
    int colReducida = COL - 1;

    for(int i = 1; i < FILA; i++){
        for(int j = colReducida; j < COL; j++){
            resul += matriz[i][j];
        }
        colReducida--;
    }
    return resul;
}
double sumatoriaInclusivaDebajoDgPrincipal(double matriz[][COL]){

    double resul = 0;

    for(int i = 0; i < FILA; i++){
        for(int j = 0; j <= i; j++){
            resul += matriz[i][j];
        }
    }
    return resul;
}
double sumatoriaInclusivaDebajoDgSecundaria(double matriz[][COL]){

    double resul = 0;
    int colReducida = COL - 1;

    for(int i = 0; i < FILA; i++){
        for(int j = colReducida; j < COL; j++){
            resul += matriz[i][j];
        }
        colReducida--;
    }
    return resul;
}

///EJERCICIO 1.11
int obtenerTraza(int matriz[][COL]){

     int resul = 0;

     for(int i = 0; i < FILA; i++){
        resul += matriz[i][i];
     }
     return resul;
}

int obtenerSumaDgSecundaria(int matriz[][COL]){

    int resul = 0;
    int colReducida = COL - 1;

    for(int i = 0; i < FILA; i++){
        resul += matriz[i][colReducida];
        colReducida--;
    }
    return resul;
}

///EJERCICIO 1.12
BOOL esMatrizDiagonal(int matriz[][COL]){

    BOOL esDiagonal = TRUE;

    for(int i = 0; i < FILA; i++){
        for(int j = 0; j < COL; j++){
            if(i != j && matriz[i][j] != 0){
                esDiagonal = FALSE;
                break;
            }
        }
        if(!esDiagonal)
            break;
    }
    return esDiagonal;
}

///EJERCICIO 1.13
BOOL esMatrizIdentidad(int matriz[][COL]){

    BOOL esIdentidad = TRUE;

    for(int i = 0; i < FILA; i++){
        for(int j = 0; j < COL; j++){
            if((i == j && matriz[i][j] != 1) ||
               (i != j && matriz[i][j] != 0)){
                esIdentidad = FALSE;
                break;
            }
        }
        if(!esIdentidad)
            break;
    }
    return esIdentidad;
}

///EJERCICIO 1.14
BOOL esMatrizSimetrica(int matriz[][COL]){

    BOOL esSimetrica = TRUE;

    for(int i = 0; i < FILA; i++){
        for(int j = 0; j < COL; j++){
            if(matriz[i][j] != matriz[j][i]){
                esSimetrica = FALSE;
                break;
            }
        }
        if(!esSimetrica)
            break;
    }

    return esSimetrica;
}

///EJERCICIO 1.16
void obtenerMatrizTraspuesta(int *matriz){

    int aux = 0,
        colInicial = 0;
    for(int i = 0; i < FILA; i++){
        for(int j = colInicial; j < COL; j++){
            //aux = matriz[i][j];
            aux = *(matriz+i*COL+j);
            //matriz[i][j] = matriz[j][i];
            *(matriz+i*COL+j) = *(matriz+j*COL+i);
            //matriz[j][i] = aux;
            *(matriz+j*COL+i) = aux;

        }
        colInicial++;
    }
}

///EJERCICIO 1.17
void obtenerMatrizProducto(int *mProd, int *matriz1, int *matriz2, int filas1, int filas2){

    if(COL != filas2){
        printf("\nLa cantidad de columnas de la primer matriz debe ser igual a la cantidad de filas de la seugnda matriz para obtener el producto");
        return;
    }

    // Necesitamos hacer esto por cada columna de la segunda matriz
    for (int a = 0; a < COL; a++) {
        // Dentro recorremos las filas de la primera
        for (int i = 0; i < filas1; i++) {
            int suma = 0;
            // Y cada columna de la primera
            for (int j = 0; j < COL; j++) {
                // Multiplicamos y sumamos resultado
                //suma += matriz1[i][j] * matriz2[j][a];
                suma += *(matriz1 + i*COL + j) * (*(matriz2 + j*COL + a));
            }
            // Lo acomodamos dentro del producto
            //mProd[i][a] = suma;
            *(mProd+i*COL+a) = suma;
        }
    }

    //recorrerMatrizDeEnteros(&mProd[0][0]);
}

