#include <bits/stdc++.h>
using namespace std;

class Stack {
    list<int> ll;

   public:
    void push(int val) { ll.push_front(val); }

    void pop() { ll.pop_front(); }

    int top() { return ll.front(); }

    bool empty() { return ll.size() == 0; }
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