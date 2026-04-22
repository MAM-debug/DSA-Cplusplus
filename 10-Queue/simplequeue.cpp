#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int value){
        data=value;
        next=nullptr;
    }
};
Node* front=nullptr;
Node* rear=nullptr; 
void enqueue(int value){
    Node* newNode=new Node(value);
    if(front==nullptr){
        front=rear=newNode;
    }else{
        rear->next=newNode;
        rear=newNode;
    }
}
void dequeue(){
    if(front==nullptr){
        cout<<"queue underflow"<<endl;
        return;
    }
    Node* temp=front;
    front=front->next;
    if(front==nullptr){
        rear=nullptr;
    }
    
    delete temp;
}