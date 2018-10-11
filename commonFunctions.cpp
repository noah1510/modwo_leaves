//
//  commonFunctions.cpp
//  modwo_leaves
//
//  Created by Tobias Höpp on 10.10.18.
//  Copyright © 2018 Tobias Höpp. All rights reserved.
//

#include "commonFunctions.hpp"
#include <math.h>
#include <iostream>

using namespace std;

float durchschnitt(float* arr, int laenge){
    float sum = 0;
    for(int i=0; i < laenge; i++){
        sum += *(arr+i);
    }
    return (float(sum) / float(laenge));
}

float standartabweichung(float* arr, int laenge){
    float av = durchschnitt(arr, laenge);
    float sum = 0;
    for(int i=0; i< laenge; i++){
        sum += pow((*(arr+i) - av),2);
    }
    return (float(sum) / float(laenge));
}

int ableitung(float* arr, int laenge, float* result){
    float lastvalue = *(arr+laenge-1);

    for(int i = 0; i < laenge; i++){
        *(result+i) = *(arr+i) - *(arr+(i+1)%laenge);
    }
    return 0;
}

float bfrequenz(float* arr, int laenge){
    int anzahlWechsel = 0;
    float abl[laenge];
    ableitung(arr, laenge, abl);
    bool lastVZ;
    if(abl[laenge-1] < 0){
        lastVZ = false;
    }else{
        lastVZ = true;
    }
    for(int i=0; i<laenge; i++){
        if(abl[i] < 0){
            if(lastVZ) anzahlWechsel++;
            lastVZ = false;
        }else{
            if(!lastVZ) anzahlWechsel++;
            lastVZ = true;
        }
    }
    cout << anzahlWechsel << ";" << laenge << endl;
    return (float(anzahlWechsel) / float(laenge));
}

