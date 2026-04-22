#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;

    Node(int value){
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};
Node* head = nullptr;
Node* tail = nullptr;
\
void pushFront(int value){
    Node* newNode = new Node(value);

    if(head == nullptr){
        head = tail = newNode;
    }
    else{
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

Node*pushbackrec(Node* head, int value){
    if(head == nullptr){
        Node* newNode = new Node(value);
        tail=newNode;
        return newNode;
    }
    head->next=pushbackrec(head->next,value);
    head->next->prev=head;
    return head;
}