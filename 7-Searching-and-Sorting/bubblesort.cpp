#include <iostream>
using namespace std;

int arr[]={5, 1, 4, 2, 8};
int arr_size=sizeof(arr)/sizeof(arr[0]);

void display(){
    for(int i=0;i<arr_size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void bubblesort(){
    bool swapped;
    for (int i=0;i<arr_size-1;i++){
        swapped=false;
        for (int j=0;j<arr_size-i-1;j++){ //minus -i-1 because if only -i then it will compare with arr[5] which is out of range.
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped=true;
            }
        }  // ← End of j loop HERE
        
        // ← Move the check HERE (outside j loop)
        if(!swapped){
            break;  // If no swaps happened, array is sorted!
        }
    }
}

int main(){
    cout<<"Before sorting: ";
    display();
    bubblesort();
    cout<<"After sorting: ";
    display();
    return 0;
}


