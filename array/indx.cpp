// problem link- https://www.geeksforgeeks.org/problems/find-minimum-and-maximum-element-in-an-array4428/1
#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[5] = {11, 200, 62, 4, 70}, mini, maxi;
    mini = arr[0];
    maxi = arr[0];
    for (int i = 0; i < 4; i++) {
        mini = min(arr[i], mini);
        maxi = max(arr[i], maxi);
    }
    cout << mini << " " << maxi << endl;
}