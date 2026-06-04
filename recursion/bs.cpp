#include<bits/stdc++.h>
using namespace std;

bool binarySearch(int *arr, int s, int e, int k){
    if(s>e) return false;
    int m = (s+e)/2;
    if(arr[m] < k){
        binarySearch(arr,m+1,e, k);
    }
    else if(arr[m] > k){
        binarySearch(arr, s , e-1, k);
    }
    else{
        return true;
    }
    
}

int main() {
    int arr[] = {2,4,6,8,14,20};
    int size = sizeof(arr)/sizeof(arr[0]);
    int key = 20;
    bool ans = binarySearch(arr,0,size-1, key);
    cout << ans<< endl;
    return 0;
}