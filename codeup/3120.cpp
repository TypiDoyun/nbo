#include <iostream>

using namespace std;

int main(void) {
    int current, target;

    cin >> current >> target;

    int gap = abs(target - current);
    int count = 0;

    while (gap >= 10) {
        count += 1;
        gap -= 10;
    }

    if (gap == 9) count += 2;
    if (gap == 8) count += 3;
    if (gap == 7) count += 3;
    if (gap == 6) count += 2;
    if (gap == 5) count += 1;
    if (gap == 4) count += 2;
    if (gap == 3) count += 3;
    if (gap == 2) count += 2;
    if (gap == 1) count += 1;

    cout << count;
}