#include "edx-io.hpp"
#include <string>

int main() {
    int n;
    io >> n;
    int* scores = new int[n];
    for(int i = 0; i < n; i++){
        io >> scores[i];
    }

    for(int i = 0; i < n - 1; i++){
        int minIndex = i;
        for(int j = i + 1; j < n; j++){
            if (scores[j] < scores[minIndex]){
                minIndex = j;
            }
        }
        if (minIndex != i){
            int tmp = scores[i];
            scores[i] = scores[minIndex];
            scores[minIndex] = tmp;
            std :: string str = "Swap elements at indices " + std::to_string(i + 1)  + 
            " and " + std::to_string(minIndex + 1)  + ".\n";
            io << str;
        }
    }
    io << "No more swaps needed.\n";
    for(int i = 0; i < n; i++){
        io << scores[i] << ' ';
    }
    return 0;
}