//#include "stdafx.h"
#include <iostream>
#include <math.h>

#include "convert.hpp"
#include "convert.cpp"
#include "schwerpunkt.hpp"
#include "schwerpunkt.cpp"
#include "vektoren.hpp"
#include "vektoren.cpp"
#include "symmetry.hpp"
#include "symmetry.cpp"
#include "auswertung.hpp"
#include "auswertung.cpp"
#include "commonFunctions.hpp"
#include "commonFunctions.cpp"

using namespace std;


const int BILDGROESSE = 256;
const int ANZAHLVECS = 400;
const int BLATTSORTEN = 4;
const float LERNINGRATE = 0.5f;
const int BILDMENGE = 15;


int main() {

    int mode = 0;
    string filename;
    static int pgm [BILDGROESSE*BILDGROESSE];
    static float sims [ANZAHLVECS/2];
    int* point;
    static float vecs [ANZAHLVECS];
    float abw;
    static int sym;
    float rund;
    static float abl [ANZAHLVECS];
    static float bernd[ANZAHLVECS];
    static float bernd_sims[ANZAHLVECS/2];

    int err = 0;
    do{
    //std::vector< std::vector<int> > img =  convertImage("test");
        cout << "Waehlen Sie Ihren Modus" << endl;
        cout << "0 - programm beenden" << endl;
        cout << "1 - grayscale (.pgm)" << endl;
        cout << "2 - farbbild (.png)" << endl;
        cout << "3 - training" << endl;

        cin >> mode;

        switch(mode){
            //Beenden
            case(0):
                cout << "Programm wird beendet" << endl;
                break;

            //Grayscale
            case(1):        

                do{
                    cout << "Geben Sie den Dateinamen ein." << endl;

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

                

                cout << checkSymmetry(ANZAHLVECS, &abw, &sym, vecs, &rund, sims) << endl;

                cout << "Abw: " << abw << ", Achse: " << sym << ", Ruendlichkeit: " << rund << endl;

                for(int i = 0; i < ANZAHLVECS; i++){
                    cout << *(vecs + i) << ", ";
                }
                cout << endl;

                
                break;

            // Farbbild
            case(2):
                do{
                    cout << "Geben Sie den Dateinamen ein." << endl;

                    cin >> filename;
    
                    err = convcsv(filename+".csv", pgm);
                    if(err != 0){
                        cout << "Datei nicht vorhanden!" << endl;
                    }
                }while(err != 0);

                point = schwerpunkt(pgm, BILDGROESSE);

                cout << "\nSchwerpunkt x:" << *(point) << " , y:" << *(point+1) << "\n" << endl;
                
                cout << vektoren(vecs,pgm,point,BILDGROESSE,ANZAHLVECS) << endl;

                
                cout << normVecs(vecs, ANZAHLVECS) << endl;

                

                cout << checkSymmetry(ANZAHLVECS, &abw, &sym, vecs, &rund, sims) << endl;

                cout << "Abw: " << abw << ", Achse: " << sym << ", Ruendlichkeit: " << rund << endl <<endl;
                
                for(int i = 0; i < ANZAHLVECS; i++){
                    cout << *(vecs + i) << ", ";
                }
                cout << endl;
                
                break;

            //training
            case(3):
				err = auswertung(ANZAHLVECS,BILDGROESSE,LERNINGRATE,"trainingData",BLATTSORTEN, pgm, sims, vecs, abl, bernd, bernd_sims, BILDMENGE, true);
                if(err != 0){
                    cout << "Fehler!" << endl;
                };
                break;

            //ungültige fälle
            default:
                cout << "falsche Eingabe!" << endl;
                break;
        }

    }while(mode != 0);

    return 0;
} 
