//
//  abgleich.cpp
//  modwo_leaves
//
//  Created by Tobias Höpp on 10.10.18.
//  Copyright © 2018 Tobias Höpp. All rights reserved.
//

#include "abgleich.hpp"
#include "commonFunctions.hpp"
using namespace std;

int abweichung(float* laengen, float* laengen_example, int anzahlvektoren, int achse){
    float diffs [anzahlvektoren];
    for (int i = 0; i < anzahlvektoren; i++){
        diffs[i] = laengen_example - laengen_example;
    }
    float average = durchschnitt(diffs, anzahlvektoren);
    float standartabw = standartabweichung(diffs, anzahlvektoren);
    return 0;
}

