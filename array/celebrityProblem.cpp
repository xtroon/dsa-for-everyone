// everyone knows bro, but bro knows no one  

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<int> iKnow(n,0);
        vector<int> knowMe(n,0);

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i==j) continue;
                if(mat[i][j] == 1){
                    iKnow[i]++;
                    knowMe[j]++;
                }
            }
        }

        for(int i=0; i<n; i++){
            if(knowMe[i] == n-1 && iKnow[i]==0) return i;
        }
        return -1;
    }
};

int main() {
    vector<vector<int>> mat = {
        {1, 1, 0},
        {0, 1, 0},
        {0, 1, 1}
    };

    Solution obj;
    cout << obj.celebrity(mat) << endl;

    return 0;
}