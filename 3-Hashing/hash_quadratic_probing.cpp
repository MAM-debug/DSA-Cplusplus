#include <iostream>
using namespace std;
int tablesize=10; // Hash table of size 10
int hashfunction (int key)
{
    return key % tablesize; // Simple hash function
};

void insert(int key,int hashtable[]){
    int idex=hashfunction(key);
    int i=0;
    while(hashtable[idex]!=-1 && hashtable[idex]!=-2){ // Quadratic probing to resolve collision
        cout<<"Collision occurred for key "<<key<<" at index "<<idex<<endl;
        i++;
        idex=(hashfunction(key)+i*i)%tablesize; // Move to the next index using quadratic probing
        if(i==tablesize){ // If we have probed all indices, the table is full
            cout<<"Hash table is full, cannot insert key "<<key<<endl;
            return;
        }
    }
    hashtable[idex]=key; // Insert the key at the found index
}