//problem link- https://www.geeksforgeeks.org/dsa/check-whether-k-th-bit-set-not/
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // Brute Force: Convert to binary string - O(logN)
    bool checkKthBitBrute(int n, int k) {
        string binary = "";

        while (n > 0) {
            binary += (n % 2 ? '1' : '0');
            n /= 2;
        }

        if (k >= binary.size()) return false;

        return binary[k] == '1';
    }

    // Optimal: Bit Manipulation - O(1)
    bool checkKthBitOptimal(int n, int k) { return ((n >> k) & 1); }
};

int main() {
    Solution obj;

    int n = 13;
    int k = 2;

    cout << "Brute Force : ";
    cout << (obj.checkKthBitBrute(n, k) ? "Set" : "Not Set") << endl;

    cout << "Optimal     : ";
    cout << (obj.checkKthBitOptimal(n, k) ? "Set" : "Not Set") << endl;

    return 0;
}