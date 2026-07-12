#include <bits/stdc++.h>
using namespace std;

int last(vector<int>& arr, int n, int k) {
    int s = 0, e = n - 1;
    int ans = -1;
    int mid = s + (e - s) / 2;
    while (s <= e) {
        if (arr[mid] == k) {
            ans = mid;
            s = mid + 1;
        } else if (arr[mid] < k) {
            s = mid + 1;
        } else if (arr[mid] > k) {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}
int first(vector<int>& arr, int n, int k) {
    int s = 0, e = n - 1;
    int ans = -1;
    int mid = s + (e - s) / 2;
    while (s <= e) {
        if (arr[mid] == k) {
            ans = mid;
            e = mid - 1;
        } else if (arr[mid] < k) {
            s = mid + 1;
        } else if (arr[mid] > k) {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k) {
    pair<int, int> p;
    p.first = first(arr, n, k);
    p.second = last(arr, n, k);
    return p;
}
int main() {
    vector<int> arr = {1, 7, 7, 7, 7, 56, 62, 84, 90, 90, 90};
    pair<int, int> ans = firstAndLastPosition(arr, 11, 7);
    cout << ans.first << " " << ans.second;

    return 0;
}