#ifndef CTOR
#define CTOR

#include <stdio.h>
#include <stdlib.h>

char ** Split ( char *buffer, const int file_size, size_t *n_lines_ptr );
char *TextCtor ( int *file_size, FILE *f );

#endif // CTOR
