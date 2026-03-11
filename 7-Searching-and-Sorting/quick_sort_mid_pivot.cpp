#include <iostream>
using namespace std;

int arr[] = {38,33,27,23,44,24,42};

void exchange(int a, int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

int splitting(int left, int right){
    int mid = (left + right) / 2;
    exchange(mid, right); // middle element ko pivot bana diya
    int pivot = arr[right];
    int i = left - 1;

    for(int j = left; j < right; j++){
        if(arr[j] < pivot){
            i++;
            exchange(i, j);
        }
    }
    exchange(i+1, right);
    return i+1;
}

void quicksort(int left, int right){
    if(left < right){
        int pivotIndex = splitting(left, right);
        quicksort(left, pivotIndex-1);
        quicksort(pivotIndex+1, right);
    }
}

int main(){
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Original array: ";
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    quicksort(0, n-1);

    cout << "Sorted array: ";
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

