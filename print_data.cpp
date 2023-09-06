#include <stdio.h>

void PrintDataTriagle ( const char *str, size_t rows, size_t cols );
void PrintDataLine ( const char *str, size_t rows, size_t cols );
void PrintDataPtrArray ( const char *str, size_t rows, size_t cols );

void PrintDataTriagle ( char *str, size_t rows, size_t cols )
{
    int n = 0;
    for ( int j = 1; j <= rows; ++j ) {
        if ( j == rows ) {
            for ( int i = 0; i < cols; ++i ) {
                printf ( "%d", *(str + n + i ) );
            }
        }

        else {
            for ( int i = 0; i < j; ++i ) {
                printf ( "%d", *(str + n + i ) );
            }
        }
        n = n + j;
        printf ( "\n" );
    }

}

void PrintDataLine ( const char *str, size_t rows, size_t cols )
{
    for ( int i = 0; i < rows; ++i ) {
        for ( int j = 0; j < cols; ++j ) {
            printf ( "%c", *(str + cols * i + j ) );
        }
        printf ( "\n" );
    }
}

void PrintDataPtrArray ( char *str[], size_t rows, size_t cols )
{
    for ( int i = 0; i < rows; ++i ) {
        //for ( int j = 0; j < cols; ++j ) {
            printf ( "%s", str[i] );
        //}
        printf ( "\n" );
    }
}
