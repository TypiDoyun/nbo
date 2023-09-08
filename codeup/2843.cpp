#include <iostream>
#include <cmath>

using namespace std;

#define RADIUS 1000

int main(void) {
    int numberOfPoints;
    int numberOfInnerPoints = 0;

    cin >> numberOfPoints;

    for (int i = 0; i < numberOfPoints; i++) {
        int x, y;

        cin >> x >> y;

        if (sqrt(x * x + y * y) > 1000) continue;

        numberOfInnerPoints++;
    }

    cout << fixed;
    cout.precision(6);
    cout << 4 * (double)numberOfInnerPoints / numberOfPoints;
}