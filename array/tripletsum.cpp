// problem link- https://www.naukri.com/code360/problems/three-sum_6922132
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> pairSum(vector<int> &arr, int s) {
    // Write your code here.
    set<vector<int>> ans;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = i + 1; j < arr.size(); j++) {
            for (int k = j + 1; k < arr.size(); k++) {
                vector<int> temp;
                if ((arr[i] + arr[j] + arr[k]) == s) {
                    temp = {arr[i], arr[j], arr[k]};
                    sort(temp.begin(), temp.end());
                    ans.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> answer(ans.begin(), ans.end());
    return answer;
}

int main() {
    int n, s;
    cin >> n >> s;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<vector<int>> result = pairSum(arr, s);

    for (auto pair : result) {
        cout << pair[0] << " " << pair[1] << " " << pair[2] << endl;
    }
    return 0;
}