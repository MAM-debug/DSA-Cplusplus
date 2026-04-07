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
Node* head=nullptr;
void push(int value){
    Node* newNode= new Node(value);
    newNode->next=head;
    head=newNode;
}
void pop(){
    if(head==nullptr){
        cout<<"stack is empty"<<endl;
        return;
    }
    Node* temp=head;
    head=head->next;
    delete temp;
}
void peek(){
    if(head==nullptr){
        cout<<"stack is empty"<<endl;
        return;
    }
    cout<<"top element is "<<head->data<<endl;
}
void display(){
    if(head==nullptr){
        cout<<"stack is empty"<<endl;
        return;
    }
    Node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" -> ";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
int main(){
    push(10);
    push(20);
    push(30);
    display();
    peek();
    pop();
    display();
    peek();
    return 0;
}


   