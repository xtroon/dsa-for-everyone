#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int solve(vector<int>& bt) {
        sort(bt.begin(), bt.end());

        int waitTime = 0;
        int totTime = 0;

        for (int i = 0; i < bt.size(); i++) {
            waitTime += totTime;
            totTime += bt[i];
        }

        return waitTime / bt.size();
    }
};

int main() {
    Solution obj;

    vector<int> bt = {4, 3, 7, 1, 2};

    cout << obj.solve(bt) << endl;

    return 0;
}