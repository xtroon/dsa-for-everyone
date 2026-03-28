#include<bits/stdc++.h>
using namespace std;
int main() {
    //stock prices
    vector<int>arr = {4, 8, 5, 2, 25};

    //soluiton
    vector<int> ans(arr.size(), 0);
    stack<int> st;

    for(int i=arr.size()-1; i>=0; i--){

        while(!st.empty() && arr[i]<st.top()) st.pop();

        if(st.empty()) ans[i] = -1;
        else ans[i] = st.top();

        st.push(arr[i]);
    }

    for(int val: ans){
        cout << val << " ";
    }
    return 0;
}