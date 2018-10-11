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

int auswertung(int anzahlvecs, int bildgroesse, float lernrate, string path, int anzahl_blattsorten);

inline double sigmoid(double x);

inline double sigmoid(float x);