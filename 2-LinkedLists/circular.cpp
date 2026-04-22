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
void insertAtPosition(int value, int position){
    if(position==0){
        pushfront(value);
        return;
    }
    Node* newNode = new Node(value);
    Node* temp=head;
    int idx=0;
    while(temp->next!=head && idx<position-1){
        temp=temp->next;
        idx++;
    }
    if(temp->next==head){
        pushback(value);
        return;
    }
    newNode->next=temp->next;
    temp->next=newNode;

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
void search(int key){
    if(head==nullptr){
        cout<<"list is empty"<<endl;
        return;
    }
    Node* temp=head;
    int index=0;
    do{
        if(temp->data==key){
            cout<<"key found at index "<<index<<endl;
            return;
        }
        temp=temp->next;
        index++;
    }while(temp!=head);
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
    Node* temp=head;
    while(temp->next!=head && temp==head 
    && temp->next!=tail){
        if(temp->next->data==key){
            Node* toDelete=temp->next;
            temp->next=toDelete->next;
            delete toDelete;
            return;
        }
        temp=temp->next;
    }

}
int main(){
    pushback(1);
    pushback(2);
    pushback(3);
    pushback(4);
    pushback(5);
    display();
    cout<<"Inserting 10 at position 2"<<endl;
    insertAtPosition(10,2);
    display();
    cout<<"Searching for 3 in the list"<<endl;
    search(3);
    cout<<"Searching for 20 in the list"<<endl;
    search(20);
    cout<<"Deleting 3 from the list"<<endl;
    del(3);
    display();
}

    


