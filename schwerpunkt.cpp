/*
    Author: Tobias Höpp (c)
    Created: 08.10.2018
    Description: Ermittelt Aritmethisches Mittel der Zeilen und Spalten (in abhängigkeit von Pixel ist Blatt oder nicht: 1 oder 0), um Schwerpunkt zu bestimmen  
*/
#include "schwerpunkt.hpp"
#include <math.h>

 int*  schwerpunkt(int* arr_img,int groesse){
    int Sum = 0;
    int rowWeight = 0;
    int colWeight = 0;

     //Mittel berechnen
     int x = 0;
     for(int i = 0;i < groesse * groesse;i++){
         for (int y = 0; y < groesse; y++){
             int i_pixel = *(arr_img+i);
             if (i_pixel > 220) break;
             Sum++;
             rowWeight += x;
             colWeight += y;
             i++;
         }
         x++;
    }
     static int point [2];
     
     point[0] = round(rowWeight / Sum);
     point[1] = round(rowWeight / Sum);
     
     return point;
}
