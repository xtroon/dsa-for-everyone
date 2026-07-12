#include <bits/stdc++.h>
using namespace std;

class MyStack {
   public:
    queue<int> q1;
    queue<int> q2;
    MyStack() {}

    void push(int x) {
        if (q1.empty()) {
            q1.push(x);
        } else {
            while (!q1.empty()) {
                q2.push(q1.front());
                q1.pop();
            }
            q1.push(x);
            while (!q2.empty()) {
                q1.push(q2.front());
                q2.pop();
            }
        }
    }

    int pop() {
        if (!q1.empty()) {
            int ans = q1.front();
            q1.pop();
            return ans;
        }
        return -1;
    }

    int top() { return q1.front(); }

    bool empty() { return q1.empty(); }
};

int main() {
    MyStack st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << st.top() << endl;  // 30 - top

    cout << st.pop() << endl;  // 30
    cout << st.top() << endl;  // 20

    cout << st.pop() << endl;  // 20

    cout << st.empty() << endl;  // 0 (false)

    cout << st.pop() << endl;  // 10

    cout << st.empty() << endl;  // 1 (true)

    return 0;
}