#include "Archivos.h"
#include <stdlib.h>
#include <stdio.h>
#include "MiString.h"

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

int mostrarArchivoTextoLongVariableConStringH(const char *path){

    FILE *pf = fopen(path, "rb");
    if(!pf)
        return 0;

    char cadena[100];
    t_alumno alu;

    while(fgets(cadena,sizeof(cadena),pf)){

        char *aux = miStrchr(cadena, '\n');
        *aux = '\0';
        //Promedio
        aux = miStrrchr(cadena,'|');
        sscanf(aux + 1, "%f", &alu.prom);
        //Fecha de ingreso
        *aux = '\0';
        aux = miStrrchr(cadena, '|');
        sscanf(aux + 1, "%d/%d/%d",  &alu.fechaIngreso.dia,
                                     &alu.fechaIngreso.mes,
                                     &alu.fechaIngreso.anio);
        //Edad
        *aux = '\0';
        aux = miStrrchr(cadena, '|');
        sscanf(aux + 1, "%d", &alu.edad);
        //Legajo
        *aux = '\0';
        aux = miStrrchr(cadena, '|');
        sscanf(aux + 1, "%d", &alu.legajo);
        //DNI
        *aux = '\0';
        aux = miStrrchr(cadena, '|');
        sscanf(aux + 1, "%d", &alu.dni);
        //Apellido y nombre
        *aux = '\0';
        sscanf(cadena, "%[^|\n]", alu.apeNom);

        printf("\n%s %d %d %d %d/%d/%d %f",
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

int compararDni(void *ptr1, void *ptr2){

    t_alumno *alumno1 = (t_alumno*)ptr1;
    t_alumno *alumno2 = (t_alumno*)ptr2;

    return alumno1->dni-alumno2->dni;
}

int compararDniIdxAlu(void *ptr1, void *ptr2){

    idx_alumno *idx1 = (idx_alumno*)ptr1;
    idx_alumno *idx2 = (idx_alumno*)ptr2;

    return idx1->dni - idx2->dni;
}

int mergeArchivosBinAlumnoUnion(const char *path1, const char *path2, const char *pathRes){

//Los elementos de cad archivo fueron guardados previamente ordenados (en este caso, por dni)
    FILE *pf1 = fopen(path1, "rb");
    FILE *pf2 = fopen(path2, "rb");
    FILE *pfRes = fopen(pathRes, "wb");
    t_alumno alu1,
             alu2;

    if(!pf1 || !pf2 || !pfRes)
        return 0;

    fread(&alu1,sizeof(t_alumno),1,pf1);
    fread(&alu2,sizeof(t_alumno),1,pf2);
    while(!feof(pf1) && !feof(pf2)){
        int cmpRes = compararDni((void*)&alu1, (void*)&alu2);

        if(cmpRes == 0){
            fwrite(&alu1,sizeof(t_alumno),1,pfRes);
            fread(&alu1,sizeof(t_alumno),1,pf1);
            fread(&alu2,sizeof(t_alumno),1,pf2);
        }
        else if(cmpRes < 0){
            fwrite(&alu1,sizeof(t_alumno),1,pfRes);
            fread(&alu1,sizeof(t_alumno),1,pf1);
        }
        else if(cmpRes > 0){
            fwrite(&alu2,sizeof(t_alumno),1,pfRes);
            fread(&alu2,sizeof(t_alumno),1,pf2);
        }
    }
     while(!feof(pf1)){
        fwrite(&alu1, sizeof(t_alumno), 1, pfRes);
        fread(&alu1, sizeof(t_alumno), 1, pf1);
    }
    while(!feof(pf2)){
        fwrite(&alu2, sizeof(t_alumno), 1, pfRes);
        fread(&alu2, sizeof(t_alumno), 1, pf2);
    }


    fclose(pf1);
    fclose(pf2);
    fclose(pfRes);

    return 1;
}

int mergeArchivosBinAlumnoInterseccion(const char *path1, const char *path2, const char *pathRes){

    //Los elementos de cad archivo fueron guardados previamente ordenados (en este caso, por dni)
    FILE *pf1 = fopen(path1, "rb");
    FILE *pf2 = fopen(path2, "rb");
    FILE *pfRes = fopen(pathRes, "wb");
    t_alumno alu1,
             alu2;

    if(!pf1 || !pf2 || !pfRes)
        return 0;

    fread(&alu1,sizeof(t_alumno),1,pf1);
    fread(&alu2,sizeof(t_alumno),1,pf2);
    while(!feof(pf1) && !feof(pf2)){
        int cmpRes = compararDni((void*)&alu1, (void*)&alu2);

        if(cmpRes == 0){
            fwrite(&alu1,sizeof(t_alumno),1,pfRes);
            fread(&alu1,sizeof(t_alumno),1,pf1);
            fread(&alu2,sizeof(t_alumno),1,pf2);
        }
        else if(cmpRes < 0){
             fread(&alu1, sizeof(t_alumno), 1, pf1);
        }
        else if(cmpRes > 0){
             fread(&alu2, sizeof(t_alumno), 1, pf2);
        }

    }

    fclose(pf1);
    fclose(pf2);
    fclose(pfRes);

    return 1;
}

int construirIndice(const char *pathMaster, const char *pathIdx){

    FILE *pfMaster = fopen(pathMaster, "rb");
    FILE *pfIdx = fopen(pathIdx, "wb");

    if(!pfMaster || !pfIdx)
        return 0;

    t_alumno alu;
    idx_alumno idx;
    int n = 0;

    while(fread(&alu, sizeof(t_alumno), 1, pfMaster)){
        idx.dni = alu.dni;
        idx.indice = n++;
        fwrite(&idx, sizeof(idx), 1, pfIdx);
    }

    fclose(pfMaster);
    fclose(pfIdx);
    return 1;
}

int ordenarArchivoIndices(const char *path){

    FILE *pf = fopen(path, "r+b");
    if(!pf)
        return 0;

    fseek(pf, 0, SEEK_END);
    size_t cantReg = ftell(pf)/sizeof(idx_alumno);
    idx_alumno *indices = (idx_alumno*)malloc(sizeof(idx_alumno)*cantReg);
    fseek(pf, 0, SEEK_SET);
    fread(indices, sizeof(idx_alumno), cantReg, pf);

    ordenarSeleccionGenerico(indices, cantReg, sizeof(idx_alumno), compararDniIdxAlu);
    fseek(pf, 0, SEEK_SET);
    fwrite(indices, sizeof(idx_alumno), cantReg, pf);

    fclose(pf);
    free(indices);
    return 1;
}

int mostrarArchivoBinarioIndices(const char *path){

    FILE *pf = fopen(path, "rb");
    if(!pf)
        return 0;

    idx_alumno indice;

    while(fread(&indice, sizeof(idx_alumno), 1, pf)){
        printf("\nClave: %d, posicion: %d", indice.dni, indice.indice);
    }

    fclose(pf);
    return 1;
}

int buscarAlumnoPorArchivoIndices(const char *pathIdx, const char *pathMaster, int dni){

    FILE *pfIdx = fopen(pathIdx, "rb");
    FILE *pfMaster = fopen(pathMaster, "rb");

    if(!pfIdx || !pfMaster)
        return 0;

    t_alumno alu;
    idx_alumno indice;

    while(fread(&indice, sizeof(idx_alumno), 1, pfIdx)){
        if(indice.dni == dni){
            fseek(pfMaster, (long)(sizeof(t_alumno)*indice.indice), SEEK_SET);
            fread(&alu, sizeof(t_alumno), 1, pfMaster);
            printf("\nEncontrado: %s %d %d %d %d/%d/%d %f",
                   alu.apeNom,
                   alu.dni,
                   alu.legajo,
                   alu.edad,
                   alu.fechaIngreso.dia,
                   alu.fechaIngreso.mes,
                   alu.fechaIngreso.anio,
                   alu.prom);

            fclose(pfIdx);
            fclose(pfMaster);
            return 1;
        }
    }
    printf("\nNo encontrado");

    fclose(pfIdx);
    fclose(pfMaster);
    return 1;
}
