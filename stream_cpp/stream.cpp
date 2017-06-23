#include <iostream>
#include <fstream>
#include "read.h"
#include "min.h"

using namespace std;

int main( int argc, const char* argv[] )
{
    auto n = argc - 1;
    int values[n];
    int index;
    string linebuffer;
    fstream files[n];

    for (int i = 1; i < argc; i++) {
        files[i-1].open(argv[i], files[i-1].in);
        if (!files[i-1].is_open()) {
            cout << "failed to open " << argv[i] << '\n';
            return 1;
        }
        else {
            cout << "open" << argv[i] << '\n';
        }
    }

    for (int i = 0; i < n; i++) {
        values[i] = read_file( files[i] );
        cout << "read stream n " << i << " of value " << values[i] << "\n";
    }

    while (1) {
        index = minimum(values, n);
        cout <<  values[index] << "\n";
        values[index] = read_file(files[index]); 
    }

    return 0;
}