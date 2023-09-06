#include <stdio.h>
#include <string.h>

int main()
{
    FILE *f = fopen ( "text.txt", "r" );

    char buffer[5][100] = {};
    int n = 1;
    //fputs ( "meow", f );
    char *s = 0;

    for ( int p = 0; p < 4; ++p ) {

        fgets ( &buffer[p][0], sizeof ( buffer ), f ) ;

        //printf ("%d\n", strlen ( buffer ) );
        printf ( "%s\n", &buffer[p][0] );
        if ( p > 0 ) {
            printf ( "%s\n", &buffer[p-1][0] );
        }

        //if ( fscanf ( f, "%s", buffer ) == 1 ) {
        //    printf ( "aboba\n" );
        //}

    }

    return 0;
}
