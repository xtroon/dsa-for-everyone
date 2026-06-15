#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Better
    int countSetBitsBetter(int n) {

        int cnt = 0;

        while (n > 0) {
            cnt += (n & 1);
            n >>= 1;
        }

        return cnt;
    }

    // Optimal (Brian Kernighan's Algorithm)
    int countSetBitsOptimal(int n) {

        int cnt = 0;

        while (n > 0) {
            n = n & (n - 1);
            cnt++;
        }

        return cnt;
    }
};

int main() {

    Solution obj;

    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "Better      : "
         << obj.countSetBitsBetter(n) << endl;

    cout << "Optimal     : "
         << obj.countSetBitsOptimal(n) << endl;

    return 0;
}