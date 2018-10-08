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
	string filename;
	static int pgm [BILDGROESSE*BILDGROESSE];

	int err = 0;
	do{
		cout << "Geben sie den Dateinamen ein." << endl;

		cin >> filename;
	
		err = convimg(filename+".pgm", pgm);
		if(err != 0){
			cout << "Datei nicht vorhanden!" << endl;
		}
	}while(err != 0);

	int* point = schwerpunkt(pgm, BILDGROESSE);

	cout << "Schwerpunkt x:" << *(point) << " , y:" << *(point+1) << endl;

	return 0;
} 
