#include <stdio.h>
#include <string.h>

#include "print_data.cpp"

int main()
{
    char s[] = { 1, 5, 4, 2, 6, 3 };

    const int size = strlen ( s );

    for ( int n = size; n > 0; --n ) {
        for ( int j = 0; j <= size; ++j ) {
            if ( s[j] > s[j + 1] ) {
                char value = s[j];
                s[j] = s[j+1];
                s[j+1] = value;
            }
        }
    }
    PrintDataLine ( s, 1, size );

    return 0;
}
