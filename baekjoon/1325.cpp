#include <cstdio>
#include <algorithm>
#include <vector>
#include <array>

using namespace std;

int dfs(int computer, vector<vector<int>>& connections, vector<bool>& visitedComputer) {
    visitedComputer[computer] = true;

    int numberOfConnections = 1;

    for (int connection : connections[computer]) {
        if (visitedComputer[connection] == true) continue;

        numberOfConnections += dfs(connection, connections, visitedComputer);
    }

    return numberOfConnections;
}

int main(void) {
    int numberOfComputers, numberOfConnections;

    scanf("%d %d", &numberOfComputers, &numberOfConnections);

    vector<vector<int>> connections(numberOfComputers);
    vector<bool> visitedComputer(numberOfComputers, false);

    for (int i = 0; i < numberOfConnections; i++) {
        int computerA, computerB;

        scanf("%d %d", &computerA, &computerB);

        computerA--;
        computerB--;

        connections[computerB].push_back(computerA);
    }

    vector<int> hackedMap(numberOfComputers);

    for (int i = 0; i < numberOfComputers; i++) {
        fill(visitedComputer.begin(), visitedComputer.end(), false);
        hackedMap[i] = dfs(i, connections, visitedComputer);
    }

    int maxHacked = *max_element(hackedMap.begin(), hackedMap.end());

    for (int i = 0; i < numberOfComputers; i++) {
        if (hackedMap[i] == maxHacked) printf("%d ", i + 1);
    }
}