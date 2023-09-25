#ifndef BUBLE
#define BUBLE

#include <stdio.h>
#include <string.h>

int compare ( const void * str_1, const void * str_2 );
int bouble_sort ( char **s, size_t size, int (*func) ( const void *, const void * ) );

#endif

