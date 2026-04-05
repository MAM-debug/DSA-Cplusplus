#include <iostream>
using namespace std;

int tablesize=10; // Hash table of size 10
int hashfunction (int key)
{
    return key % tablesize; // Simple hash function
};
void insert(int key,int hashtable[]){

    int index=hashfunction(key);
    int startindex=0; // Store the starting index to detect loop
    while(hashtable[index]!=-1 && hashtable[index]!=-2){ // Linear probing to resolve collision
        cout<<"Collision occurred for key "<<key<<" at index "<<index<<endl;
        index=(index+1)%tablesize; // Move to the next index
        startindex++; // Increment the start index to detect loop
        if(startindex==tablesize){ // If we have looped back to the start index, the table is full
            cout<<"Hash table is full, cannot insert key "<<key<<endl;
            return;
        }
    }
    hashtable[index]=key; // Insert the key at the found index
}
void display(int hashtable[]){
    for(int i=0;i<tablesize;i++){
        cout<<i<<" : "<<hashtable[i]<<endl;
    }
}
void delkey(int key,int hashtable[]){
    int index=hashfunction(key);
    int startindex=index; // Store the starting index to detect loop
    while(hashtable[index]!=-1){ // Linear probing to find the key
        if(hashtable[index]==key){
            hashtable[index]=-2; // Mark as deleted
            return;
        }
        index=(index+1)%tablesize; // Move to the next index
        if(index==startindex){ // If we have looped back to the start index, the key is not found
            cout<<"Key not found, cannot delete key "<<key<<endl;
            return;
        }
    }
}
int search(int key,int hashtable[]){
    int index=hashfunction(key);
    int startindex=index; // Store the starting index to detect loop
    while(hashtable[index]!=-1){
        if(hashtable[index]==key){
            cout<<"key found at index "<<index<<endl;
            return;
        }
        index=(index+1)%tablesize; // Move to the next index
        if(index==startindex){ // If we have looped back to the start index, the key is not found
            cout<<"key not found"<<endl;
            return;
        }
    }
    cout<<"key not found"<<endl;
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