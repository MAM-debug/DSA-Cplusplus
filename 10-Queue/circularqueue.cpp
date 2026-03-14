#include <iosrtream>
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
        rear->next=front; // Make it circular.its that easy

    }
};
void dequeue(int value){
    if(front==nullptr){
        cout<<"Queue is empty"<<endl;
        return;
    }
    Node*temp=front;
    front=front->next;
    rear->next=front; // Update rear's next to the new front
    delete temp;
    if(front==nullptr){
        rear=nullptr;
    }
}