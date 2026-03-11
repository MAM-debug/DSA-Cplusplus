#include <iostream>
using namespace std;

int hashfunction (int key,int tablesize)
{
    return key % tablesize;
}

void quadriticprob (int key,int tablesize,int hashtable[]){
    int original=hashfunction(key,tablesize);
    int hashindex=original;
    int i=0;
    while(hashtable[hashindex] != -1){
        cout<<"sorry this place is full"<<endl;
        i++;
        hashindex=(original+(i*i))%tablesize;
    }
    hashtable[hashindex]=key;
    cout<<"key:"<<key<<" is at index:"<<hashindex<<endl;
}
int main()
{
    int key[]={8,15,22,29,36};
    int tablesize=7;
    int hashtable[7];
    for(int i=0;i<tablesize;i++){
        hashtable[i]=-1;
    }
    for(int i=0;i<5;i++){
        quadriticprob(key[i],tablesize,hashtable);
    }
    return 0;
}