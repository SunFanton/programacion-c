#ifndef SELECCIONGENERICO_H_INCLUDED
#define SELECCIONGENERICO_H_INCLUDED
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
void *buscarMenor(void *vec, void *fin, size_t tam, int (*comparar)(const void *p1, const void *p2));
void intercambiar(void *p1, void *p2, size_t tam);
void *ordSeleccion(void *vec, size_t ce, size_t tam, int (*comparar)(const void *p1, const void *p2));


#endif // SELECCIONGENERICO_H_INCLUDED
