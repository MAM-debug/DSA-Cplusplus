#include <iostream>
using namespace std;
int table_size=10;

int hash_function(int key){
    return key%table_size;
}
void insert(int hashtable[],int key){
    int index=hash_function(key);
    if(hashtable[index]!=-1){
        cout<<"collision occured for key: "<<key<<" at index: "<<index<<endl;
        return; 
    }
    hashtable[index]=key;
}
void search(int hashtable[], int key){
    int index=hash_function(key);
    if(hashtable[index]==key){
        cout<<"key found at index: "<<index<<endl;
    }
    else{
        cout<<"key not found in the hash table"<<endl;
    }
}
void display(int hashtable[]){
    for(int i=0;i<table_size;i++){
        if(hashtable[i]!=-1){
            cout<<"index: "<<i<<" key: "<<hashtable[i]<<endl;
        }
    }
}
int main(){
    int hashtable[table_size];
    for(int i=0;i<table_size;i++){
        hashtable[i]=-1;
    }
    insert(hashtable,10);
    insert(hashtable,20);
    insert(hashtable,30);
    insert(hashtable,40);
    search(hashtable,20);
    search(hashtable,25);
    display(hashtable);
}   
