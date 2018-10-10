//
//  commonFunctions.cpp
//  modwo_leaves
//
//  Created by Tobias Höpp on 10.10.18.
//  Copyright © 2018 Tobias Höpp. All rights reserved.
//

#include "commonFunctions.hpp"
#include <math.h>

using namespace std;

float durchschnitt(float* arr, int laenge){
    float sum = 0;
    for(int i=0; i < laenge; i++){
        sum += *(arr+i);
    }
    return (sum / laenge);
}

float standartabweichung(float* arr, int laenge){
    float av = durchschnitt(arr, laenge);
    float sum = 0;
    for(int i=0; i<laenge; i++){
        sum += pow((*(arr+i) - av),2);
    }
    return (sum / laenge);
}

int ableitung(float* arr, int laenge, float* result){
    float lastvalue = *(arr+laenge-1);
    float* res = nullptr;
    for(int i = 0; i < laenge; i++){
        res[i] = *(arr+i) - lastvalue;
    }
    result = res;
    return 0;
}

float bfrequenz(float* arr, int laenge){
    int anzahlWechsel = 0;
    bool lastVZ;
    if(*(arr+laenge-1) < 0){
        lastVZ = false;
    }else{
        lastVZ = true;
    }
    for(int i=0; i<laenge; i++){
        if(*(arr+i) < 0){
            if(lastVZ) anzahlWechsel++;
            lastVZ = false;
        }else{
            if(!lastVZ) anzahlWechsel++;
            lastVZ = true;
        }
    }
    return (anzahlWechsel / laenge);
}

