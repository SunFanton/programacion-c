#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

void* buscar(const void * vec, size_t ce, size_t tam, void* elem,
             int (*cmp)(const void*, const void*));

void* amap(void*vec, size_t ce, size_t tam, void(*accion)(void*));

void* reduce(void*vec, size_t ce, size_t tam, void* valor_retorno,
             void (*freduccion)(void*vr, const void* e));

void* filter(void*vec, size_t *ce, size_t tam,
             int (*ffilter)(const void*));

#endif // VECTOR_H_INCLUDED
