#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // brute 
    bool isPowerOfTwoBrute(int n) {

        if (n <= 0) return false;

        while (n % 2 == 0) {
            n /= 2;
        }

        return n == 1;
    }

    // optimal 
    bool isPowerOfTwoOptimal(int n) {
        return n > 0 && ((n & (n - 1)) == 0);
    }
};

int main() {

    Solution obj;

    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "Brute Force : "
         << (obj.isPowerOfTwoBrute(n) ? "True" : "False")
         << endl;

    cout << "Optimal     : "
         << (obj.isPowerOfTwoOptimal(n) ? "True" : "False")
         << endl;

    return 0;
}