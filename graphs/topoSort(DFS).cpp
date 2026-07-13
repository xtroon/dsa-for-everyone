#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void dfs(int node, vector<int> adj[], vector<int>& vis, stack<int>& st) {
        vis[node] = 1;
        for (int nei : adj[node]) {
            if (!vis[nei]) {
                dfs(nei, adj, vis, st);
            }
        }
        // Push after visiting all neighbours
        st.push(node);
    }

    vector<int> topoSort(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        stack<int> st;

        // Handle disconnected graph
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, adj, vis, st);
            }
        }
        vector<int> topo;
        while (!st.empty()) {
            topo.push_back(st.top());
            st.pop();
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

    for (int x : ans) cout << x << " ";
    return 0;
}