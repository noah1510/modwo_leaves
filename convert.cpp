#include "convert.hpp"

using namespace std;

int* convimg (string path) {

    static int pgm [BILDGROESSE*BILDGROESSE];
    string out;
    string line;
    ifstream imageget (path);
    if (imageget.is_open() ) {
        int counter = 0;
        while ( getline (imageget, line)) {
            if(counter>3) {
                pgm[counter-4] = stoi(line);
                out = out + " " + line;
            }

            counter++;
            
        }
        imageget.close();
    }

    return pgm;
}
