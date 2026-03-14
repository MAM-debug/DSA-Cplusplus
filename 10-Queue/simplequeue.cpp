#include <iostream>
using namespace std;
 struct Node{
    int data;
    Node*next;
    Node(int value){
        data=value;
        next=nullptr;
    }
 };

Node*front=nullptr;
Node*rear=nullptr;

void enqueue(int value){
    Node*newNode= new Node(value);
    if(rear==nullptr){
        front=rear=newNode;
    }
    else{
        rear->next=newNode;
        rear=newNode;
    }
}
void dequeue(int value){
    if(front==nullptr){
        cout<<"Queue is empty"<<endl;
        return;
    }
    Node*temp=front;
    front=front->next;
    delete temp;
    if(front==nullptr){
        rear=nullptr;
    }
}
void display(){
    Node*temp=front;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    cout<<"Queue after enqueuing 10, 20, 30: ";
    display();
    dequeue(10);
    cout<<"Queue after dequeuing 10: ";
    display();
    return 0;
}