#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

void dps(int node, vector<vector<int>>& connections, vector<bool>& visitedNodes, vector<int>& parents) {
    visitedNodes[node] = true;

    for (int connection : connections[node]) { // queue에서 저장한 노드와 연결된 인접 노드들을 방문한다.
        if (visitedNodes[connection]) continue;
        parents[connection] = node; // 인접 노드 중 방문한 기록이 없는 노드는 부모 노드가 현재 노드이므로 부모 노드 리스트를 업데이트해준다.
        dps(connection, connections, visitedNodes, parents);
    }
}

int main(void) {
    int numberOfNodes;

    scanf("%d", &numberOfNodes);

    vector<vector<int>> connections(numberOfNodes);
    vector<int> parents(numberOfNodes, -1);
    vector<bool> visitedNodes(numberOfNodes, false);

    for (int i = 1; i < numberOfNodes; i++) { // numberOfNodes - 1개의 연결을 받으므로 i는 1부터 시작한다.
        int nodeA, nodeB; // 연결될 노드 2개를 입력받을 변수를 선언한다.

        scanf("%d %d", &nodeA, &nodeB); // 연결을 입력받는다.

        nodeA--; // 연결은 첫번째 노드가 1부터 시작하므로 인덱스처럼 0으로 시작하도록 바꾸기 위해 -1을 해준다.
        nodeB--;

        connections[nodeA].push_back(nodeB); // 연결을 저장하는 변수에 각 노드간의 연결을 저장한다.
        connections[nodeB].push_back(nodeA);
    }
    
    dps(0, connections, visitedNodes, parents);

    for (int parent : parents) {
        if (parent == -1) continue;

        printf("%d\n", parent + 1);
    }


}