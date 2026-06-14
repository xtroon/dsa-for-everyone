#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        int i = 0, j = 0;

        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());

        int maxCnt = 0, cnt = 0;

        while (i < arr.size()) {
            if (arr[i] <= dep[j]) {
                cnt++;
                i++;
            } else {
                cnt--;
                j++;
            }

            maxCnt = max(maxCnt, cnt);
        }

        return maxCnt;
    }
};

int main() {
    Solution obj;

    vector<int> arr = {900, 940, 950, 1100, 1500, 1800};
    vector<int> dep = {910, 1200, 1120, 1130, 1900, 2000};

    cout << obj.minPlatform(arr, dep) << endl;

    return 0;
}