#include <iostream>
using namespace std;
int arr[10]={1,2,3,4,5,6,7,8,9,10};
int arr_size=sizeof(arr)/sizeof(arr[0]);

int linearsearch(int key,int n){
    if(n>=arr_size){
        return -1; // Key not found
    }
    if(arr[n]==key){
        return n;
    }
    return linearsearch(key,n+1);

}
int main() {
    cout<<"enter what key you want to search: ";
    int key;
    cin>>key;
    int result=linearsearch(key,0);
    if(result==-1){
        cout<<"key not found in the array"<<endl;
    }
    else{
        cout<<"key found at index: "<<result<<endl;
    }
}