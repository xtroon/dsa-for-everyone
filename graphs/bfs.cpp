#include <bits/stdc++.h>
using namespace std;

vector<int> bfsTraversal(int V, vector<int> adj[]) {
    vector<int> bfs;
    vector<bool> vis(V, false);

    queue<int> q;
    q.push(0);
    vis[0] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        bfs.push_back(node);

        for (int nei : adj[node]) {
            if (!vis[nei]) {
                vis[nei] = true;
                q.push(nei);
            }
        }
    }

    return bfs;
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<int> adj[V];

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;

        // Undirected Graph
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> ans = bfsTraversal(V, adj);

    cout << "BFS Traversal: ";
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}