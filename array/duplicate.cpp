#include <iostream>
using namespace std;

// one approach is to find sum of array elements then substract sum from 0 to n-1;
// https://www.naukri.com/code360/problems/duplicate-in-array_893397?source=youtube&campaign=love_babbar_codestudio1&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio1&leftPanelTabValue=SUBMISSION

int duplicate(int arr[], int n) {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = ans ^ arr[i] ^ i;  // xoring all and xoring 1-[n-1]
    }
    return ans;
}

int main() {
    int arr[] = {1, 5, 3, 4, 1, 2};
    cout << duplicate(arr, 6);

    return 0;
}