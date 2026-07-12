#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // XOR from 1 to n
    int xorTillN(int n) {
        if (n % 4 == 0) return n;
        if (n % 4 == 1) return 1;
        if (n % 4 == 2) return n + 1;

        return 0;
    }

    // XOR from l to r
    int findXOR(int l, int r) { return xorTillN(r) ^ xorTillN(l - 1); }
};

int main() {
    Solution obj;

    int l, r;

    cout << "Enter l and r: ";
    cin >> l >> r;

    cout << "XOR from " << l << " to " << r << " = " << obj.findXOR(l, r) << endl;

    return 0;
}