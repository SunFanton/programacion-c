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

int cargar_archivo1(char * path);
int cargar_archivo2(char * path);

int cmp_alu_dni(const t_alumno * a1, const t_alumno * a2)
{
    return a1->dni - a2->dni;
}

int main()
{
    FILE * pf1, * pf2, *pfr;
    t_alumno alu1, alu2;


    ///TODO: Validar se hayan cargado los arch
    cargar_archivo1("alu1.dat");
    cargar_archivo2("alu2.dat");

    ///Merge o apareo de archivos
    pf1 = fopen("alu1.dat", "rb");
    if (!pf1)
    {
        return 1;
    }

    pf2 = fopen("alu2.dat", "rb");
    if (!pf2)
    {
        fclose(pf1);
        return 2;
    }

    pfr = fopen("alu_res.dat", "wb");
    if (!pfr)
    {
        fclose(pf1);
        fclose(pf2);
        return 3;
    }

    ///UNION

    fread(&alu1, sizeof(t_alumno), 1, pf1);
    fread(&alu2, sizeof(t_alumno), 1, pf2);
    while(!feof(pf1)&&!feof(pf2))
    {
        int rc=cmp_alu_dni(&alu1, &alu2);
        if(rc < 0)
        {
            fwrite(&alu1, sizeof(t_alumno), 1, pfr);
            fread(&alu1, sizeof(t_alumno), 1, pf1);
        }
        else if (rc > 0)
        {
            fwrite(&alu2, sizeof(t_alumno), 1, pfr);
            fread(&alu2, sizeof(t_alumno), 1, pf2);
        }
        else
        {
            fwrite(&alu1, sizeof(t_alumno), 1, pfr);
            fread(&alu1, sizeof(t_alumno), 1, pf1);
            fread(&alu2, sizeof(t_alumno), 1, pf2);
        }
    }
    while(!feof(pf1))
    {
        fwrite(&alu1, sizeof(t_alumno), 1, pfr);
        fread(&alu1, sizeof(t_alumno), 1, pf1);
    }
    while(!feof(pf2))
    {
        fwrite(&alu2, sizeof(t_alumno), 1, pfr);
        fread(&alu2, sizeof(t_alumno), 1, pf2);
    }



    ///INTERSECCION
//    fread(&alu1, sizeof(t_alumno), 1, pf1);
//    fread(&alu2, sizeof(t_alumno), 1, pf2);
//    while(!feof(pf1)&&!feof(pf2))
//    {
//        if(alu1.dni < alu2.dni)
//        {
//            fread(&alu1, sizeof(t_alumno), 1, pf1);
//        }
//        else if (alu1.dni > alu2.dni)
//        {
//            fread(&alu2, sizeof(t_alumno), 1, pf2);
//        }
//        else
//        {
//            fwrite(&alu1, sizeof(t_alumno), 1, pfr);
//            fread(&alu1, sizeof(t_alumno), 1, pf1);
//            fread(&alu2, sizeof(t_alumno), 1, pf2);
//        }
//    }

    fclose(pf1);
    fclose(pf2);
    fclose(pfr);

    pfr = fopen("alu_res.dat", "rb");
    if (!pfr)
    {
        return 1;
    }
    fread(&alu1, sizeof(t_alumno), 1, pfr);
    while (!feof(pfr)){
        printf("\n%ld - %d, %s, %02d/%02d/%d, %c", ftell(pfr), alu1.dni, alu1.apyn, alu1.f_ing.d, alu1.f_ing.m, alu1.f_ing.a, alu1.estado);
        fread(&alu1, sizeof(t_alumno), 1, pfr);
    }

    fclose(pfr);

    return 0;
}


int cargar_archivo1(char * path){
    t_alumno alu_vec[] = {
                        {90, "Sa, Lia", 'F', 7.5, {7,8}, {1,2,2005}, 'A'},
                        {98, "Jose Perez", 'M', 8, {7,8, 9}, {1,2,1999}, 'A'},
                        {110, "Alumno uno", 'F', 7.5, {7,8}, {1,2,2005}, 'I'},
                        {130, "Alumno tres", 'M', 8, {7,8}, {1,2,2000}, 'A'},
                        {150, "Alumno cinco", 'F', 4, {7,8}, {1,2,1997}, 'A'},
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


int cargar_archivo2(char * path){
    t_alumno alu_vec[] = {
                        {90, "Sa, Lia", 'F', 7.5, {7,8}, {1,2,2005}, 'A'},
                        {120, "Alumno dos", 'M', 7.5, {7,8}, {1,2,2015}, 'A'},
                        {140, "Alumno cuatro", 'F', 7.5, {7,8}, {1,2,1998}, 'A'},
                        {150, "Alumno cinco", 'F', 4, {7,8}, {1,2,1997}, 'A'},
                        {160, "Alumno seis", 'F', 5, {7,8}, {1,2,1997}, 'A'}
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
