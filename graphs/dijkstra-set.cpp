#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int src) {
        // {distance, node}
        set<pair<int, int>> st;

        vector<int> dist(V, INT_MAX);

        dist[src] = 0;
        st.insert({0, src});

        while (!st.empty()) {
            auto it = *(st.begin());

            int dis = it.first;
            int node = it.second;

            st.erase(it);

            // Traverse all neighbours
            for (auto edge : adj[node]) {
                int adjNode = edge[0];
                int edgeWeight = edge[1];

                // Relax the edge
                if (dis + edgeWeight < dist[adjNode]) {
                    // Remove previous distance if it exists
                    if (dist[adjNode] != INT_MAX) {
                        st.erase({dist[adjNode], adjNode});
                    }

                    dist[adjNode] = dis + edgeWeight;

                    st.insert({dist[adjNode], adjNode});
                }
            }
        }

        return dist;
    }
};

int main() {
    int V = 3;

    vector<vector<int>> adj[3];

    adj[0].push_back({1, 1});
    adj[0].push_back({2, 6});

    adj[1].push_back({2, 3});

    Solution obj;

    vector<int> ans = obj.dijkstra(V, adj, 0);

    for (int x : ans) cout << x << " ";

    return 0;
}