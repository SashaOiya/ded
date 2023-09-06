#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "print_data.cpp"

int main()
{
    FILE *f = fopen ( "text.txt", "r" );

    const int rows = 4;
    const int line = 100;
    char *text2[rows] = {};

    for ( int p = 0; p < rows; ++p ) {
        char buffer[line] = {};
        fgets ( buffer, sizeof ( buffer ), f ) ;
        text2[p] = (char *)calloc ( rows, strlen ( buffer ) );
        strcpy ( text2[p], buffer );
    }

    PrintDataPtrArray ( text2, rows, line );

    for ( int i = 0; i < rows; ++i ) {
        free ( text2[i] ) ;
        text2[i] = nullptr;
    }

    return 0;
}
