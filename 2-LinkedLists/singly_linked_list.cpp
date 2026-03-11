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

void pushFront(int value){
    Node* newNode = new Node(value);

    if(head == nullptr){
        head = tail = newNode;
    }
    else{
        newNode->next = head;
        head = newNode;
    }
}

void pushBack(int value){
    Node* newNode = new Node(value);

    if(head == nullptr){
        head = tail = newNode;
    }
    else{
        tail->next = newNode;
        tail = newNode;
    }
}

void popFront(){
    if(head == nullptr){
        cout<<"List is empty"<<endl;
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;

    if(head == nullptr){
        tail = nullptr;
    }
}

void popBack(){
    if(head == nullptr){
        cout<<"List is empty"<<endl;
        return;
    }

    if(head->next == nullptr){
        delete head;
        head = tail = nullptr;
        return;
    }

    Node* temp = head;

    while(temp->next != tail){
        temp = temp->next;
    }

    delete tail;
    tail = temp;
    tail->next = nullptr;
}

void search(int key){
    Node* temp = head;
    int index = 0;

    while(temp != nullptr){
        if(temp->data == key){
            cout<<"Key found at index "<<index<<endl;
            return;
        }
        temp = temp->next;
        index++;
    }

    cout<<"Key not found"<<endl;
}
void del(int key){
    Node*prev=head;
    Node*curr=head->next;
    if(head==nullptr){
        cout<<"List is empty"<<endl;
        return;
    }
    if(head->data==key){
        popFront();
        return;
    }
    if(tail->data==key){
        popBack();
        return;
    }
    while(curr->next!=nullptr && curr->data!=key){
        prev=curr;
        curr=curr->next;
    }
    prev->next=curr->next;
    delete curr;
    
}

void display(){
    if(head == nullptr){
        cout<<"List is empty"<<endl;
        return;
    }

    Node* temp = head;

    while(temp != nullptr){
        cout<<temp->data<<" -> ";
        temp = temp->next;
    }

    cout<<"NULL"<<endl;
}

int main(){

    pushBack(10);
    pushBack(20);
    pushBack(30);

    

    display();

    search(10);
    search(50);

    popFront();
    display();

    popBack();
    display();
    del(20);
    display();

    return 0;
}




