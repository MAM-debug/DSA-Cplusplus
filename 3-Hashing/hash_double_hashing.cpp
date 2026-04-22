//double hashing practice

#include<iostream>
using namespace std;

int tablesize=13; // Hash table of size 13
int hashtable[13]; // Hash table array
int hashfunction1(int key){
    return key%tablesize; // First hash function
}
int hashfunction2(int key){
    return 11-(key%11); // Second hash function, must be non-zero and less than tablesize
}
void insert(int key){
    int index=hashfunction1(key);
    int jump=hashfunction2(key);
    int i=0;
    while(hashtable[index]!=-1 && hashtable[index]!=-2){
        cout<<"Collision occurred for key "<<key<<" at index "<<index<<endl;
        i++;
        index=(index+jump)%tablesize; // Double hashing to resolve collision
        if(i==tablesize){ // If we have probed all indices, the table is full
            cout<<"Hash table is full, cannot insert key "<<key<<endl;
            return;
        }
    }
    hashtable[index]=key;
}