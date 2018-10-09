#include "symmetry.hpp"

using namespace std;

int checkSymmetry(int anzahlvektoren, float* abweichung, int* achse, float* vecs){

    int pos_min;
    float abw_min = 0;
    bool isFirst = true;
    for(int i = 0; i < (anzahlvektoren/2); i++){
        float abw_sum = 0;
        for(int j = 0; j < (anzahlvektoren/2); j++){
            abw_sum += pow((*(vecs+(i+j)%400)-*(vecs+(i+400-j)%400)), 16);
        }
        if(abw_sum < abw_min ){
            abw_min = abw_sum;
            pos_min = i;
        }
        else if(isFirst){
            abw_min = abw_sum;
            pos_min = i;
            isFirst = false;
        }
        cout << i << " " << abw_sum <<endl;
    }
    *(achse) = pos_min;
    *(abweichung) = abw_min;
    return 0;
}

/*float sum = 0;
    for(int i=0;i<(anzahlvektoren/2);i++){
        sum += *(vecs+i);
    }

    float min_abweichung = sum-(anzahlvektoren/2);
    int vec_sym = 0;

    for(int i=0;i<(anzahlvektoren/2);i++){
        sum = sum - *(vecs+i) + *(vecs+i+(anzahlvektoren/2));
        if( abs(sum-(anzahlvektoren/2)) < abs(min_abweichung)){
            vec_sym = i;
            min_abweichung = sum - (anzahlvektoren/2);
        }
        
    }
    *(achse) = vec_sym;
    *(abweichung) = min_abweichung;
    cout << vec_sym << " " << min_abweichung << endl;
    return 0;
*/
