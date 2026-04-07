#include <iostream>
using namespace std;

int arr[] = {5, 2, 9, 1, 5, 6};
int arr_size = sizeof(arr) / sizeof(arr[0]);

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
        if(!swapped){
            break;
        }
    }

}
void display(){
    bubblesort();
    for(int i=0;i<arr_size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    cout<<"Before sorting: ";
    for(int i=0;i<arr_size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"After sorting: ";
    display();
    return 0;
}


