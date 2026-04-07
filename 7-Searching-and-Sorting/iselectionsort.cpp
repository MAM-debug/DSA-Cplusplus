#include <iostream>
using namespace std;
int arr[] = {64, 25, 12, 22, 11};
int arr_size = sizeof(arr)/sizeof(arr[0]);

void selectionsort(){
    for(int i=0;i<arr_size-1;i++){
        int min_idx=i;
        bool swapped=false;
        for(int j=i+1;j<arr_size;j++){
            if(arr[j]<arr[min_idx]){
                min_idx=j;
                swapped=true;
            }
        }
        if(swapped==false){
            break;
        
        }

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