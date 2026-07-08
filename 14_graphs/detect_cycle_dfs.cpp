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
                if (detectCycleDFS(adj, visited, i, -1))
                    return true;
            }
        }
        return false;
    }

    bool detectCycleDFS(vector<vector<int>>& adj, vector<int>& visited, int currentNode,
                        int parentNode) {
        visited[currentNode] = 1;
        for (int adjacentNode : adj[currentNode]) {
            if (!visited[adjacentNode]) {
                if (detectCycleDFS(adj, visited, adjacentNode, currentNode))
                    return true;
            } else if (adjacentNode != parentNode)
                return true;
        }
        return false;
    }
};
