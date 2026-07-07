#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;
template <typename T>

class Graph {
public:
    unordered_map<T, list<T>> adj;

    // direction = 0 -> Undirected
    // direction = 1 -> Directed
    void addEdge(T u, T v, bool direction) {

        // Edge from u to v
        adj[u].push_back(v);

        // If undirected, also add edge from v to u
        if (direction == 0) {
            adj[v].push_back(u);
        }
    }

    void printAdjList() {

        for (auto i : adj) {

            cout << i.first << " -> ";

            for (auto j : i.second) {
                cout << j << " ";
            }

            cout << endl;
        }
    }
};

int main() {

    Graph<int> g;

    int n, m;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;


    cout << "Enter the edges:\n";

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, 0);
    }

    cout << "\nAdjacency List:\n";
    g.printAdjList();

    return 0;
}