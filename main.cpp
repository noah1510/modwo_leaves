//#include "stdafx.h"
#include "convert.cpp"
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int main() {
	//std::vector< std::vector<int> > img =  convertImage("test");
	int* p = convimg("Hi");
	for (int i = 0; i<BILDGROESSE*BILDGROESSE;i++){
		cout << *(p+i) << ", " ;
	}
	cout << "Hello World!!" << endl;
	return 0;
} 