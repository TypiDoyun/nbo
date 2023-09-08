#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

const int INF = 0x3f3f3f3f;

vector<int> dijkstra(int start, int V, vector<vector<pair<int, int>>> ways) {
    vector<int> dist(V, INF);
    priority_queue<pair<int, int>> openedQueue;
    
    dist[start] = 0;
    openedQueue.push(make_pair(0, start));
 
    while (!openedQueue.empty()) {
        int cost = -openedQueue.top().first;
        int cur = openedQueue.top().second;
        openedQueue.pop();
        for (int i = 0; i < ways[cur].size(); i++) {
            int next = ways[cur][i].first;
            int nCost = cost + ways[cur][i].second;
            if (nCost < dist[next] ) { 
                dist[next] = nCost; 
                openedQueue.push(make_pair(-nCost, next)); 
            }
        }
    }
    return dist;
}

int main(void) {
    int numberOfBases, numberOfWays;

    cin >> numberOfBases >> numberOfWays;

    vector<vector<pair<int, int>>> ways(numberOfBases);

    for (int i = 0; i < numberOfWays; i++) {
        int cost;
        char from, to;

        cin >> from >> to >> cost;

        from -= 65;
        to -= 65;

        ways[from].push_back(make_pair(to, cost));
        ways[to].push_back(make_pair(from, cost));
    }

    char from, to;

    cin >> from >> to;

    from -= 65;
    to -= 65;

    vector<int> distances = dijkstra(from, numberOfBases, ways);

    bool condition = distances[to] == INF;

    cout << (condition ? -1 : distances[to]);
}