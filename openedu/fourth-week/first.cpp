#include <iostream>
#include <string>

using namespace std;

#include "edx-io.hpp"
#define cin io
#define cout io


int main() {
    char operation;
    int* stack = new int[1000000];
    int pointer = -1;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> operation;
        if (operation == '-') {
            cout << stack[pointer] << '\n';
            pointer--;
        }
        else {
            pointer++;
            cin >> stack[pointer];
        }
    }

    return 0;
}