#include <iostream>
#include <array>

struct Case {
    int price;
    int volume;
};

using namespace std;

int main(void) {
    int amount;

    Case case1;
    Case case2;

    cin >> amount;

    cin >> case1.price >> case1.volume;
    cin >> case2.price >> case2.volume;

    array<int, 2> purchased = { 0, 0 };

    double caseRatio1 = case1.volume / (double)case1.price;
    double caseRatio2 = case2.volume / (double)case2.price;

    cout << caseRatio1 << ", " << caseRatio2 << endl;

    bool isFull = true;

    while (amount > 0) {
        int remain1 = amount % case1.volume;
        int remain2 = amount % case2.volume;
        if (caseRatio1 > caseRatio2) {
            if (remain1 == 0) {
                purchased[0]++;
                amount -= case1.volume;
            } else if (remain2 == 0) {
                purchased[1]++;
                amount -= case2.volume;
            } else {
                isFull = false;
                break;
            }
        } else {
            if (remain2 == 0) {
                purchased[1]++;
                amount -= case2.volume;
            } else if (remain1 == 0) {
                purchased[0]++;
                amount -= case1.volume;
            } else {
                isFull = false;
                break;
            }
        }
    }

    if (!isFull) cout << "Not Full";
    else cout << purchased[0] << " " << purchased[1];
}