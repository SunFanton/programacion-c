#include <stdlib.h>
#include <string.h>

void* buscar(const void * vec, size_t ce, size_t tam, void* elem,
             int (*cmp)(const void*, const void*))
{
    while(ce)
    {
        if(cmp(vec, elem)==0)
        {
            return (void*) vec;
        }
        vec+=tam;
        ce--;
    }
    return NULL;
}


void* amap(void*vec, size_t ce, size_t tam, void(*accion)(void*))
{
    void* ini=vec;
    while(ce)
    {
        accion(vec);
        ce--;
        vec+=tam;
    }
    return ini;
}

void* reduce(void*vec, size_t ce, size_t tam, void* valor_retorno,
             void (*freduccion)(void*vr, const void* e))
{
    while(ce)
    {
        freduccion(valor_retorno, vec);
        ce--;
        vec+=tam;
    }
    return valor_retorno;
}


void* filter(void*vec, size_t *ce, size_t tam,
             int (*ffilter)(const void*))
{
    void * pl = vec, * pe = vec;
    int ciclos= *ce;
    while(ciclos--)
    {
        if(ffilter(pl))
        {
            if(pe!=pl)
                memcpy(pe, pl, tam);
            pe+=tam;
        }else{
            (*ce)--;
        }
        pl+=tam;
    }
    return vec;
}
