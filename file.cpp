#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "print_data.cpp"

int main()
{
    FILE *f = fopen ( "text.txt", "r" );

    const int line = 100;
    const int nlines = 4;
    char * *text4 = (char **)calloc ( nlines, sizeof ( char * ) );

    for ( int p = 0; p < nlines; ++p ) {
        char buffer[100] = {};
        fgets ( buffer, sizeof ( buffer ), f );
        text4[p] = (char *)calloc ( nlines, strlen ( buffer ) + 1 );
        strcpy ( text4[p], buffer );
    }

    PrintDataPtrArray ( text4, nlines, line );

    for ( int i = 0; i < nlines; ++i ) {
        free ( text4[i] ) ;
        text4[i] = nullptr;
    }

    return 0;
}
