/**
 * https://www.acmicpc.net/problem/2606
*/

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

queue<int> virusQueue;
vector<int> hackedComputer;

int main(void) {
    int amountOfComputer, amountOfNetworkConnection;
    int totalHackedComputer = -1; // 1번 컴퓨터는 해킹으로 취급하지 않으므로 -1로 초기화

    cin >> amountOfComputer >> amountOfNetworkConnection;

    vector<vector<int>> network(amountOfComputer, vector<int>());

    for (int index = 0; index < amountOfNetworkConnection; index++) {
        int computerA, computerB;

        cin >> computerA >> computerB;

        network[computerA - 1].push_back(computerB - 1);
        network[computerB - 1].push_back(computerA - 1);
    }

    virusQueue.push(0);

    while (!virusQueue.empty()) {
        int currentComputer = virusQueue.front();
        virusQueue.pop();

        bool alreadyHacked = find(
            hackedComputer.begin(),
            hackedComputer.end(),
            currentComputer
        ) != hackedComputer.end();

        if (alreadyHacked) continue;

        totalHackedComputer++;
        hackedComputer.push_back(currentComputer);

        for (int nearbyComputer : network[currentComputer])
            virusQueue.push(nearbyComputer);
    }

    printf("%d", totalHackedComputer);
}