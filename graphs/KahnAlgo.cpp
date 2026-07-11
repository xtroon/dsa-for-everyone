#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<int> topoSort(int V, vector<int> adj[]) {

        vector<int> indegree(V, 0);

        // Calculate indegree of every node
        for (int i = 0; i < V; i++) {
            for (int nei : adj[i]) {
                indegree[nei]++;
            }
        }

        queue<int> q;
        // Push all nodes having indegree = 0
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> topo;
        while (!q.empty()) {

            int node = q.front();
            q.pop();
            topo.push_back(node);

            for (int nei : adj[node]) {
                indegree[nei]--;
                if (indegree[nei] == 0)
                    q.push(nei);
            }
        }
        return topo;
    }
};

int main() {
    // Graph:
    //
    // 5 → 2 ← 4
    // ↓    ↓
    // 0 → 3 → 1
    int V = 6;
    vector<int> adj[6];
    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);
    Solution obj;
    vector<int> ans = obj.topoSort(V, adj);
    for (int x : ans)
        cout << x << " ";

    return 0;
}