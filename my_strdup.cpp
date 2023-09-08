#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *my_strdup ( char *str );

char *my_strdup ( char *str )
{
    char *s = ( char * )calloc( 1, strlen ( str ) );

    if ( strlen ( str ) == EOF ) {
        return nullptr;
    }
    else {
        strcpy ( s, str );
    }

    return s;
}
