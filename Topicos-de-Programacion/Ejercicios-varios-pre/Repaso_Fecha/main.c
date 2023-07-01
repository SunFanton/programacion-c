#include <stdio.h>
#include <stdlib.h>
#include "Fecha.h"

int main()
{

    t_fecha fecha1 = {12, 1, 1990};
    t_fecha fecha2 = {23, 11, 1989};
    printf("%d/%d/%d\n\n", fecha1.dia, fecha1.mes, fecha1.anio);
    printf("Es fecha valida? %d\n\n", esFechaValida(&fecha1));
    sumarUnDia(&fecha1);
    printf("Sumar 1 dia a la fecha: %d/%d/%d\n\n", fecha1.dia, fecha1.mes, fecha1.anio);
    sumarNDias(&fecha1, 20);
    printf("Sumar %d dias a la fecha: %d/%d/%d\n\n", 20, fecha1.dia, fecha1.mes, fecha1.anio);
    restarNDias(&fecha1, 20);
    printf("Restar %d dias a la fecha: %d/%d/%d\n\n", 20, fecha1.dia, fecha1.mes, fecha1.anio);

    restarNDias(&fecha1, 1);
    printf("Dias de diferencia entre %d/%d/%d y %d/%d/%d: %d\n\n", fecha1.dia, fecha1.mes, fecha1.anio,
                                                                   fecha2.dia, fecha2.mes, fecha2.anio,
                                                                   diasDiferenciaEntreFechas(&fecha1, &fecha2));

    return 0;
}
