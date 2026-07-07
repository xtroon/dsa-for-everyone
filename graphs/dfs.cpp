#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], vector<int>& vis, vector<int>& ls){
    vis[node] = true;
    ls.push_back(node);

    for(auto it : adj[node]){
        if(!vis[it]){
            dfs(it, adj, vis, ls);
        }
    }
}

vector<int> dfsTraversal(int V, vector<int> adj[]) {
    vector<int> vis(V, false);
    int st = 0;
    vector<int> ls;
    dfs(st, adj, vis, ls);
    return ls;
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

    vector<int> ans = dfsTraversal(V, adj);

    cout << "DFS Traversal: ";
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}