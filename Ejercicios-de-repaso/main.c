#include <stdio.h>
#include <stdlib.h>
#include "matematica.h"

int mostrarMenu();
void ejercicio01();
void ejercicio02();
void ejercicio03();
void ejercicio04();
void ejercicio05();
void ejercicio06();
void ejercicio07();
void ejercicio08();
void ejercicio09();
void ejercicio10();
void ejercicio11();
void ejercicio12();
void ejercicio13();

int main()
{
    int eleccion;
    eleccion = mostrarMenu();

    while(eleccion != 0){

        switch(eleccion){
            case 1:
                ejercicio01();
                break;
            case 2:
                ejercicio02();
                break;
            case 3:
                ejercicio03();
                break;
            case 4:
                ejercicio04();
                break;
            case 5:
                ejercicio05();
                break;
            case 6:
                ejercicio06();
                break;
            case 7:
                ejercicio07();
                break;
            case 8:
                ejercicio08();
                break;
            case 9:
                ejercicio09();
                break;
            case 10:
                ejercicio10();
                break;
            case 11:
                ejercicio11();
                break;
            case 12:
                ejercicio12();
                break;
            case 13:
                ejercicio13();
                break;
            default:
                printf("No existe esa opcion, intente nuevamente");
                break;

        }
        eleccion = mostrarMenu();
    }

    return 0;
}

int mostrarMenu(){

    int eleccion;
    printf("\n\n*************** CALCULOS MATEMATICOS ***************\n\n");
    printf("Ingrese una opcion: \n");
    printf("\t1. Factorial de un numero natural\n");
    printf("\t2. Combinatorio de dos numeros naturales\n");
    printf("\t3. Obtener e a la x\n");
    printf("\t4. Raiz cuadrada de un numero positivo\n");
    printf("\t5. Verificar existencia de un numero natural en la serie Fibonacci\n");
    printf("\t6. Obtener seno de x\n");
    printf("\t7. Verificar si un numero natural es deficiente, perfecto o abundante\n");
    printf("\t8. Producto de dos numeros naturales (incluido el cero) por sumas sucesivas\n");
    printf("\t9. Obtener el cociente entero y el resto de dos numeros naturales\n");
    printf("\t10. Suma de los primeros N numeros naturales\n");
    printf("\t11. Suma de los primeros N numeros pares naturales\n");
    printf("\t12. Suma de los numeros naturales pares menores que N\n");
    printf("\t13. Verificar si un numero natural es primo\n");
    printf("\t0. Salir\n");
    printf("Opcion: ");
    scanf("%d", &eleccion);
    printf("\n\n");

    return eleccion;
}

//Ejercicio 01
void ejercicio01(){

    int n;

    do{
        printf("Ingrese un numero natural para saber su factorial: ");
        scanf("%d", &n);
    }while(n < 0);

    printf("El factorial de %d es: %d", n, factorial(n));
}

//Ejercicio 02
void ejercicio02(){

    int n,
        m;

    do{
        printf("Ingrese el primer numero natural para saber su combinatorio: ");
        scanf("%d", &n);
        printf("Ingrese el segundo numero natural para saber su combinatorio: ");
        scanf("%d", &m);
    }while(n < 0 || m < 0);

    printf("El combinatorio de %d y %d es: %.2lf", n, m, combinatorio(n,m));
}

//Ejercicio 03
void ejercicio03(){

    double n;
    printf("Ingrese un numero para elevar e a dicho numero: ");
    scanf("%lf", &n);

    printf("E elevado a %.2f es %.5f", n, eALaX(n));

}

//Ejercicio 04
void ejercicio04(){

    double n;
    do{
        printf("Ingrese un numero para saber su raiz cuadrada: ");
        scanf("%lf", &n);
    }while(n < 0);

    printf("La raiz cuadrada de %.2f es %.5f", n, raizCuadrada(n));

}

//Ejercicio 05
void ejercicio05(){

    int n;

    do{
        printf("Ingrese un numero natural para saber si esta en la serie Fibonacci: ");
        scanf("%d", &n);
    }while(n < 0);

    int BOOL = estaEnFibonacci(n);
    if(BOOL)
        printf("%d esta en la serie Fibonacci", n);
    else
        printf("%d no esta en la serie Fibonacci", n);
}

//Ejercicio 06
void ejercicio06(){

    float n;
    int cant;
    printf("Ingrese un numero para saber su seno: ");
    scanf("%f", &n);
    printf("Ingrese un numero para saber la cantidad de iteraciones: ");
    scanf("%d", &cant);

    printf("El seno de %.2f es %.5f", n, seno(n, cant));

}

//Ejercicio 07
void ejercicio07(){

    int n;

    do{
        printf("Ingrese un numero natural para saber si DEFICIENTE, PERFECTO O ABUNDANTE: ");
        scanf("%d", &n);
    }while(n < 0);

    naturalPerfectoDeficienteOAbundante(n);
}

//Ejercicio 08
void ejercicio08(){

    int n,
        m;

    do{
        printf("Ingrese el primer numero natural para realizar el producto: ");
        scanf("%d", &n);
        printf("Ingrese el segundo numero natural para realizar el producto: ");
        scanf("%d", &m);
    }while(n < 0 || m < 0);

    printf("El producto entre %d y %d es %d", n, m, productoPorSumasSucesivas(n,m));
}

//Ejercicio 09
void ejercicio09(){

    int n,
        m;

    printf("Ingrese el primer numero natural para realizar la division: ");
    scanf("%d", &n);

    do{
        printf("Ingrese el segundo numero natural para realizar la division: ");
        scanf("%d", &m);
    }while(m == 0);

    Division division = cocienteYResto(n,m);
    printf("El cociente de la division entre %d y %d es: %d", n,m,division.cociente);
    printf("\nEl resto de la division entre %d y %d es: %d", n,m,division.resto);
}

//Ejercicio 10
void ejercicio10(){

    int n;
    do{
        printf("Ingrese la cantidad de primeros numeros naturales a sumar: ");
        scanf("%d", &n);
    }while(n <= 0);

    printf("La suma de los primeros %d numeros naturales es %d", n, sumaPrimerosNNaturales(n));
}

//Ejercicio 11
void ejercicio11(){

    int n;
    do{
        printf("Ingrese la cantidad de primeros numeros naturales pares a sumar: ");
        scanf("%d", &n);
    }while(n <= 0);

    printf("La suma de los primeros %d numeros naturales pares es %d", n, sumaPrimerosNPares(n));

}

//Ejercicio 12
void ejercicio12(){

    int n;
    do{
        printf("Ingrese un numero natural mayor a 1 cuyos numeros pares menores a el se sumaran: ");
        scanf("%d", &n);
    }while(n <= 1);

    printf("La suma de los numeros pares menores a %d es %d", n, sumaParesMenoresAN(n));

}

//Ejercicio 13 (ejemplo usando punteros)
void ejercicio13(){

    int n;
    do{
        printf("Ingrese un numero natural para saber si es primo: ");
        scanf("%d", &n);
    }while(n <= 1);

    BOOL *primo = esPrimo(&n);

    if(*primo)
        printf("%d es primo", n);
    else
        printf("%d no es primo", n);

    free(primo);
}
