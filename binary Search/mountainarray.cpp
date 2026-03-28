#include <iostream>
#include<vector>
using namespace std;

int montainArray(vector<int>& arr, int n){
    int s = 0, e = arr.size() -1;
    int mid = s +(e-s)/2;
    while(s<e){
        if(arr[mid] < arr[mid+1]){
            s = mid+1;
        }
        else{
            e = mid;
        }
    mid = s +(e-s)/2;
    }
    return s;
}

int main(){
    vector<int> arr = {1,3,9,89,23,21,6,1};
    cout << montainArray(arr, 8);


    return 0;
}
