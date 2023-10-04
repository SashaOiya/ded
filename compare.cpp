#include "compare.h"

int compare ( const void * str_1, const void * str_2 )
{

    return strcmp ( (const char *)str_1, (const char *)str_2 );       // *(char **)
}

