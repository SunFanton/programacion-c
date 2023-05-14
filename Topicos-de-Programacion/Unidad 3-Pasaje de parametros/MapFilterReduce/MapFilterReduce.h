#ifndef MAPFILTERREDUCE_H_INCLUDED
#define MAPFILTERREDUCE_H_INCLUDED

void* mi_map(void*, size_t, size_t, void(*accion)(void*));
void* mi_reduce(void*, size_t, size_t, void*,
             void(*freduccion)(void*, const void*));
void* mi_filter(void*, size_t*, size_t, int(*ffilter)(const void*));

#endif // MAPFILTERREDUCE_H_INCLUDED
