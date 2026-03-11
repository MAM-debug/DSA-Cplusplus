#include <iostream>
using namespace std;

int arr[] = {38,33,27,23,44,24,42};

void exchange(int a, int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

int splitting(int left, int right){
    int pivot = arr[right];
    int i = left - 1; // pointer for smaller elements

    for(int j = left; j < right; j++){ // pointer to traverse array
        if(arr[j] < pivot){
            i++;
            exchange(i, j);
        }
    }
    exchange(i+1, right);
    return i+1; // pivot index after partition
}

void quicksort(int left, int right){
    if(left < right){
        int pivotIndex = splitting(left, right);
        quicksort(left, pivotIndex-1); // sort left half
        quicksort(pivotIndex+1, right); // sort right half
    }
}

int main(){
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Original array: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    quicksort(0, n-1);

    cout << "Sorted array: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
