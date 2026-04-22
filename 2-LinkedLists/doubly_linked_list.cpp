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
        tail->next=nullptr;
    }
}
void insertAtPoistion(int value,int position){
    Node* newNode=new Node(value);
    if(position==0){
        pushfront(value);
        return; 
    }
    Node* temp=head;
    int idx=0;
    while(temp!=nullptr && idx<position-1){
        temp=temp->next;
        idx++;
    }
    if(temp==nullptr){
        cout<<"position out of bounds"<<endl;
        delete newNode;
        return;
    }
        if(temp->next==nullptr){
            pushback(value);
            return;
        }
    newNode->next=temp->next;
    newNode->prev=temp;
    temp->next->prev=newNode;
    temp->next=newNode;

}
void popfront(){
    if(head==nullptr){
        cout<<"list is empty"<<endl;
        return;
    }
    Node* temp=head;
    if(head==tail){
        head=tail=nullptr;
    }
    else{
        head=head->next;
        head->prev=nullptr;
    }
    delete temp;

}
void popback(){
    if(head==nullptr){
        cout<<"list is empty"<<endl;
        return;
    }
    Node*temp=tail;
    if(head==nullptr){
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
        cout<<"list is empty"<<endl;
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
    Node* temp=head->next;
    while(temp!=nullptr && temp->data!=key){
        temp=temp->next;
    }
    if(temp==nullptr){
        cout<<"key not found in the list"<<endl;
        return;
    }
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    if(temp==tail){
        tail=temp->prev;
    }
    delete temp;
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
