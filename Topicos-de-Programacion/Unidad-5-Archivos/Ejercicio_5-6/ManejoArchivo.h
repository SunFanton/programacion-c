#ifndef MANEJOARCHIVO_H_INCLUDED
#define MANEJOARCHIVO_H_INCLUDED
#define CANT_PARCIALES 2

typedef struct{
    int numAlu;
    char nombre[11];
    char apellido[11];
    float parciales[CANT_PARCIALES];
    float promedio;
}t_alumno;


int ingresarAlumnos(t_alumno *vec_alu, float *promGenerales);
void ingresarParcialesYCalcularPromedio(float *parciales, float *promedio);
void mostrarAlumnosPorPantalla(t_alumno *vec_alu, int ce);

#endif // MANEJOARCHIVO_H_INCLUDED
