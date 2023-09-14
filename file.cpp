#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>

#include "my_strdup.cpp"
#include "print_data.cpp"
#include "getfilesize.cpp"

int main()
{
    FILE *f = fopen ( "text.txt", "r" );

    int nlines = 0;
    int value = GetFileSize ( f );

    char *buffer = (char *)calloc ( value + 1, sizeof ( char ) );
    fread ( buffer, sizeof( char ), value, f );//error
    buffer[value] = '\n';

    for ( int i = 0; i <= value; ++i ) {
        if ( buffer[i] == '\n' ) {
            ++nlines;
            buffer[i] = '\0';
        }
    }

    char * *text5 = (char **)calloc ( nlines, sizeof ( char * ) );

    text5[0] = buffer;

    for ( int i = 1, j = 1; i < value  && j < nlines; ++i ) {
        if ( buffer[i] == '\0' ) {
            text5[j++] = my_strdup ( buffer + i + 1 );
        }
    }

    PrintDataPtrArray ( text5, nlines );

    for ( int i = 0; i < nlines; ++i ) {
        free ( text5[i] );
        text5[i] = nullptr;
    }

    fclose ( f );

    return 0;
}

