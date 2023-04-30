#include "cadenas.h"

BOOL esLetra(char caracter){
    if(caracter >= 'A' && caracter <='z')
        return TRUE;
    return FALSE;
}

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
char* substringPropio(char *destination, const char *source, int beg, int n)
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

void toLowerPropio(char* str) {
    while (*str) {
        if (*str >= 'A' && *str <= 'Z') {//Si el caracter se encuentra en ASCII entre A y Z
            //a minuscula en ASCII tiene una valor mayor que A mayuscula.
            /*Como la distancia entre ambas va a ser la misma distancia que separa
            a cada letra mayuscula de su respectiva minuscula, al caracter actual en mayuscula
            se le suma esa diferencia para que llegue a la posicion en Ascii de su minuscula*/
            *str = *str + ('a' - 'A');
        }
        str++;
    }
}

int strcmpiPropio(char *cadena1, char *cadena2){

    toLowerPropio(cadena1);
    toLowerPropio(cadena2);
    int flag=0;
    while(*cadena1!='\0' && *cadena2!='\0'){
        if(*cadena1!=*cadena2){
            flag = 1;
            break;
        }
        cadena1++;
        cadena2++;
    }

    if(flag == 0)
        return 0;
    else
        return 1;
}

///EJERCICIO 1.6
int cadenaEsPalindromo(char *cadena){

    int longitud = strlenPropio(cadena) + 1;
    char cadenaOriginal[longitud];
    char cadenaInvertida[longitud];

    substringPropio(cadenaOriginal, cadena, 0, strlenPropio(cadena));
    //substring(cadenaInvertida, cadena, 0, strlenPropio(cadena));
    char *fin = cadena + strlenPropio(cadena) - 1;
    int i = 0;

    while(fin >= cadena){
        cadenaInvertida[i] = *fin;
        fin--;
        i++;
    }

    cadenaInvertida[i] = '\0';

    //int comp = strcmpi(cadenaOriginal,cadenaInvertida);
    int comp = strcmpiPropio(cadenaOriginal,cadenaInvertida);
    BOOL esPalindromo = comp == 0 ? TRUE : FALSE;

    return esPalindromo;
}

///EJERCICIO 1.7
int valorNumericoEnteroDeCadena(char *cadena){

    int num = 0;
    int leng = strlenPropio(cadena) - 1;

    /*Los numeros son representados a partir del 30 (equivalente a 0) en ASCII
    Si a un char que representa un digito le restamos 30, obtenemos su valor numerico
    Ej: 30 = 0 en ASCII. 30 - 30 = 0 en int
    Como tenemos mas d eun char y mas de un digito, debemos multiplicar por 10
    para ir agregando las unidades. EJ:
    1 * 10 = 10 => 10 + 2 = 12, 12 * 10 = 120 => 120 + 3 = 123...*/
    for(int i = 0; i < leng; i++){
        num = num * 10 + cadena[i] - '0';
    }

    return num;
}

///EJERJCICIO 1.8
int cantidadOcurrenciasPalabra(char *cadena, char *buscada){

   //int lengCadena = strlen(cadena);
   //int lengBuscada = strlen(buscada);
   int lengCadena = strlenPropio(cadena);
   int lengBuscada = strlenPropio(buscada);

   if(lengBuscada > lengCadena){
        return -1;
   }


    int i = 0,
        cont = 0;
    char subCadena[lengBuscada];
    int comp;

    while(i < lengCadena){
        if(i + lengBuscada - 1 < lengCadena){
             substringPropio(subCadena,cadena,i,lengBuscada);
             //comp = strcmpi(subCadena, buscada);
             comp = strcmpiPropio(subCadena, buscada);
             if(!comp){
                cont++;
             }
        }
        i++;
    }
    return cont;

}

///EJERCICIO 1.9
void normalizarCadenaYQuitarEspaciosExcedentes(char *cadena){

    char *inicio = cadena;
    int cont = 0;

    while(*cadena){
        if(*cadena == ' ')
            cont++;
        while(*cadena && esLetra(*cadena)){
            if(*(cadena - 1)==' ' || cadena == inicio)
               *cadena = *cadena - ('a' - 'A'); //Paso a mayuscula la primer letra de la palabra
            //FALTA ELIMINAR ESPACIOS EXCEDENTES
            cadena++;
        }
        cadena++;
    }
}
