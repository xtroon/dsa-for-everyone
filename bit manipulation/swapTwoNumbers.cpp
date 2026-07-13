#include <bits/stdc++.h>
using namespace std;

void swapXOR(int &a, int &b) {
    a ^= b;
    b ^= a;
    a ^= b;
}

int main() {
    int a = 5, b = 3;

    cout << a << " " << b << endl;
    swapXOR(a, b);
    cout << "After swap" << endl;
    cout << a << " " << b << endl;

    return 0;
}