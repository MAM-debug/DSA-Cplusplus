#include <iostream>
using namespace std;

const int tablesize = 10;

struct Node {
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

Node* hashTable[tablesize] = {nullptr};

int hashfunction(int key) {
    return key % tablesize;
}

void insert(int key) {
    int index = hashfunction(key);
    Node* newNode = new Node(key);

    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

void del(int key) {
    int index = hashfunction(key);
    Node* current = hashTable[index];
    Node* prev = nullptr;

    while(current != nullptr) {
        if(current->data == key) {
            if(prev == nullptr) {
                hashTable[index] = current->next;
            } else {
                prev->next = current->next;
            }
            delete current;
            return;
        }
        prev = current;
        current = current->next;
    }

    cout << "Key not found\n";
}

void search(int key) {
    int index = hashfunction(key);
    Node* current = hashTable[index];

    while(current != nullptr) {
        if(current->data == key) {
            cout << "Key found\n";
            return;
        }
        current = current->next;
    }

    cout << "Key not found\n";
}

int main() {
    insert(5);
    insert(15);
    insert(25);

    search(15);
    search(35);

    del(15);
    search(15);

    return 0;
}