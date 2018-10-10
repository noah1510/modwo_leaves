#include <iostream>
#include <fstream>
#include <string>

#include "magick/Magick++.h"

using namespace std;

//const int BILDGROESSE = 256;

int convgrayscale (string path, int* output);

int convcsv (string path, int* output);

int getimage(string path, int* output, bool is_colored);