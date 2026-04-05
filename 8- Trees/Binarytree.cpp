#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node*right;
    Node(int value){
        data=value;
        left=NULL;
        right=NULL;
    }

void inorder(Node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void preorder(Node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " "; //dry run karna hai inorder, preorder, postorder ka 
}
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    
    cout << "Root: " << root->data << endl;
    cout << "Left child of root: " << root->left->data << endl;
    cout << "Right child of root: " << root->right->data << endl;
    cout << "Left child of left child: " << root->left->left->data << endl;
    cout << "Right child of left child: " << root->left->right->data << endl;
    cout << "Inorder traversal: ";
    inorder(root);
    cout << "\nPreorder traversal: ";
    preorder(root);
    cout << "\nPostorder traversal: ";
    postorder(root);
    return 0;
}