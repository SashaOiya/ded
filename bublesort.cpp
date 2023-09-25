#include "bublesort.h"
#include "print_data.h"

void Swap ( char **s, const int j );

// compare
// void* void* aize_t
int bubble_sort ( char *s[], size_t size )
{
    for ( int n = size; n > 0; --n ) {
        for ( int j = 0; j < size -1 ; ++j ) {
            if ( strcmp ( s[j], s[j+1] ) > 0 ) {
                Swap ( s, j );
            }
        }
    }
    //PrintDataPtrArray ( s, size );

    return 0;
}

// p p size
void Swap ( char **s, const int j )
{
    char *value = s[j];
    s[j] = s[j+1];
    s[j+1] = value;
}
