#include<bits/stdc++.h>
using namespace std;
int main() {

    vector<int>arr = {3, 1, 0, 8, 6};

    vector<int> ans(arr.size(), 0);
    stack<int> st;

    for(int i=0; i< arr.size(); i++){
        
        while(!st.empty() && arr[i] > st.top()) st.pop();

        if(st.empty()) ans[i] = -1;
        else ans[i] = st.top();

        st.push(arr[i]);
    }

    for(int val: ans){
        cout << val << " ";
    }



    return 0;
}