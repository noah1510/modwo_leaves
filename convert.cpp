#include "convert.hpp"

using namespace std;

using namespace Magick;

int convgrayscale (string path, int* output){
    
    string line;

    ifstream imageget (path);
    if (imageget.is_open() ) {
        int counter = 0;
        while ( getline (imageget, line)) {
            if(counter>3) {
                *(output + counter - 4) = stoi(line);
            }
            counter++;           
        }
        imageget.close();
        return 0;
    }else{
        return 1;
    }

    
}

int convpng (string path, int* output){
    
    string line;

    ifstream imageget (path);
    if (imageget.is_open() ) {
        int counter = 0;
        while ( getline (imageget, line)) {
            if(counter>3) {
                *(output + counter - 4) = stoi(line);
            }
            counter++;           
        }
        imageget.close();
        return 0;
    }else{
        return 1;
    }

    
}