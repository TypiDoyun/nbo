#include <iostream>

using namespace std;

int check(int& change, int unit) {
    int count = 0;

    while (change >= unit) {
        count += 1;
        change -= unit;
    }

    return count;
}

int main(void) {
    int change;
    int count = 0;

    cin >> change;

    count += check(change, 50000);
    count += check(change, 10000);
    count += check(change, 5000);
    count += check(change, 1000);
    count += check(change, 500);
    count += check(change, 100);
    count += check(change, 50);
    count += check(change, 10);

    cout << count;

    return 0;
}