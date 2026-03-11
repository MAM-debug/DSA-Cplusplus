#include <iostream>
using namespace std;

int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int arr_size = sizeof(arr) / sizeof(arr[0]);

void selectionsort(){
    for (int i=0;i<arr_size-1;i++){
        int min_index=i;
        for (int j=i+1;j<arr_size;j++){
            if(arr[j]<arr[min_index]){
                min_index=j;
            }
        }
        swap(arr[i],arr[min_index]);
    }
}   
int main(){
    cout<<"Before sorting: ";
    for(int i=0;i<arr_size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    selectionsort();
    cout<<"After sorting: ";
    for(int i=0;i<arr_size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
   