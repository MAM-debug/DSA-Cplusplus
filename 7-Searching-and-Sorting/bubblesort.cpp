#include<iostream>
using namespace std;
int arr[]={64, 34, 25, 12, 22, 11,90,66};
int arr_size=sizeof(arr)/sizeof(arr[0]);
void bubblesort(){
    bool swapped;
    for(int i=0;i<arr_size-1;i++){
        swapped=false;
        for(int j=0;j<arr_size-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped=true;
            }
        }
        if(swapped==false){
            break;
        }
    }

}
int main(){
    cout<<"Unsorted array: ";
    for(int i=0;i<arr_size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    bubblesort();
    cout<<"Sorted array: ";
    for(int i=0;i<arr_size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<arr_size<<endl;
}


