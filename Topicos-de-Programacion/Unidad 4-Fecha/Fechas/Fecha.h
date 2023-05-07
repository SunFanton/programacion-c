#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED
#define TRUE 1
#define FALSE 0

typedef struct{

    int dia;
    int mes;
    int anio;
}tFecha;

typedef int BOOL;

BOOL esFechaValida(tFecha *);
int cantDiasMes(int,int);
int esBisiesto(int);
void sumarUnDia(tFecha *);
void sumarNDias(tFecha *, int);
void restarNDias(tFecha *, int);
int diasDesdeInicioAnio(tFecha *);
int diasDiferenciaEntreFechas(tFecha *, tFecha *);

#endif // FECHA_H_INCLUDED
