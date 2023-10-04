#include "ctor.h"


// CALLOC
char ** Split ( char *buffer, const int file_size, size_t *n_lines_ptr )
{
    buffer[file_size] = '\n';

    int n_lines = 0;

    for ( int i = 0; i <= file_size; ++i ) {
        if ( *( buffer + i ) == '\n' ) {
            ++n_lines;
            *( buffer + i ) = '\0';
        }
    }

    *n_lines_ptr = n_lines;

    char **ptr_array = ( char **)calloc( n_lines, sizeof ( char * ) );

    ptr_array[0] = buffer;

    for ( int i = 1, j = 1; i < file_size && j < n_lines; ++i ) {
        if ( buffer[i] == '\0' ) {
            ptr_array[j++] = buffer + i + 1;
        }
    }

    return ptr_array;
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
