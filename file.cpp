#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "compare.h"
#include "my_strdup.h"
#include "print_data.h"
#include "getfilesize.h"
#include "bublesort.h"
#include "ctor.h"

/*struct Line_t
{
    char* start = nullptr;
    size_t len;
};

struct Text_t
{
    size_t n_lines = 0;
    //char ** ptr_array = nullptr;
    Line_t* lines;
    char* buffer = nullptr;
}; */

struct Line_t
{
    char* buffer = nullptr;
};

struct Text_t
{
    size_t n_lines = 0;
    char ** ptr_array = nullptr;
};

int main()
{
    Text_t Text_Elements = {};
    Line_t  Ptr_Elements = {};
    FILE *f = fopen ( "text.txt", "r" );    // "r" or "rb"

    if ( f == nullptr )
    {
        printf("%s\n", strerror(errno));            // print('File not found')
                                                    // errno
        return EXIT_FAILURE;                        // strerror(21) --> "...."
    }                                               // perror

    int file_size = GetFileSize ( f );

    Ptr_Elements.buffer = TextCtor ( &file_size, f );

    Text_Elements.ptr_array= Split ( Ptr_Elements.buffer, file_size, &Text_Elements.n_lines );

    //char *ptr_array[Text_Elements.n_lines]; // calloc

    //Split2 ( Text_Elements.n_lines, ptr_array, Ptr_Elements.buffer, file_size );

    bubble_sort ( Text_Elements.ptr_array, Text_Elements.n_lines, compare );

    PrintDataPtrArray ( Text_Elements.ptr_array, Text_Elements.n_lines );

    free ( Ptr_Elements.buffer );
    //*Ptr_Array = nullptr;    // wtf text5=nullptr don't work

    fclose ( f );

    return 0;
}

