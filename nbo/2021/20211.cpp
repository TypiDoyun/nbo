#include <iostream>
#include <algorithm>

using namespace std;

int getTax(int money) {
    int tax = 0;

    tax += min(money, 12000000) * 0.06;
    tax += min(max(money - 12000000, 0), 46000000 - 12000000) * 0.15;
    tax += min(max(money - 46000000, 0), 88000000 - 46000000) * 0.24;
    tax += min(max(money - 88000000, 0), 150000000 - 88000000) * 0.35;
    tax += min(max(money - 150000000, 0), 300000000 - 150000000) * 0.38;
    tax += min(max(money - 300000000, 0), 500000000 - 300000000) * 0.40;
    tax += max(money - 500000000, 0) * 0.42;

    return tax;
}

int main(void) {
    int a, b, c;

    cin >> a >> b >> c;

    int money = a - b;
    int tax = getTax(money);

    cout << tax - c;
}