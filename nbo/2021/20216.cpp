#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

bool check(int targetQuest, int currentQuest, vector<vector<int>>& links) {
    bool exist = false;

    for (int requirement : links[currentQuest]) {

        // cout << requirement << ", " << targetQuest << ", " << currentQuest << endl;
        if (requirement == targetQuest) {
            exist = true;
            return exist;
        } else exist = exist || check(targetQuest, requirement, links);
    }

    return exist;
}

int main(void) {
    int amountOfQuest, targetQuest;
    stack<int> order;

    cin >> amountOfQuest >> targetQuest;

    vector<vector<int>> links(amountOfQuest);
    vector<int> timeTakens(amountOfQuest);
    vector<bool> visited(amountOfQuest, false);

    for (int index = 0; index < amountOfQuest; index++) {
        cin >> timeTakens[index];

        int need;

        cin >> need;

        while (need != -1) {
            links[index].push_back(need - 1);

            cin >> need;
        }
    }

    for (vector<int> requirements : links) {
        sort(requirements.begin(), requirements.end(), [=](int a, int b) {
            return timeTakens[a] > timeTakens[b];
        });
    }

    for (int )
}