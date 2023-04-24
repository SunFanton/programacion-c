#include <stdio.h>
#include <stdlib.h>
#include "matrices.h"

int mostrarMenu();
void ejercicio1_10();
void ejercicio1_11();
void ejercicio1_12();
void ejercicio1_13();
void ejercicio1_14();
void ejercicio1_15();
void ejercicio1_16();
void ejercicio1_17();

int main()
{
    int eleccion = mostrarMenu();
    while(eleccion != 0){

        switch(eleccion){
            case 1:
                ejercicio1_10();
                break;
            case 2:
                ejercicio1_11();
                break;
            case 3:
                ejercicio1_12();
                break;
            case 4:
                ejercicio1_13();
                break;
            case 5:
                ejercicio1_14();
                break;
            case 6:
                ejercicio1_15();
                break;
            case 7:
                ejercicio1_16();
                break;
            case 8:
                ejercicio1_17();
                break;
            default:
                printf("\nLo sentimos, no existe esa opcion. Intente nuevamente");
                break;
        }

        eleccion = mostrarMenu();
    }
}

int mostrarMenu(){

    int opcion = 0;
    printf("\n\n********** MATRICES **********\n\n");
    printf("\n Elija una opcion: ");
    printf("\n\n\t1. Sumatoria de elementos encima de la diagonal principal (excluida), sumatoria encima de la diagonal secundaria (excluida), lo mismo debajo de ambas (excluidas), lo mismo incluyendolas para cada caso.");
    printf("\n\t2. Traza de la matriz y suma de los elementos de la diagonal secundaria.");
    printf("\n\t3. Comprobar si una matriz cuadrada es diagonal (ceros en todas las pos. excepto en diagonal principal).");
    printf("\n\t4. Comprobar si una matriz cuadrada es identidad (ceros en todas las pos., unos en la diagonal principal).");
    printf("\n\t5. Comprobar si una matriz cuadrada es simetrica (igual a su traspuesta).");
    printf("\n\t6. Trasponer in situ una matriz.");
    printf("\n\t7. Trasponer mediante funcion una matriz.");
    printf("\n\t8. Obtener matriz producto de dos matrices.");
    printf("\n\t0. Salir.");
    printf("\nOpcion: ");
    scanf("%d", &opcion);

    return opcion;

}

void ejercicio1_10(){

    double matriz[FILA][COL];

    /*
    for(int i = 0; i < FILA; i++){

        for(int j = 0; j < COL; j++){

            printf("\nElemento[%d][%d] = ", i, j);
            scanf("%lf", &matriz[i][j]);
        }
    }

    printf("\n\nMatriz: \n");
    for(int i = 0; i < FILA; i++){

        for(int j = 0; j < COL; j++){
            printf(" %5.0lf", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    */

    llenarMatrizDeDoubles(&matriz[0][0]);
    recorrerMatrizDeDoubles(&matriz[0][0]);

    if(FILA != COL){
        printf("\n\nLa matriz debe ser cuadrada");
        return;
    }

    printf("\n\nSumatoria elementos sobre diag. principal (excluyendola): %.0lf", sumatoriaExclusivaSobreDgPrincipal(matriz));
    printf("\n\nSumatoria elementos sobre diag. secundaria (excluyendola): %.0lf", sumatoriaExclusivaSobreDgSecundaria(matriz));
    printf("\n\nSumatoria elementos sobre diag. principal (incluyendola): %.0lf", sumatoriaInclusivaSobreDgPrincipal(matriz));
    printf("\n\nSumatoria elementos sobre diag. secundaria (incluyendola): %.0lf", sumatoriaInclusivaSobreDgSecundaria(matriz));
    printf("\n\nSumatoria elementos debajo diag. principal (excluyendola): %.0lf", sumatoriaExclusivaDebajoDgPrincipal(matriz));
    printf("\n\nSumatoria elementos debajo diag. secundaria (excluyendola): %.0lf", sumatoriaExclusivaDebajoDgSecundaria(matriz));
    printf("\n\nSumatoria elementos debajo diag. principal (incluyendola): %.0lf", sumatoriaInclusivaDebajoDgPrincipal(matriz));
    printf("\n\nSumatoria elementos debajo diag. secundaria (incluyendola): %.0lf", sumatoriaInclusivaDebajoDgSecundaria(matriz));
}

void ejercicio1_11(){

    int matriz[FILA][COL];

    /*
    for(int i = 0; i < FILA; i++){

        for(int j = 0; j < COL; j++){

            printf("\nElemento[%d][%d] = ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("\n\nMatriz: \n");
    for(int i = 0; i < FILA; i++){

        for(int j = 0; j < COL; j++){
            printf(" %5d", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    */

    llenarMatrizDeEnteros(&matriz[0][0]);
    recorrerMatrizDeEnteros(&matriz[0][0]);

     if(FILA != COL){
        printf("\n\nLa matriz debe ser cuadrada");
        return;
    }

    printf("\n\nTraza de la matriz: %d", obtenerTraza(matriz));
    printf("\n\nSumatoria elementos diagonal secundaria: %d", obtenerSumaDgSecundaria(matriz));

}

void ejercicio1_12(){

    int matriz[FILA][COL];

    /*
    for(int i = 0; i < FILA; i++){

        for(int j = 0; j < COL; j++){

            printf("\nElemento[%d][%d] = ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("\n\nMatriz: \n");
    for(int i = 0; i < FILA; i++){

        for(int j = 0; j < COL; j++){
            printf(" %5d", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    */

    llenarMatrizDeEnteros(&matriz[0][0]);
    recorrerMatrizDeEnteros(&matriz[0][0]);


     if(FILA != COL){
        printf("\n\nLa matriz debe ser cuadrada");
        return;
    }

    BOOL esDiagonal = esMatrizDiagonal(matriz);

    if(esDiagonal)
        printf("\n\nLa matriz es diagonal");
    else
        printf("\n\nLa matriz NO es diagonal");

}

void ejercicio1_13(){

    int matriz[FILA][COL];

    /*
    for(int i = 0; i < FILA; i++){

        for(int j = 0; j < COL; j++){

            printf("\nElemento[%d][%d] = ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("\n\nMatriz: \n");
    for(int i = 0; i < FILA; i++){

        for(int j = 0; j < COL; j++){
            printf(" %5d", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    */

    llenarMatrizDeEnteros(&matriz[0][0]);
    recorrerMatrizDeEnteros(&matriz[0][0]);


     if(FILA != COL){
        printf("\n\nLa matriz debe ser cuadrada");
        return;
    }

    BOOL esIdentidad = esMatrizIdentidad(matriz);

    if(esIdentidad)
        printf("\n\nLa matriz es identidad");
    else
        printf("\n\nLa matriz NO es identidad");

}

void ejercicio1_14(){

    int matriz[FILA][COL];

    /*
    for(int i = 0; i < FILA; i++){

        for(int j = 0; j < COL; j++){

            printf("\nElemento[%d][%d] = ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("\n\nMatriz: \n");
    for(int i = 0; i < FILA; i++){

        for(int j = 0; j < COL; j++){
            printf(" %5d", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    */

    llenarMatrizDeEnteros(&matriz[0][0]);
    recorrerMatrizDeEnteros(&matriz[0][0]);

     if(FILA != COL){
        printf("\n\nLa matriz debe ser cuadrada");
        return;
    }

    BOOL esSimetrica = esMatrizSimetrica(matriz);

    if(esSimetrica)
        printf("\n\nLa matriz es simetrica");
    else
        printf("\n\nLa matriz NO es simetrica");

}

void ejercicio1_15(){
    int matriz[FILA][COL];

    /*
    for(int i = 0; i < FILA; i++){

        for(int j = 0; j < COL; j++){

            printf("\nElemento[%d][%d] = ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("\n\nMatriz original: \n");
    for(int i = 0; i < FILA; i++){

        for(int j = 0; j < COL; j++){
            printf(" %5d", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    */

    llenarMatrizDeEnteros(&matriz[0][0]);
    printf("\n\nMatriz original: \n");
    recorrerMatrizDeEnteros(&matriz[0][0]);

    //Se traspone la matriz in situ
    int aux = 0,
        colInicial = 0;
    for(int i = 0; i < FILA; i++){
        for(int j = colInicial; j < COL; j++){
            aux = matriz[i][j];
            matriz[i][j] = matriz[j][i];
            matriz[j][i] = aux;
        }
        colInicial++;
    }

    printf("\n\nMatriz traspuesta: \n");
    recorrerMatrizDeEnteros(&matriz[0][0]);
    /*
    for(int i = 0; i < FILA; i++){

        for(int j = 0; j < COL; j++){
            printf(" %5d", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    */
}

void ejercicio1_16(){
    int matriz[FILA][COL];

    /*
    for(int i = 0; i < FILA; i++){

        for(int j = 0; j < COL; j++){

            printf("\nElemento[%d][%d] = ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("\n\nMatriz original: \n");
    for(int i = 0; i < FILA; i++){

        for(int j = 0; j < COL; j++){
            printf(" %5d", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    */

    llenarMatrizDeEnteros(&matriz[0][0]);
    printf("\n\nMatriz original: \n");
    recorrerMatrizDeEnteros(&matriz[0][0]);

    obtenerMatrizTraspuesta(&matriz[0][0]);
    printf("\n\nMatriz traspuesta: \n");
    recorrerMatrizDeEnteros(&matriz[0][0]);

}

void ejercicio1_17(){
    int matriz1[FILA][COL];
    llenarMatrizDeEnteros(&matriz1[0][0]);


    int matriz2[FILA][COL];
    llenarMatrizDeEnteros(&matriz2[0][0]);

    printf("\n\nMatriz 1: \n");
    recorrerMatrizDeEnteros(&matriz1[0][0]);
    printf("\n\nMatriz 2: \n");
    recorrerMatrizDeEnteros(&matriz2[0][0]);

    int matrizProd[FILA][COL] = {{0,0,0}};
    printf("\n\nMatriz prod. al iniciar: \n");
    recorrerMatrizDeEnteros(&matrizProd[0][0]);
    printf("\n\nMatriz prod. al realizar el producto: \n");
    obtenerMatrizProducto(&matrizProd[0][0],&matriz1[0][0],&matriz2[0][0],FILA,FILA);
    recorrerMatrizDeEnteros(&matrizProd[0][0]);

}



