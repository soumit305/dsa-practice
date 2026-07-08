#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool isCyclic(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V);
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        vector<int> visited(V, 0);
        vector<int> pathVisited(V, 0);
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfs(i, adj, visited, pathVisited))
                    return true;
            }
        }
        return false;
    }
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& visited, vector<int>& pathVisited) {
        visited[node] = 1;
        pathVisited[node] = 1;
        for (int adjacentNode : adj[node]) {
            if (!visited[adjacentNode]) {
                if (dfs(adjacentNode, adj, visited, pathVisited))
                    return true;
            } else {
                if (pathVisited[adjacentNode])
                    return true;
            }
        }
        pathVisited[node] = 0;
        return false;
    }
};