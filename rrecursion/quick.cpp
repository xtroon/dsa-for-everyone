#include<bits/stdc++.h>
using namespace std;

int partition(int *arr, int s, int e){

    // pivot 
    int p = arr[s];
    // count 
    int cnt = 0;
    for(int i=s+1; i<e; i++){
        if(arr[i]<=p){
            cnt++;
        }
    }
    int pivotIndex = s + cnt;

    swap(arr[s],arr[pivotIndex]);
    int i=s,j=e;
    while(i<pivotIndex && j>pivotIndex){
        while(arr[i]<=p){
            i++;
        }
        while(arr[j]>p){
            j--;
        }
        if(i < pivotIndex && j >pivotIndex){
            swap(arr[i++],arr[j--]);
        }
    }
    return pivotIndex;
 
}

void quicksort(int *arr, int s, int e){
    if(s>=e) return;

    // fimd partition index
    int p = partition(arr,s,e);

    // left side sort 
    quicksort(arr,s, p-1);
    // right side sort 
    quicksort(arr, p+1, e);
    
}

int main() {
    int arr[] = {2,43,12,64,23,76,12,12,2,0};
    int size = sizeof(arr)/sizeof(arr[0]);
    quicksort(arr,0,size-1);
    for(int i=0; i<size; i++){
        cout << arr[i] << " ";
    }
    return 0;
}