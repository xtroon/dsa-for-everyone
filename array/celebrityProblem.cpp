// everyone knows bro, but bro knows no one

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int Brutecelebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<int> iKnow(n, 0);
        vector<int> knowMe(n, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (mat[i][j] == 1) {
                    iKnow[i]++;
                    knowMe[j]++;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (knowMe[i] == n - 1 && iKnow[i] == 0) return i;
        }
        return -1;
    }

    int Efficientcelebrity(vector<vector<int>>& mat) {
        int n = mat.size();

        // find potential celebrity
        int candidate = 0;

        for (int i = 1; i < n; i++) {
            if (mat[candidate][i] == 1) {
                // candidate knows i
                // candidate can't be celebrity
                candidate = i;
            }
        }

        // Verify candidate
        for (int i = 0; i < n; i++) {
            if (i == candidate) continue;

            // candidate should know nobody
            // everybody should know candidate
            if (mat[candidate][i] == 1 || mat[i][candidate] == 0) {
                return -1;
            }
        }

        return candidate;
    }
};

int main() {
    vector<vector<int>> mat = {{1, 1, 0}, {0, 1, 0}, {0, 1, 1}};

    Solution obj;
    cout << obj.Brutecelebrity(mat) << endl;
    cout << obj.Efficientcelebrity(mat) << endl;

    return 0;
}