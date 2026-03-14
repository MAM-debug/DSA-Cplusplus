#include <iostream>
using namespace std;
int hashfunction (int key,int tablesize)
{
    return key % tablesize;
}

void insert(int key,int tablesize){
    int index=hashfunction(key,tablesize);
    //insert key at index
    // Implementation for actual insertion would go here
    cout<<"Inserting key "<<key<<" at index "<<index<<endl;
    while(table[index] != -1) {
        index = (index + 1) % tablesize; // Linear probing
    }
    table[index] = key; // Insert the key
}
