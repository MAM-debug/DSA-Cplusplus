#include <iostream>
using namespace std;

// divide and conquer approach

// ✅ STEP 1 - merge function (combines two sorted halves)
void merge(int arr[], int start, int mid, int end) {
    int n1=mid-start+1; // size of left half
    int n2= end-mid;//size of right half
    int left[n1], right[n2];
    for (int i=0;i<n1;i++) {
        left[i]=arr[start+i];
    }
    for (int j=0;j<n2;j++){
        right[j]=arr[mid+1+j];
    }
    int i=0,j=0,k=start;
    while(i<n1 && j<n2){
        if(left[i]<=right[j]){
            arr[k]=left[i];
            i++;
        }
        else{
            arr[k]=right[j];
            j++;
        }
       
        k++;
        
    }
    while(i<n1){
        arr[k]=left[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=right[j];
        j++;
        k++;
    }



}

// ✅ STEP 2 - mergeSort function (does the splitting)
void mergeSort(int arr[], int start, int end) {
    
    if (start >= end) return;
    int mid = start + (end - start) / 2;

    mergeSort(arr, start, mid);       // sort left half
    mergeSort(arr, mid + 1, end);     // sort right half
    merge(arr, start, mid, end);      // merge both halv

}
int main() {
    int arr[]={38,33,27,23,44,24,42};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"Original array: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    mergeSort(arr,0,n-1);
    cout<<"Sorted array: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }



}