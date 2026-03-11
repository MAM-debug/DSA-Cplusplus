#include <iostream>
using namespace std;

int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int arr_size = sizeof(arr) / sizeof(arr[0]);

int binarysearch(int key, int low, int high){
    while (low <=high){
        int mid=(low+high)/2;
        if(arr[mid]==key){
            return mid;
        }
        else if (arr[mid]>key){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return -1; // Key not found
}
int main(){
    int key;
    cout<<"enter what key you want to search: ";
    cin>>key;
    int result=binarysearch(key,0,arr_size-1);
    if(result==-1){
        cout<<"key not found in the array"<<endl;
    }
    else{
        cout<<"key found at index: "<<result<<endl;
    }
}