#include <iostream>
using namespace std;
int arr[10]={1,2,3,4,5,6,7,8,9,10};
int arr_size=sizeof(arr)/sizeof(arr[0]);

void insertionsort(){
    for(int i=1;i<arr_size;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}