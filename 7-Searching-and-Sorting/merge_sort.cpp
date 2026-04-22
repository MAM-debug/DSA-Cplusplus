#include <iostream>
using namespace std;

void merge(int arr[],int l,int mid,int r){
    int n1 = mid - l + 1;
    int n2 = r - mid;

    int arr1[n1], arr2[n2];

    for(int i=0;i<n1;i++){
        arr1[i] = arr[l+i];
    }
    for(int j=0;j<n2;j++){
        arr2[j] = arr[mid+1+j];
    }

    int i=0, j=0, k=l;

    while(i<n1 && j<n2){
        if(arr1[i] < arr2[j]){
            arr[k] = arr1[i];
            i++;
        }
        else{
            arr[k] = arr2[j];
            j++;
        }
        k++;
    }

    while(i<n1){
        arr[k] = arr1[i];
        i++;
        k++;
    }

    while(j<n2){
        arr[k] = arr2[j];
        j++;
        k++;
    }
}

void mergesort(int arr[],int l,int r){
    if(l<r){
        int mid = (l+r)/2;
        mergesort(arr,l,mid);
        mergesort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
}

int main(){
    int arr[]={38,27,43,3,9,82,10};
    int n=sizeof(arr)/sizeof(arr[0]);

    mergesort(arr,0,n-1);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}