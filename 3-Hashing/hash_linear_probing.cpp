#include <iostream>
using namespace std;
int tablesize=10; // Hash table of size 10
int hashfunction (int key)
{
    return key % tablesize; // Simple hash function
};
void insert(int key,int hashTable[]){
    int index=hashfunction(key);
    int i=0;
    while(hashTable[index]!=-1 && hashTable[index]!=-2){
        cout<<"Collision occured for key "<<key<<" at index "<<index<<endl;
        index=(index+1)%tablesize;//linear probing
        i++;
        if(i==tablesize){ // If we have probed all indices, the table is full
            cout<<"Hash table is full, cannot insert key "<<key<<endl;
            return;
        }

    }
    hashTable[index]=key;
}
void deletion(int key,int hashTable[]){
    int index=hashfunction(key);
    int i=0;
    while(hashTable[index]!=-1){
        if(hashTable[index]==key){
            hashTable[index]=-2; // Mark as deleted
            return;
        
        }
        index=(index+1)%tablesize; // linear probing
        i++;
        if(i==tablesize){ // If we have probed all indices, the key is not found
            cout<<"Key "<<key<<" not found in the hash table."<<endl;
            return;
        }

    }
}
void display(int hashTable[]){
    for(int i=0;i<tablesize;i++){
        if(hashTable[i]!=-1 && hashTable[i]!=-2){
        cout<<i<<" : "<<hashTable[i]<<endl;
        }
    }
}
void search(int key,int hashTable[]){
    int index=hashfunction(key);
    int i=0;
    while(hashTable[index]!=-1){
        if(hashTable[index]==key){
            cout<<"key found at index "<<index<<endl;
            return;
        }
        index=(index+1)%tablesize; // linear probing
        i++;
        if(i==tablesize){ // If we have probed all indices, the key is not found
            cout<<"Key "<<key<<" not found in the hash table."<<endl;
            return;
        }
    }
    cout<<"key not found"<<endl;
}
int main(){
    int hashTable[tablesize];
    for(int i=0;i<tablesize;i++){
        hashTable[i]=-1; // Initialize hash table with -1 (indicating empty)
    }
    insert(1,hashTable);
    insert(11,hashTable); // This will cause a collision with key 1 
    insert(2,hashTable);
    display(hashTable);         
}