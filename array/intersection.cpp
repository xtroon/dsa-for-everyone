//problem link- https://www.naukri.com/code360/problems/intersection-of-2-arrays_1082149

#include <bits/stdc++.h>
using namespace std;

vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m) {
    int i = 0, j = 0;
    vector<int> ans;
    while (i < n && j < m) {
        if (arr1[i] < arr2[j]) {
            i++;
        } else if (arr1[i] == arr2[j]) {
            ans.push_back(arr1[i]);
            i++;
            j++;
        } else if (arr1[i] > arr2[j]) {
            j++;
        }
    }
    return ans;
}

int main() {
    vector<int> arr1 = {1, 2, 2, 2, 3, 4};
    vector<int> arr2 = {2, 2, 3, 3};
    findArrayIntersection(arr1, 6, arr2, 4);

    return 0;
}