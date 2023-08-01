#include <iostream>
#include <algorithm>

using namespace std;

class Node {
public:
    int value;
    Node* left;
    Node* right;

    Node(int value) {
        this->value = value;
    }

    void decay(Node* root) {
        if (root == nullptr) return;

        decay(root->left);
        decay(root->right);
        delete root;
    }

    void appendChild(Node* node) {
        if (this->left == nullptr) this->left = node;
        else if (this->right == nullptr) this->right = node;
    }

    bool isLeafNode() {
        return this->left == nullptr && this->right == nullptr;
    }
};

class Tree {
public:
    Node* root;

    Node* find(Node* root, int value) {
        if (root == nullptr) return nullptr;
        if (root->value == value) return root;

        Node* result;

        result = find(root->left, value);
        if (result != nullptr) return result;
        return find(root->right, value);
    }

    int leafNodes(Node* root, int exclude) {
        if (root == nullptr) return 0;
        if (root->value == exclude) return 0;

        int count = leafNodes(root->left, exclude) + leafNodes(root->right, exclude);
        if (root->isLeafNode()) count++;

        return count;
    }
};

int main(void) {
    Tree tree;
    int length;

    cin >> length;

    for (int nodeId = 0; nodeId < length; nodeId++) {
        int parentId;
        cin >> parentId;
        Node* node = new Node(nodeId);

        if (parentId == -1) {
            tree.root = node;
            continue;
        }

        Node* parent = tree.find(tree.root, parentId);
        parent->appendChild(node);
    }

    int exclude;
    cin >> exclude;
    cout << tree.leafNodes(tree.root, exclude);

    return 0;
}