#include <iostream>
using namespace std;

const int TABLE_SIZE = 11;

int hashTable[TABLE_SIZE];   

int hashFunction(int key) {
    return key % TABLE_SIZE;
}

void inser(int key) {

    int hashIndex = hashFunction(key);

    for(int i = 0; i < TABLE_SIZE; i++) {

        int newIndex = (hashIndex + i*i) % TABLE_SIZE;

        if(hashTable[newIndex] == -1) {
            hashTable[newIndex] = key;
            cout << "Key: " << key 
                 << " inserted at index: " << newIndex << endl;
            return;
        }
    }

    cout << "Sorry, Hash Table is FULL!" << endl;
}

int main() {

    for(int i = 0; i < TABLE_SIZE; i++)
        hashTable[i] = -1;

    int keys[] = {8, 15, 22, 29, 36};

    for(int i = 0; i < 5; i++)
        inser(keys[i]);

    return 0;
}

// We use a prime table size and quadratic probing formula (h + i²) % tableSize.
//The loop is limited to table size to prevent infinite looping.
//If an empty slot (-1) is found, we insert the key; otherwise, we declare the table full.