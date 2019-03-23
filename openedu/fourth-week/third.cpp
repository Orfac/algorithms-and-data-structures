#include <iostream>
#include <string>

using namespace std;

#define LRB '('
#define RRB ')'
#define LSB '['
#define RSB ']'

int main() {
    char * stack = new char[1000000];
    int pointer = -1;
    int n;
    cin >> n;

    string sequence;
    for (int i = 0; i < n; i++) {
        cin >> sequence;
        bool isWrong = false;
        pointer = -1;
        for (int j = 0; j < sequence.length() && !isWrong; ++j) {
            if (sequence[j] == LSB || sequence[j] == LRB){
                pointer++;
                stack[pointer] = sequence[j];
            } else {
                if (pointer == -1){
                    isWrong = true;
                }
                else {
                    if (sequence[j] == RRB){
                        stack[pointer] == LRB ? (pointer--) : isWrong = true;
                    } else{
                        stack[pointer] == LSB ? (pointer--) : isWrong = true;
                    }
                }

            }
        }
        isWrong = isWrong || pointer > -1;
        cout << (isWrong ? "NO\n" : "YES\n");
    }

    return 0;
}