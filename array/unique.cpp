//problem link- https://leetcode.com/problems/single-number/
#include <iostream>
using namespace std;

int findUnique(int arr[], int n) {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = ans ^ arr[i];
    }
    return ans;

    // int hashArr[100] = {0};
    // for(int i =0; i<n ; i++){
    //     hashArr[arr[i]]++;
    // }
    // for(int i=0 ; i<n; i++){
    //     if(hashArr[arr[i]] == 1){
    //        return arr[i];
    //     }
    // }
}

int main() {
    int arr[] = {81, 2, 3, 81, 2, 1, 3};
    cout << findUnique(arr, 7);
    return 0;
}