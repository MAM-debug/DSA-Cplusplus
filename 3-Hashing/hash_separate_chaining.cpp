#include <iostream>
using namespace std;
int tableSize = 10;

struct Node {
    int data;
    Node* next;
    Node(int value){
        data = value;
        next = nullptr;
    }
};

Node* hashTable[tableSize] = {nullptr};

int hashFunction(int key){
    return key % tableSize;
}

void insert(int key){
    int index = hashFunction(key);
    Node* newNode = new Node(key);

    if(hashTable[index] == nullptr){
        hashTable[index] = newNode;
    }
    else{
        newNode->next = hashTable[index];
        hashTable[index] = newNode;
    }
}
int search(int key){
    int index= hashFunction(key);
    Node* temp = hashTable[index];
    while(temp!=nullptr){
        if(temp->data==key){
            return true;
        }
        temp = temp->next;
    }
    return false;
}



