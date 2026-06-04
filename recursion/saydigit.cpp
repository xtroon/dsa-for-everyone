#include<bits/stdc++.h>
using namespace std;

void saydig(int n, string arr[]){
    if(n==0) return;
    int digit = n%10;
    n=n/10;
    saydig(n,arr);
    cout << arr[digit] << " ";
}

int main() {
    int n;
    cin >> n;
    string arr[] = {"zero", "one","two", "three", "four", "five", "six","seven", "eight", "nine"};
    saydig(n,arr);
    return 0;
}