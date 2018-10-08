//#include "stdafx.h"
#include <iostream>
#include <math.h>

#include "convert.hpp"
#include "convert.cpp"
#include "schwerpunkt.hpp"
#include "schwerpunkt.cpp"


using namespace std;


const int BILDGROESSE = 256;


int main() {

	//std::vector< std::vector<int> > img =  convertImage("test");
	int* p = convimg("sample.pgm", BILDGROESSE);
	int* point = schwerpunkt(p, BILDGROESSE);

	cout << "Schwerpunkt x:" << *(p) << " , y:" << *(p+1) << endl;

	return 0;
} 