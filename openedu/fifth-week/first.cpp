#include <iostream>
#include <string>
using namespace std;
#include "edx-io.hpp"


int main() {
    int n;
    io >> n;
    int* heap = new int[n+1];
    for (int i = 1; i <= n; ++i) {
        io >> heap[i];
    }

    bool isHeap = true;
    for (int i = n; isHeap && i > 1; i--) {
        if (heap[i / 2] > heap[i]){
            isHeap = false;
        }
    }
    io << (isHeap ? "YES" : "NO");
    return 0;
}