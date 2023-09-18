#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "compare.h"
#include "my_strdup.h"
#include "print_data.h"
#include "getfilesize.h"

// doxygen!!!
// readme!!!

struct Line
{
    char** ptr_array;
};

struct Text
{
    size_t n_lines = 0;
    Line *lines;
    char* buffer;
};

int Split ( char *buffer, int File_Size );

int main()
{
    Text Text_Elements;
    Line  Ptr_Elements;
    FILE *f = fopen ( "text.txt", "r" );    // "r" or "rb"

    if ( f == nullptr )
    {
        printf("%s\n", strerror(errno));

        return EXIT_FAILURE; //
    }

    // print('File not found')
    // errno
    // strerror(21) --> "...."
    // perror

    int File_Size = GetFileSize ( f );

    Text_Elements.buffer = (char *)calloc ( File_Size + 1, sizeof ( char ) ); // free!!!
    if ( Text_Elements.buffer == nullptr ) {
        fclose ( f );

        return EXIT_FAILURE;    //
    }

    fread ( Text_Elements.buffer, sizeof( char ), File_Size, f );//error
    // if (...) free() return
    Text_Elements.buffer[File_Size] = '\n';

    Text_Elements.n_lines = Split ( Text_Elements.buffer, File_Size );

    char *Ptr_Array[Text_Elements.n_lines];
    // if (...)  free(buffer)

    Ptr_Array[0] = Text_Elements.buffer;

    for ( int i = 1, j = 1; i < File_Size  && j < Text_Elements.n_lines; ++i ) {
        if ( Text_Elements.buffer[i] == '\0' ) {
            Ptr_Array[j++] = Text_Elements.buffer + i + 1;
        }
    }

    qsort ( Ptr_Array, Text_Elements.n_lines, sizeof ( char * ), compare );

    PrintDataPtrArray ( Ptr_Array, Text_Elements.n_lines );

    free ( Text_Elements.buffer );
    *Ptr_Array = nullptr;    // wtf text5=nullptr don't work

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

