#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<int>& arr, int k) {
    int n = arr.size();
    k = k%n;
    vector<int> rotated(n);
    for(int i=0;i <n; i++){
        rotated[(i+k)%n] = arr[i];
    }
    for(int i =0; i<n;i++){
        arr[i] = rotated[i];
    }

}

int main(){
    vector<int> nums = {1,2,3,4,5,6,7};
    int k;
    cin >> k;
    rotate(nums,k);
    for(int i=0; i< nums.size(); i++){
        cout << nums[i] << " ";
    }
    return 0;
}