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
    fclose(pf);
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

int mostrarArchivoTextoLongVariable(const char *path){

    FILE *pf = fopen(path, "rt");
    t_alumno alu;

    if(!pf)
        return 1;

    //--------------------------------
    ///Usando fscanf:

    /*Al comparar lo que devuelve el fscanf contra el 8, lo que hago es comprobar
    si en la lectura del archivo lo que lei fueron 8 datos (que serian los campos
    listados del alumno)*/
    while(fscanf(pf, "%[^|\n]|%d|%d|%d|%d/%d/%d|%f\n",
                alu.apeNom,
                &alu.dni,
                &alu.legajo,
                &alu.edad,
                &alu.fechaIngreso.dia,
                &alu.fechaIngreso.mes,
                &alu.fechaIngreso.anio,
                &alu.prom) == 8){

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

    fclose(pf);
    return 1;
}

int mostrarArchivoTextoLongFija(const char *path){

    FILE *pf = fopen(path, "rt");
    t_alumno alu;

    if(!pf)
        return 1;

    //--------------------------------
    ///Usando fscanf:
    while(fscanf(pf, "%31[^\n] %8d %4d %d %2d/%2d/%4d %f\n",
                alu.apeNom,
                &alu.dni,
                &alu.legajo,
                &alu.edad,
                &alu.fechaIngreso.dia,
                &alu.fechaIngreso.mes,
                &alu.fechaIngreso.anio,
                &alu.prom) == 8){

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

    fclose(pf);
    return 1;
}

int archivoAlumnoBinarioATextoLongVariable(const char *path){

    FILE *pfBin = fopen(path, "rb");
    if(!pfBin)
        return 0;
    FILE *pfTexto = fopen("BinarioATexto.txt", "wt");
    if(!pfTexto)
        return 0;

    t_alumno alumno;

    while(fread(&alumno,sizeof(alumno),1,pfBin)){
         fprintf(pfTexto,"%s|%d|%d|%d|%d/%d/%d|%.2f\n",
                alumno.apeNom,
                alumno.dni,
                alumno.legajo,
                alumno.edad,
                alumno.fechaIngreso.dia,
                alumno.fechaIngreso.mes,
                alumno.fechaIngreso.anio,
                alumno.prom);
    }

    fclose(pfBin);
    fclose(pfTexto);
    return 1;
}

int archivoAlumnoTextoLongVariableABinario(const char *path){

    FILE *pfTexto = fopen(path, "rt");
    if(!pfTexto)
        return 0;
    FILE *pfBin = fopen("TextoABinario.dat", "wb");
    if(!pfBin)
        return 0;

    t_alumno alumno;

    while(fscanf(pfTexto, "%[^|\n]|%d|%d|%d|%d/%d/%d|%f\n",
                alumno.apeNom,
                &alumno.dni,
                &alumno.legajo,
                &alumno.edad,
                &alumno.fechaIngreso.dia,
                &alumno.fechaIngreso.mes,
                &alumno.fechaIngreso.anio,
                &alumno.prom) == 8){

        fwrite(&alumno,sizeof(alumno),1,pfBin);
    }

    fclose(pfBin);
    fclose(pfTexto);
    return 1;
}
