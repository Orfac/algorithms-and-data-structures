#include <string>

using namespace std;

int main() {
    FILE *in;
    in = fopen("input.txt","r");
    int n;
    fscanf(in,"%i",&n);

    auto *garland = new double[n];

    fscanf(in,"%lf",&(garland[0]));
    fclose(in);
    const double precision = 1e-10;

    double lowestEdge = 0;
    double highestEdge = garland[0];

    while (highestEdge - lowestEdge > precision){
        garland[1] = (lowestEdge + highestEdge) / 2;

        int i = 2;
        do{
            double value =  2 * garland[i-1] - garland[i-2] + 2;
            garland[i] = value;
            i++;
        } while (garland[i - 1] >= precision && i < n);

        if (i == n && garland[i-1] >= 0){
            highestEdge = garland[1];
        } else {
            lowestEdge = garland[1];
        }
    }

    FILE *out;
    out = fopen("output.txt","w");
    fprintf(out,"%lf", garland[n-1]);
    fclose(out);
    return 0;
}

