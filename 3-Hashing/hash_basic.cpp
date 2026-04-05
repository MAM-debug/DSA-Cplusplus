#include <iostream>
using namespace std;
int tablesize=10; // Hash table of size 10

int hashfunction (int key)
{
    return key % tablesize; // Simple hash function
};

void insert(int key,int hashTable[]){
    int index=hashfunction(key);
    if(hashTable[index]!=-1){
        cout<<"Collision occurred for key "<<key<<" at index "<<index<<endl;
        return;
    }
    hashTable[index]=key;
}
void display(int hashTable[]){
    for(int i=0;i<tablesize;i++){
        cout<<i<<" : "<<hashTable[i]<<endl;
    }
}
void deletekey(int key,int hashTable[]){
    int index=hashfunction(key);
    hashTable[index]=-1; // Mark as deleted
}
void search(int key,int hashtable[]){
    int index=hashfunction(key);
    if(hashtable[index]==key){
        cout<<"key found at index"<<index<<endl;
        
    }else{
        cout<<"key not found"<<endl;
    }
}
int main(){
    int hashtable[tablesize];
    for(int i=0;i<tablesize;i++){  
        hashtable[i]=-1; // Initialize hash table with -1 (indicating empty)
    }
    insert(1,hashtable);
    insert(11,hashtable); // This will cause a collision with key 1 
    insert(2,hashtable);
    display(hashtable);         
}
