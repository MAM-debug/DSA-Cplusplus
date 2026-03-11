#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};
Node* top = nullptr;
void push(int value){
    if (top == nullptr) {
        top = new Node(value);
    } else {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }
    
}
void pop(){
     if( top==nullptr){
        cout<<"stack underflow"<<endl;
        return;
    }
    Node* temp=top;
    top=top->next;
    delete temp;
}
void display(){
    Node* temp=top;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main(){
    push(10);
    push(20);
    push(30);
    cout<<"Top element: "<<top->data<<endl; // Output: 30
    display();
    pop();
    cout<<"Top element after pop: "<<top->data<<endl; // Output: 20
    display();
    return 0;
}


   