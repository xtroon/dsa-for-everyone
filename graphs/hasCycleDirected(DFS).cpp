#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool dfs(int node, vector<int> adj[],
             vector<int> &vis, vector<int> &pathVis)
    {
        vis[node] = 1;
        pathVis[node] = 1;
        for (int nei : adj[node])
        {
            // Visit unvisited neighbour
            if (!vis[nei])
            {
                if (dfs(nei, adj, vis, pathVis))
                    return true;
            }
            // Neighbour already exists in current DFS path
            // => Back edge => Cycle
            else if (pathVis[nei])
            {
                return true;
            }
        }
        // Remove from current recursion path
        pathVis[node] = 0;
        return false;
    }

    bool isCycle(int V, vector<int> adj[])
    {
        vector<int> vis(V, 0);
        vector<int> pathVis(V, 0);
        // Handle disconnected graph
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (dfs(i, adj, vis, pathVis))
                    return true;
            }
        }
        return false;
    }
};

int main()
{

    // 0 -> 1 -> 2 -> 0 (Cycle)
    vector<int> adj[3];
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(0);

    Solution obj;

    cout << obj.isCycle(3, adj);

    return 0;
}