#include <iostream>
#include <fstream>
#include "read.h"

using namespace std;

void sleep(unsigned int mseconds) //microsecondi
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

int read_file( fstream &file ) 
{
    string linebuffer;
    int value;
   
    while (  file.eof() ) {
        sleep(1000000);
        cout<< "sleep\n";
    }
    getline(file, linebuffer);
    value = stoi(linebuffer);
    return value;
}