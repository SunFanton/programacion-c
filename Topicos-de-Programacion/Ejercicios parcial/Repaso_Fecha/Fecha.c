#include "Fecha.h"

int esFechaValida(t_fecha *fecha){
    if(fecha->anio > 1600){
        if(fecha->mes >= 1 && fecha->mes <= 12){
            if(fecha->dia >= 1 && fecha->dia <= cantDiasMes(fecha->anio, fecha->mes))
                return 1;
        }
    }
    return 0;
}

int cantDiasMes(int anio, int mes){
    int diasMes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return esBisiesto(anio) && mes == 2 ? 29 : diasMes[mes - 1];
}

int esBisiesto(int anio){
    return anio % 400 == 0 || (anio % 4 == 0 && anio % 100 != 0) ? 1 : 0;
}

void sumarUnDia(t_fecha *fecha){

    int diasMes = cantDiasMes(fecha->anio, fecha->mes);
    fecha->dia++;

    if(fecha->dia > diasMes){
        fecha->dia = 1;
        fecha->mes++;

        if(fecha->mes > 12){
            fecha->mes = 1;
            fecha->anio++;
        }
    }
}

void sumarNDias(t_fecha *ptr, int n){

    while(n > 0){
        int diasMes = cantDiasMes(ptr->anio, ptr->mes);
        int diasRestantes = diasMes - ptr->dia + 1;

        if(n > diasRestantes){
            ptr->dia = 1;
            ptr->mes++;

            if(ptr->mes > 12){
                ptr->mes = 1;
                ptr->anio++;
            }
            n -= diasRestantes;
        }
        else{
            ptr->dia += n;
            n = 0;
        }
    }
}

void restarNDias(t_fecha *ptr, int n){

    int diasMes;

    while(n > 0){
        if(n >= ptr->dia){
            n -= ptr->dia;
            ptr->mes--;

            if(ptr->mes < 1){
                ptr->mes = 12;
                ptr->anio--;
            }
            diasMes = cantDiasMes(ptr->anio, ptr->mes);
            ptr->dia = diasMes;
        }
        else{
            ptr->dia -= n;
            n = 0;
        }
    }
}

int diasDesdeInicioAnio(t_fecha *fecha){

    int sumaDias = 0;
    for(int i = 1; i < fecha->mes; i++){
        sumaDias += cantDiasMes(fecha->anio, i);
    }
    sumaDias += fecha->dia - 1;
    return sumaDias;
}

int diasDiferenciaEntreFechas(t_fecha *fecha1, t_fecha *fecha2){

    int diasTranscurridosFecha1 = 0,
        diasTranscurridosFecha2 = 0,
        diferencia = 0;

    if(fecha1->anio > fecha2->anio ||
       (fecha1->anio == fecha2->anio && fecha1->mes > fecha2->mes) ||
       (fecha1->anio == fecha2->anio && fecha1->mes == fecha2->mes && fecha1->dia > fecha2->dia)){
            t_fecha *temp = fecha1;
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

    diferencia += (diasTranscurridosFecha2 - diasTranscurridosFecha1);
    return diferencia;
}
