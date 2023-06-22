#ifndef CADENAS_H_INCLUDED
#define CADENAS_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>

size_t miStrlen(const char *s);
char *miStrchr(char *s, int c);
char *miStrrchr(char *s, int c);
char *miStrcpy(char *dest, const char *src);
char *miStrcat(char*s1, const char *s2);
int miToLower(char c);
int miStrcmp(const char *s1, const char *s2);
int miStrcmpi(const char *s1, const char *s2);
char *miStrstr(const char *s1, const char *s2);
void *miMemcpy(void *s1, const void *s2, size_t n);
void *miMemmove(void *s1, const void *s2, size_t n);

#endif // CADENAS_H_INCLUDED
