#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "my_strdup.cpp"
#include "print_data.cpp"

int main()
{
    FILE *f = fopen ( "text.txt", "r" );

    const int line = 100;
    const int nlines = 4;
    char * *text4 = (char **)calloc ( nlines, sizeof ( char * ) );

    for ( int p = 0; p < nlines; ++p ) {
        char buffer[100] = {};
        text4[p] = strdup ( fgets ( buffer, sizeof ( buffer ), f ) );
    }

    PrintDataPtrArray ( text4, nlines, line );

    for ( int i = 0; i < nlines; ++i ) {
        free ( text4[i] ) ;
        text4[i] = nullptr;
    }

    return 0;
}
