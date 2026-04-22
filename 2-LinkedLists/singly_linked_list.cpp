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
void insertAtPosition(int value, int position){
    Node* newNode= new Node(value);
    if(position == 0){
        pushFront(value);
        return;
    }

    Node *temp=head;
    int idx=0;
    
    

    while(temp!=nullptr && idx<position-1){
        temp=temp->next;
        idx++;
    }
    if(temp==nullptr){
        cout<<"Position out of bounds"<<endl;
        delete newNode;
        return;
    }
    if(temp->next == nullptr){
        pushBack(value);
        return;
    }
    newNode->next=temp->next;
    temp->next=newNode;
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
        temp=temp->next;                                                                  
        index++;
    }

    cout<<"Key not found"<<endl;
}
void del(int key){

    if(head == nullptr){
        cout << "List is empty" << endl;
        return;
    }

    if(head->data == key){
        popFront();
        return;
    }

    if(tail->data == key){
        popBack();
        return;
    }
    Node* prev = head;
    Node* curr = head->next;

    while(curr != nullptr && curr->data != key){
        prev = curr;
        curr = curr->next;
    }
    if(curr == nullptr){
        cout << "Value not found" << endl;
        return;
    }
    prev->next = curr->next;
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
int forwarddisplay(Node* temp){
    if(temp == nullptr){
        return 0;
    }
    cout<<temp->data<<" -> ";
    forwarddisplay(temp->next);
}
int reversedisplay(Node* temp){
    if(temp == nullptr){
        return 0;
    }
    reversedisplay(temp->next);
    cout<<temp->data<<" -> ";
}
void reversell(){
    Node* prev= nullptr;
    Node* curr = head;
    Node* next = nullptr;
    while(curr != nullptr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}



int main(){
    pushBack(1);
    pushBack(2);
    pushBack(3);
    pushBack(4);
    pushBack(5);

    cout<<"Initial list: ";
    display();

    cout<<"Inserting 10 at position 2"<<endl;
    insertAtPosition(10, 2);
    display();

    cout<<"Popping front"<<endl;
    popFront();
    display();

    cout<<"Popping back"<<endl;
    popBack();
    display();

    cout<<"Searching for 10"<<endl;
    search(10);

    cout<<"Deleting 10"<<endl;
    del(10);
    display();
    reversedisplay(head);
    forwarddisplay(head);

    return 0;
}




