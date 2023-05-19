#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"vector.h"

typedef struct
{
    int dni;
    char apyn[30];
    float promedio;
    int mat_probadas;
}t_alumno;

int cmp_alu_dni(const void* v1, const void* v2)
{
    const t_alumno * a1 = (const t_alumno *) v1;
    const t_alumno * a2 = (const t_alumno *) v2;
    return a1->dni - a2->dni;
}

void agrega_letra_apyn(void * v1)
{
    t_alumno * alu = (t_alumno *) v1;
    strcat(alu->apyn, "_a");
}

void mostrar_alumno(void * v1)
{
    t_alumno * alu = (t_alumno *) v1;
    printf("\n%d, %s", alu->dni, alu->apyn);
}

void concat_alus_apyn(void* vr, const void* e)
{
    char* ret =(char*) vr;
    const t_alumno * a = (const t_alumno *) e;
    strcat(strcat(ret, a->apyn), ", ");
//    strcat(ret, a->apyn);
//    strcat(ret, ", ");
}

int dni_impar(const void *e)
{
    const t_alumno * a = (const t_alumno *) e;
    return a->dni%2;
}

int main()
{
    t_alumno vec []= {
        {1,"a"},
        {2,"b"},
        {3,"c"},
        {4,"d"},
        {5,"e"},
    };

    size_t ce = 5;
    t_alumno alu = {6};
    t_alumno * r;
    char alus_apyn[1000]="";

    if ((r=buscar(vec, ce, sizeof(t_alumno), &alu, cmp_alu_dni)))
        printf("%s", r->apyn);

    amap(vec, ce, sizeof(t_alumno), agrega_letra_apyn);
    amap(vec, ce, sizeof(t_alumno), mostrar_alumno);

    reduce(vec, ce, sizeof(t_alumno), alus_apyn, concat_alus_apyn);
    printf("\n\n%s", alus_apyn);

    filter(vec, &ce, sizeof(t_alumno), dni_impar);
    amap(vec, ce, sizeof(t_alumno), mostrar_alumno);

    return 0;
}
