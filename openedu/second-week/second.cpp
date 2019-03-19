#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;


int main() {

    ifstream in;
    in.open("input.txt");
    int n;
    in >> n;
    int m;
    in >> m;
    int k;
    in >> k;

    auto ** matrix = new char*[m];
    auto ** tmpMatrix = new char*[m];
    for (int i = 0; i < m; ++i) {
        matrix[i] = new char[n];
        tmpMatrix[i] = new char[n];
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            in >> matrix[i][j];
            tmpMatrix[i][j] = matrix[i][j];
        }
    }
    in.close();


    int* c = new int[123];

    int* indexes = new int[n];
    int* tmpIndexes = new int[n];
    for (int i = 0; i < n; ++i) {
        indexes[i] = i;
        tmpIndexes[i] = i;
    }

    for (int i = 0; i < k; ++i) {

        for (char j = 97; j < 123; ++j) {
            c[j] = 0;
        }

        for (int j = 0; j < n; ++j) {
            c[matrix[m-i-1][j]]++;
        }

        for (int j = 98; j < 123; ++j) {
            c[j] += c[j-1];
        }

        for (int j = n-1; j >= 0; j--){

            int indexReplace = c[matrix[m-i-1][j]] - 1;

            c[matrix[m-i-1][j]]--;

            for (int i2 = 0; i2 < m; ++i2) {
                tmpMatrix[i2][indexReplace] = matrix[i2][j];
            }

            tmpIndexes[indexReplace] = indexes[j];

        }

        for (int i2 = 0; i2 < m; ++i2) {
            for (int j2 = 0; j2 < n; ++j2) {
                matrix[i2][j2] = tmpMatrix[i2][j2];
            }
        }

        for (int i2 = 0; i2 < n; ++i2) {
            indexes[i2] = tmpIndexes[i2];
        }

    }

    ofstream out;
    out.open ("output.txt");
    for (int i = 0; i < n; ++i) {
        out << indexes[i] + 1 << ' ';
    }
    out.close();

    return 0;
}
