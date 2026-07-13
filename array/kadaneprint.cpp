// problem link- https://leetcode.com/problems/maximum-subarray/

#include <bits/stdc++.h>
using namespace std;

vector<int> maxSubarray(vector<int> nums) {
    int sum = 0;        // Currentsum count
    int ans = INT_MIN;  // max sum count
    int start = 0;      // track start or ending index
    int startIdx = -1, endIdx = -1;
    vector<int> res;

    for (int i = 0; i < nums.size(); i++) {
        if (sum == 0) start = i;
        sum = sum + nums[i];

        if (sum > ans) {
            ans = sum;
            startIdx = start;
            endIdx = i;
        }

        if (sum < 0) sum = 0;
    }

    for (int i = startIdx; i <= endIdx; i++) {
        res.push_back(nums[i]);
    }
    return res;
}

void print(vector<int> arr) {
    for (int i : arr) {
        cout << i << " ";
    }
}

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    vector<int> ans = maxSubarray(nums);
    print(ans);

    return 0;
}