#include "auswertung.hpp"

using namespace std;

int auswertung(int anzahlvecs, int bildgroesse, float lernrate, string path, int anzahl_blattsorten){

    //variable init
    float matrix[(int)(2.5*anzahlvecs)+3][anzahl_blattsorten];
    bool inited = false;
    float input[(int)(2.5*anzahlvecs)+3];
    float output[anzahl_blattsorten];

    //read or create matrix.leaves
    string line;
    ifstream csvGet (path + "/matrix.leaves");
    if (csvGet.is_open() ) {
        int counter = 0;
        while ( getline (csvGet, line)) {
            if(counter != 0 && inited){

                int pos_str = 0;
                for(int i = 0; i < (int)(2.5*anzahlvecs)+2; i++){

                    matrix[i][counter] = stof( line.substr(pos_str, line.find(",")-pos_str));

                    pos_str = line.find(",")+1;

                }
                matrix[(int)(2.5*anzahlvecs)+2][counter] = stof( line.substr(pos_str, line.find(",")-pos_str));
                counter++;   
            }else{
                
                int x,y;

                cout << line.find(",")<<endl;
                x = stoi(line.substr(0,line.find(",",0)-1));
                y = stoi(line.substr(line.find(","),line.find(" ")-line.find(",")));

                if(x == (int)(2.5*anzahlvecs)+3 && y == anzahl_blattsorten){
                    inited = true;
                    cout << "format is right!" << endl;
                    break;
                }else{
                    cout << "wrong format!" << endl;
                }
                
            }
        }
        csvGet.close();
    }else{
        cout << "file not found" << endl;
    }

    if (!inited){
        for(int j = 0; j < anzahl_blattsorten;j++){
            for(int i = 0; i < (int)(2.5*anzahlvecs)+3;i++){
                matrix[i][j] = 0.25;
            }
        }
    }


    //output in matrix.leaves
    string out;
    ofstream csvWrite (path + "/matrix.leaves");
    out += (int)(2.5*anzahlvecs)+3;
    out += "," + anzahl_blattsorten;
    out += " \n";
    for(int i=0; i>anzahl_blattsorten; i++){
        for(int j=0; j>(int)(2.5*anzahlvecs)+2; j++){
            out += matrix[i][j];
            out += ", ";
        }
        out += matrix[i][(int)(2.5*anzahlvecs)+2];
        out += "\n";
    }
    csvWrite << out;
    csvWrite.close();

    return 0;
}
