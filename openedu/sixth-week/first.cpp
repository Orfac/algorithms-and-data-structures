#include <iostream>
#include <string>

using namespace std;


int binSearch(const int *arr, int n, int value){
    int l = -1;
    int r = n;
    while ( r > l + 1){
        int m = (l + r) / 2;
        if (arr[m] < value) {
            l = m;
        } else {
            r = m;
        }
    }
    if (r < n and arr[r] == value){
        return r;
    } else {
        return -1;
    }
}


int searchMax(int *arr, int n, int value, int leftIndex){
    int l = leftIndex;
    int r = n;
    while ( r > l + 1){
        int m = (l + r) / 2;
        if (arr[m] == value){
            l = m;
        } else {
            r = m;
        }
    }
    return l;
}

int main() {
    int n;
    cin >> n;
    int* arr = new int[n+1];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int requestCount;
    cin >> requestCount;
    for (int i = 0; i < requestCount; ++i) {
        int value;
        cin >> value;
        int indexMin = binSearch(arr, n, value);
        if (indexMin == -1){
            cout << indexMin << ' ' << indexMin << '\n';
        } else {
            int indexMax = searchMax(arr, n, value, indexMin);
            cout << indexMin + 1 << ' ' << indexMax + 1 << '\n';
        }
    }
    return 0;
}
