#include "Fecha.h"
#include <stdlib.h>
#include <stdio.h>

BOOL esFechaValida(tFecha *f){
    if(f->anio>1600)
        if(f->mes>=1 &&f->mes<=12)
            if(f->dia>=1 && f->dia<=cantDiasMes(f->mes,f->anio))
                return TRUE;
    return FALSE;
}

int cantDiasMes(int m,int a){
    int diasMes[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    return esBisiesto(a)&&m==2? 29 : diasMes[m-1];
}

int esBisiesto(int a){
    return a%400 == 0 || (a % 4 == 0 && a % 100 != 0);
}

void sumarUnDia(tFecha *ptr){

    int diasMes = cantDiasMes(ptr->mes, ptr->anio);
    ptr->dia++;

    if(ptr->dia > diasMes){
        ptr->dia = 1;
        ptr->mes++;

        if(ptr->mes > 12){
            ptr->mes = 1;
            ptr->anio++;
        }
    }
}

void sumarNDias(tFecha *ptr, int n){

    while(n > 0){
        int diasMes = cantDiasMes(ptr->mes, ptr->anio);
        int diasRestantesMes = diasMes - ptr->dia + 1; //Se le suma 1 porque se considera el dia de la fecha actual

        if(n > diasRestantesMes){
            ptr->dia = 1;
            ptr->mes++;

            if(ptr->mes > 12){
                ptr->mes = 1;
                ptr->anio++;
            }
            n -= diasRestantesMes;
        }
        else{
            ptr->dia += n;
            n = 0;
        }

    }
}

void restarNDias(tFecha *ptr, int n){

    int diasMes;

    while(n > 0){

        if(n >= ptr->dia){
            n -= ptr->dia;
            ptr->mes--;

            if(ptr->mes == 0){
                ptr->mes = 12;
                ptr->anio--;
            }

            diasMes = cantDiasMes(ptr->mes, ptr->anio);
            ptr->dia = diasMes;
        }
        else{
            ptr->dia -= n;
            n = 0;
        }
    }
}

int diasDesdeInicioAnio(tFecha *fecha) {
      int dias = 0;
      for (int i = 1; i < fecha->mes; i++) {
        dias += cantDiasMes(i, fecha->anio);
      }
      dias += fecha->dia - 1;
      return dias;
}

int diasDiferenciaEntreFechas(tFecha *fecha1, tFecha *fecha2){

    int diasTranscurridosFecha1 = 0,
        diasTranscurridosFecha2 = 0,
        diferencia = 0;

    //Si la fecha 1 es mayor ya se por año, mes o dia, se intercambian las fechas:
    if(fecha1->anio > fecha2->anio ||
      (fecha1->anio == fecha2->anio && fecha1->mes > fecha2->mes) ||
      (fecha1->anio == fecha2->anio && fecha1->mes == fecha2->mes && fecha1->dia > fecha2->dia)) {
        tFecha *temp = fecha1;
        fecha1 = fecha2;
        fecha2 = temp;
    }

    for(int i = fecha1->anio; i < fecha2->anio; i++){
        if(esBisiesto(i))
            diferencia += 366;
        else
            diferencia += 365;
    }
    diasTranscurridosFecha1 = diasDesdeInicioAnio(fecha1);
    diasTranscurridosFecha2 = diasDesdeInicioAnio(fecha2);
    diferencia += diasTranscurridosFecha2 - diasTranscurridosFecha1;

    return diferencia;
}
