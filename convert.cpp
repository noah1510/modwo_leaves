#include "convert.hpp"

using namespace std;


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

int convcsv (string path, int* output){
    
    string line;

    ifstream imageget (path);
    if (imageget.is_open() ) {
        int counter = 0;
        while ( getline (imageget, line)) {
            int pos_str = 0;
            for(int i = 0; i < 255; i++){
                

                *(output + i) = stoi( line.substr(pos_str, line.find(",")-pos_str));

                pos_str = line.find(",")+1;

            }
            *(output + 255) = stoi( line.substr(pos_str, line.find(",")-pos_str));    
        }
        imageget.close();
        return 0;
    }else{
        return 1;
    }

    
}

int getimage(string path, int* output, bool is_colored){

    
}

/*if(!is_colored){
        int width;
        int height;
        
        //Bildgroesse bestimmen
        string line;
        ifstream getSize(path);
        if(getSize.is_open){
            int counter = 0;
            while(getline (getSize, line)){
                if(counter>3) {
                    break;
                }
                else if(counter=2){
                    int pos_space = line.find(" ");
                    width = stoi(line.substr(0,(pos_space-1)));
                    height = stoi(line.substr((pos_space + 1), (line.length()-pos_space - 1)));
                }
                counter++;
            }
        }
        else{
            return 1;
        }
        getSize.close();

        //Bild in Array umwandeln

        int unresized[width*height];

        ifstream imageget (path);
        if (imageget.is_open() ) {
            int counter = 0;
            while ( getline (imageget, line)) {
                if(counter>3) {
                    unresized[counter-4] = stoi(line);
                }
                counter++;           
            }
            imageget.close();
            return 0;
        }
        else{
            return 1;
        }
        
        
    }
    else{


    }
    */
