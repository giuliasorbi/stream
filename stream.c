#include <stdio.h>
#include <unistd.h>

int read_file(FILE *file){
    int value;
    int restart = 0;
    while(!restart)
    {
        if(fscanf(file,"%d",&value) != EOF)
            restart = 1;
        else
            sleep(1);
    }
    return value;
}

int minimum(int v1, int v2, int v3)
{
    if(v1 <= v2){
        if(v1 <= v3)
            return v1;
    }
    else{
        if(v2 <= v3)
            return v2;
        else
            return v3;
    }
}
int main()
{
    FILE *f1, *f2, *f3;
    int value1, value2, value3, min;
    f1 = fopen("file1.txt", "r");
    f2 = fopen("file2.txt", "r");
    f3 = fopen("file3.txt", "r");
    value1 = read_file(f1);
    value2 = read_file(f2);
    value3 = read_file(f3);
    //printf("%d %d %d\n", value1, value2,value3);

    while(1)
    {
        min = minimum(value1, value2, value3);
        printf("%d\n", min);

        if (min == value1) {
            value1 = read_file(f1);
        } else if (min == value2) {
            value2 = read_file(f2);
        } else if (min == value3) {
            value3 = read_file(f3);
        }
    }
}

