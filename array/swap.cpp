#include <bits/stdc++.h>
using namespace std;

void swap(int arr[], int n) {
    for (int i = 0; i < n - 1; i += 2) {
        swap(arr[i], arr[i + 1]);
    }
}

int main() {
    int n, arr[100];
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    swap(arr, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
