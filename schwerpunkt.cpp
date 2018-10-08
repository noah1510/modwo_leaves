/*
    Author: Tobias Höpp (c)
    Created: 08.10.2018
    Description: Ermittelt Aritmethisches Mittel der Zeilen und Spalten (in abhängigkeit von Pixel ist Blatt oder nicht: 1 oder 0), um Schwerpunkt zu bestimmen  
*/
#include "convert.hpp"
#include <math.h>;

vector <int>  schwerpunkt(vector < vector < int > > image){
    int Sum;
    int rowWeight;
    int colWeight;

//Mittel berechnen
    for (int x = 0; x < image.size();){
        vector<int> row = image[x];
        for(int y = 0; y < row.size();){
            if (i_pixel > 220) break; 
            int i_pixel = row[y];
            Sum++;
            rowWeight += x;
            colWeight += y;
        }
    }
    return vector(round(rowWeight / Sum), round(colWeight / Sum));
}