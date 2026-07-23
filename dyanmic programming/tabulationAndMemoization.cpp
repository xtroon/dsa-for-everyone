#include <bits/stdc++.h>

using namespace std;

// DP on Fibonacci Numbers

// 1. Top-Down Approach (Recursion + Memoization)
// tc: O(N) sc: O(2N)

int fibMemoization(int n, vector<int>& dp) {
    if (n <= 1) {
        return n;
    }

    if (dp[n] != -1) {
        return dp[n];
    }

    dp[n] = fibMemoization(n - 1, dp) + fibMemoization(n - 2, dp);
    return dp[n];
}

// 2. Bottom-Up Approach (Tabulation)
// tc: O(N) sc O(N)
int fibTabulation(int n) {
    if (n <= 1) return n;
    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;
    
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    
    return dp[n];
}

// 3. Space Optimization Method
// tc: O(N) sc: O(1)
int fibSpaceOptimized(int n) {
    if (n <= 1) return n;
    
    int prev2 = 0;
    int prev1 = 1;
    int curr = 0;
    
    for (int i = 2; i <= n; i++) {
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    
    return prev1;
}

int main() {
    int n = 10;
    
    cout << "--- Finding " << n << "th Fibonacci Number ---" << endl;
    
    vector<int> dp(n + 1, -1);
    cout << "1. Memoization (Top-Down): " << fibMemoization(n, dp) << endl;
    cout << "2. Tabulation (Bottom-Up): " << fibTabulation(n) << endl;
    cout << "3. Space Optimization: " << fibSpaceOptimized(n) << endl;
    return 0;
}
