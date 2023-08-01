#include <iostream>

using namespace std;

int main() {
    int principal, interestPeriod, remainingMaturity;
    double interestRate, rateOfReturn, incomeTaxRate = 15.4 / 100.0;

    cin >> principal >> interestRate >> interestPeriod >> remainingMaturity >> rateOfReturn;

    interestRate /= 100.0;
    rateOfReturn /= 100.0;

    int result = floor((floor(principal * interestPeriod * interestRate / 12 * (1 - incomeTaxRate)) * ceil(remainingMaturity / interestPeriod) + principal) / (remainingMaturity * rateOfReturn / 12 + 1));

    cout << result;
}