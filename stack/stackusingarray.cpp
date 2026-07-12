#include <bits/stdc++.h>
using namespace std;

class Stack {
    vector<int> v;

   public:
    void push(int val) { v.push_back(val); }

    void pop() { v.pop_back(); }

    int top() { return v[v.size() - 1]; }

    bool empty() { return v.size() == 0; }
};

int main() {
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);

    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
    return 0;
}