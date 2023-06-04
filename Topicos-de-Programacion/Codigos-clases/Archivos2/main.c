#include <stdio.h>
#include <stdlib.h>

/**
int ingresar_datos_alumno(t_alumno * alu)
{
    char opc;
    printf("Desea ingresar un alumno(s/n)?");
    scanf("%c", &opc);

    if (opc!='s')
        return 0;

    //ingresar los datos del alumno
}

while(ingresar_datos_alumno(&alu))
{
    fwrite(...);
}
*/

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
            fwrite(&alu, sizeof(t_alumno), 1, pf);

            fseek(pf, 0, SEEK_CUR);
        }

        fread(&alu, sizeof(t_alumno), 1, pf);
    }

    ///fseek(pf, 0, SEEK_END);

    tam_arch = ftell(pf);
    cant_reg = tam_arch/sizeof(t_alumno);

    printf("\nTam Arch: %d   Cant Reg: %d", tam_arch, cant_reg);


    fseek(pf, 0, SEEK_SET);
    ///rewind(pf); === fseek(pf, 0, SEEK_SET);

//    fprintf(stdout,"formato %d", 5); ///=== printf("formato %d", 5);
//    fprintf(stderr,"formato %d", 5);

    ///Mostrar a los alumnos
    fread(&alu, sizeof(t_alumno), 1, pf);
    while (!feof(pf)){
        printf("\n%ld - %s, %02d/%02d/%d, %c", ftell(pf), alu.apyn, alu.f_ing.d, alu.f_ing.m, alu.f_ing.a, alu.estado);
        fread(&alu, sizeof(t_alumno), 1, pf);
    }
    fclose(pf);

//    printf("\n\n'%-*s'",9,"Hola");
//
//    printf("\n\n%*s",9,"");
//    printf("%3d",5);

    return 0;
}

int cargar_archivo(char * path){
    t_alumno alu_vec[] = {
                        {90, "Sa, Lia", 'F', 7.5, {7,8}, {1,2,2005}, 'A'},
                        {98, "Jose Perez", 'M', 8, {7,8, 9}, {1,2,1999}, 'A'},
                        {110, "Alumno uno", 'F', 7.5, {7,8}, {1,2,2005}, 'I'},
                        {120, "Alumno dos", 'M', 7.5, {7,8}, {1,2,2015}, 'A'},
                        {130, "Alumno tres", 'M', 8, {7,8}, {1,2,2000}, 'A'},
                        {140, "Alumno cuatro", 'F', 7.5, {7,8}, {1,2,1998}, 'A'},
                        {150, "Alumno cinco", 'F', 4, {7,8}, {1,2,1997}, 'A'},
                        };

    FILE * pf = fopen(path, "wb");
    if(!pf)///if(pf == NULL)
    {
        return 0;
    }

    fwrite(alu_vec, sizeof(t_alumno), 7, pf);
    ///fwrite(alu_vec, sizeof(alu_vec), 1, pf);

    fclose(pf);
    return 1;
}
