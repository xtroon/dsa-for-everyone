#include<bits/stdc++.h>
using namespace std;

class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        if(s1.empty()){
            s1.push(x);
        }else{
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            s1.push(x);
            while(!s2.empty()){
                s1.push(s2.top());
                s2.pop();
            }
        }
    }
    
    int pop() {
        if(!s1.empty()){
            int ans = s1.top();
            s1.pop();
            return ans;
        }
        return -1;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }
};

int main() {
    MyQueue qu;

    qu.push(10);
    qu.push(20);
    qu.push(30);

    cout << qu.peek() << endl;     // 10 - peek

    cout << qu.pop() << endl;     // 10
    cout << qu.peek() << endl;     // 20

    cout << qu.pop() << endl;     // 20

    cout << qu.empty() << endl;   // 0 (false)

    cout << qu.pop() << endl;     // 30

    cout << qu.empty() << endl;   // 1 (true)

    return 0;
}