#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Biblioteca/vectores.h"

typedef struct
{
    int dni;
    char apyn [30];
}t_alumno;

int cmp_alu_dni(const void * a1, const void * a2);
int cmp_alu_apyn(const void * a1, const void * a2);
int cmp_ent(const void * a1, const void * a2);

int main()
{
    int vec[]={14,12,5,4,1,3,6,8,15,2,7,9,13,10,11};
    float fvec[]={12.4,12.2,5,4,1,3,6,8,15,2,7,9,12.3,10,11};

    t_alumno avec[]={
                    {14,"m"},
                    {12,"a"},
                    {5,"g"},
                    {4,"d"},
                    {1,"f"},
                    {3,"c"},
                    {6,"e"},
                    {8,"b"},
                    {15,"n"},
                    {2,"h"},
                    {7,"o"},
                    {9,"i"},
                    {13,"l"},
                    {10,"j"},
                    {11,"k"}
    };

    int ce = sizeof(vec)/sizeof(int);
    int i;

    orenarSeleccion(vec, ce, sizeof(int), cmp_ent);
    ///ord_sel_vec(vec, ce, sizeof(int), cmp_ent);

    for(i=0; i<ce;i++)
    {
        printf("%d ", vec[i]);
    }

    printf("\n\n");

    orenarSeleccion(avec, ce, sizeof(t_alumno), cmp_alu_dni);
    ///ord_sel_vec(avec, ce, sizeof(t_alumno), cmp_alu_dni);


    for(i=0; i<ce;i++)
    {
        printf("%d, %s ", avec[i].dni, avec[i].apyn);
    }

    printf("\n\n");

    orenarSeleccion(avec, ce, sizeof(t_alumno), cmp_alu_apyn);
    ///ord_sel_vec(avec, ce, sizeof(t_alumno), cmp_alu_apyn);

    for(i=0; i<ce;i++)
    {
        printf("%d, %s ", avec[i].dni, avec[i].apyn);
    }

    return 0;
}

int cmp_alu_dni(const void * a1, const void * a2)
{
    const t_alumno *alu1 = (const t_alumno *)a1,
                   *alu2 = (const t_alumno *)a2;
    return alu1->dni - alu2->dni;
}

int cmp_alu_dni_apyn(const void * a1, const void * a2)
{
    const t_alumno *alu1 = (const t_alumno *)a1,
                   *alu2 = (const t_alumno *)a2;

    return alu1->dni - alu2->dni ? alu1->dni - alu2->dni : strcmpi(alu1->apyn, alu2->apyn);
}

int cmp_alu_apyn(const void * a1, const void * a2)
{
    const t_alumno *alu1 = (const t_alumno *)a1,
                   *alu2 = (const t_alumno *)a2;
    return strcmpi(alu1->apyn, alu2->apyn);
}

int cmp_ent(const void * a1, const void * a2)
{
    const int * e1 = (const int *)a1;
    return *e1-*(const int*)a2;
}
