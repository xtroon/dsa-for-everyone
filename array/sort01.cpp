//problem link- https://www.geeksforgeeks.org/problems/segregate-0s-and-1s5106/1

#include <iostream>
using namespace std;

void print(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void sort(int arr[], int n) {
    int start = 0, last = n - 1;
    while (start < last) {
        while (arr[start] == 0 && start < last) {
            start++;
        }
        while (arr[last] == 1 && start < last) {
            last--;
        }
        if (start < last) {
            swap(arr[start], arr[last]);
            start++;
            last--;
        }
    }
}

int main() {
    int arr[] = {1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 0};
    sort(arr, 11);
    print(arr, 11);

    return 0;
}