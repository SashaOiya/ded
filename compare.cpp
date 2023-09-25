#include "compare.h"

int compare ( const void * str_1, const void * str_2 )
{
    if ( strcmp ( *(const char **)str_1, *(const char **)str_2 ) < 0 ) {      // *(const void **)
        return -1;
    }

    return 1;
}

