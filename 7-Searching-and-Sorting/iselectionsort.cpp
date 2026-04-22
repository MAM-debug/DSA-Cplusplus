#include <iostream>
using namespace std;

int arr[]={64, 34, 25, 12, 22, 11,90,66};
int arr_size=sizeof(arr)/sizeof(arr[0]);

void selectionsort(){
    for(int i=0;i<arr_size-1;i++){
        int min_index=i;
        for(int j=i+1;j<arr_size;j++){
            if(arr[j]<arr[min_index]){
                min_index=j;
            }
        }
        swap(arr[i],arr[min_index]);

    }
}