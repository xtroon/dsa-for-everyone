#include <bits/stdc++.h>
using namespace std;

bool is_sorted(int *arr, int size) {
    if (size == 0 || size == 1) return true;

    if (arr[0] > arr[1])
        return false;
    else {
        return is_sorted(arr + 1, size - 1);
    }
}

int main() {
    int arr[] = {1, 3, 4, 8, 6, 8, 8, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    bool ans = is_sorted(arr, size);
    cout << ans << endl;
    return 0;
}