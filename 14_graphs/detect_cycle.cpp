#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<int> visited(V, 0);
        vector<vector<int>> adj(V);
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (detectCycle(adj, V, visited, i))
                    return true;
            }
        }
        return false;
    }

    bool detectCycle(vector<vector<int>> adj, int V, vector<int>& visited, int source) {
        visited[source] = 1;
        queue<pair<int, int>> q;
        q.push({source, -1});
        while (q.size()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for (int adjacentNode : adj[node]) {
                if (!visited[adjacentNode]) {
                    visited[adjacentNode] = 1;
                    q.push({adjacentNode, node});
                } else if (parent != adjacentNode) {
                    return true;
                }
            }
        }
        return false;
    }
};
