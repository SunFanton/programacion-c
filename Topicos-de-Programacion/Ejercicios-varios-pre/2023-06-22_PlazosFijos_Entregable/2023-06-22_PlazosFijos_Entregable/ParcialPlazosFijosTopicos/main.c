#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Fecha/Fecha.h"
#include "../SolucionParcialPlazosFijosTopicos/PlazoFijo.h"

//Funciones de Fecha
int esBisiesto_ALU(int anio);
int diasMes_ALU(int anio, int mes);
int diasTranscurridosDesdeInicioAnio_ALU(tFecha *fecha);
int diferenciaDias_ALU(tFecha *fecha1, tFecha *fecha2);

//Funciones con archivos
int cargarArchivoCuentas(const char *path, tCuenta *, int ce);
tPlazoFijo* cargarVectorPF_ALU(const char* nombrePlazosFijos, int* ce);
void procesarPF_ALU(FILE* cuentasDat, tPlazoFijo* plazosFijosVec, int ce, tFecha* fechaProceso);
void mostrarVecPlazos_ALU(tPlazoFijo* p, int ce);
void actualizarInteres_ALU(tCuenta *cuenta, tPlazoFijo plazoFijo, tFecha *fechaProceso);

//Funciones para ordenar
int compararNroPlazos_ALU(const void* p1, const void* p2);
void *miMemmove_ALU(void *destino, void *origen, size_t tam);
void intercambiar_ALU(void* p1, void* p2, size_t tam);
void *buscarMenor_ALU(void *vec, void *fin, size_t tam, int (*cmp)(void* p1, void* p2));
void *ordenarVector_ALU(void* vec, int ce, size_t tamElem,  int (*cmp)(void* p1, void* p2));


/*

VECTOR ORDENADO POR CUENTAS

3|1000|3400.00|50.00|3/1/2019|60
1|2000|2500.00|40.00|5/3/2019|30
6|2000|6250.00|65.00|12/5/2018|90
5|3000|5350.00|55.00|16/6/2018|180
2|5000|2000.00|54.00|24/5/2018|90
4|7000|10000.00|48.00|12/4/2019|180



FECHA ACTUAL: 27/6/2019

*/


int main()
{
    tCuenta cuentas[] = {
                            {1000, "Camila Diaz", 4500.0},
                            {3000, "Sol Perez", 7900.0},
                            {7000, "Luz Torres", 5000.0}
                        };

    if(!cargarArchivoCuentas("Cuentas.dat", cuentas, sizeof(cuentas)/sizeof(tCuenta)))
        return 1;
    int cePlazosFijos = 0;
    tPlazoFijo *ptrPlazoFijo = cargarVectorPF_ALU("PlazosFijos.txt", &cePlazosFijos);
    if(!ptrPlazoFijo)
        return 1;
    ordenarVector_ALU(ptrPlazoFijo, cePlazosFijos, sizeof(tPlazoFijo), compararNroPlazos_ALU);
    mostrarVecPlazos_ALU(ptrPlazoFijo, cePlazosFijos);

    FILE *pfBin = fopen("Cuentas.dat", "r+b");
    if(!pfBin)
        return 1;

    tFecha fechaActual = {27, 6, 2023};
    procesarPF_ALU(pfBin, ptrPlazoFijo, cePlazosFijos, &fechaActual);

    fclose(pfBin);
    free(ptrPlazoFijo);
    return 0;
}

tPlazoFijo* cargarVectorPF_ALU(const char* nombrePlazosFijos, int* ce){

    FILE *pf = fopen(nombrePlazosFijos, "rt");
    if(!pf)
        return NULL;

    char linea[100];
    while(fgets(linea, sizeof(linea), pf)){
        (*ce)++;
    }
    rewind(pf);


    tPlazoFijo *ptr = (tPlazoFijo*)malloc(*ce * sizeof(tPlazoFijo));
    if(!ptr){
        fclose(pf);
        return NULL;
    }
    int i = 0;
    while(fgets(linea, sizeof(linea), pf) != NULL){
         sscanf(linea, "%d|%d|%f|%f|%d/%d/%d|%d",
                    &ptr[i].nroPF,
                    &ptr[i].cuenta,
                    &ptr[i].monto,
                    &ptr[i].interesAnual,
                    &ptr[i].fechaConstitucion.dia,
                    &ptr[i].fechaConstitucion.mes,
                    &ptr[i].fechaConstitucion.anio,
                    &ptr[i].dias);

                    /*
         printf("%d|%d|%f|%f|%d/%d/%d|%d\n",
                        ptr[i].nroPF,
                        ptr[i].cuenta,
                        ptr[i].monto,
                        ptr[i].interesAnual,
                        ptr[i].fechaConstitucion.dia,
                        ptr[i].fechaConstitucion.mes,
                        ptr[i].fechaConstitucion.anio,
                        ptr[i].dias);
                        */

        i++;
    }
    fclose(pf);
    return ptr;
}

int compararNroPlazos_ALU(const void* p1, const void* p2){

    tPlazoFijo *pf1 = (tPlazoFijo*)p1;
    tPlazoFijo *pf2 = (tPlazoFijo*)p2;

    return pf1->cuenta - pf2->cuenta;
}

void *miMemmove_ALU(void *destino, void *origen, size_t tam){

    char *dest = (char*)destino;
    char *ori = (char*)origen;
    char *temp = (char*)malloc(tam * sizeof(char));

    for(int i = 0; i < tam; i++){
        temp[i] = ori[i];
    }

    for(int i = 0; i < tam; i++){
        dest[i] = temp[i];
    }

    free(temp);
    return dest;
}

void intercambiar_ALU(void* p1, void* p2, size_t tam){

    char *aux = (char*)malloc(tam * sizeof(char));
    miMemmove_ALU(aux, p1, tam);
    miMemmove_ALU(p1, p2, tam);
    miMemmove_ALU(p2, aux, tam);
    free(aux);
}

void *buscarMenor_ALU(void *vec, void *fin, size_t tam, int (*cmp)(void* p1, void* p2)){

    void *menor = vec;
    vec += tam;

    while(vec <= fin){
        if(cmp(vec, menor) < 0)
            menor = vec;
        vec += tam;
    }
    return menor;
}

void *ordenarVector_ALU(void* vec, int ce, size_t tamElem, int (*cmp)(void* p1, void* p2)){

    void *inicio = vec,
         *fin = vec + (ce - 1)*tamElem,
         *menor;

    while(vec < fin){
        menor = buscarMenor_ALU(vec, fin, tamElem, cmp);
        if(menor != vec)
            intercambiar_ALU(vec, menor, tamElem);
        vec += tamElem;
    }
    vec = inicio;
    return vec;
}

void mostrarVecPlazos_ALU(tPlazoFijo* p, int ce){

    for(int i = 0; i < ce; i++){
        printf("%d|%d|%.2f|%.2f|%d/%d/%d|%d\n",
                        p[i].nroPF,
                        p[i].cuenta,
                        p[i].monto,
                        p[i].interesAnual,
                        p[i].fechaConstitucion.dia,
                        p[i].fechaConstitucion.mes,
                        p[i].fechaConstitucion.anio,
                        p[i].dias);
    }
}

int esBisiesto_ALU(int anio){
    return anio % 400 == 0 || (anio % 4 == 0 && anio % 100 != 0);
}

int diasMes_ALU(int anio, int mes){

    int diasMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return esBisiesto_ALU(anio) && mes == 2 ? 29 : diasMes[mes-1];
}

int diasTranscurridosDesdeInicioAnio_ALU(tFecha *fecha){

    int diasTranscurridos = 0;
    for(int i = 1; i < fecha->mes; i++){
        diasTranscurridos += diasMes_ALU(fecha->anio, fecha->mes);
    }
    diasTranscurridos += fecha->dia;
    return diasTranscurridos;
}

int diferenciaDias_ALU(tFecha *fecha1, tFecha *fecha2){

    int diferencia = 0,
        diasTranscurridosFecha1 = 0,
        diasTranscurridosFecha2 = 0;

    if(fecha1->anio > fecha2->anio ||
       (fecha1->anio == fecha2->anio && fecha1->mes > fecha2->mes) ||
       (fecha1->anio == fecha2->anio && fecha1->mes == fecha2->mes && fecha1->dia > fecha2->dia)){

            tFecha *temp = fecha1;
            fecha1 = fecha2;
            fecha2 = temp;
       }

    for(int i = fecha1->anio; i < fecha2->anio; i++){
        if(esBisiesto_ALU(i))
            diferencia += 366;
        else
            diferencia += 365;
    }

    diasTranscurridosFecha1 = diasTranscurridosDesdeInicioAnio_ALU(fecha1);
    diasTranscurridosFecha2 = diasTranscurridosDesdeInicioAnio_ALU(fecha2);
    diferencia += diasTranscurridosFecha2 - diasTranscurridosFecha1;
    return diferencia;
}

void procesarPF_ALU(FILE* cuentasDat, tPlazoFijo* plazosFijosVec, int ce, tFecha* fechaProceso){

    tCuenta cuenta;
    int comp;

    fread(&cuenta, sizeof(tCuenta), 1, cuentasDat);
    int i = 0;
    while (!feof(cuentasDat) && i < ce) {
        if (cuenta.cuenta < plazosFijosVec[i].cuenta) {
            printf("Cuenta: %d, Cliente: %s, Saldo: %f\n", cuenta.cuenta, cuenta.cliente, cuenta.saldo);
            fread(&cuenta, sizeof(tCuenta), 1, cuentasDat);
        }
        else if (cuenta.cuenta > plazosFijosVec[i].cuenta) {
            i++;
        }
        else {
            printf("Cuenta: %d, Cliente: %s, Saldo: %f\n", cuenta.cuenta, cuenta.cliente, cuenta.saldo);
            actualizarInteres_ALU(&cuenta, plazosFijosVec[i], fechaProceso);
            fseek(cuentasDat, -(long)sizeof(tCuenta), SEEK_CUR);
            fwrite(&cuenta, sizeof(tCuenta), 1, cuentasDat);
            fseek(cuentasDat, 0, SEEK_CUR);
            fread(&cuenta, sizeof(tCuenta), 1, cuentasDat);
            i++;
        }
    }

    while (!feof(cuentasDat)) {
        printf("Cuenta: %d, Cliente: %s, Saldo: %f\n", cuenta.cuenta, cuenta.cliente, cuenta.saldo);
        fread(&cuenta, sizeof(tCuenta), 1, cuentasDat);
    }
}



void actualizarInteres_ALU(tCuenta *cuenta, tPlazoFijo plazoFijo, tFecha *fechaProceso){
    float nuevoMonto = 0;
    tFecha *fechaPF = &plazoFijo.fechaConstitucion;

    if(diferenciaDias_ALU(fechaPF, fechaProceso) > plazoFijo.dias){
       nuevoMonto = plazoFijo.monto + ((float)plazoFijo.dias / 365.0) * ((float)plazoFijo.interesAnual / 100.0) * plazoFijo.monto;
       cuenta->saldo += nuevoMonto;
    }
}

int cargarArchivoCuentas(const char *path, tCuenta *cuentas, int ce){

    FILE *pf = fopen(path, "wb");
    if(!pf)
        return 0;

    fwrite(cuentas, sizeof(tCuenta), ce, pf);

    fclose(pf);
    return 1;
}

