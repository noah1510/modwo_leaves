//#include "stdafx.h"
#include <iostream>
#include <math.h>

#include "convert.hpp"
//#include "convert.cpp"
#include "schwerpunkt.hpp"
//#include "schwerpunkt.cpp"


using namespace std;


const int BILDGROESSE = 256;


int main() {

	//std::vector< std::vector<int> > img =  convertImage("test");
	int* p = convimg("schwarz_links.pgm", BILDGROESSE);
	int* point = schwerpunkt(p, BILDGROESSE);

	cout << "Schwerpunkt x:" << *(point) << " , y:" << *(point+1) << endl;

	return 0;
} 
