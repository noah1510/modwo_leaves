//#include "stdafx.h"
#include "convert.cpp"
#include <iostream>
#include <math.h>
#include "convert.hpp"
#include "schwerpunkt.hpp"
#include <vector>
using namespace std;

vector<int> v_int(1,0);

vector< vector<int> > fog (1,v_int);

int main() {

	//std::vector< std::vector<int> > img =  convertImage("test");
	int* p = convimg("sample.pgm");
	for (int i = 0; i<BILDGROESSE*BILDGROESSE;i++){
		cout << *(p+i) << ", " ;
	}
	cout << "Hello World!!" << endl;

	return 0;
} 