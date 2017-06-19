#include <stdio.h>
#include <unistd.h>
#include "read_file.h"

int read_file( FILE *file ) 
{
    int value;

    while ( fscanf(file, "%d", &value) == EOF ) {
        printf( "sleep %d\n", feof(file) );
        sleep(1);
    }
    return value;
}



