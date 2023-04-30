#include <stdio.h>
#include <stdlib.h>
#include "cadenas.h"

int mostrarMenu();
void ejercicio1_6();
void ejercicio1_7();
void ejercicio1_8();
void ejercicio1_9();

int main(){

    int eleccion;
    eleccion = mostrarMenu();

    while(eleccion != 0){

        switch(eleccion){
            case 1:
                ejercicio1_6();
                break;
            case 2:
                ejercicio1_7();
                break;
            case 3:
                ejercicio1_8();
                break;
            case 4:
                ejercicio1_9();
                break;
            default:
                printf("No existe esa opcion, intente nuevamente");
                break;

        }
        eleccion = mostrarMenu();
    }
    return 0;

}

//Mostrar menu
int mostrarMenu(){

    int eleccion;
    printf("\n\n******************** VECTORES *******************\n\n");
    printf("Opciones: \n");
    printf("\t1. Averiguar si una cadena de caracteres es palindromo.\n");
    printf("\t2. Obtener el valor numerico de una cadena.\n");
    printf("\t3. Obtener cantidad de ocurrencias de una palabra (cadena) dentro de otra.\n");
    printf("\t4. Normalizar una cadena y quitar espacios excedentes.\n");
    printf("\t0. Salir\n\n");
    printf("Opcion elegida: ");
    scanf("%d", &eleccion);
    printf("\n\n");
    fflush(stdin);

    return eleccion;
}

//Ejercicio 1.6
void ejercicio1_6(){

    int longitud;
    printf("\nIngrese la longitud de la cadena (ultima posicion sera de fin de cadena): ");
    scanf("%d", &longitud);
    char cadena[longitud];
    fflush(stdin);
    printf("\nIngrese la cadena: ");
    //fgets(cadena,longitud,stdin);
    gets(cadena);

    BOOL resul = cadenaEsPalindromo(cadena);
    if(resul){
        printf("\nLa cadena %s es palindromo", cadena);
    }
    else{
        printf("\nLa cadena %s no es palindromo", cadena);
    }
}

//Ejercicio 1.7
void ejercicio1_7(){

    int longitud;
    printf("\nIngrese la longitud de la cadena (ultima posicion sera de fin de cadena): ");
    scanf("%d", &longitud);
    fflush(stdin);
    char cadena[longitud];
    printf("\nIngrese la cadena (debe representar digitos numericos): ");
    fgets(cadena,longitud,stdin);
    fflush(stdin);

    printf("\nLa cadena en digitos numericos es %d", valorNumericoEnteroDeCadena(cadena));
}

//Ejercicio 1.8
void ejercicio1_8(){

    int longitud;

    printf("\nIngrese la longitud de la cadena (ultima posicion sera de fin de cadena): ");
    scanf("%d", &longitud);
    fflush(stdin);
    char cadena[longitud];
    printf("\nIngrese la cadena: ");
    gets(cadena);
    fflush(stdin);

    printf("\nIngrese la longitud de la cadena cuya cantidad de ocurrencias se buscaran: ");
    scanf("%d", &longitud);
    fflush(stdin);
    char buscada[longitud];
    printf("\nIngrese la cadena: ");
    gets(buscada);
    fflush(stdin);

    printf("\nLa cantidad de ocurrencias en la cadena es %d", cantidadOcurrenciasPalabra(cadena,buscada));
}

//Ejercicio 1.9
void ejercicio1_9(){

    int longitud;

    printf("\nIngrese la longitud de la cadena (ultima posicion sera de fin de cadena): ");
    scanf("%d", &longitud);
    fflush(stdin);
    char cadena[longitud];
    printf("\nIngrese la cadena: ");
    gets(cadena);
    fflush(stdin);

    normalizarCadenaYQuitarEspaciosExcedentes(cadena);
    printf("\n\nLa cadena normalizada y sin espacios excedentes es: %s", cadena);

}
