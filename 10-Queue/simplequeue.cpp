#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* next;
    Node(int k) {
        key = k;
        next = nullptr;
    }
};
Node* front = nullptr;
Node* rear = nullptr;
void pushback(int key) {
    Node* newNode = new Node(key);
    if (rear == nullptr) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}



