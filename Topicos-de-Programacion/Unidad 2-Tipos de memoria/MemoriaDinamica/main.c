#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

char* copiaCadena(const char *origen);
void* copiaCosas(void* elemento, unsigned tam);
void* miMemmove(void* destino, void* origen, size_t tam);
void* miMemcpy(void* destino, void* origen, size_t tam);

typedef int BOOL;

typedef struct{
    int dni;
    char nombreApellido[30];
    char genero;
    float peso;
}tPersona;

int main()
{

    ///---------------------------------------------------------------

    printf("***** EJERCICIO 2.1 *****\n\n");

    int ce1 = 10;
    int *ptr1, *inicio;
    ptr1 = (int*)malloc(ce1 * sizeof(int)); //10 elementos de tipo int

    if(ptr1 == NULL){
        printf("Memoria insuficiente para asignar dinamicamente");
        exit(0);
    }

    inicio = ptr1;
    for(int i = 0; i < ce1; i++){
        *ptr1 = i+1;
        ptr1++;
    }

    printf("Elementos generados: \n");

    ptr1 = inicio;
    for(int i = 0; i < ce1; i++){
        printf("Elemento %d: %d\n", i+1, *ptr1);
        ptr1++;
    }

    ptr1 = inicio; //Para que se libere la memoria desde el comienzo del bloque
    free(ptr1);

    ///---------------------------------------------------------------

    printf("\n\n");
    printf("***** EJERCICIO 2.2 *****\n\n");

    int ce2;
    int *ptr2;

    do{
        printf("Ingrese la cantidad de elementos deseada: ");
        scanf("%d", &ce2);
    }while(ce2 < 0);

    ptr2 = (int*)malloc(ce2 * sizeof(int));

    if(ptr2 == NULL){
        printf("Memoria insuficiente para asignar dinamicamente");
        exit(0);
    }

    for(int i = 0; i < ce2; i++){
        ptr2[i] = i + 1;
    }

    printf("\nElementos generados: \n");

    for(int i = 0; i < ce2; i++){
        printf("Elemento %d: %d\n", i+1, ptr2[i]);
    }

    free(ptr2);

    ///---------------------------------------------------------------

    printf("\n\n");
    printf("***** EJERCICIO 2.3 *****\n\n");

    int ce3 = 1;
    tPersona *ptr3, *inicioPersona;
    ptr3 = (tPersona*)malloc(ce3 * sizeof(tPersona));

    if(ptr3 == NULL){
        printf("Memoria insuficiente para asignar dinamicamente");
        exit(0);
    }

    inicioPersona = ptr3;
    for(int i = 0; i < ce3; i++){
        fflush(stdin);
        printf("\nIngrese el nombre y apellido de la persona: ");
        gets(ptr3->nombreApellido);
        printf("Ingrese el DNI: ");
        scanf("%d", &ptr3->dni);
        fflush(stdin);
        printf("Ingrese el genero (M o F): ");
        scanf("%c", &ptr3->genero);
        printf("Ingrese el peso: ");
        scanf("%f", &ptr3->peso);

        ptr3++;
    }

    ptr3 = inicioPersona;

    printf("\nElementos ingresados: \n");
    for(int i = 0; i < ce3; i++){
        printf("Nombre y apellido: %s\n", ptr3->nombreApellido);
        printf("DNI: %d\n", ptr3->dni);
        printf("Genero: %c\n", ptr3->genero);
        printf("Peso: %.2f\n", ptr3->peso);

        printf("\n");
        ptr3++;
    }

    ptr3 = inicioPersona;

    free(ptr3);

    ///---------------------------------------------------------------

    printf("\n\n");
    printf("***** EJERCICIO 2.4 *****\n\n");

    char cadena[20] = "Hola";
    int vector[5] = {1,2,3,4,5};

    char *ptrCadena;
    ptrCadena = copiaCadena(cadena);

    printf("Cadena: %s\n", ptrCadena);

    int *ptrGenerico;
    ptrGenerico = (int*)copiaCosas(vector, sizeof(int)*3);
    printf("Primer pos vector de int: %d\n", *ptrGenerico);
    free(ptrGenerico);

    ///---------------------------------------------------------------

    printf("\n\n");
    printf("***** EJERCICIO 2.5 *****\n\n");

    printf("Implementacion propia de memmove()\n\n");

    printf("Usando cadenas:\n");

    char ch1[] = {'L','i','n','u','x'};

    int length = sizeof(ch1)/sizeof(ch1[0]); // tam vector/tam tipo dato vector

    printf ("Antes de aplicar miMemmove(): ");
    for (int i=0; i< length; i++){
        printf("%c", ch1[i]);
    }

    char *ch2 = &ch1[2]; //La primer pos de ch2 es a partir del indice 2 de ch1 (letra n)
    /*Sobreescribira lo que haya a partir de ch1 subindice 2 hasta 2 posiciones mas*/
    miMemmove(ch2, ch1, sizeof(char)*2); //Los datos de ch1 seran sobreescritos a partir del indice 2 (letra n)

    printf ("\nDespues de aplicar miMemmove(): ");

    for (int i=0; i<5; i++){
        printf ("%c", ch1[i]);
    }

     printf("\n\nUsando vector de int:\n");

    int ent1[] = {1,2,3,4,5};

    length = sizeof(ent1)/sizeof(ent1[0]); // tam vector/tam tipo dato vector

    printf ("Antes de aplicar miMemmove(): ");
    for (int i=0; i < length; i++){
        printf("%d", ent1[i]);
    }

    int *ent2 = &ent1[2];
    /*Sobreescribira lo que haya a partir de ent1 subindice 2 hasta 3 posiciones mas*/
    miMemmove(ent2, ent1, sizeof(int)*3);

    printf ("\nDespues de aplicar miMemmove(): ");

    for (int i=0; i<5; i++){
        printf ("%d", ent1[i]);
    }

    ///---------------------------------------------------------------

    printf("\n\n");
    return 0;
}

//-------------------------
/*Funciones con fines didacticos que NO se recomiendan usar en entornos productivos
Quizas por la erronea gestion de la memoria dinamica, o por la erronea gestion
en la copia de datos de un bloque de memoria a otro ???*/
//CONSULTAR !!
char* copiaCadena(const char *origen){

    int ce = 1;
    char *inicio = origen;
    while(*origen){
        ce++;
        origen++;
    }
    origen = inicio;
    char *ptr = (char*)malloc(ce * sizeof(char));
    inicio = ptr;

    while(*origen){
        *ptr = *origen;
        ptr++;
        origen++;
    }
    *ptr = '\0';
    ptr = inicio;

    return ptr;
}

void* copiaCosas(void* elemento, unsigned tam){

    char *copia = (char*)elemento;
    char *ptr = (char*)malloc(tam * sizeof(char));

    for(int i = 0; i < tam; i++){
        ptr[i] = copia[i];
    }

    return ptr;
}

//-------------------------

//memmove() y memcopy() son similares, aunque se recomienda mas utilizar memmove por posible perdida de datos de memcopy()

/*Esta implementacion propia de memmove, como tambien la original de la biblioteca
stdlib lo que hace es copiar en las posiciones en que se va moviendo el puntero
destino los datos de las posiciones del puntero origen. Pero para ello, ambos punteros
se castean a char para poder copiar byte a byte los datos, teniendo como limite tope
en la iteracion de la copia byte a byte el parametro tam, que no es mas que la
cantidad total de bytes*/
void* miMemmove(void* destino, void* origen, size_t tam){

    // Casteo de los punteros genericos a char, que representa la unidad mas pequeña de tamaño en bytes
    //1 char = 1 byte
    char *cDestino = (char *)destino;
    char *cOrigen = (char *)origen;

    //Se crea un puntero de char temporario para guardar los datos del origen
    /*No puedo usar asi: cDestino[i] = cOrigen[i] porque los datos de cOrigen se van a
    ir sobreescribiendo (como se ve en los punteros que se pasan como parametros en el main)
    y por eso necesito otro puntero temporal*/
    char *temp = (char*)malloc(tam * sizeof(char));

    //Se copian los datos de cOrigen[] a temp[] byte por byte
    for (int i=0; i < tam; i++)
        temp[i] = cOrigen[i];

    //Se copia los datos de temp[] a cDestino[] byte por byte
    for (int i=0; i < tam; i++)
        cDestino[i] = temp[i];

    free(temp);

    return cDestino;
}

void* miMemcpy(void* destino, void* origen, size_t tam){

    char *cDestino = (char*)destino;
    char *cOrigen = (char*)origen;

    for(int i = 0; i < tam; i++){
        *cDestino = *cOrigen;
        cOrigen++;
        cDestino++;
    }
    return destino;
}
