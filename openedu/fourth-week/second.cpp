#include <iostream>
#include <string>

using namespace std;

#include "edx-io.hpp"
#define cin io
#define cout io

int main() {
    char operation;
    int* queue = new int[1000000];
    int pointerEnd = -1;
    int pointerStart = 0;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> operation;
        if (operation == '-') {
            cout << queue[pointerStart] << '\n';
            pointerStart++;
        }
        else {
            pointerEnd++;
            cin >> queue[pointerEnd];
        }
    }

    return 0;
}