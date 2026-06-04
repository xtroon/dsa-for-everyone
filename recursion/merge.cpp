#include<bits/stdc++.h>
using namespace std;

void merge(int *arr, int s, int e){

    int m = (s+e)/2;
    int L1 = m-s+1;
    int L2 = e-m;

    int arr1[L1];
    int arr2[L2];

    //copy values
    int k = s;
    for(int i=0; i<L1;i++){
        arr1[i] = arr[k++];
    }
    k = m+1;
    for(int i=0; i<L2;i++){
        arr2[i] = arr[k++];
    }

    // mergin sorted arrays
    int i=0,j=0;
    k=s;
    while(i<L1 && j<L2){
        if(arr1[i]<arr2[j]) arr[k++] = arr1[i++];
        else arr[k++] = arr2[j++];
    }

    while(i<L1){
        arr[k++] = arr1[i++];
    }
    while(j<L2){
        arr[k++] = arr2[j++];
    }

}

void mergeSort(int *arr, int s, int e){
    if(s>=e) return;
    int m = (s+e)/2;

    // left ko sort
    mergeSort(arr,s,m);
    //right ko sort
    mergeSort(arr,m+1,e);

    //merging both
    merge(arr,s,e);
    
}

int main() {
    int arr[] = {2,43,12,64,23,76,12,12,2,0};
    int size = sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr,0,size-1);
    for(int i=0; i<size; i++){
        cout << arr[i] << " ";
    }
    return 0;
}