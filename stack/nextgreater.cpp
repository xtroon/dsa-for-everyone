#include <bits/stdc++.h>
using namespace std;
int main() {
    // stock prices
    vector<int> arr = {5, 1, 4, 2, 3};

    // soluiton
    vector<int> ans(arr.size(), 0);
    stack<int> s;

    for (int i = arr.size() - 1; i >= 0; i--) {
        while (!s.empty() && arr[i] > s.top()) s.pop();

        if (s.empty())
            ans[i] = -1;
        else
            ans[i] = s.top();
        s.push(arr[i]);
    }

    for (int val : ans) {
        cout << val << " ";
    }
    return 0;
}