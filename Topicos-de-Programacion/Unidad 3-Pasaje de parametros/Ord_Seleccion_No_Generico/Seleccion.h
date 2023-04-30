#ifndef SELECCION_H_INCLUDED
#define SELECCION_H_INCLUDED
#define TRUE 1
#define FALSE 0

typedef int BOOL;

typedef struct {
    int dni;
    char apellido[20];
    char nombres[30];
    float peso;
} tPersona;

int *buscarMenorEntero(int *vec, int *fin);
void intercambiarEnteros(int *vec1, int *vec2);
void ordSeleccionEntero(int *vec, int ce);

tPersona *buscarMenorPersonaPorDni(tPersona *vec, tPersona *fin);
tPersona *buscarMenorPersonaPorApellidoYNombre(tPersona *vec, tPersona *fin);
tPersona *buscarMenorPersonaPorPeso(tPersona *vec, tPersona *fin);
void intercambiarPersonas(tPersona *vec1, tPersona *vec2);
void ordSeleccionPersonaPorDni(tPersona *vec, int ce);
void ordSeleccionPersonaPorApellidoYNombre(tPersona *vec, int ce);
void ordSeleccionPersonaPorPeso(tPersona *vec, int ce);

#endif // SELECCION_H_INCLUDED
