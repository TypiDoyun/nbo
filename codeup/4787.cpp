#include <iostream>
#include <algorithm>
#include <vector>
#include <array>

using namespace std;

int main(void) {
    int villages, weightLimit;
    int amountOfBox;

    cin >> villages >> weightLimit;
    cin >> amountOfBox;

    vector<array<int, 3>> information(amountOfBox);
    vector<int> weightLimits(villages, weightLimit);

    for (int box = 0; box < amountOfBox; box++) {
        int from, to, weight;

        cin >> from >> to >> weight;

        information[box] = { from, to, weight };
    }

    sort(information.begin(), information.end(), [](array<int, 3> a, array<int, 3> b) {
        if (a[1] == b[1]) return a[0] < b[0];
        else return a[1] < b[1];
    });

    for (auto box : information) {
        cout << box.at(0) << " -> " << box.at(1) << " " << box.at(2) << endl;
    }

    int result = 0;

    for (auto box : information) {
        int from = box[0], to = box[1], weight = box[2];
        int move = min(weight, *min_element(weightLimits.begin() + from - 1, weightLimits.begin() + to - 2));

        for (int index = from - 1; index < to - 1; index++) {
            weightLimits[index] -= move;
        }

        result += move;

    }

    cout << result;

}