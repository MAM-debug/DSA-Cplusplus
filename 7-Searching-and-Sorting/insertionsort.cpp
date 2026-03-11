#include <iostream>
using namespace std;

int arr[] = {3, 1, 4, 2, 5};
int arr_size = sizeof(arr) / sizeof(arr[0]);

void insertionsort(){
    for(int i=1; i< arr_size;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
int main(){
    cout<<"Before sorting: ";
    for(int i=0;i<arr_size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    insertionsort();
    cout<<"After sorting: ";
    for(int i=0;i<arr_size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}