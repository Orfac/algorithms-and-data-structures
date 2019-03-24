#include <iostream>
#include <string>
#include <deque>

using namespace std;


int main() {
    char operation;
    long* queue = new long[1000000];
    int pointerEnd = -1;
    int pointerStart = 0;
    int n;
    cin >> n;

    deque<long> deque;

    for (int i = 0; i < n; i++) {
        cin >> operation;
        if (operation == '-') {
            if (deque.front() == queue[pointerStart]){
                deque.pop_front();
            }
            pointerStart++;
        } else if (operation == '?'){
            cout << to_string(deque.front()) << '\n';
        } else {
            pointerEnd++;
            cin >> queue[pointerEnd];
            while (!deque.empty() && deque.back() > queue[pointerEnd]) {
                deque.pop_back();
            }
            deque.push_back(queue[pointerEnd]);
        }
    }

    return 0;
}