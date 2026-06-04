#include<bits/stdc++.h>
using namespace std;

int summ(int *arr , int size){
    if(size==0) return 0;
    if(size==1) return arr[0];
    int sum = arr[0] + summ(arr+1,sum-1);
    return sum;
}

int main() {
    int arr[] = {1,8,4,3};
    int size = sizeof(arr)/sizeof(arr[0]);
    int ans = summ(arr,size);
    cout << ans<< endl;
    return 0;
}