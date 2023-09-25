#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "compare.h"
#include "my_strdup.h"
#include "print_data.h"
#include "getfilesize.h"
#include "bublesort.h"

struct Line
{
    char** ptr_array = nullptr;
};

struct Text
{
    size_t n_lines = 0;
    Line *lines = nullptr;
    char* buffer = nullptr;
};

int Split ( char *buffer, int file_size );
int Split2 (  int n_lines, char **ptr_array, char *buffer, int file_size );

int main()
{
    Text Text_Elements = {};
    Line  Ptr_Elements = {};
    FILE *f = fopen ( "text.txt", "r" );    // "r" or "rb"

    if ( f == nullptr )
    {
        printf("%s\n", strerror(errno));            // print('File not found')
                                                    // errno
        return EXIT_FAILURE;                        // strerror(21) --> "...."
    }                                               // perror

    int file_size = GetFileSize ( f );

    Text_Elements.buffer = (char *)calloc ( file_size + 1, sizeof ( char ) );

    if ( Text_Elements.buffer == nullptr ) {
        fclose ( f );

        return EXIT_FAILURE;
    }

    file_size = fread ( Text_Elements.buffer, sizeof( char ), file_size, f );
    if ( ferror ( f ) ) {
            perror ( "Error reading test.bin" );
            free ( Text_Elements.buffer );

            return EXIT_FAILURE;
    }

    Text_Elements.buffer[file_size] = '\n';

    Text_Elements.n_lines = Split ( Text_Elements.buffer, file_size );

    char *ptr_array[Text_Elements.n_lines];

    ptr_array[0] = Text_Elements.buffer;

    Split2 ( Text_Elements.n_lines, ptr_array, Text_Elements.buffer, file_size );

    //qsort ( ptr_array, Text_Elements.n_lines, sizeof ( char * ), compare );

    bouble_sort ( ptr_array, Text_Elements.n_lines, compare );

    PrintDataPtrArray ( ptr_array, Text_Elements.n_lines );

    free ( Text_Elements.buffer );
    //*Ptr_Array = nullptr;    // wtf text5=nullptr don't work

    fclose ( f );
    return 0;
}

int Split ( char *buffer, int File_Size )
{
    int nlines = 0;

    for ( int i = 0; i <= File_Size; ++i ) {
        if ( *( buffer + i ) == '\n' ) {
            ++nlines;
            *( buffer + i ) = '\0';
        }
    }

    return nlines;
}

int Split2 (  int n_lines, char **Ptr_Array, char *buffer, int File_Size )
{
    for ( int i = 1, j = 1; i < File_Size && j < n_lines; ++i ) {
        if ( buffer[i] == '\0' ) {
            Ptr_Array[j++] = buffer + i + 1;
        }
    }
}

