#ifndef MANEJOARCHIVO_H_INCLUDED
#define MANEJOARCHIVO_H_INCLUDED
#define CANT_PARCIALES 2

typedef struct{
    int numAlu;
    char apNom[21];
    float parciales[CANT_PARCIALES];
    float promedio;
}t_alumno;


int ingresarAlumnos(t_alumno *vec_alu, float *promGenerales);
void ingresarParcialesYCalcularPromedio(float *parciales, float *promedio);
void mostrarAlumnosPorPantalla(t_alumno *vec_alu, int ce);
int cargarArchivoTextoAlumnosLongitudFija(char *path, t_alumno *vec_alu, int cantIngresada);

#endif // MANEJOARCHIVO_H_INCLUDED
