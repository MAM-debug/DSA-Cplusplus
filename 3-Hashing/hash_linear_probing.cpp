#include <iostream>
using namespace std;

int hashfunction(int key,int tablesize){
    return key % tablesize;
}

void linearprob(int key,int tablesize,int hashtable[]){
    int hashindex=hashfunction(key,tablesize);
    while(hashtable[hashindex] != -1){
        cout<<"sorry this place is full"<<endl;
        hashindex=(hashindex+1)%tablesize;
    }
    hashtable[hashindex]=key;
    cout<<"key:"<<key<<" is at index:"<<hashindex<<endl;
}

int main(){
    int key[]={8,15,22,29,36};
    int tablesize=7;
    int hashtable[7];
    for(int i=0;i<tablesize;i++){
        hashtable[i]=-1;
    }
    for(int i=0;i<5;i++){
        linearprob(key[i],tablesize,hashtable);
    }
    return 0;
}
