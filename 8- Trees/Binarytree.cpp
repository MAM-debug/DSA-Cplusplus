#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left; // address of left child
    Node* right; // address of right child

    Node(int value) {
        data = value;
        left = NULL;//pointing to null because when we create a new node, it does not have any children yet.
        right = NULL;
    }
};

int main() {
    // Creating a binary tree
    Node* root = new Node(1); // root node
    root->left = new Node(2); // left child of root
    root->right = new Node(3); // right child of root
    root->left->left = new Node(4); // left child of node 2
    root->left->right = new Node(5); // right child of node 2

    // The structure of the binary tree is as follows:
    //         1
    //        / \
    //       2   3
    //      / \
    //     4   5

    return 0;
}