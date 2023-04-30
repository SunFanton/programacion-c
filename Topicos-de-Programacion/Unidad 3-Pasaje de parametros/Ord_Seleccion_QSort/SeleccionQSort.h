#ifndef SELECCIONQSORT_H_INCLUDED
#define SELECCIONQSORT_H_INCLUDED
#define TRUE 1
#define FALSE 0

typedef int BOOL;

typedef struct {
    int dni;
    char apellido[20];
    char nombres[30];
    float peso;
} tPersona;

int compararEntero(const void *p1, const void *p2);
int compararPersonaDni(const void *p1, const void *p2);
int compararPersonaApellidoYNombre(const void *p1, const void *p2);
int compararPersonaPeso(const void *p1, const void *p2);


#endif // SELECCIONQSORT_H_INCLUDED
