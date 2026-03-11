#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

// Insert a value into the BST
Node* insert(Node* root, int value) {
    if (root == NULL) {
        return new Node(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    }
    else {
        root->right = insert(root->right, value);
    }
    return root;
}

// Find the minimum value node (used in delete)
Node* findMin(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Delete a node from the BST
Node* deleteNode(Node* root, int value) {
    if (root == NULL) {
        cout << "Value not found to delete\n";
        return NULL;
    }
    
    // Traverse to find the node to delete
    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    }
    else {
        // Node found
        // Case 1: No children (leaf node)
        if (root->left == NULL && root->right == NULL) {
            cout << "Deleting leaf node: " << value << "\n";
            delete root;
            return NULL;
        }
        
        // Case 2: One child
        if (root->left == NULL) {
            cout << "Deleting node with right child: " << value << "\n";
            Node* temp = root->right;
            delete root;
            return temp;
        }
        if (root->right == NULL) {
            cout << "Deleting node with left child: " << value << "\n";
            Node* temp = root->left;
            delete root;
            return temp;
        }
        
        // Case 3: Two children
        // Find the inorder successor (smallest in right subtree)
        cout << "Deleting node with two children: " << value << "\n";
        Node* successor = findMin(root->right);
        root->data = successor->data;
        root->right = deleteNode(root->right, successor->data);
    }
    
    return root;
}

// Inorder traversal: Left -> Root -> Right
void inorder(Node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Preorder traversal: Root -> Left -> Right
void preorder(Node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Postorder traversal: Left -> Right -> Root
void postorder(Node* root) {
    if (root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// Level-order traversal (Breadth-First): Use queue
void levelOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    queue<Node*> q;
    q.push(root);
    
    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        cout << current->data << " ";
        
        if (current->left != NULL) {
            q.push(current->left);
        }
        if (current->right != NULL) {
            q.push(current->right);
        }
    }
}

// Search for a value
void search(Node* root, int key) {
    if (root == NULL) {
        cout << "Key " << key << " not found\n";
        return;
    }
    if (root->data == key) {
        cout << "Key " << key << " found\n";
        return;
    }
    if (key < root->data) {
        search(root->left, key);
    }
    else {
        search(root->right, key);
    }
}

int main() {
    Node* root = NULL;
    
    // Insert values
    root = insert(root, 5);
    insert(root, 3);
    insert(root, 7);
    insert(root, 2);
    insert(root, 4);
    insert(root, 6);
    insert(root, 8);
    
    cout << "=== ORIGINAL TREE ===\n";
    cout << "Inorder traversal: ";
    inorder(root);
    cout << "\n";
    
    cout << "Preorder traversal: ";
    preorder(root);
    cout << "\n";
    
    cout << "Postorder traversal: ";
    postorder(root);
    cout << "\n";
    
    cout << "Level-order traversal: ";
    levelOrder(root);
    cout << "\n";
    
    // Search operations
    cout << "\n=== SEARCH OPERATIONS ===\n";
    search(root, 5);
    search(root, 2);
    search(root, 10);
    
    // Delete operations
    cout << "\n=== DELETE OPERATIONS ===\n";
    
    // Delete leaf node
    root = deleteNode(root, 2);
    cout << "After deleting 2: ";
    inorder(root);
    cout << "\n";
    
    // Delete node with one child
    root = deleteNode(root, 3);
    cout << "After deleting 3: ";
    inorder(root);
    cout << "\n";
    
    // Delete node with two children
    root = deleteNode(root, 5);
    cout << "After deleting 5: ";
    inorder(root);
    cout << "\n";
    
    cout << "\n=== FINAL TREE ===\n";
    cout << "Inorder traversal: ";
    inorder(root);
    cout << "\n";
    
    cout << "Level-order traversal: ";
    levelOrder(root);
    cout << "\n";
    
    return 0;
}

