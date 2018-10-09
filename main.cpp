//#include "stdafx.h"
#include <iostream>
#include <math.h>

#include "convert.hpp"
#include "convert.cpp"
#include "schwerpunkt.hpp"
#include "schwerpunkt.cpp"
#include "vektoren.hpp"
#include "vektoren.cpp"


using namespace std;


const int BILDGROESSE = 256;
const int ANZAHLVECS = 400;


int main() {

	int mode = 0;
	string filename;
	static int pgm [BILDGROESSE*BILDGROESSE];
	int* point;
    static float vecs [ANZAHLVECS];

	int err = 0;
	do{
	//std::vector< std::vector<int> > img =  convertImage("test");
		cout << "Waehlen die ihren modus" << endl;
		cout << "0 - programm beenden" << endl;
		cout << "1 - grayscale (.pgm)" << endl;
		cout << "2 - farbbild (.png)" << endl;
		cout << "3 - testmodus" << endl;

		cin >> mode;

		switch(mode){
			//Beenden
			case(0):
				cout << "Programm wird beendet" << endl;
				break;

			//Greyscale
			case(1):		

				do{
					cout << "Geben sie den Dateinamen ein." << endl;

					cin >> filename;
	
					err = convgrayscale(filename+".pgm", pgm);
					if(err != 0){
						cout << "Datei nicht vorhanden!" << endl;
					}
				}while(err != 0);

				point = schwerpunkt(pgm, BILDGROESSE);

				cout << "\nSchwerpunkt x:" << *(point) << " , y:" << *(point+1) << "\n" << endl;
				
				cout << vektoren(vecs,pgm,point,BILDGROESSE,ANZAHLVECS) << endl;

				
				cout << normVecs(vecs, ANZAHLVECS) << endl;

				for(int i = 0; i < ANZAHLVECS; i++){
					cout << *(vecs + i) << ", ";
				}
				cout << endl;
				
				break;

			// Farbbild
			case(2):
				do{
					cout << "Geben sie den Dateinamen ein." << endl;

					cin >> filename;
	
					err = convgrayscale(filename+".png", pgm);
					if(err != 0){
						cout << "Datei nicht vorhanden!" << endl;
					}
				}while(err != 0);

				point = schwerpunkt(pgm, BILDGROESSE);

				cout << "\nSchwerpunkt x:" << *(point) << " , y:" << *(point+1) << "\n" << endl;

				cout << vektoren(vecs,pgm,point,BILDGROESSE,ANZAHLVECS) << endl;

				for(int i = 0; i < ANZAHLVECS; i++){
					cout << *(vecs + i) << ", ";
				}
				cout << endl;

				break;

			//testmodus
			case(3):
				err = convgrayscale("sample.pgm", pgm);
				point = schwerpunkt(pgm, BILDGROESSE);

				cout << "\nSchwerpunkt x:" << *(point) << " , y:" << *(point+1) << "\n" << endl;
				
				cout << vektoren(vecs,pgm,point,BILDGROESSE,ANZAHLVECS) << endl;

				for(int i = 0; i < ANZAHLVECS; i++){
					cout << *(vecs + i) << ", ";
				}
				cout << endl;
				break;

			//ungültige fälle
			default:
				cout << "falsche Eingabe!" << endl;
				break;
		}

	}while(mode != 0);

	return 0;
} 
