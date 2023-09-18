#include <stdio.h>

/*

fread(...)
GetFileSize
fread(...)

*/

int GetFileSize ( FILE * f )
{
    FILE *start_position = f;

    fseek ( f, 0, SEEK_END );
    size_t sizet = ftell ( f );
    fseek ( f, 0, SEEK_SET );

    f = start_position;

    return sizet;
}
