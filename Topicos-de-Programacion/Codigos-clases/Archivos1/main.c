#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**

    streams - flujo

    FILE

*/

typedef struct
{
    int dni;
    char apyn[30];
    char sexo;
    float promedio;
    int notas[50];
} t_alumno;

///typedef unsigned size_t;

//struct s_alumno
//{
//    int dni;
//    char apyn[30];
//    char sexo;
//    float promedio;
//    int notas[50];
//};
//
//typedef struct s_alumno t_alumno;

int main()
{
    FILE * pf;

//    struct s_alumno alu;

    t_alumno alu = {12345678, "Sa, Lia1", 'F', 7.5, {7,8}};
    t_alumno alu2;

    t_alumno alu_vec[] = {
                        {12345678, "Sa, Lia", 'F', 7.5, {7,8}},
                        {23456789, "Jose Perez", 'M', 8, {7,8, 9}}
                        };


///    r - read
///    w - write
///    a - append
///
///    modificador +
///
///    r+
///    w+
///    a+
///
///    b - binario
///    t - texto (por defecto)


    pf = fopen("alus.dat", "wb");

    if(pf == NULL)
    {
        return 1;
    }

    fwrite(&alu, sizeof(t_alumno), 1, pf);

    ///fwrite(alu_vec, sizeof(t_alumno), 2, pf);
    fwrite(alu_vec, sizeof(alu_vec), 1, pf);

//    system("pause");
//
//    fflush(pf);
//
//    system("pause");

    fclose(pf);

    ///system("pause");

    pf = fopen("alus.dat", "rb");

    if(pf == NULL)
    {
        return 1;
    }

    size_t r;

//    r=fread(&alu2, sizeof(t_alumno), 1, pf);
//
//    printf("\n%d - %s", r, alu2.apyn);
//
//    r=fread(&alu2, sizeof(t_alumno), 1, pf);
//
//    printf("\n%d - %s", r, alu2.apyn);
//
//    r=fread(&alu2, sizeof(t_alumno), 1, pf);
//
//    printf("\n%d - %s", r, alu2.apyn);
//
//    strcpy(&alu2.apyn, "Termino");
//
//    r=fread(&alu2, sizeof(t_alumno), 1, pf);
//
//    printf("\n%d - %s", r, alu2.apyn);
//
//    r=fread(&alu2, sizeof(t_alumno), 1, pf);
//
//    printf("\n%d - %s", r, alu2.apyn);



    // r= fread(alu_vec, sizeof(t_alumno), 2, pf);

    // r= fread(alu_vec, sizeof(alu_vec), 1, pf);
//
//    printf("\n%d - %s", r, alu_vec[0].apyn);
//    printf("\n%d - %s", r, alu_vec[1].apyn);

    fread(&alu2, sizeof(t_alumno), 1, pf);
    while(!feof(pf))
    {
        printf("\n%s", alu2.apyn);
        fread(&alu2, sizeof(t_alumno), 1, pf);
    }


    fclose(pf);





    return 0;
}
