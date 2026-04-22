#include <iostream>
using namespace std;

int arr[]={10,7,8,9,1,5};

int partition(int low,int high){
    int pivot=arr[low];
    int p=low+1;
    int q=high;
    while(p<=q){
        while(p<=high && arr[p]<=pivot) //equal paai agai chlta rehega
        {
            p++;
        }
        while(q>=low && arr[q]>pivot){//equal paai rukjaega
            q--;
        }
        if(p<q){
            swap(arr[p],arr[q]);   
        }

    
}
    swap(arr[low],arr[q]);
    return q;
}
void quicksort(int low,int high){
    if(low<high){
        int pi=partition(low,high);
        quicksort(low,pi-1);
        quicksort(pi+1,high);
    }
}
