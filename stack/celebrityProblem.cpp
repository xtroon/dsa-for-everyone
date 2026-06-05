// everyone knows bro, but bro knows no one  

#include <bits/stdc++.h>
using namespace std;

class Solution {
    stack<int> st;
public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        for(int i=0; i<n; i++) st.push(i);

        while(st.size() > 1){
            int i  = st.top();
            st.pop();

            int j = st.top();
            st.pop();

            if(mat[i][j] == 1) st.push(j);
            else st.push(i);
        }

        int celeb = st.top();
        for(int i=0; i<n; i++){
            if(i == celeb) continue;

            if(mat[i][celeb] == 0 ||  mat[celeb][i] == 1){
                return -1;
            }
        }
        return celeb;
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