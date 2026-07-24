#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 1. Memoization (Top-Down)
    // tc - O(N*M)  sc - O(N*M) + O(N+M) recursion stack space
    int lcsUtil(string &s1, string &s2, int ind1, int ind2, vector<vector<int>> &dp) {
        if (ind1 < 0 || ind2 < 0)
            return 0;

        if (dp[ind1][ind2] != -1)
            return dp[ind1][ind2];

        if (s1[ind1] == s2[ind2])
            return dp[ind1][ind2] = 1 + lcsUtil(s1, s2, ind1 - 1, ind2 - 1, dp);

        return dp[ind1][ind2] = max(lcsUtil(s1, s2, ind1 - 1, ind2, dp), lcsUtil(s1, s2, ind1, ind2 - 1, dp));
    }

    int lcsMemo(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return lcsUtil(s1, s2, n - 1, m - 1, dp);
    }

    // 2. Tabulation (Bottom-Up)
    // tc - O(N*M)  sc - O(N*M)
    int lcsTabulation(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n][m];
    }

    // 3. Space Optimization
    // tc - O(N*M)  sc - O(M)
    int lcsSpaceOptimized(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<int> prev(m + 1, 0), cur(m + 1, 0);

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1])
                    cur[j] = 1 + prev[j - 1];
                else
                    cur[j] = max(prev[j], cur[j - 1]);
            }
            prev = cur;
        }
        return prev[m];
    }
};

int main() {
    string s1 = "adebc";
    string s2 = "dcadb";

    Solution obj;

    cout << "1. Memoization (Top-Down): " 
         << obj.lcsMemo(s1, s2) << endl;

    cout << "2. Tabulation (Bottom-Up): " 
         << obj.lcsTabulation(s1, s2) << endl;

    cout << "3. Space Optimization: " 
         << obj.lcsSpaceOptimized(s1, s2) << endl;

    return 0;
}
