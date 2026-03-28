#include<bits/stdc++.h>
using namespace std;

int gcd(int n1, int n2){
    int mini = min(n1,n2);
    while(mini){
        if((n1%mini==0)&& (n2%mini==0)){
            return mini;
        }
        mini--;
    }
}

int main() {
    int n1,n2;
    cin >> n1 >> n2;
    cout << gcd(n1,n2);
    return 0;
}