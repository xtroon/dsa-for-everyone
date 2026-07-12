#include <bits/stdc++.h>
using namespace std;

string postfixToInfix(string s) {
    stack<string> st;

    for (char ch : s) {
        if (isalnum(ch)) {
            st.push(string(1, ch));
        } else {
            string op2 = st.top();
            st.pop();
            string op1 = st.top();
            st.pop();

            st.push("(" + op1 + ch + op2 + ")");
        }
    }

    return st.top();
}

int main() {
    string s = "ab+c*";  // Hardcoded postfix expression

    cout << "Postfix : " << s << endl;
    cout << "Infix   : " << postfixToInfix(s) << endl;

    return 0;
}