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

int* vektoren(int* arr_img, int* point, int bildgroesse, int anzahlvektoren){
    //alle Vektoren erstellen
    static int* laengen;
    for (int i = 0; i<anzahlvektoren; i++){
        float vecA = sin(360/anzahlvektoren*i)*WURZEL2;
        float vecB = cos(360/anzahlvektoren*i)*WURZEL2;
        for(int j = 0; true; j++){
            int pixNum = round(vecB * j) + *(point + 1) * bildgroesse + round(vecA * j) + *(point);
            if(*(arr_img+pixNum)){
                *(laengen + i) = j;
                break;
            }else if (j > bildgroesse){
                *(laengen + i) = 0;
            }
        }
    }
    return laengen;
}
