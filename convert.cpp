#include "convert.hpp"

using namespace std;

int* convimg (string path, int groesse) {

    static int pgm [256*256];
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
