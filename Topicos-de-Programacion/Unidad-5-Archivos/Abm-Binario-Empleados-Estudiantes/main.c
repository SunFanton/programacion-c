#include <stdio.h>
#include <stdlib.h>

/*
Se dispone de dos archivos binarios empleados y estudiantes
Cada registro del primer archivo contiene los campos: dni, apellido, nombre y sueldo
Cada registro del segundo archivo contiene los campos: dni, apellido, nombre y promedio
Ambos archivos estan ordenados alfabeticamente por apellido, nombre y dni
Ambos archivos deben ser leidos una sola vez y no deben ser almacenados en arrays
El sueldo es double y el promedio es float
Escriba un programa que, leyendo ambos archivos, actualice el sueldo de aquellos empleados
que tengan un registro de estudiante con un promedio superior a 7 en un 7,28%
*/

typedef struct{
    int dni;
    char nombre[30];
    char apellido[30];
    float promedio;
}t_estudiante;

typedef struct{
    int dni;
    char nombre[30];
    char apellido[30];
    double sueldo;
}t_empleado;


int cargar_archivo_binario(char* path, void* data, size_t tam);


int main()
{
    t_estudiante estudiante;
    t_estudiante estudiantes[] = {
                                    {34567877, "Ana", "Diaz", 6.5},
                                    {43546748, "Emilia", "Torres", 8},
                                    {41345625, "Julian", "Fuentes", 7.5}
                                 };
    if(!cargar_archivo_binario("estudiantes.dat", estudiantes, sizeof(estudiantes))){
        printf("No se pudo cargar el archivo");
        return 1;
    }

    printf("Lectura de archivo estudiantes.dat antes de modificacion\n\n");
    int contEstudiante = 1;
    FILE *pfEstudiante = fopen("estudiantes.dat", "r+b");
    fread(&estudiante, sizeof(t_estudiante), 1, pfEstudiante);
    while(!feof(pfEstudiante)){
        printf("Estudiante %d -> Nombre: %s, Apellido: %s, DNI: %d, Promedio: %.2f\n",
               contEstudiante, estudiante.nombre, estudiante.apellido, estudiante.dni, estudiante.promedio);
        fread(&estudiante, sizeof(t_estudiante), 1, pfEstudiante);
        contEstudiante++;
    }


    fclose(pfEstudiante);

    return 0;
}

int cargar_archivo_binario(char* path, void* data, size_t tam){

    char *ptrData = (char*)data;

    FILE *pf = fopen(path, "wb");
    if(!pf){
        return 0;
    }

    fwrite(ptrData, tam, 1, pf);
    fclose(pf);
    return 1;
}
