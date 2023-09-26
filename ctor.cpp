#include "ctor.h"

int Split ( char *buffer, const int File_Size )
{
    buffer[File_Size] = '\n';

    int n_lines = 0;

    for ( int i = 0; i <= File_Size; ++i ) {
        if ( *( buffer + i ) == '\n' ) {
            ++n_lines;
            *( buffer + i ) = '\0';
        }
    }

    return n_lines;
}

int Split2 ( const int n_lines, char **Ptr_Array, char *buffer, const int File_Size )
{
    Ptr_Array[0] = buffer;

    for ( int i = 1, j = 1; i < File_Size && j < n_lines; ++i ) {
        if ( buffer[i] == '\0' ) {
            Ptr_Array[j++] = buffer + i + 1;
        }
    }
}

char *TextCtor ( int *file_size, FILE *f )
{
    char *buffer = (char *)calloc ( *file_size + 1, sizeof ( char ) );

    if ( buffer == nullptr ) {
        fclose ( f );

        return nullptr;
    }

    *file_size = fread ( buffer, sizeof( char ), *file_size, f );
    if ( ferror ( f ) ) {
        perror ( "Error reading test.bin" );
        free ( buffer );

        return nullptr;
    }

    return buffer;
}
