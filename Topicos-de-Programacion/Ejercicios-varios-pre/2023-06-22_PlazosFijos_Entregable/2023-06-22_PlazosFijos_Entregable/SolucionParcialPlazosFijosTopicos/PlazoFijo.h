#ifndef PLAZOFIJO_H
#define PLAZOFIJO_H

#include "../Fecha/Fecha.h"

typedef struct{
    int cuenta;
    char cliente[51];
    float saldo;
}tCuenta;

typedef struct{
    int nroPF;
    int cuenta;
    float monto;
    float interesAnual;
    tFecha fechaConstitucion;
    int dias;
}tPlazoFijo;


#endif // PLAZOFIJO_H
