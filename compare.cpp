#include <string.h>
#include <ctype.h>

/*
    enum !!!!
struct Return_Value_t {
    const int NEGATIVE = -1;
    const int POSITIVE =  1;
    const int EQUAL    =  0;
};   */

// < > 0
int compare ( const void * str_1, const void * str_2 )
{
    /*for ( ;isspace ( **(const char **)str_1 )
        && isspace ( **(const char **)str_2 ); ++(*(const char **)str_1),
                                               ++(*(const char **)str_2) ) {
        ;
    }
    --(*(const char **)str_1);
    --(*(const char **)str_2);   */

    return strcmp ( *(const char **)str_1, *(const char **)str_2 );
}
