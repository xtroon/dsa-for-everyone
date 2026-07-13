// problem link- https://www.geeksforgeeks.org/problems/reverse-an-array/1
#include <bits/stdc++.h>
using namespace std;

void print(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void reverse(int arr[], int n) {
    int temp;
    for (int i = 0; i < n / 2; i++) {
        temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
}

int main() {
    int arr[6] = {11, 200, 62, 4, 19, 70};
    print(arr, 6);
    reverse(arr, 6);
    print(arr, 6);
}