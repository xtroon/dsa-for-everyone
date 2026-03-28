#include <iostream>
#include <vector>
using namespace std;

bool rotate(vector<int>& arr) {
    int count = 0;
    int n = arr.size();
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]) count++;
    }
    if(arr[n-1]>arr[0]) count++;
    cout << count << endl;
    return count<=1;    

}

int main(){
    vector<int> nums = {2,1,3,4};
    cout << rotate(nums);
    return 0;
}