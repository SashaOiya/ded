#ifndef BUBLE
#define BUBLE

#include <stdio.h>
#include <string.h>

void Swap ( void **str_1, void **str_2 );
int bubble_sort ( char *s[], const size_t size, int (*compare) ( const void *, const void *) );

// qsort()

#endif

