#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 0/1 Knapsack Problem (2D DP)
// items[i][0] = weight (wt), items[i][1] = value (val)

// 1. Brute Force (Recursion)
// tc: O(2^N), sc: O(N)
int knapsackBrute(int ind, int W, const vector<vector<int>>& items) {
    if (ind == 0) {
        if (items[0][0] <= W) return items[0][1];
        return 0;
    }

    int exclude = knapsackBrute(ind - 1, W, items);
    int include = 0;
    if (items[ind][0] <= W) {
        include = items[ind][1] + knapsackBrute(ind - 1, W - items[ind][0], items);
    }

    return max(include, exclude);
}

// 2. Memoization (Top-Down)
// tc: O(N * W), sc: O(N * W)
int knapsackMemo(int ind, int W, const vector<vector<int>>& items, vector<vector<int>>& dp) {
    if (ind == 0) {
        if (items[0][0] <= W) return items[0][1];
        return 0;
    }

    if (dp[ind][W] != -1) return dp[ind][W];

    int exclude = knapsackMemo(ind - 1, W, items, dp);
    int include = 0;
    if (items[ind][0] <= W) {
        include = items[ind][1] + knapsackMemo(ind - 1, W - items[ind][0], items, dp);
    }

    return dp[ind][W] = max(include, exclude);
}

// 3. Tabulation (Bottom-Up - 1-based indexing)
// tc: O(N * W), sc: O(N * W)
int knapsackTabulation(int n, int W, const vector<vector<int>>& items) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int ind = 1; ind <= n; ind++) {
        int wt = items[ind - 1][0];
        int val = items[ind - 1][1];

        for (int w = 1; w <= W; w++) {
            int exclude = dp[ind - 1][w];
            int include = 0;
            if (wt <= w) {
                include = val + dp[ind - 1][w - wt];
            }
            dp[ind][w] = max(include, exclude);
        }
    }

    return dp[n][W];
}

int main() {
    // items[i] = {weight, value}
    vector<vector<int>> items = {
        {1, 5},
        {2, 4},
        {4, 8},
        {5, 6}
    };
    int W = 5;
    int n = items.size();

    cout << "--- 0/1 Knapsack Problem ---" << endl;

    vector<vector<int>> dp(n, vector<int>(W + 1, -1));
    cout << "1. Brute Force (Recursion): " << knapsackBrute(n - 1, W, items) << endl;
    cout << "2. Memoization (Top-Down): " << knapsackMemo(n - 1, W, items, dp) << endl;
    cout << "3. Tabulation (Bottom-Up): " << knapsackTabulation(n, W, items) << endl;

    return 0;
}
