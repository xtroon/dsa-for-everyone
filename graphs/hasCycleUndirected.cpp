#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // ===================== BFS =====================

    bool bfs(int start, vector<int> adj[], vector<int>& vis) {

        // {current node, parent}
        queue<pair<int, int>> q;

        q.push({start, -1});
        vis[start] = 1;

        while (!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (int nei : adj[node]) {
                // Visit unvisited neighbour
                if (!vis[nei]) {
                    vis[nei] = 1;
                    q.push({nei, node});
                }
                // Visited neighbour which is NOT parent
                // => Cycle found
                else if (nei != parent) {
                    return true;
                }
            }
        }

        return false;
    }

    bool isCycleBFS(int V, vector<int> adj[]) {

        vector<int> vis(V, 0);
        // Handle disconnected graph
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (bfs(i, adj, vis))
                    return true;
            }
        }
        return false;
    }


    // ===================== DFS =====================

    bool dfs(int node, int parent, vector<int> adj[], vector<int>& vis) {
        vis[node] = 1;

        for (int nei : adj[node]) {
            // Visit unvisited neighbour
            if (!vis[nei]) {
                if (dfs(nei, node, adj, vis))
                    return true;
            }

            // Already visited and not parent
            // => Cycle found
            else if (nei != parent) {
                return true;
            }
        }
        return false;
    }

    bool isCycleDFS(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        // Handle disconnected graph
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (dfs(i, -1, adj, vis))
                    return true;
            }
        }

        return false;
    }
};

int main() {

    // Graph:
    //
    // 1 ----- 2
    //         |
    //         3
    //
    // No cycle

    vector<int> adj[4] = {
        {},
        {2},
        {1, 3},
        {2}
    };

    Solution obj;

    cout << obj.isCycleBFS(4, adj) << endl;
    cout << obj.isCycleDFS(4, adj) << endl;

    return 0;
}