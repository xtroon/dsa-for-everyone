#include<bits/stdc++.h>
using namespace std;

void selectionsort(int *arr , int n){
    if( n == 0 || n==1) return;

    for(int i=0; i<n-1; i++){
        if(arr[0]>arr[i+1]){
            swap(arr[0],arr[i+1]);
        }
    }
    selectionsort(arr+1,n-1);
    
}

int main() {
    int arr[] = {2,4,8,1,5,9,7,36,52,13};
    int size = sizeof(arr)/sizeof(arr[0]);
    selectionsort(arr,size);
    for(int i=0; i<size; i++){
        cout << arr[i] << " ";
    }
    return 0;
}

//insertion, selection sort by rec.