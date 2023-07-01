/***************************************************************************************
******************************* Complete sus datos *************************************
****************************************************************************************
* Apellido, Nombres:
*
* DNI:
*
****************************************************************************************/

#include <locale.h>
#include <windows.h>
#include <stdio.h>
#include "../SolucionParcialArmadoPCTopicos/TiposArmadoPC.h"
#include "../SolucionParcialArmadoPCTopicos/SolucionParcialArmadoPC.h"


#define ARG_PATH_COMP 1
#define ARG_PATH_ARM_REP 2

int buscarEnVec_ALU(ArmadoYRep *p, char *cod, int reg);
char miToUpper_ALU(int car);
int miStrcmpi_ALU(char *cad1, char *cad2);
int comparaCodigo_ALU(void*, void*);
void intercambiar_ALU(void *p1, void *p2, size_t tam);
void *buscarMenor_ALU(void *vec, void *fin, size_t tam, int (*cmp)(void*, void*));
void *ordenar_ALU(void *vec, size_t ce, size_t tam, int (*cmp)(void*, void*));


int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "spanish");	// Cambiar locale - Suficiente para máquinas Linux
    SetConsoleCP(1252); 			// Cambiar STDIN -  Para máquinas Windows
    SetConsoleOutputCP(1252);		// Cambiar STDOUT - Para máquinas Windows

    generarArchivoStockComponentes(argv[ARG_PATH_COMP]);

    generarArchivoArmadosYReparaciones(argv[ARG_PATH_ARM_REP]);

    puts("Componentes antes de actualizar:\n");
    mostrarArchivoComponentes(argv[ARG_PATH_COMP]);
    puts("");

    puts("Armados/Reparaciones:");
    mostrarArchivoArmadoYRep(argv[ARG_PATH_ARM_REP]);
    puts("");

    ///*********************************************************************************************************
    //int resp = actualizarComponentes(argv[ARG_PATH_COMP], argv[ARG_PATH_ARM_REP]);
    ///******** Descomente la línea de abajo y comente la de arriba para probar su código **********************
    int resp = actualizarComponentes_ALU(argv[ARG_PATH_COMP], argv[ARG_PATH_ARM_REP]);
    ///*********************************************************************************************************

    if(resp != TODO_OK)
    {
        puts("Error actualizando los componentes.");
        return resp;
    }

    puts("\nComponentes despues de actualizar:\n");
    mostrarArchivoComponentes(argv[ARG_PATH_COMP]);

//	getchar();

    return 0;
}

int buscarEnVec_ALU(ArmadoYRep *p, char *cod, int reg){

    for(int i = 0; i < reg; i++){
        if(miStrcmpi_ALU(p[i].codigo, cod)==0)
            return i;
    }
    return -1;
}

char miToUpper_ALU(int car){

    if((char)car >= 'a' && (char)car <= 'z')
        car = car - ('a' - 'A');

    return (char)car;
}

int miStrcmpi_ALU(char *cad1, char *cad2){

     if (cad1 == NULL && cad2 == NULL) {
        return 0; // Ambas cadenas son nulas, considerarlas iguales
    } else if (cad1 == NULL) {
        return -1; // cad1 es nula, considerarla menor que cad2
    } else if (cad2 == NULL) {
        return 1; // cad2 es nula, considerarla mayor que cad1
    }

    char car1,
         car2;
    while(*cad1 && *cad2){
        car1 = miToUpper_ALU((int)*cad1);
        car2 = miToUpper_ALU((int)*cad2);

        if(car1 < car2)
            return -1;
        else if(car1 > car2)
            return 1;

        cad1++;
        cad2++;
    }
    if(*cad1)
        return 1;

    else if(*cad2)
        return -1;

    return 0;
}


int comparaCodigo_ALU(void* p1, void* p2){

    ArmadoYRep *ar1 = (ArmadoYRep*)p1;
    ArmadoYRep *ar2 = (ArmadoYRep*)p2;

    return miStrcmpi_ALU(ar1->codigo, ar2->codigo);
}

void intercambiar_ALU(void *p1, void *p2, size_t tam){

    char *aux = (char*)malloc(tam * sizeof(char));
    memmove(aux, p1, tam);
    memmove(p1, p2, tam);
    memmove(p2, aux, tam);
    free(aux);
}

void *buscarMenor_ALU(void *vec, void *fin, size_t tam, int (*cmp)(void*, void*)){

    void *menor = vec;
    vec += tam;
    while(vec <= fin){

        if(cmp(vec, menor) < 0)
            menor = vec;

        vec += tam;
    }
    return menor;
}

void *ordenar_ALU(void *vec, size_t ce, size_t tam, int (*cmp)(void*, void*)){

    void *inicio = vec;
    void *fin = vec + (ce - 1)*tam;
    void *menor;

    while (vec < fin){
        menor = buscarMenor_ALU(vec, fin, tam, cmp);
        if(menor != vec)
            intercambiar_ALU(vec, menor, tam);

        vec += tam;
    }

    vec = inicio;
    return vec;
}




int actualizarComponentes_ALU(const char* pathComponentes, const char* pathArmadoYRep)
{
///	Resolver.
/// Nota: Resuelva esta, y todas las funciones que necesite, en este archivo. Que será el que debe entregar. No modifique ni entregue otro/s archivos del proyecto.
/// Agregue el sufijo "_ALU" a todas las funciones que genere.

    FILE *pfArmado = fopen(pathArmadoYRep, "rt");
    if(!pfArmado)
        return ERR_CARGA_IND;

    char linea[100];
    int regArmado = 0;

    ArmadoYRep *armYResp = NULL;
    int indiceExistente;

    int nroOp;
    char codigo[21];
    int cantidad;
    double precioUnitario;

    while(fgets(linea, sizeof(linea), pfArmado)){

            if (sscanf(linea, "%d|%[^|\n]|%d|%lf\n", &nroOp, codigo, &cantidad, &precioUnitario) == 4) {
            indiceExistente = buscarEnVec_ALU(armYResp, codigo, regArmado);
            if (indiceExistente != -1) {
                // Actualizar el registro existente
                armYResp[indiceExistente].cantidad += cantidad;
                armYResp[indiceExistente].precioUnitario = precioUnitario;
            } else {
                // Código de artículo no encontrado en el vector, agregar un nuevo registro
                regArmado++;
                armYResp = realloc(armYResp, regArmado * sizeof(ArmadoYRep));

                strcpy(armYResp[regArmado-1].codigo, codigo);
                armYResp[regArmado-1].nroOp = nroOp;
                armYResp[regArmado-1].cantidad = cantidad;
                armYResp[regArmado-1].precioUnitario = precioUnitario;
            }
        }

    }

    FILE *pfInd = fopen("Componentes.idx", "rb");
    FILE *pfComp = fopen(pathComponentes, "r+b");

    if(!pfInd || !pfComp){
        free(armYResp);
        fclose(pfArmado);
        return ERR_CARGA_IND;
    }

    fseek(pfInd, 0, SEEK_END);
    int regInd = ftell(pfInd) / sizeof(IndComponente);
    rewind(pfInd);
    IndComponente *indices = (IndComponente*)malloc(regInd * sizeof(IndComponente));
    for(int i = 0; i < regInd; i++){
        fread(&indices[i], sizeof(IndComponente), 1, pfInd);
    }

    ordenar_ALU(armYResp, regArmado, sizeof(ArmadoYRep), comparaCodigo_ALU);
    ordenar_ALU(indices, regInd, sizeof(IndComponente), comparaCodigo_ALU);

    t_Componente comp;

    for(int i = 0; i < regInd; i++){
        indiceExistente = buscarEnVec_ALU(armYResp, indices[i].codigo, regArmado);
        if(indiceExistente != -1){
            fseek(pfComp, (long)(sizeof(t_Componente)*(indices[i].nroReg)), SEEK_SET);
            fread(&comp, sizeof(t_Componente), 1, pfComp);
            comp.precioUnitario = armYResp[indiceExistente].precioUnitario;
            comp.stock -= armYResp[indiceExistente].cantidad;
            fseek(pfComp, -(long)(sizeof(t_Componente)), SEEK_CUR);
            fwrite(&comp,sizeof(t_Componente), 1, pfComp);
        }
    }

    free(armYResp);
    free(indices);
    fclose(pfArmado);
    fclose(pfInd);
    fclose(pfComp);
    return TODO_OK;
}

