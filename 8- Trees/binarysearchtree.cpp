#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(){
        data = 0;
        left = nullptr;
        right = nullptr;
    }
};
void insertion(Node* &root,int key){
    if(root==nullptr){
        root=new Node();    
        root->data=key;
        return;
    }
    if(key<root->data){
        insertion(root->left,key);
    }
    else if(key>root->data){
        insertion(root->right,key);
    }
}
void inorder(Node* root){
    if(root==nullptr){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder(Node* root){
    if(root==nullptr){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root){
    if(root==nullptr){
        return; 
        
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
void deletenode(Node* &root,int key){
    if(root=nullptr){
        return;
    }
    if(key<root->data){
        deletenode(root->left,key);
    }
    else if(key>root->data){
        deletenode(root->right,key);
    }
    else{
        //case 1: no child
        if(root->left==nullptr && root->right==nullptr){
            delete root;
            root=nullptr;
        }
        //case 2: one child
        else if(root->left==nullptr){
            Node* temp=root;
            root=root->right;
            delete temp;
        }
        else if(root->right==nullptr){
            Node* temp=root;
            root=root->left;
            delete temp;
        }
        //case 3: two children
        else{
            Node* temp=root->right;
            while(temp->left!=nullptr){
                temp=temp->left;
            }
            root->data=temp->data;
            deletenode(root->right,temp->data);
        }
    }
    }

int main(){
    Node* root=nullptr;
    insertion(root,10);
    insertion(root,5);
    insertion(root,15);
    insertion(root,3);
    insertion(root,7);
    insertion(root,12);
    insertion(root,18);
    cout<<"Inorder Traversal: ";
    inorder(root);
    cout<<endl;
    cout<<"Preorder Traversal: ";
    preorder(root);
    cout<<endl;
    cout<<"Postorder Traversal: ";
    postorder(root);
    cout<<endl;
    deletenode(root,5);
    cout<<"Inorder Traversal after deletion: ";
    inorder(root);
    cout<<endl;
}
