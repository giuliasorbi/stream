#include <stdio.h>
#include "minimum.h"

int minimum( int *values, int n ) 
{
    int min = values[0];
    int index = 0;
    for (int i = 1; i < n; i++) {
        if (values[i] <= min) {
            min = values[i];
            index = i;
        }
    }
    return index;
}