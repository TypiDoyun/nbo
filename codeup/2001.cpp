#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
    int pasta1, pasta2, pasta3;
    int juice1, juice2;

    cin >> pasta1 >> pasta2 >> pasta3;
    cin >> juice1 >> juice2;

    int pasta = min(pasta1, min(pasta2, pasta3));
    int juice = min(juice1, juice2);
    int sum = pasta + juice;
    double result = sum * 1.1;

    cout << fixed;
    cout.precision(1);
    cout << result;
}