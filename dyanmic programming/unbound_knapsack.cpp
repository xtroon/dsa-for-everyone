#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 1. Memoization (Top-Down)
    // tc - O(N*W) sc - O(N*W)

    int knapsackUtil(vector<int>& wt, vector<int>& val, int ind, int W, vector<vector<int>>& dp) {
        if (ind == 0) {
            return (W / wt[0]) * val[0];
        }

        if (dp[ind][W] != -1)
            return dp[ind][W];

        int notTaken = knapsackUtil(wt, val, ind - 1, W, dp);

        int taken = INT_MIN;
        if (wt[ind] <= W)
            taken = val[ind] + knapsackUtil(wt, val, ind, W - wt[ind], dp);

        return dp[ind][W] = max(notTaken, taken);
    }

    int unboundedKnapsackMemo(int n, int W, vector<int>& val, vector<int>& wt) {
        vector<vector<int>> dp(n, vector<int>(W + 1, -1));
        return knapsackUtil(wt, val, n - 1, W, dp);
    }

    // 2. Tabulation (Bottom-Up)
    // tc - O(N*W)  sc - O(N*W)

    int unboundedKnapsackTabulation(int n, int W, vector<int>& val, vector<int>& wt) {
        // Create a DP table where dp[i][j] represents max value using first i items and capacity j
        vector<vector<int>> dp(n, vector<int>(W + 1, 0));

        // Base condition: fill first row considering infinite supply of first item
        for (int i = wt[0]; i <= W; i++) {
            dp[0][i] = (i / wt[0]) * val[0];
        }

        for (int ind = 1; ind < n; ind++) {
            for (int cap = 0; cap <= W; cap++) {
                int notTaken = dp[ind - 1][cap];

                int taken = INT_MIN;
                if (wt[ind] <= cap)
                    taken = val[ind] + dp[ind][cap - wt[ind]];
                dp[ind][cap] = max(notTaken, taken);
            }
        }
        return dp[n - 1][W];
    }

    // 3. Space Optimization (1D DP Array)
    // tc - O(N*W)  sc - O(W)
    int unboundedKnapsackSpaceOptimized(int n, int W, vector<int>& val, vector<int>& wt) {
        vector<int> cur(W + 1, 0);

        for (int i = wt[0]; i <= W; i++) {
            cur[i] = (i / wt[0]) * val[0];
        }

        for (int ind = 1; ind < n; ind++) {
            for (int cap = 0; cap <= W; cap++) {
                int notTaken = cur[cap];

                int taken = INT_MIN;
                if (wt[ind] <= cap) {
                    taken = val[ind] + cur[cap - wt[ind]];
                }

                cur[cap] = max(notTaken, taken);
            }
        }
        return cur[W];
    }
};

int main() {
    vector<int> wt = {2, 4, 6};
    vector<int> val = {5, 11, 13};
    int W = 10;
    int n = wt.size();

    Solution obj;

    cout << "1. Memoization (Top-Down): " 
         << obj.unboundedKnapsackMemo(n, W, val, wt) << endl;

    cout << "2. Tabulation (Bottom-Up): " 
         << obj.unboundedKnapsackTabulation(n, W, val, wt) << endl;

    cout << "3. Space Optimization: " 
         << obj.unboundedKnapsackSpaceOptimized(n, W, val, wt) << endl;

    return 0;
}
