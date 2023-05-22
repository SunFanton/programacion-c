#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    char nombre[20];
    char apellido[20];
    float promedio;
}t_estudiante;

typedef struct{
    int dni;
    char nombre[20];
    char apellido[20];
    double sueldo;
}t_empleado;

int comparaEstudiantePorApellidoNombreYDni(void *p1, void *p2);
int comparaEmpleadoPorApellidoNombreYDni(void *p1, void *p2);
void *buscarMenor(void *vec, void *fin, size_t tam, int(*cmp)(void *p1,void *p2));
void intercambiar(void *p1, void *p2, size_t tam);
void *ordenar(void *vec, size_t ce, size_t tam, int(*cmp)(void *p1,void *p2));
int cargar_archivo_binario(char* path, void* data, size_t tam);

int main()
{
    t_estudiante estudiante;
    t_estudiante estudiantes[] = {
                                    {34567877, "Ana", "Diaz", 6.5},
                                    {43546748, "Emilia", "Torres", 8},
                                    {41342222, "Julian", "Fuentes", 7.5},
                                    {38652453, "Silvia", "Andrejasevich", 9},
                                    {41345600, "Marina", "Rodriguez", 8},
                                    {42563752, "Marcos", "Diaz", 5},
                                    {39890766, "Mauricio", "Gomez", 6.5},
                                    {44567822, "Analia", "Martin", 4.5},
                                    {40356289, "Juan", "Ferrara", 9.5},
                                    {41345625, "Lucia", "Sanchez", 3}
                                 };

    size_t tamEstudiante = sizeof(t_estudiante);
    size_t ceEstudiantes = sizeof(estudiantes)/sizeof(t_estudiante);
    ordenar(estudiantes,ceEstudiantes,tamEstudiante,comparaEstudiantePorApellidoNombreYDni);

    if(!cargar_archivo_binario("estudiantes.dat", estudiantes, sizeof(estudiantes))){
        printf("No se pudo cargar el archivo");
        return 1;
    }

    t_empleado empleado;
    t_empleado empleados[] = {
                                    {34567877, "Ana", "Diaz", 100000},
                                    {43546748, "Emilia", "Torres", 98000},
                                    {41342222, "Julian", "Fuentes", 250000},
                                    {38652453, "Silvia", "Andrejasevich", 300000},
                                    {41345600, "Marina", "Rodriguez", 99000},
                                    {42563752, "Marcos", "Diaz", 87000},
                                    {39890766, "Mauricio", "Gomez", 265000},
                                    {44567822, "Analia", "Martin", 80000},
                                    {40356289, "Juan", "Ferrara", 120000},
                                    {39876453, "Tamara", "Suarez", 135000},
                                    {37865322, "Tobias", "Ibarra", 280000},
                                    {38523415, "Mariana", "Rodriguez", 230000},
                                    {34567265, "Francisco", "Fernandez", 305000},
                                    {42765342, "Sofia", "Nunez", 103000},
                                    {33456235, "Marcela", "Rios", 302000}
                                 };
    size_t tamEmpleado = sizeof(t_empleado);
    size_t ceEmpleados = sizeof(empleados)/sizeof(t_empleado);
    ordenar(empleados,ceEmpleados,tamEmpleado,comparaEmpleadoPorApellidoNombreYDni);

     if(!cargar_archivo_binario("empleados.dat", empleados, sizeof(empleados))){
        printf("No se pudo cargar el archivo");
        return 1;
    }

    printf("Lectura de archivo estudiantes.dat\n");
    int contEstudiante = 1;
    FILE *pfEstudiante = fopen("estudiantes.dat", "rb");
    fread(&estudiante, sizeof(t_estudiante), 1, pfEstudiante);
    printf("ESTUDIANTE           NOMBRE         APELLIDO       DNI        PROMEDIO\n");
    while(!feof(pfEstudiante)){
        printf("%10d  %15s  %15s  %8d  %9.2f\n",
               contEstudiante, estudiante.nombre, estudiante.apellido, estudiante.dni, estudiante.promedio);
        fread(&estudiante, sizeof(t_estudiante), 1, pfEstudiante);
        contEstudiante++;
    }

    printf("\n\nLectura de archivo empleados.dat antes de modificacion de sueldos\n");
    int contEmpleado = 1;
    FILE *pfEmpleado = fopen("empleados.dat", "r+b");
    fread(&empleado, sizeof(t_empleado), 1, pfEmpleado);
    printf("EMPLEADO           NOMBRE         APELLIDO       DNI        SUELDO\n");
    while(!feof(pfEmpleado)){
         printf("%8d  %15s  %15s  %8d  %12.2lf\n",
               contEmpleado, empleado.nombre, empleado.apellido, empleado.dni, empleado.sueldo);
        fread(&empleado, sizeof(t_empleado), 1, pfEmpleado);
        contEmpleado++;
    }


    fseek(pfEstudiante,0,SEEK_SET);
    fseek(pfEmpleado,0,SEEK_SET);

    fread(&estudiante, sizeof(t_estudiante), 1, pfEstudiante);
    int dni;
    while(!feof(pfEstudiante)){

        if(estudiante.promedio > 7.0){
            dni = estudiante.dni;
            fread(&empleado, sizeof(t_empleado), 1, pfEmpleado);

            while(!feof(pfEmpleado)){
                if(empleado.dni == dni){
                    empleado.sueldo += empleado.sueldo*7.28/100;
                    fseek(pfEmpleado, (long)-sizeof(t_empleado), SEEK_CUR);
                    fwrite(&empleado, sizeof(t_empleado), 1, pfEmpleado);
                    fseek(pfEmpleado, 0, SEEK_CUR);
                }
                fread(&empleado, sizeof(t_empleado), 1, pfEmpleado);
            }
            fseek(pfEmpleado, 0, SEEK_SET);
        }
        fread(&estudiante, sizeof(t_estudiante), 1, pfEstudiante);
    }

    fseek(pfEmpleado,0,SEEK_SET);

    printf("\n\nLectura de archivo empleados.dat despues de modificacion de sueldos\n");
    contEmpleado = 1;
    fread(&empleado, sizeof(t_empleado), 1, pfEmpleado);
    printf("EMPLEADO           NOMBRE         APELLIDO       DNI        SUELDO\n");
    while(!feof(pfEmpleado)){
        printf("%8d  %15s  %15s  %8d  %12.2lf\n",
               contEmpleado, empleado.nombre, empleado.apellido, empleado.dni, empleado.sueldo);
        fread(&empleado, sizeof(t_empleado), 1, pfEmpleado);
        contEmpleado++;
    }

    fclose(pfEstudiante);
    fclose(pfEmpleado);

    return 0;
}

///CARGAR DATOS EN ARCHIVO BINARIO
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

///FUNCIONES DE COMPARACION PERSONALIZADAS
int comparaEstudiantePorApellidoNombreYDni(void *p1, void *p2){
    t_estudiante *pEst1 = (t_estudiante*)p1;
    t_estudiante *pEst2 = (t_estudiante*)p2;
    int compApellido = strcmpi(pEst1->apellido, pEst2->apellido);
    int compNombre = strcmpi(pEst1->nombre, pEst2->nombre);
    int compDNI = pEst1->dni - pEst2->dni;

    if(compApellido != 0)
        return compApellido;
    else if(compNombre != 0)
        return compNombre;
    else
        return compDNI;
}

int comparaEmpleadoPorApellidoNombreYDni(void *p1, void *p2){
    t_empleado *pEmp1 = (t_empleado*)p1;
    t_empleado *pEmp2 = (t_empleado*)p2;
    int compApellido = strcmpi(pEmp1->apellido, pEmp2->apellido);
    int compNombre = strcmpi(pEmp1->nombre, pEmp2->nombre);
    int compDNI = pEmp1->dni - pEmp2->dni;

    if(compApellido != 0)
        return compApellido;
    else if(compNombre != 0)
        return compNombre;
    else
        return compDNI;
}

///FUNCIONES GENERICAS PARA EL ORDENAMIENTO
void *buscarMenor(void *vec, void *fin, size_t tam, int(*cmp)(void *p1,void *p2)){
    void *men = vec;
    vec += tam;

    while(vec <= fin){
        if(cmp(vec, men) < 0){
            men = vec;
        }
        vec += tam;
    }
    return men;
}

void intercambiar(void *p1, void *p2, size_t tam){
    static char aux[1000];
    memcpy(aux,p1,tam);
    memcpy(p1,p2,tam);
    memcpy(p2,aux,tam);
}

void *ordenar(void *vec, size_t ce, size_t tam, int(*cmp)(void *p1,void *p2)){
    void *inicio = vec;
    void *fin = vec + (ce - 1)*tam;
    void *men;

    while(vec < fin){
        men = buscarMenor(vec,fin,tam,cmp);
        if(men != vec){
            intercambiar(vec,men,tam);
        }
        vec += tam;
    }
    return inicio;
}
