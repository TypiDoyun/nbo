#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

class Node {
public:
    int value;
    bool stackVisited;
    bool queueVisited;
    vector<int> edges;

    Node(int value) {
        this->value = value;
        this->stackVisited = false;
        this->queueVisited = false;
    };
};

int main(void) {
    int amountOfNode, amountOfEdge, startAt;

    cin >> amountOfNode >> amountOfEdge >> startAt;

    startAt--;

    vector<Node> graph;
    stack<int> visitStack;
    queue<int> visitQueue;

    visitStack.push(startAt);
    visitQueue.push(startAt);

    for (int index = 0; index < amountOfNode; index++) {
        Node node(index);

        graph.push_back(node);
    }

    graph[startAt].stackVisited = true;
    graph[startAt].queueVisited = true;

    for (int index = 0; index < amountOfEdge; index++) {
        int nodeA, nodeB;

        cin >> nodeA >> nodeB;

        nodeA--;
        nodeB--;

        graph[nodeA].edges.push_back(nodeB);
        graph[nodeB].edges.push_back(nodeA);
    }

    for (Node& node : graph) {
        sort(node.edges.begin(), node.edges.end(), [](int a, int b) {
            return a < b;
        });
    }

    cout << startAt + 1 << " ";

    while (visitStack.size() != 0) {
        Node current = graph[visitStack.top()];
        
        bool isEnd = true;

        for (int nodeId : current.edges) {
            Node& node = graph[nodeId];

            if (node.stackVisited) continue;

            node.stackVisited = true;
            isEnd = false;
            visitStack.push(nodeId);
            cout << nodeId + 1 << " ";
            break;
        }
        
        if (isEnd) visitStack.pop();
    }

    cout << endl;

    while (visitQueue.size() != 0) {
        Node current = graph[visitQueue.front()];
        visitQueue.pop();
        cout << current.value + 1 << " ";

        for (int nodeId : current.edges) {
            Node& node = graph[nodeId];

            if (node.queueVisited) continue;

            node.queueVisited = true;
            visitQueue.push(nodeId);
        }

    }
}