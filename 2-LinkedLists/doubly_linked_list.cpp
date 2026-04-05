#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};
Node* head = nullptr;
Node* tail = nullptr;

void pushfront(int value){
    Node* newNode=new Node(value);
    if(head==nullptr){
        head=tail=newNode;
    }
    else{
        newNode->next=head;
        head->prev=newNode;
        head=newNode;
    }
}

void pushback(int value){
    Node* newNode=new Node(value);
    if(head==nullptr){
        head=tail=newNode;
    }
    else{
        tail->next=newNode;
        newNode->prev=tail;
        tail=newNode;
    }
}
void popfront(){
    if(head==nullptr){
        cout<<"list is empty"<<endl;
        return;
    }
    Node* temp=head;
    head=head->next;
    if(head!=nullptr){
        head->prev=nullptr;
    }
    else{
        tail=nullptr;
    }
    
    delete temp;
    }
void popback(){
    if(head==nullptr){
        cout<<"list is empty"<<endl;
        return;
    }
    Node*temp=tail;
    if(tail==nullptr){
        head=tail=nullptr;
    }
    else{
        tail=tail->prev;
        tail->next=nullptr;
    }
    delete temp;
}
void display(){
    if(head==nullptr){
        cout<<"list is empty"<<endl;
        return;
    }
    Node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" <-> ";
        temp=temp->next;
    }
    cout<<"nullptr"<<endl;
}
void search(int key){
    Node *temp=head;
    while(temp!=nullptr){
        if(temp->data==key){
            cout<<"key found in the list"<<endl;
            return;
        }
        temp=temp->next;
    }
    cout<<"key not found in the list"<<endl;
}
void del(int key){
    if(head==nullptr){
        cout<<"chal bhai"<<endl;
        return;
    }
    if(head->data==key){
        popfront();
        return;
    }
    if(tail->data==key){
        popback();
        return; 
    }
Node* temp = head->next;

while(temp != nullptr){
    if(temp->data == key){

        temp->prev->next = temp->next;

        if(temp->next != nullptr){  
            temp->next->prev = temp->prev;
        } else {
            tail = temp->prev;       
        }

        delete temp;
        return;
    }

    temp = temp->next;
}
    cout<<"key not found in the list"<<endl;
}
int main() {
    pushback(10);
    pushback(20);
    pushback(30);
    pushfront(5);
    pushfront(1);
    display();

    search(20);
    search(100);

    del(10);
    del(1);
    del(100); // key not found case
    display();

    return 0;
}
