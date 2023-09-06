#include <stdio.h>
#include <string.h>
#include "print_data.cpp"

int main()
{
    FILE *f = fopen ( "text.txt", "r" );

    const int rows = 4;
    const int line = 100;
    char buffer[rows][line] = {};
    //fputs ( "meow", f );

    for ( int p = 0; p < rows; ++p ) {
        fgets ( &buffer[p][0], sizeof ( buffer ), f ) ;
    }

    PrintDataLine ( &buffer[0][0], rows, line  ) ;

    return 0;
}
