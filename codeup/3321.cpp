#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main(void) {
    int toppings, doughPrice, toppingPrice, doughKcal;
    int toppingKcal;
    vector<int> toppingKcals;

    cin >> toppings;
    cin >> doughPrice >> toppingPrice;
    cin >> doughKcal;

    for (int index = 0; index < toppings; index++) {
        cin >> toppingKcal;

        toppingKcals.push_back(toppingKcal);
    }

    sort(toppingKcals.begin(), toppingKcals.end(), [](int a, int b) {
        return a > b;
    });

    // toppingKcals.erase(unique(toppingKcals.begin(), toppingKcals.end()), toppingKcals.end());


    double bestPizza = doughKcal / doughPrice;
    int kcal = doughKcal;
    int price = doughPrice;

    for (int cal : toppingKcals) {
        if (bestPizza < (double)(kcal + cal) / (price + toppingPrice)) {
            kcal += cal;
            price += toppingPrice;
            bestPizza = kcal / (double)price;
        } else break;
    }
    cout << fixed;
    cout.precision(0);
    cout << floor(bestPizza);
}