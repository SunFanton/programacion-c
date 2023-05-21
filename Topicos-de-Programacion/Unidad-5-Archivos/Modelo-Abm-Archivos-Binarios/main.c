#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int d, m, a;
}t_fecha;

typedef struct
{
    int dni;
    char apyn[30];
    char sexo;
    float promedio;
    int notas[50];
    t_fecha f_ing;
    char estado;
} t_alumno;

int cargar_archivo(char * path);
/// Modificar el estado del alumno a 'I-Inactivo' cuando
/// la (fecha de ingreso del alumno sea menor 2000 y su estado sea 'A-Activo')

int main()
{
    FILE * pf;
    t_alumno alu;
    int tam_arch, cant_reg;
    if(!cargar_archivo("alus.dat"))
    {
        printf("No se pudo cargar el archivo");
        return 1;
    }
    pf = fopen("alus.dat", "r+b");
    if(!pf)///if(pf == NULL)
    {
        printf("No se pudo abrir el archivo");
        return 1;
    }
    fread(&alu, sizeof(t_alumno), 1, pf);
    while (!feof(pf))
    {
        if (alu.f_ing.a < 2000 && alu.estado == 'A')
        {
            alu.estado = 'I';
            fseek(pf, (long)-sizeof(t_alumno), SEEK_CUR);
           /// fseek(pf, -1L*(sizeof(t_alumno)), SEEK_CUR);
            fwrite(&alu, sizeof(t_alumno), 1, pf);
            fseek(pf, 0, SEEK_CUR);
        }
        fread(&alu, sizeof(t_alumno), 1, pf);
    }
   fseek(pf, 0, SEEK_END);

    //fseek(pfile,desplamiento(en bytes),origen);
    ///SEEK_SET Reposicionar comenzando desde el principio del archivo (es lo mismo poner un 0)
    ///SEEK_CUR Reposicionar comenzando desde la posición actual del puntero de archivo (es lo mismo poner un 1)
    ///SEEK_END Reposicionar comenzando desde el final del archivo (es lo mismo poner un 2)

    fseek(pf, 0, SEEK_SET);
    ///rewind(pf); === fseek(pf, 0, SEEK_SET);

    fprintf(stdout,"formato %d", 5); ///=== printf("formato %d", 5);
    fprintf(stderr,"formato %d", 5);
    ///Mostrar a los alumnos
    fread(&alu, sizeof(t_alumno), 1, pf);
    while (!feof(pf)){
        printf("\n%ld - %s, %02d/%02d/%d, %c", ftell(pf), alu.apyn, alu.f_ing.d, alu.f_ing.m, alu.f_ing.a, alu.estado);
        fread(&alu, sizeof(t_alumno), 1, pf);
    }
    fclose(pf);
    return 0;
}
int cargar_archivo(char * path){
    t_alumno alu_vec[] = {
                        {110, "Alumno 1", 'F', 5, {7,8},{1,2,2005}, 'I'},
                        {120, "Alumno 2", 'M', 4, {7,8}, {1,2,2015}, 'A'},
                        {130, "Alumno 3", 'M', 8, {7,8}, {1,2,2000}, 'A'},
                        {140, "Alumno 4", 'F', 7.5, {7,8}, {1,2,1998}, 'A'},
                        {150, "Alumno 5", 'F', 4, {7,8}, {1,2,1997}, 'A'},
                        {900, "Alumno 6", 'F', 8.5, {7,8,9},{1,2,2005}, 'A'},
                        {980, "Alumno 7", 'M', 8, {7,8, 9},{1,2,1999}, 'A'},
                        };
    FILE * pf = fopen(path, "wb");
    if(!pf)///if(pf == NULL)
    {
        return 0;
    }
    ///fwrite(alu_vec, sizeof(t_alumno), 7, pf);
    fwrite(alu_vec, sizeof(alu_vec), 1, pf);
    fclose(pf);
    return 1;
}
