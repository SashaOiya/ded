#include "bublesort.h"
#include "print_data.h"

void Swap ( char **s, const int j );

int bouble_sort ( char **s, size_t size, int (*func) ( const void *, const void * ) )  //s
{
    //char s[] = { 1, 5, 4, 2, 6, 3 };
    //int (*func) ( const char, const char ) = compare;

    //const int size = strlen ( s );
    printf ("%s\n", (s + 1 * sizeof (char*) ) );

    for ( int n = size; n > 0; --n ) {
        for ( int j = 0; j <= size; ++j ) {
            if ( func ( *(s + j * sizeof ( char *) ), *(s + ( j + 1 ) * sizeof ( char *)  ) ) ) {
                Swap ( s, j );
            }
        }
    }

    return 0;
}

void Swap ( char **s, const int j )
{
    char *value = *(s + j * sizeof ( char *) );
    *(s + j * sizeof ( char *) ) = *(s + ( j + 1 ) * sizeof ( char *) );
    *(s + ( j + 1 ) * sizeof ( char *) ) = value;
}
