#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

typedef struct{
    int dia;
    int mes;
    int anio;
}t_fecha;

int esFechaValida(t_fecha *fecha);
int cantDiasMes(int anio, int mes);
int esBisiesto(int anio);
void sumarUnDia(t_fecha *fecha);
void sumarNDias(t_fecha *ptr, int n);
void restarNDias(t_fecha *ptr, int n);
int diasDesdeInicioAnio(t_fecha *fecha);
int diasDiferenciaEntreFechas(t_fecha *fecha1, t_fecha *fecha2);

#endif // FECHA_H_INCLUDED
