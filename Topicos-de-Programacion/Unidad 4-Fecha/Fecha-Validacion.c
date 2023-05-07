#include <stdio.h>
#include <stdlib.h>
/*struct sFecha
{
    int d, m, a;
};
typedef struct sFecha tFecha;*/
typedef struct
{
    int d, m, a;
}tFecha;
typedef struct
{
    int dni;
    char apyn[30];
    tFecha fNac;
}tPersona;
int esFechaValida(tFecha *);
int cantDiasMes(int,int);
int esBisiesto(int);
int main()
{
    tFecha fec={30,2,2023};
    printf("Es fecha valida? %d\n", esFechaValida(&fec));
    return 0;
}
int esFechaValida(tFecha *f)
{
    if(f->a>1600)
        if(f->m>=1 &&f->m<=12)
            if(f->d>=1 && f->d<=cantDiasMes(f->m,f->a))
                return 1;
    return 0;
}
int cantDiasMes(int m,int a)
{
    int diasMes[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    return esBisiesto(a)&&m==2? 29 : diasMes[m-1];
}
int esBisiesto(int a)
{
    return a%400 == 0 || (a % 4 == 0 && a % 100 != 0);
}