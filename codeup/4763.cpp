#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    int amountOfMonkey;

    cin >> amountOfMonkey;

    vector<vector<int>> diagram(amountOfMonkey);

    vector<bool> pinfold1(amountOfMonkey, true);
    vector<bool> pinfold2(amountOfMonkey, false);

    for (int monkey = 0; monkey < amountOfMonkey; monkey++) {
        int amountOfEnmity;

        cin >> amountOfEnmity;

        for (int enmity = 0; enmity < amountOfEnmity; enmity++) {
            int enmityNumber;

            cin >> enmityNumber;

            diagram[monkey].push_back(enmityNumber - 1);
        }
    }

    bool success = false;

    while (true) {
        success = true;
        for (int monkey = 0; monkey < amountOfMonkey; monkey++) {
            if (!pinfold1[monkey]) continue;

            int count = 0;

            for (int enmityNumber : diagram[monkey]) {
                if (pinfold1[enmityNumber]) count++;
            }

            if (count <= 1) continue;

            pinfold1[monkey] = false;
            pinfold2[monkey] = true;
            success = false;
        }
        if (success) break;

        success = true;
        for (int monkey = 0; monkey < amountOfMonkey; monkey++) {
            if (!pinfold2[monkey]) continue;

            int count = 0;

            for (int enmityNumber : diagram[monkey]) {
                if (pinfold2[enmityNumber]) count++;
            }

            if (count <= 1) continue;

            pinfold1[monkey] = true;
            pinfold2[monkey] = false;
            success = false;
        }
        if (success) break;
    }

    for (int monkey = 0; monkey < amountOfMonkey; monkey++) {
        if (pinfold1[monkey]) cout << monkey + 1 << " ";
    }
    cout << endl;
    for (int monkey = 0; monkey < amountOfMonkey; monkey++) {
        if (pinfold2[monkey]) cout << monkey + 1 << " ";
    }
}