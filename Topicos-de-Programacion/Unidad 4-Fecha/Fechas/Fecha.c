#include "Fecha.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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

/*Funcion para obtener dia de la semana segun una fecha.
En dicha funcion se utilizara el algoritmo de Zeller, que consiste
en una formula matematica para obtener dicho dia.
El algoritmo enlaza un numero de codigo al dia de la semana, un codigo
al mes y un codigo al numero de siglo:

Dia de la semana:       Mes:                                    Siglo (se toma las dos primeras cifras del año):
0 -> Domingo            0 -> Enero      2 -> Agosto             6 -> 1600
1 -> Lunes              3 -> Febrero    5 -> Septiembre         4 -> 1700
2 -> Martes             3 -> Marzo      0 -> Octubre            2 -> 1800
3 -> Miercoles          6 -> Abril      3 -> Noviembre          0 -> 1900
4 -> Jueves             1 -> Mayo       5 -> Diciembre          6 -> 2000
5 -> Viernes            4 -> Junio
6 -> Sabado             6 -> Julio

Formula:
Dia +
Codigo del mes +
Codigo del siglo +
Cociente de dividir dos digitos finales del año por 4 +
Resto de dividir dos digitos finales del año por 7

El resultado de la suma se divide por 7 y el resto sera el codigo del dia de
la semana

Por ej: 16 Julio 1969
16 + 6 + 0 + 17 + 6 = 45 -> 45 % 7 = 3 -> Miercoles

Se agrega un paso extra si el año es bisiesto y el mes es Enero o Febrero, y es que
se resta 1 al resultado final
Ej: 1 Enero 2020
1 + 0 + 6 + 5 + 6 = 18 -> 18 % 7 = 4 -> 4 - 1 -> Miercoles
*/
int obtenerDiaSemana(tFecha *ptr){

    int codigosXMes[] = {0,3,3,6,1,4,6,2,5,0,3,5};
    int codigosXSiglo[5][2] = {{16,6},{17,4},{18,2},{19,0},{20,6}};

    char anio[5];
    itoa(ptr->anio, anio, 10); //int a char
    char anioPrimerosDigitos[] = {anio[0], anio[1], '\0'};
    char anioUltimosDigitos[] = {anio[2], anio[3], '\0'};

    int siglo = atoi(anioPrimerosDigitos); //char a int
    int anioAOperar = atoi(anioUltimosDigitos); //char a int
    int codigoSiglo,
        codigoMes = codigosXMes[ptr->mes - 1];

    for(int i = 0; i < 5; i++){
        if(siglo == codigosXSiglo[i][0])
            codigoSiglo = codigosXSiglo[i][1];
    }

    int diaSemana = ptr->dia + codigoMes + codigoSiglo + anioAOperar/4 + anioAOperar%7;
    diaSemana %= 7;

    if(esBisiesto(ptr->anio) && (ptr->mes==1 || ptr->mes==2))
        diaSemana--;

    return diaSemana;
}
