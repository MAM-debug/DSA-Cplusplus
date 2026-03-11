#include <iostream>
using namespace std;
int arr[10]={1,2,3,4,5,6,7,8,9,10};
int arr_size=sizeof(arr)/sizeof(arr[0]);
int linearsearch(int key){
    for(int i=0;i<arr_size;i++){
        if(arr[i]==key){
            return i;
        }
    }
    return -1;

}

int main() {
    cout<<"enter what key you want to search: ";
    int key;
    cin>>key;
    int result=linearsearch(key);
    if(result==-1){
        cout<<"key not found in the array"<<endl;
    }
    else{
        cout<<"key found at index: "<<result<<endl;
    }
}
