#include <stdio.h>
#include <stdlib.h>
#include "read_file.h"
#include "minimum.h"

int main( int argc, const char* argv[] )
{
    int n = argc - 1;
    int values[n];
    int index;
    FILE *files[n];

    if (argc == 1) {
        printf("Error no input file");
        exit(1);
    }

    // opening all the files and checking whether they exist or not.
    for (int i = 1; i < argc; i++) {
        files[i-1] = fopen(argv[i], "r+");
        if (files[i-1] == NULL) {
            printf("File %s doesn't exist!!!", argv[i]);
            return 1;
        }
    }

    for (int i = 0; i < n; i++) {
        values[i] = read_file(files[i]);
        printf("read stream n %d of value %d\n", i, values[i]);
    }

    while (1) {
        index = minimum(values, n);
        printf("%d\n", values[index]);
        values[index] = read_file(files[index]); 
    }
}