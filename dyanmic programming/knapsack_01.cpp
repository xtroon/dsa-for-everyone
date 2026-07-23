#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//  0/1 Knapsack Problem (2D DP)

// 1. Brute Force (Pure Recursion)
// tc: O(2^N) sc: O(N)
int knapsackBrute(int index, int capacity, const vector<int>& weight, const vector<int>& value) {
    if (index == 0) {
        if (weight[0] <= capacity) return value[0];
        return 0;
    }

    int exclude = knapsackBrute(index - 1, capacity, weight, value);

    int include = 0;
    if (weight[index] <= capacity) {
        include = value[index] + knapsackBrute(index - 1, capacity - weight[index], weight, value);
    }

    return max(include, exclude);
}

// 2. Top-Down Approach (Recursion + Memoization)
// tc: O(N * Capacity) sc: O(N * Capacity)
int knapsackMemo(int index, int capacity, const vector<int>& weight, const vector<int>& value, vector<vector<int>>& dp) {
    
    if (index == 0) {
        if (weight[0] <= capacity) return value[0];
        return 0;
    }

    if (dp[index][capacity] != -1) {
        return dp[index][capacity];
    }

    int exclude = knapsackMemo(index - 1, capacity, weight, value, dp);

    int include = 0;
    if (weight[index] <= capacity) {
        include = value[index] + knapsackMemo(index - 1, capacity - weight[index], weight, value, dp);
    }

    return dp[index][capacity] = max(include, exclude);
}

// 3. Bottom-Up Approach (Tabulation)
// tc: O(N * Capacity) sc: O(N * Capacity)
int knapsackTabulation(int n, int maxCapacity, const vector<int>& weight, const vector<int>& value) {
    
    vector<vector<int>> dp(n, vector<int>(maxCapacity + 1, 0));
    for (int w = weight[0]; w <= maxCapacity; w++) {
        dp[0][w] = value[0];
    }

    for (int index = 1; index < n; index++) {
        for (int cap = 0; cap <= maxCapacity; cap++) {
            int exclude = dp[index - 1][cap];
            int include = 0;
            if (weight[index] <= cap) {
                include = value[index] + dp[index - 1][cap - weight[index]];
            }
            dp[index][cap] = max(include, exclude);
        }
    }

    return dp[n - 1][maxCapacity];
}

int main() {
    vector<int> weight = {1, 2, 4, 5};
    vector<int> value = {5, 4, 8, 6};
    int maxCapacity = 5;
    int n = weight.size();

    cout << "--- 0/1 Knapsack Problem ---" << endl;

    vector<vector<int>> dp(n, vector<int>(maxCapacity + 1, -1));
    cout << "1. Brute Force (Recursion): " << knapsackBrute(n - 1, maxCapacity, weight, value) << endl;
    cout << "2. Memoization (Top-Down): " << knapsackMemo(n - 1, maxCapacity, weight, value, dp) << endl;
    cout << "3. Tabulation (Bottom-Up): " << knapsackTabulation(n, maxCapacity, weight, value) << endl;

    return 0;
}
