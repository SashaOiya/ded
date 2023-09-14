#include <stdio.h>
#include <stdlib.h>
#include "print_data.cpp"

int sort ( char *data, int left, int right )
{
    const int mid = ( right - left ) / 2;
    char value = data[mid];
    int pointer = 0;
    char *buffer =( char *)calloc( right, sizeof ( char ) );
    int j = right;
    int g = 0;
    int flag = 0;
    char bla = 0;
    //char *buffer = (char *)calloc ( value + 1, sizeof ( char ) );
    printf ( "meow\n" );

    for ( int i = 0; left + i < mid && j >= mid; ++i, --j ) {
        if ( data[i] >= value && flag == 0 ) {
            pointer = i;
            flag = 2;
            bla = data[i];
        }
        else if ( data[i] >= value && flag == 1 ) {
            data[pointer] = data[j];
            data[j] = bla;
            flag = 0;
        }
        if ( data[j] < value && flag == 2 ) {     //enum
            data[pointer] = data[j];
            data[j] = bla;
            flag = 0;
        }
        else if ( data[j] < value && flag == 0 ) {
            pointer = j;
            flag = 1;
            bla = data[j];
        }
    }
    for ( int i = 0; right - i >= mid && g >= 0; ++i ) {
        if ( data[i] > value && g - 1 > 0 ) {
            data[i] = buffer[g--] ;
        }
    }

    //free

    return mid;
}

int main ()
{
    char data[] = { 9, 8, 8, 4, 6, 7 };
    int mid = sort ( data, 0, 5 );  //6
    //printf ( "%d\n", mid );
    //printf ( "%s\n", data );
    PrintDataLine ( data, 1, 6 );

    return 0;
}
