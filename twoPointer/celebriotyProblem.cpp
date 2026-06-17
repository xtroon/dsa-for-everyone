// everyone knows bro, but bro knows no one  

#include <bits/stdc++.h>
using namespace std;

class Solution {
    stack<int> st;
public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        int top = 0, down = n-1;
        while(top < down){

            if(mat[top][down] == 1) top++; //top know down, it cant
            else if(mat[down][top] == 1) down--;  //down know top, it cant

            //both dont know each other, both can celebrity
            else{ 
                top++;
                down--;
            }
        }

        if(top > down) return -1; // no celeb found 

        //check if selected is celeb
        for(int i=0; i<n; i++){
            if(i==top) continue;

            if(mat[i][top] == 0 || mat[top][i] == 1) return -1;
        }
        return top;
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