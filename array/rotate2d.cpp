#include <bits/stdc++.h>
using namespace std;

void rotateArray(vector<vector<int>> &arr) {
    int n = arr.size();

    // transpose matrix
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(arr[i][j], arr[j][i]);
        }
    }

    // reverse each row
    for (int i = 0; i < n; i++) {
        reverse(arr[i].begin(), arr[i].end());
    }
}

int main() {
    int n;
    if (!(cin >> n)) return 0;

    vector<vector<int>> arr(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    rotateArray(arr);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
