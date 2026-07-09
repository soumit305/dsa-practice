#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int shortestPath(int V, vector<vector<int>>& edges, int src, int dest) {
        vector<vector<int>> adj(V);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // bfs
        queue<int> q;
        q.push(src);
        vector<int> visited(V, 0);
        vector<int> dist(V, -1);
        dist[src] = 0;
        visited[src] = 1;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int adjacentNode : adj[node]) {
                if (!visited[adjacentNode]) {
                    visited[adjacentNode] = 1;
                    dist[adjacentNode] = dist[node] + 1;
                    q.push(adjacentNode);
                }
            }
        }
        return dist[dest] - dist[src];
    }
};
