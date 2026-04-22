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

Node* insertatendrec(Node* head, int value){
    if(head == nullptr){
        Node* newNode = new Node(value);
        tail=newNode;
        return newNode;
    }
    head->next = insertatendrec(head->next, value);
    return head;
}
void pushFront(int value){
    Node* newNode = new Node(value);

    if(head == nullptr){
        head = tail = newNode;
    }
    else{
        newNode->next = head;
        head = newNode;
    }
}//no recursion in push front because we are adding new node at the beginning of the list so we don't need to traverse the list to find the position where we want to add the new node

Node* insertatposition(Node* head, int value, int position){
    if(position==0){
        Node* newNode = new Node(value);
        newNode->next=head;
        return newNode;
    }
    if(head==nullptr){
        cout<<"position out of bounds"<<endl;
        return nullptr;
    }
    head->next=insertatposition(head->next,value,position-1);
    return head;

}
void popfrontrec(Node* &head){
    if(head==nullptr){
        cout<<"list is empty"<<endl;
        return;
    }
    Node* temp=head;
    temp=temp->next;
    delete head;
    head = temp;
}
Node* popBack(Node* &head){
    if(head == nullptr){
        cout<<"List is empty"<<endl;
        return nullptr;
    }
    if(head->next == nullptr){
        delete head;
        head = tail = nullptr;
        return nullptr;
    }
    if(head->next->next == nullptr){
        delete head->next;
        head->next = nullptr;
        tail = head;
        return head;
    }
    head->next = popBack(head->next);
    return head;
}
Node* deletion(Node* head,int key){
    if(head==nullptr){
        cout<<"list is empty"<<endl;
        return nullptr;
    }
    if(head->data==key){
        Node* temp=head->next;
        delete head;
        return temp;
    }
    head->next=deletion(head->next,key);
    return head;
}
int displayrec(Node* temp){
    if(temp==nullptr){
        return 0;
    }
    cout<<temp->data<<" -> ";
    displayrec(temp->next);
}
int reverseDisplayrec(Node* temp){
    if(temp==nullptr){
        return 0;
    }
    reverseDisplayrec(temp->next);
    cout<<temp->data<<" -> ";
}
int main(){
    pushFront(1);
    pushFront(2);
    pushFront(3);
    pushFront(4);
    pushFront(5);
    cout<<"List: ";
    displayrec(head);
    cout<<"NULL"<<endl;
    cout<<"List in reverse: ";
    reverseDisplayrec(head);
    cout<<"NULL"<<endl;
    head=insertatposition(head,10,2);
    cout<<"List after inserting 10 at position 2: ";
    displayrec(head);
    cout<<"NULL"<<endl;
    popfrontrec(head);
    cout<<"List after popping front: ";
    displayrec(head);
    cout<<"NULL"<<endl;
    head=popBack(head);
    cout<<"List after popping back: ";
    displayrec(head);
    cout<<"NULL"<<endl;
    head=deletion(head,3);
    cout<<"List after deleting key 3: ";
    displayrec(head);
    cout<<"NULL"<<endl;
}