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

Node* head = nullptr;
Node* tail = nullptr;

void pushfront(int value){
    Node* newNode = new Node(value);
    if(tail==nullptr){
        tail=head=newNode;
        tail->next=head;//ye circular linked list ke liye hai


    }
    else{
        newNode->next=head;
        head=newNode;
        tail->next=head;//ye circular linked list ke liye hai..head update hone ke baad tail ka next bhi head ko point karega
    }
}
void pushback(int value){
    Node* newNode = new Node(value);
    if(tail==nullptr){
        tail=head=newNode;
        tail->next=head;//ye circular linked list ke liye hai
    }
    else{
        tail->next=newNode;
        tail=newNode;
        tail->next=head;//ye circular linked list ke liye hai..tail update hone ke baad tail ka next bhi head ko point karega
    }//sab kch same hai bas tail ka next head ko point kar raha hai
}

void popfront(){
    if (head==nullptr){
        cout<<"list is empty"<<endl;
        return;
    }
    if(head==tail){
        delete head;
        head=tail=nullptr;
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
    tail->next=head;
}
void popback(){
    if(head==nullptr){
        cout<<"list is empty"<<endl;
        return;
    }
    if(head==tail){
        delete head;
        head=tail=nullptr;
        return;
    }
    Node* temp = head;
    while(temp->next!=tail){
        temp=temp->next;
    }
    delete tail;
    tail=temp;
    tail->next=head;

}
void display(){
    if(head==nullptr){
        cout<<"list is empty"<<endl;
        return;
    }
    Node* temp=head;
    while(temp->next!=head){
        cout<<temp->data<<" -> ";
        temp=temp->next;
    }

    
}

