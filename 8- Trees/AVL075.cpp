#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
    int height; // height of the node
};
Node* createNode(int key) {
    Node* newNode = new Node();
    newNode->data = key;
    newNode->left = nullptr;
    newNode->right = nullptr;
    newNode->height = 0; // new node is initially added at leaf
    return newNode;
}
int height(Node* node) {
    if (node == nullptr) {
        return -1; // height of null is -1
    }
    return node->height;
}
int getBalance(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return height(node->left) - height(node->right);
}
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));

    // Return new root
    return x;
} 
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    // Return new root
    return y;
}
Node* insert(Node* node, int key) {
    // Perform the normal BST insert
    if (node == nullptr) {
        return createNode(key);
    }
    if (key < node->data) {
        node->left = insert(node->left, key);
    } else if (key > node->data) {
        node->right = insert(node->right, key);
    } else {
        // Duplicate keys not allowed
        return node;
    }

    // Update height of this ancestor node
    node->height = 1 + max(height(node->left), height(node->right));

    // Get the balance factor to check whether this node became unbalanced
    int balance = getBalance(node);

    // If the node becomes unbalanced, then there are 4 cases

    // Left Left Case
    if (balance > 1 && key < node->left->data) {
        return rightRotate(node);
    }

    // Right Right Case
    if (balance < -1 && key > node->right->data) {
        return leftRotate(node);
    }

    // Left Right Case
    if (balance > 1 && key > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // Return the unchanged node pointer
    return node;
}
int main() {
    Node* root = nullptr;

    // Insert nodes into the AVL tree
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    cout << "AVL Tree created successfully!" << endl;

    return 0;
}