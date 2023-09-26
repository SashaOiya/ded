#ifndef CTOR
#define CTOR

#include <stdio.h>
#include <stdlib.h>

int Split ( char *buffer, const int file_size );
int Split2 ( const int n_lines, char **ptr_array, char *buffer, const int file_size );
char *TextCtor ( int *file_size, FILE *f );

#endif // CTOR
