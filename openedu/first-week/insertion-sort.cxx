#include "edx-io.hpp"
#include <string>

int main() {

    int n;
    io >> n;
    int* array = new int[n];

    for(int i = 0; i < n; i++){
        
        int newElem;
        io >> newElem;
        int j = 0;
        bool isInserted = false;
        
        while (!isInserted && j < i){
            if (array[j] > newElem ){
                isInserted = true;
                for(int k = i; k > j; k--){
                    array[k] = array[k-1];
                }
                array[j] = newElem;
                io << j + 1 << ' ';
            } else {
                j++;
            }
        }

        if (!isInserted){
            array[i] = newElem;
            io << i + 1 << ' ';
        }
    }
    io << "\n";
    for(int i = 0; i < n; i++)
    {
        io << array[i] << ' ';
    }
    
    return 0;
}