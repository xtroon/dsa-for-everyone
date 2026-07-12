#include <bits/stdc++.h>
using namespace std;

int main() {
    deque<int> q;

    q.push_back(1);
    q.push_back(2);
    q.push_back(3);

    q.push_front(4);

    cout << q.front() << " " << q.back() << endl;

    q.pop_back();

    cout << q.front() << " " << q.back() << endl;
    return 0;
}