//
//  vektoren.cpp
//  modwo_leaves
//
//  Created by Tobias Höpp on 09.10.18.
//  Copyright © 2018 Tobias Höpp. All rights reserved.
//
#define _USE_MATH_DEFINES

#include "vektoren.hpp"
#include <math.h>

const float WURZEL2 = sqrt(2);

int vektoren(float* laengen, int* arr_img, int* point, int bildgroesse, int anzahlvektoren){
    //alle Vektoren erstellen

    //String für .csv Datei
    string csv = "angle(rad); distance \n";
    
    for (int i = 0; i<anzahlvektoren; i++){
        float vecA = sin(6.28318f/anzahlvektoren*i);
        float vecB = cos(6.28318f/anzahlvektoren*i);
        //cout << "vectorA:" << vecA << ", vectorB:" << vecB << endl;
        
        for(int j = 0; true; j++){
            int pos_x = round(vecA * j + *(point + 1));
            int pos_y = round(vecB * j) + *(point);

            int delta_x = 0;
            int delta_y = 0;

            delta_x = abs(pos_x - *(point));
            delta_y = abs(pos_y - *(point + 1));

            float dist = sqrt( (delta_x * delta_x) + (delta_y * delta_y) );
 

            if(pos_x > bildgroesse || pos_x < 0){
                *(laengen + i) = dist; 
                //cout << "i:" << i << ", dist:" << *(laengen + i) << ", j:" << j << ", dx:" << delta_x << ", dy:" << delta_y << endl;
                break;
            }

            if(pos_y > bildgroesse || pos_y < 0){ 
                *(laengen + i) = dist;
                //cout << "i:" << i << ", dist:" << *(laengen + i) << ", j:" << j << ", dx:" << delta_x << ", dy:" << delta_y << endl;
                break;
            }

            int pixNum = pos_x  * bildgroesse + pos_y;
            if(*(arr_img+pixNum) > 220){
                *(laengen + i) = dist;
                //cout << "i:" << i << ", dist:" << *(laengen + i) << ", j:" << j << ", dx:" << delta_x << ", dy:" << delta_y << endl;
                break;
            }
        }   
        csv = csv + to_string(6.28318f/anzahlvektoren*i) + "; " +  to_string( *(laengen + i)) + "\n";   
        
        
    ofstream csvwriter;
    csvwriter.open ("result.csv");
    csvwriter << csv;
    csvwriter.close();

    }
    return 0;
}
