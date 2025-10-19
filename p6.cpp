#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v;
    int w;
};

int main() {
    int V, E, src;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    vector<Edge> edges(E);
    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < E; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    cout << "Enter source vertex: ";
    cin >> src;

    const int INF = 1e9;
    vector<int> dist(V, INF);
    dist[src] = 0;

    for (int i = 1; i <= V - 1; i++) {
        for (auto &edge : edges) {
            int u = edge.u;
            int v = edge.v;
            int w = edge.w;
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    bool negCycle = false;
    for (auto &edge : edges) {
        int u = edge.u;
        int v = edge.v;
        int w = edge.w;
        if (dist[u] != INF && dist[u] + w < dist[v]) {
            negCycle = true;
            break;
        }
    }

    if (negCycle) {
        cout << "\nNegative weight cycle detected! Shortest paths not valid.\n";
        return 0;
    }

    cout << "\nShortest distances from source " << src << ":\n";
    for (int i = 0; i < V; i++) {
        if (dist[i] == INF)
            cout << "Vertex " << i << ": Not Reachable\n";
        else
            cout << "Vertex " << i << ": " << max(0, dist[i]) << "\n";
    }

    return 0;
}
