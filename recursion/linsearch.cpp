#include<bits/stdc++.h>
using namespace std;

bool linearsearch(int *arr , int size, int k){
    if(size==0) return false;
    if(arr[0]==k) return true;
    else return linearsearch(arr+1, size-1, k);

}

int main() {
    int arr[] = {1,8,4,3};
    int size = sizeof(arr)/sizeof(arr[0]);
    int key = 5;
    bool ans = linearsearch(arr,size, key);
    cout << ans<< endl;
    return 0;
}