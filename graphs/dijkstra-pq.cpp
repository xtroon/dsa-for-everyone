#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int src) {
        // {distance, node in min-heap}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<int> dist(V, INT_MAX);

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            // Traverse all neighbours
            for (auto it : adj[node]) {
                int adjNode = it[0];
                int edgeWeight = it[1];

                // Relax the edge
                if (dis + edgeWeight < dist[adjNode]) {
                    dist[adjNode] = dis + edgeWeight;

                    pq.push({dist[adjNode], adjNode});
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