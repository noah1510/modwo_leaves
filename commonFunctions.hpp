//
//  commonFunctions.hpp
//  modwo_leaves
//
//  Created by Tobias Höpp on 10.10.18.
//  Copyright © 2018 Tobias Höpp. All rights reserved.
//

#ifndef commonFunctions_hpp
#define commonFunctions_hpp

#include <stdio.h>
#include <math.h>
#endif /* commonFunctions_hpp */
float durchschnitt(float* arr, int laenge);
float standartabweichung(float* arr, int laenge); //ggf. ebenfalls durchschnitt übergeben für bessere performance?
int ableitung(float* arr, int laenge, float* result);
float frequenz(float* arr, int laenge);
