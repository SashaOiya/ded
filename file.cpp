#include <stdio.h>


// raZdelnaya compilatsia
#include "my_strdup.cpp"
#include "print_data.cpp"
#include "getfilesize.cpp"
#include "compare.cpp"

// doxygen!!!
// readme!!!

/*
struct Line
{
    const char* start_p;
};

struct Text
{
    size_t n_lines;
    Line *lines;
    const char* buffer;
};

*/

int main()
{
    FILE *f = fopen ( "text.txt", "r" );    // "r" or "rb"
    /*
    if ( f == nullptr )
    {
        printf("%s\n", strerror(errno));
        return EXIT_FAILURE; //
    }
    */
    // print('File not found')
    // errno
    // strerror(21) --> "...."
    // perror

    int nlines = 0;
    int File_Size = GetFileSize ( f ); // file_size

    char *buffer = (char *)calloc ( File_Size + 1, sizeof ( char ) ); // free!!!
    //if (...)
    fread ( buffer, sizeof( char ), File_Size, f );//error
    // if (...) free() return
    buffer[File_Size] = '\n';

    // fn Split
    for ( int i = 0; i <= File_Size; ++i ) {
        if ( buffer[i] == '\n' ) {
            ++nlines;
            buffer[i] = '\0';
        }
    }

    char **text5 = (char **)calloc ( nlines, sizeof ( char * ) );
    // if (...)  free(buffer)

    text5[0] = buffer;

    for ( int i = 1, j = 1; i < File_Size  && j < nlines; ++i ) {
        if ( buffer[i] == '\0' ) {
            text5[j++] = my_strdup ( buffer + i + 1 );
        }
    }

    // [hello\0world\0it\0is\0me now]
    // p1 --> [hello]
    // p2 --> [world]
    // p3 --> [it]
    // p4 --> [is]
    // p5 --> [me]
    // p6 --> [now]

    // p1 -->


    qsort ( text5, nlines, sizeof ( char * ), compare );

    PrintDataPtrArray ( text5, nlines );

    // Fix --> one! free()
    for ( int i = 0; i < nlines; ++i ) {
        free ( text5[i] );
        text5[i] = nullptr;
    }

    // text5 = nullptr;
    //->[   ]->[ ]->   80       ]
    fclose ( f );
    return 0;
}

//  script!!!!!!

