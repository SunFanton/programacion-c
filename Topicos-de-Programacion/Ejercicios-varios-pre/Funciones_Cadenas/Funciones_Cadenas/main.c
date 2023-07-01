#include <stdio.h>
#include <stdlib.h>
#include "Cadenas.h"

int main()
{
    //Cadena a minuscula
    char cadAMinus[21] = "HoLa coMO estaN";
    for(int i = 0; i <= miStrlen(cadAMinus); i++){
        cadAMinus[i] = MI_TO_LOWER(cadAMinus[i]);
    }
    printf("MI_TO_LOWER()\n");
    printf("A minuscula: %s\n\n", cadAMinus);

    //Cadena a mayuscula
    char cadAMayus[21] = "HoLa coMO estaN";
    for(int i = 0; i <= miStrlen(cadAMayus); i++){
        cadAMayus[i] = MI_TO_UPPER(cadAMayus[i]);
    }
    printf("MI_TO_UPPER()\n");
    printf("A mayuscula: %s\n\n", cadAMayus);

    //Longitud de cadena (sin caracter nulo)
    char cad1[10] = "Hola";
    printf("miStrlen()\n");
    printf("La longitud de %s es %d\n\n", cad1, (int)miStrlen(cad1));

    //Buscar primer ubicacion de caracter
    char cad2[21] = "Los alces";
    char car = 'a';

    //Copiar una cadena en otra:
    printf("miStrcpy()\n");
    char cadOrigen[21] = "Hola, que tal";
    char cadDestino[21];
    miStrcpy(cadDestino, cadOrigen);
    printf("Cadena destino: %s\n\n", cadDestino);

    //Concatenar
    printf("miStrcat()\n");
    char cadConcat1[21] = "Hola";
    char cadConcat2[21] = " como estan todos?";
    miStrcat(cadConcat1, cadConcat2);
    printf("Resultado concatenacion: %s\n\n", cadConcat1);

    //Compara estricto
    printf("mistrcmp()\n");
    char comp1[21] = "hoLA";
    char comp2[21] = "Hola";
    int cmpResul = miStrcmp(comp1, comp2);
    if(cmpResul)
        printf("Las cadenas %s y %s son distintas\n\n", comp1, comp2);
    else
       printf("Las cadenas %s y %s son iguales\n\n", comp1, comp2);

    //Compara no estricto
    printf("mistrcmpi()\n");
    char compi1[21] = "hoLA";
    char compi2[21] = "Hola";
    cmpResul = miStrcmpi(compi1, compi2);
    if(cmpResul)
        printf("Las cadenas %s y %s son distintas\n\n", compi1, compi2);
    else
       printf("Las cadenas %s y %s son iguales\n\n", compi1, compi2);

    //Normalizar cadena
    printf("normalizeString()\n");
    char cadANormalizar[21] = "  hOLa  quE TaL ";
    printf("cadena sin normalizar: %s\n", cadANormalizar);
    normalizeString(cadANormalizar);
    printf("Cadena normalizada: %s\n\n", cadANormalizar);


    //atoi
    char cadAtoi[10] = "123abc";
    printf("%s a %d", cadAtoi, miAtoi(cadAtoi));

    return 0;
}
