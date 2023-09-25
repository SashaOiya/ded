#include "my_strdup.h"

char *my_strdup ( char *str )
{
    char *s = ( char * )calloc( 1, strlen ( str ) );
    if ( s == nullptr ) {

        return 0;
    }

    strcpy ( s, str );

    return s;
}
