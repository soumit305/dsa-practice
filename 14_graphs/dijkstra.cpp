#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> dijkstra(int V, vector<vector<int>>& edges, int src) {
        // Create Adjacency List
        vector<vector<pair<int, int>>> adj(V);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        // Dijkstra
        // PQ -> {dist,node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(V, INT_MAX);
        pq.push({0, src});
        dist[src] = 0;
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int weight = it.first;
            int node = it.second;
            for (auto adjacent : adj[node]) {
                int adjacentNode = adjacent.first;
                int adjacentWeight = adjacent.second;
                if (weight + adjacentWeight < dist[adjacentNode]) {
                    dist[adjacentNode] = weight + adjacentWeight;
                    pq.push({weight + adjacentWeight, adjacentNode});
                }
            }
        }
        return dist;
    }
};