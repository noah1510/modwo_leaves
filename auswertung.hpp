#include <iostream>
#include <fstream>
#include <string>

#include "convert.hpp"
//#include "convert.cpp"
#include "schwerpunkt.hpp"
//#include "schwerpunkt.cpp"
#include "vektoren.hpp"
//#include "vektoren.cpp"
#include "symmetry.hpp"
//#include "symmetry.cpp"
//#include "commonFunctions.cpp"
#include "commonFunctions.hpp"

using namespace std;

int auswertung(int anzahlvecs, int bildgroesse, float lernrate, string path, int anzahl_blattsorten, int* pgm, float* sims, float* vecs, float* abl, float* bernd, float* bernd_sims, int bildmenge, bool test);

inline double sigmoid(double x);

inline double sigmoid(float x);

inline double inv_sig(double x);