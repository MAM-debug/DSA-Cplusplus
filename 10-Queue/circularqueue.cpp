#include <iostream>
using namespace std;
#define size 5
int arr[size];
int front=-1;
int rear=-1;

void enqueue(int value){
    if((rear+1)%size==front){
        cout<<"queue overflow"<<endl;
        return;
    }else if(front==-1 && rear==-1){
        front=rear=0;
    }else{
        rear=(rear+1)%size;
    }
    arr[rear]=value;
};
void dequeue(){
    if(front==-1 && rear==-1){
        cout<<"queue underflow"<<endl;
        return;
    }else if(front == rear){
        front=rear=-1;
    }else{
        front=(front+1)%size;
    }
}
void display(){
    if(front==-1 && rear==-1){
        cout<<"queue is empty"<<endl;
        return;
    }
    int i=front;
    while(i!=rear){
        cout<<arr[i]<<" -> ";
        i=(i+1)%size;
    }
    cout<<arr[rear]<<" -> NULL"<<endl;
}
int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    display();
    dequeue();
    display();
    dequeue();
    display();
    dequeue();
    display();
    dequeue();
    display();
    dequeue();
    display();

    return 0;
}