#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> shortestPath(int V, vector<vector<int>>& edges, int src, int dest) {
        vector<vector<pair<int, int>>> adj(V + 1);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        vector<int> parent(V + 1);
        for (int i = 0; i < V + 1; i++)
            parent[i] = i;
        vector<int> dist(V + 1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, dest});
        dist[dest] = 0;
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int distance = it.first;
            int node = it.second;
            for (auto adjacent : adj[node]) {
                int adjacentWeight = adjacent.second;
                int adjacentNode = adjacent.first;
                if (distance + adjacentWeight < dist[adjacentNode]) {
                    dist[adjacentNode] = distance + adjacentWeight;
                    pq.push({dist[adjacentNode], adjacentNode});
                    parent[adjacentNode] = node;
                }
            }
        }
        if (dist[src] == INT_MAX)
            return {-1};
        int node = src;
        vector<int> path = {src};
        while (node != dest) {
            int best = -1;
            for (auto [u, w] : adj[node])
                if (dist[node] == w + dist[u] && (best == -1 || u < best))
                    best = u;
            node = best;
            path.push_back(node);
        }
        return path;
    }
};