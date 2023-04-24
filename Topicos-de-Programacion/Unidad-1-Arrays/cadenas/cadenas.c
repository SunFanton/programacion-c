#include "cadenas.h"

int contarPalabras(char *cad){

    int cont = 0,
        i = 0;
    while(*cad != '\0'){
        if(*cad == ' ' && i > 0 && *(cad-1) != ' ' && *cad != '.')
            cont++;
        i++;
        cad++;
    }
    return cont;
}

int strlenPropio(const char *cad){

    int cont = 0;
    while(*cad){
        cont++;
        cad++;
    }

    return cont;
}

// Función para implementar la función de subcadena en C
char* substring(char *destination, const char *source, int beg, int n)
{
    // extrae `n` caracteres de la string de origen a partir del índice `beg`
    // y copiarlos en la string de destino
    while (n > 0)
    {
        *destination = *(source + beg);

        destination++;
        source++;
        n--;
    }

    // string de destino de terminación nula
    *destination = '\0';

    // devuelve la string de destino
    return destination;
}

///EJERCICIO 1.6
int cadenaEsPalindromo(char *cadena){

    int longitud = strlenPropio(cadena) + 1;
    char cadenaOriginal[longitud];
    char cadenaInvertida[longitud];
    char *prtInvertida;
    prtInvertida = cadenaInvertida;

    substring(cadenaOriginal, cadena, 0, strlenPropio(cadena));
    char *fin = cadena + strlenPropio(cadena);
    //int i = 0;

    while(fin >= cadena){
        *prtInvertida = *fin;
        fin--;
        prtInvertida++;
    }

    *cadenaInvertida = '\0';

    int comp = strcmpi(cadenaOriginal,cadenaInvertida);
    BOOL esPalindromo = comp == 0 ? TRUE : FALSE;

    return esPalindromo;
/*
    char cadena1[longitud];
    char cadena2[longitud];
    char *inicio = cadena;
    char *fin = cadena + longitud - 2; //-2 porque el ultimo caracter es de fin de cadena
    int i = 0;

    while(cadena <= fin){
        cadena1[i] = *cadena;
        cadena++;
        i++;
    }
    i = 0;
    cadena = inicio;

    while(fin >= cadena){
        cadena2[i] = *fin;
        fin--;
        i++;
    }

    int comp = strcmpi(cadena1,cadena2);
    BOOL esPalindromo = comp == 0 ? TRUE : FALSE;

    return esPalindromo;
    */
}

///EJERCICIO 1.7
int valorNumericoEnteroDeCadena(char *cadena){

    int num = 0;

    /*Los numeros son representados a partir del 30 (equivalente a 0) en ASCII
    Si a un char que representa un digito le restamos 30, obtenemos su valor numerico
    Ej: 30 = 0 en ASCII. 30 - 30 = 0 en int
    Como tenemos mas d eun char y mas de un digito, debemos multiplicar por 10
    para ir agregando las unidades. EJ:
    1 * 10 = 10 => 10 + 2 = 12, 12 * 10 = 120 => 120 + 3 = 123...*/
    for(int i = 0; cadena[i] != '\0'; i++){
        num = num * 10 + cadena[i] - '0';
    }

    return num;
}

///EJERJCICIO 1.8
int cantidadOcurrenciasPalabra(char *cadena, char *buscada){

   //int lengCadena = strlen(cadena);
   //int lengBuscada = strlen(buscada);
   int lengCadena = strlen(cadena);
   int lengBuscada = strlen(buscada);

   if(lengBuscada > lengCadena){
        return -1;
   }


    int i = 0,
        cont = 0;
    char subCadena[lengBuscada];
    int comp;

    while(i < lengCadena){
        if(i + lengBuscada <= lengCadena){
             substring(subCadena,cadena,i,lengBuscada);
             comp = strcmpi(subCadena, buscada);
             if(!comp){
                cont++;
             }
        }
        i++;
    }
    return cont;

}
