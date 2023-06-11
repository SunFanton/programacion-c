#include "Archivos.h"
#include <stdlib.h>
#include <stdio.h>

int grabarArchivoBinario(const char *path, void *data, size_t tam){

    char *dataToSave = (char*)data;

    FILE *pf = fopen(path, "wb");
    if(!pf)
        return 0;

    fwrite(dataToSave,tam,1,pf);
    fclose(pf);
    return 1;
}

int mostrarArchivoBinarioAlumno(const char *path){

    FILE *pf = fopen(path, "rb");
    t_alumno alu;

    if(!pf)
        return 0;

    //Equivalente a while(!feof(pf))
    while(fread(&alu, sizeof(alu), 1, pf)){
        printf("\nAlumno: %s, DNI: %u, Legajo: %u, Edad: %u, Fecha ingreso: %u/%u/%u, Promedio: %.2f",
                alu.apeNom,
                alu.dni,
                alu.legajo,
                alu.edad,
                alu.fechaIngreso.dia,
                alu.fechaIngreso.mes,
                alu.fechaIngreso.anio,
                alu.prom);
    }
    return 1;
}

int guardarArchivoTextoLongVariable(const char *path, t_alumno *alumno, size_t cant){

    FILE *pf = fopen(path, "wt");
    if(!pf)
        return 0;

    for(int i = 0; i < cant; i++){
        fprintf(pf,"%s|%d|%d|%d|%d/%d/%d|%.2f\n",
                alumno[i].apeNom,
                alumno[i].dni,
                alumno[i].legajo,
                alumno[i].edad,
                alumno[i].fechaIngreso.dia,
                alumno[i].fechaIngreso.mes,
                alumno[i].fechaIngreso.anio,
                alumno[i].prom);
    }
    fclose(pf);
    return 1;
}

int guardarArchivoTextoLongFija(const char *path, t_alumno *alumno, size_t cant){

    FILE *pf = fopen(path, "wt");
    if(!pf)
        return 0;

    for(int i = 0; i < cant; i++){
        fprintf(pf,"%-31s %08d %04d %d %02d/%02d/%04d %.2f\n",
                alumno[i].apeNom,
                alumno[i].dni,
                alumno[i].legajo,
                alumno[i].edad,
                alumno[i].fechaIngreso.dia,
                alumno[i].fechaIngreso.mes,
                alumno[i].fechaIngreso.anio,
                alumno[i].prom);
    }
    fclose(pf);
    return 1;
}
