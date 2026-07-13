// problem link- https://www.geeksforgeeks.org/problems/sum-of-two-numbers-represented-as-arrays3110/1
#include <bits/stdc++.h>
using namespace std;

vector<int> findArraySum(vector<int>& a, int n, vector<int>& b, int m) {
    vector<int> c;
    int i = n - 1, j = m - 1, carry = 0;

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum = sum + a[i];
        if (j >= 0) sum = sum + b[j];
        i--, j--;
        c.push_back(sum % 10);
        carry = sum / 10;
    }

    reverse(c.begin(), c.end());
    return c;
}

int main() {
    vector<int> a = {1, 2, 3, 4};
    vector<int> b = {6};
    int n = a.size();
    int m = b.size();

    vector<int> c = findArraySum(a, n, b, m);

    for (int x : c) cout << x << " ";
    cout << endl;

    return 0;
}