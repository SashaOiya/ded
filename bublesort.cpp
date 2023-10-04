#include "bublesort.h"
#include "compare.h"


// void Swap( void* lhs, void* rhs, size_t size);

// p p size
void Swap ( void **str_1, void **str_2, size_t size ) // size
{
    void *value = *str_1;
    *str_1 = *str_2;
    *str_2 = value;
}
// compare
// void* void* aize_t
int bubble_sort ( char *s[], const size_t size, int (*compare) ( const void *, const void *) )
{
    for ( int n = size; n > 0; --n ) {
        for ( int j = 0; j < size - 1; ++j ) {
            if ( compare ( s[j], s[j+1] ) > 0 ) {
                Swap ( (void**)&s[j], (void**)&s[j+1], sizeof ( char *) );
            }
        }
    }

    return 0;
}

