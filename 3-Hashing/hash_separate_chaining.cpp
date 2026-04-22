#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int value){
        data=value;
        next=nullptr;
    }
};
Node* hashTable[10]; // Hash table of size 10
int hashfunction(int key){
    return key % 10; // Simple hash function
}
void insert(int key){
    int index=hashfunction(key);
    Node* newNode=new Node(key);
    if(hashTable[index]==nullptr){
        hashTable[index]=newNode;
    }
    else{
        Node* temp=hashTable[index];
        while(temp->next!=nullptr){
            temp=temp->next;
        }
        temp->next=newNode;
    }
}
void deletion(int key){
    int index=hashfunction(key);
    Node* temp=hashTable[index];
    Node* prev=nullptr;
    //case 1: key is present at head
    if(temp!=nullptr && temp->data==key){
        hashTable[index]=temp->next;
        delete temp;
        return;
    }
    //case 2: key is present at other than head
    while(temp!=nullptr && temp->data!=key){
        prev=temp;
        temp=temp->next;
    }
    if(temp==nullptr) return; // Key not found
    prev->next=temp->next;
    delete temp;
}
void display(){
    for(int i=0;i<10;i++){
        Node* temp=hashTable[i];
        cout<<"index "<<i<<" : ";
        while(temp!=nullptr){
            cout<<temp->data<<" -> ";
            temp=temp->next;
        }
        cout<<"nullptr"<<endl;
    }
}
void search(int key){
    int index=hashfunction(key);
    Node* temp=hashTable[index];
    while(temp!=nullptr){
        if(temp->data==key){
            cout<<"key found at index "<<index<<endl;
            return;
        }
        temp=temp->next;
    }
    cout<<"key not found in the hash table"<<endl;
}
int main(){
    for(int i=0;i<10;i++){
        hashTable[i]=nullptr;
    }
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    search(20);
    search(25);
    display();
}




