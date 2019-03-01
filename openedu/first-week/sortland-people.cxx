#include "edx-io.hpp"
#include <string>

int main() {

    int n;
    io >> n;
    double* scores = new double[n];
    int* scoresIndexes = new int[n];
    for(int i = 0; i < n; i++){
        
        double newElem;
        io >> newElem;
        int j = 0;
        scores[i] = newElem;
        scoresIndexes[i] = i;
        bool isInserted = false;
        
        while (!isInserted && j < i){
            if (scores[j] > newElem ){
                for(int k = i; k > j; k--){
                    scores[k] = scores[k-1];
                    scoresIndexes[k] = scoresIndexes[k-1];
                }
                scoresIndexes[j] = i;
                scores[j] = newElem;
                isInserted = true;
            } else {
                j++;
            }
        }
    }
    
    io << scoresIndexes[0] + 1 
    << ' ' 
    << scoresIndexes[n / 2] + 1
    << ' ' 
    << scoresIndexes[n -1] + 1;
    
    return 0;
}