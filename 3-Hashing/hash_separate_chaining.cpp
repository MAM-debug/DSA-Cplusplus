#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertChaining(int key, int tablesize, Node* hashtable[]) {
    int hashindex = key % tablesize;
    
    Node* newNode = new Node();
    newNode->data = key;
    newNode->next = NULL;
    
    if (hashtable[hashindex] == NULL) {
        hashtable[hashindex] = newNode;
        cout << "Student " << key << " is FIRST at position " << hashindex << endl;
    }
    else {
        Node* temp = hashtable[hashindex];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        cout << "Student " << key << " CHAINED at position " << hashindex << endl;
    }
}

void display(Node* hashtable[], int tablesize) {
    cout << "\nFinal Hash Table:\n";
    for (int i = 0; i < tablesize; i++) {
        cout << "Position " << i << ": ";
        
        if (hashtable[i] == NULL) {
            cout << "Empty";
        } else {
            Node* temp = hashtable[i];
            while (temp != NULL) {
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout << "NULL";
        }
        cout << endl;
    }
}

int main() {
    int students[] = {8, 15, 22, 29, 36};
    int tablesize = 7;
    Node* hashtable[7] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    
    for (int i = 0; i < 5; i++) {
        insertChaining(students[i], tablesize, hashtable);
    }
    
    display(hashtable, tablesize);
    
    return 0;

}