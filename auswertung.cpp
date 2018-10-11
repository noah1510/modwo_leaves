#include "auswertung.hpp"

using namespace std;

int auswertung(int anzahlvecs,int bildgroesse, float lernrate, string path, int anzahl_blattsorten,  int* pgm, float* sims, float* vecs, float* abl, float* bernd, float* bernd_sims, int bildmenge, bool test){

    //variable init
    double matrix[(int)(2.5*anzahlvecs)+3][anzahl_blattsorten];
    bool inited = false;
    

    //read or create matrix.leaves
    string line;
    ifstream csvGet (path + "/matrix.leaves");
    if (csvGet.is_open() ) {
        int counter = 0;
        while ( getline (csvGet, line)) {
            //cout << line << endl;
            if(counter != 0 && inited){

                int pos_str = 0;
                for(int i = 0; i < (int)(2.5*anzahlvecs)+2; i++){

                    matrix[i][counter-1] = stod( line.substr(pos_str, line.find(",")-pos_str));

                    pos_str = int(line.find(","))+1;

                }
                matrix[(int)(2.5*anzahlvecs)+2][counter-1] = stod( line.substr(pos_str, line.find(",")-pos_str));
                counter++;   
            }else{
                
                int x,y;

                //cout << line.find(",")<<endl;
                x = stoi(line.substr(0,line.find(",")));
                //cout << x << endl;
                y = stoi(line.substr(line.find(",")+1,line.length()-line.find(",")));
                //cout << y << endl;

                if(x == (int)(2.5*anzahlvecs)+3 && y == anzahl_blattsorten){
                    inited = true;
                    //cout << "format is right!" << endl;
                    counter++;
                }else{
                    //cout << "wrong format!" << endl;
                    break;
                }
                
            }
        }
        csvGet.close();
    }else{
        //cout << "file not found" << endl;
    }

    if (!inited){
        for(int j = 0; j < anzahl_blattsorten;j++){
            for(int i = 0; i < (int)(2.5*anzahlvecs)+3;i++){
                matrix[i][j] = 0.01;
            }
        }
    }

    int sorten_counter[anzahl_blattsorten];
    for(int i=0; i< anzahl_blattsorten; i++){
        sorten_counter[i] = 0;
    }

    string csv_Out;
    
    
    for(int i=0; i<anzahl_blattsorten*bildmenge; i++){
        int path_random = 0;
        do {

            path_random = (rand() % anzahl_blattsorten);

        }while(sorten_counter[path_random]>= bildmenge);
        
        

        if(true){

            /*
            int pgm [bildgroesse*bildgroesse];
            
            float vecs [anzahlvecs];
            float sims [anzahlvecs/2];
            float abl [anzahlvecs];
            float bernd[anzahlvecs];
            float bernd_sims[anzahlvecs/2];
            */
            int* point;

            static float abw;
            static int sym;
	        static float rund;

            double input[(int)(2.5*anzahlvecs)+3];
            double output[anzahl_blattsorten];
            double fehler[anzahl_blattsorten];

            int err = convcsv((path + "/" + to_string(path_random) + "/" + to_string(sorten_counter[path_random]) + ".csv"), pgm); //error possible here!
		    if(err != 0){
			    cout << "Datei nicht vorhanden!" << endl;
		    }

            cout << path + "/" + to_string(path_random) + "/" + to_string(sorten_counter[path_random]) << endl;

            /*
            for(int j=0; j<256;j++){
                cout << *(pgm+j+10000) << endl;
            }
            */
           //cout << "HI" << endl;

            sorten_counter[path_random] +=1;

            point = schwerpunkt(pgm, bildgroesse);

            //cout << "HI, schwer" << endl;

            vektoren(vecs,pgm,point,bildgroesse,anzahlvecs);

            //cout << "HI, vektor" << endl;

            normVecs(vecs, anzahlvecs);

            //cout << "HI, norm" << endl;

            checkSymmetry(anzahlvecs, &abw, &sym, vecs, &rund, sims);

            //cout << "HI, sims" << endl;

            for(int j = 0; j < 20; j++){
                //cout << *(sims +j) << endl;
            }
            
            //shift sims and vecs
            for(int j=0; j<anzahlvecs; j++){
                *(bernd+j)= *(vecs + (j+sym)%anzahlvecs);
            }
            
            for(int j=0; j<anzahlvecs/2; j++){
                *(bernd_sims + j) = *(sims + (j+sym)%(anzahlvecs/2));
            }

            ableitung(bernd, anzahlvecs, abl);

            cout << "abl: " << *(abl+34) << endl;

            float frequenz = bfrequenz(bernd, anzahlvecs);

            for(int j = 0; j < 20; j++){
                //cout << *(bernd_sims +j) << endl;
                //cout << *(bernd + j) << endl;
            }


            //csv-datei anfügen

            for(int j=0; j<anzahlvecs; j++){
                csv_Out += to_string(*(bernd + j - 1));
                csv_Out += "; ";
            }

            for(int j=0; j<anzahlvecs; j++){
                csv_Out += to_string(*(abl + j));
                csv_Out += "; ";
            }

            for(int j=0; j<anzahlvecs/2; j++){
                csv_Out += to_string(*(bernd_sims + j));
                csv_Out += "; ";
            }

            csv_Out += to_string(frequenz);
            csv_Out += "; ";
            csv_Out += to_string(abw);
            csv_Out += "; ";
            csv_Out += to_string(rund);
            csv_Out += "\n";




            //Werte mit Sigmoid in Input Vector schreiben
            for(int j=0; j<anzahlvecs; j++){
                input[j] = sigmoid(*(bernd + j - 1));
            }

            for(int j=0; j<anzahlvecs; j++){
                input[j + anzahlvecs] = sigmoid(*(abl + j)*100);
            }

            for(int j=0; j<anzahlvecs/2; j++){
                input[j + 2*anzahlvecs] = sigmoid(*(bernd_sims + j));
            }

            //cout << "frequenz: " << sigmoid((frequenz-0.5)) << endl; 

            input[(int)(2.5*anzahlvecs)] = sigmoid((frequenz-0.5));
            input[(int)(2.5*anzahlvecs)+1] = sigmoid(abw*1000);
            input[(int)(2.5*anzahlvecs)+2] = sigmoid(rund);

            for(int j=399;j<800;j++){
                //cout << input[j] << endl;
            }

            //Matrizenmultiplikation
            //cout << "\noutputs" << endl;

            for(int j = 0; j < anzahl_blattsorten;j++){
                for(int k = 0; k < (int)(2.5*anzahlvecs)+3;k++){
                    output[j] += matrix[k][j]* input[k];
                }
                //cout << output[j] << endl;
            }

            //Output sigmoiden
            double bias = 0.5;
            //cout << "\noutputs sigmoid" << endl;

            for(int j=0; j < anzahl_blattsorten; j++){
                output[j] = sigmoid(output[j] - bias);
                //cout << output[j] << endl;
            }

            //Fehlerkalkulation
            //cout << "\nErrors" << endl;

            for(int j = 0; j < anzahl_blattsorten; j++){
                if(path_random == j){
                    fehler[j] = (output[j] - 1);
                }
                else{
                    fehler[j] = (output[j] - 0);
                }
                //cout << fehler[j] << endl;
            }

            

            //backpropagation
            for(int j = 0; j < anzahl_blattsorten;j++){
                for(int k = 0; k < (int)(2.5*anzahlvecs)+3;k++){
                    //matrix[k][j] += lernrate * fehler[j] * output[j] * (1 - output[j]) * input[k];
                    matrix[k][j] -= lernrate * fehler[j] * matrix[k][j] * input[k];
                    //cout << lernrate * fehler[j] * output[j] * (1 - output[j]) * input[k] << endl;

                    if (matrix[k][j] < 0){
                        //cout << "SHIT" << endl;
                    }
                }
            }

            for(int w =0; w<anzahlvecs; w++){
                *(vecs+w) = 0;
            }

            /*
            for(int w =0; w<bildgroesse*bildgroesse; w++){
                *(pgm+w) = 0;
            }
            */

        }

    }


    //cout << "starting output" << endl;

    //output in matrix.leaves
    string out;
    ofstream csvWrite (path + "/matrix.leaves");
    out += to_string((int)(2.5*anzahlvecs)+3);
    out += ", ";
    out += to_string(anzahl_blattsorten);
    out += "\n";
    for(int i=0; i<anzahl_blattsorten; i++){
        for(int j=0; j<(int)(2.5*anzahlvecs)+2; j++){
            out += to_string(matrix[j][i]);
            out += ", ";
        }
        out += to_string(matrix[(int)(2.5*anzahlvecs)+2][i]);
        out += "\n";
    }

    //cout << out << endl;

    csvWrite << out;
    csvWrite.close();

    ofstream csv_Write("data.csv");
    csv_Write << csv_Out;
    csv_Write.close();


    return 0;
}

inline double sigmoid(double x){
    return 1 / (1 + (exp(-x)));
}

inline double sigmoid(float x){
    return (double) 1 / (1 + (exp((double) -x)));
}
