#include <iostream>
#include <cmath>

using namespace std;

long unsigned factorial(long unsigned x) {
    if (x == 0) return 1;
    else return x * factorial(x - 1);
}

long unsigned combination(long unsigned n, long unsigned m) {
    return factorial(n) / (factorial(n - m) * factorial(m));
}

long unsigned dp[20] = { 0 };

int main(void) {
    for (int index = 1; index < 20; index++) {
        int level = index + 1;
        long unsigned result = 0;
        for (int length = 1; length <= index; length++) {
            result += dp[index - length] * combination(level, level - length);
        }
        result += 1;

        dp[index] = factorial(level) - result;
    }

    int N;

    cin >> N;

    if (N < 1 || N > 20) cout << "오류";
    else cout << dp[N - 1];
}