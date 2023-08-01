#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <functional>

using namespace std;

class Node;

class Edge {
public:
	Node* node;
	int weight;

	Edge(Node* node, int weight);
};

class Node {
public:
	int value;
	bool marked;
	vector<Edge> edges;

	Node(int value) {
		this->value = value;
		this->marked = false;
	}
};

Edge::Edge(Node* node, int weight) {
	this->node = node;
	this->weight = weight;
}

int main(void) {
	int amountOfNode;

	cin >> amountOfNode;

	vector<Node> graph;
	vector<array<int, 2>> distance;

	for (int index = 0; index < amountOfNode; index++) {
		Node node(index + 1);
		array<int, 2> arr = { index + 1, -1 };

		distance.push_back(arr);
		graph.push_back(node);
	}

	for (int index = 0; index < amountOfNode - 1; index++) {
		int parentId, childId, weight;

		cin >> parentId >> childId >> weight;

		Node& parent = graph[parentId - 1];
		Node& child = graph[childId - 1];
		Edge parentEdge(&child, weight);
		Edge childEdge(&parent, weight);

		parent.edges.push_back(parentEdge);
		child.edges.push_back(childEdge);
	}

	for (Node& node : graph) {
		sort(node.edges.begin(), node.edges.end(), [](Edge a, Edge b) {
			return a.weight > b.weight;
		});
	}

	function<void(Node*, int)> dfs = [&](Node* current, int weight) {
		distance[current->value - 1][1] = weight;

		//cout << distance[current->value - 1][1] << endl;

		for (Edge edge : current->edges) {
			Node* node = edge.node;
			
			if (distance[node->value - 1][1] != -1) continue;

			dfs(node, weight + edge.weight);
		}
	};

	dfs(&graph[0], 0);

	sort(distance.begin(), distance.end(), [](array<int, 2> a, array<int, 2> b) {
		return a[1] > b[1];
	});
	
	Node* farthestNode = &graph[distance[0][0] - 1];

	for (int index = 0; index < amountOfNode; index++)
		distance[index] = { index + 1, -1 };

	dfs(farthestNode, 0);

	sort(distance.begin(), distance.end(), [](array<int, 2> a, array<int, 2> b) {
		return a[1] > b[1];
	});

	cout << distance[0][1];
}