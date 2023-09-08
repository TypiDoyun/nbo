#include <iostream>

using namespace std;

long long power(int n, int k) {
    long long result, powered;

    if (k != 1)
    {
        powered = power(n, k / 2);
        result = (powered * powered) % 1000000007;
        if (k % 2 == 1) result *= n;
    }
    else result = n;
    return result % 1000000007;
}

int main(void) {
    int n, k;

    cin >> n >> k;

    cout << power(n, k);
}