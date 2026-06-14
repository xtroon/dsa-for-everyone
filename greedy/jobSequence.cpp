#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> jobSequence(vector<int>& deadline, vector<int>& profit) {
        vector<pair<int, int>> jobs;
        int maxDeadline = 0;

        for(int i=0; i< profit.size(); i++){
            jobs.push_back({profit[i], deadline[i]});
            maxDeadline++;
        }

        sort(jobs.rbegin(), jobs.rend());

        vector<int> slots(maxDeadline+1, -1);
        
        int cnt = 0, maxProfit = 0;
        for(int i=0; i< profit.size(); i++){
            for(int j = jobs[i].second; j>=1; j--){
                if(slots[j] == -1){
                    slots[j] = i;
                    cnt++;
                    maxProfit += jobs[i].first;
                    break;
                }
            }
        }
        return {cnt, maxProfit};
    }
};

int main() {
    Solution obj;

    vector<int> deadline = {2, 1, 2, 1, 1};
    vector<int> profit = {100, 19, 27, 25, 15};

    for(auto it : obj.jobSequence(deadline, profit)){
        cout << it << " ";
    }

    return 0;
}