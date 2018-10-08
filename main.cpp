//#include "stdafx.h"
#include <iostream>
#include <math.h>
#include "convert.hpp"
#include "schwerpunkt.hpp"
#include <vector>
using namespace std;

vector<int> v_int(1,0);

vector< vector<int> > fog (1,v_int);

int main() {
	cout << "Hello World!!" << endl; // prints !!!Hello World!!!
	vector <int> test(2,0);
	test = schwerpunkt(fog);
	return 0;
} 