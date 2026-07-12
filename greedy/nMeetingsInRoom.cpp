#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> s = {1, 3, 0, 5, 8, 5};
    vector<int> f = {2, 4, 6, 7, 9, 9};

    // end, start, its id=ndx(1 based)
    vector<tuple<int, int, int>> meetings;

    for (int i = 0; i < s.size(); i++) {
        meetings.push_back({f[i], s[i], i + 1});
    }

    sort(meetings.begin(), meetings.end());

    int lastEnd = get<0>(meetings[0]);
    vector<int> ans = {get<2>(meetings[0])};

    for (int i = 1; i < meetings.size(); i++) {
        int st = get<1>(meetings[i]);

        if (st > lastEnd) {
            ans.push_back(get<2>(meetings[i]));
            lastEnd = get<0>(meetings[i]);
        }
    }

    sort(ans.begin(), ans.end());

    for (int x : ans) cout << x << " ";
    return 0;
}