//
//  vektoren.cpp
//  modwo_leaves
//
//  Created by Tobias Höpp on 09.10.18.
//  Copyright © 2018 Tobias Höpp. All rights reserved.
//

#include "vektoren.hpp"
#include <math.h>

const float WURZEL2 = sqrt(2);

int vektoren(float* laengen, int* arr_img, int* point, int bildgroesse, int anzahlvektoren){
    //alle Vektoren erstellen
    
    for (int i = 0; i<anzahlvektoren; i++){
        float vecA = sin(360/anzahlvektoren*i)*WURZEL2;
        float vecB = cos(360/anzahlvektoren*i)*WURZEL2;
        for(int j = 0; true; j++){
            int pos_x = round(vecB * j + *(point + 1));
            int pos_y = round(vecA * j) + *(point);

            int delta_x;
            int delta_y;

            delta_x = abs(pos_x - *(point));
            delta_y = abs(pos_y - *(point + 1));

            float dist = sqrt( (delta_x * delta_x) + (delta_y * delta_y) );
 

            if(pos_x > bildgroesse || pos_x < 0){
                *(laengen + i) = dist; 
                cout << "i:" << i << ", dist:" << *(laengen + i) << ", j:" << j << endl;
                break;
            }

            if(pos_y > bildgroesse || pos_y < 0){ 
                *(laengen + i) = dist;
                cout << "i:" << i << ", dist:" << *(laengen + i) << ", j:" << j << endl;
                break;
            }

            int pixNum = pos_x  * bildgroesse + pos_y;
            if(*(arr_img+pixNum) > 220){
                *(laengen + i) = dist;
                cout << "i:" << i << ", dist:" << *(laengen + i) << ", j:" << j << endl;
                break;
            }
            
            
        }
        
        
    }
    return 0;
}
