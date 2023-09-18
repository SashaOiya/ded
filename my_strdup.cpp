#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *my_strdup ( char *str )
{
    char *s = ( char * )calloc( 1, strlen ( str ) );
    if ( s == nullptr ) {

        return 0; //     struct
    }

    strcpy ( s, str );

    return s;
}
