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
     for(int i = 0;i < groesse * groesse;i++){
        int pos_x = i%groesse;
        int pos_y = i/groesse;
        int i_pixel = *(arr_img+i);

         if(i_pixel < 220){
            Sum++;
            rowWeight += pos_x;
            colWeight += pos_y;

         }else{
         }
         
    }
     static int point [2];
     
     point[0] = round(rowWeight / Sum);
     point[1] = round(colWeight / Sum);
     
     return point;
}
