#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int value){
        data = value;
        next = nullptr;
    }
};
Node* top = nullptr;

void push(int value){
    Node* newNode = new Node(value);
    newNode->next = top;
    top = newNode;
    if(top == nullptr){
        cout<<"Stack underflow"<<endl;
    }
}
void pop(){
    if(top==nullptr){
        cout<<"Stack underflow"<<endl;
        return;
    }
    Node*temp=top;
    toop=top->next;
    delete temp;
    
}


   