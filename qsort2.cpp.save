#include <stdio.h>
#include <stdlib.h>
#include "print_data.cpp"

int portition ( char *data, int left, int right );
void qsort ( char *data, int left, int right );


// GLOBALS!!!!!! ????????
int flag = 0;
int zerro_point = 0;

enum Value_t {
    RIGHT_POINTER = 1,
    LEFT_POINTER  = 2
};

// qsort original
// my_qsort

int main ()
{
    char data[] = { 5,2,8,1,4,3,7,5,2,1,2,4,2,6,8,8 };  // heheheheheheheheheheh
    //portition ( data, 0,  sizeof ( data ) / sizeof ( char ) - 1 );  //6   // sizeof ( data ) / sizeof ( char )
    zerro_point = sizeof ( data ) / sizeof ( char ) - 1;
    qsort ( data, 0,  sizeof ( data ) / sizeof ( char ) - 1 );
    //printf ( "%d\n", mid );
    //printf ( "%s\n", data );
    PrintDataLine ( data, 1,  sizeof ( data ) / sizeof ( char )  );

    return 0;
}

int portition ( char *data, int left, int right )
{
    int mid = 0;
    mid = ( right - left ) / 2;
    /*if (      ( right - left ) % 2 == 0 ) {
        mid = ( right - left ) / 2;
    }
    else if ( ( right - left ) % 2 == 1 ) {
        mid = ( right - left ) / 2;
    } */

    char value = data[mid+left];
    //printf ( "%d\n", value );
    int pointer = 0;
    //char *buffer =( char *)calloc( right, sizeof ( char ) );
    int j = right;
    int g = 0;
    int flag = 0;
    char bla = 0;
    //char *buffer = (char *)calloc ( value + 1, sizeof ( char ) );
    //printf ( "meow\n" );

    for ( int i = 0; left + i <= mid + left && j >= mid + left; ) {
        if ( data[i+left] >= value && flag == 0 ) {
            pointer = i + left;
            flag    = LEFT_POINTER;
            bla     = data[i+left];
        }
        else if ( data[i+left] >= value && flag == RIGHT_POINTER ) {
            data[pointer] = data[i+left];
            data[i+left]       = bla;
            flag          = 0;
        }
        /*else if ( data[i] >= value && flag == LEFT_POINTER && i == mid ) {
            data[pointer] = data[i];
            data[i]       = bla;
            flag          = 0;
        } */
        /*printf ( "%d\t%d\t", j, i );
        printf ( "%d\n", bla ); */
        if ( data[j] < value && flag == LEFT_POINTER && j != mid + left ) {     //enum
            data[pointer] = data[j];
            data[j] = bla;
            flag = 0;
        }
        else if ( data[j] < value && flag == 0 ) {   // 0 enum
            pointer = j;
            flag = RIGHT_POINTER;
            bla = data[j];
        }

        else if ( data[j] <= value && flag == LEFT_POINTER && j == mid + left ) {
            data[pointer] = data[j];
            data[j]       = bla;
            flag          = 0;
        }
        if ( flag == RIGHT_POINTER ) {
            ++i;
        }
        else if ( flag == LEFT_POINTER ) {
            --j;
        }
        else {
            ++i;
            --j;
        }
    }
    /*for ( int i = 0; right - i >= mid && g >= 0; ++i ) {
        if ( data[i] > value && g - 1 > 0 ) {
            data[i] = buffer[g--] ;
        }
    } */

    //free

    return mid;
}

void qsort ( char *data, int left, int right )
{
    int mid = portition ( data, left, right );
    portition ( data, mid , right );
    if ( mid != 0 && flag == 0 ) {
        printf ("lox\n");
        printf ("<%d>\n", flag );
        printf ( "%d\n", mid );
        qsort ( data, left, mid );
    }
    else if ( mid == 0 ) {
        flag = 1;
    }
    //printf ("lox\n");
    //$
    printf ("<<%d>>\n", flag );

    //portition ( data, mid, right );

    /*printf ("<//%d//>\n", right - left  );
    if ( right - mid != 0 && flag == 1 && right - left != zerro_point ) {
        qsort ( data, mid, right );  */
    //}

}
