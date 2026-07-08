#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool isBipartite(vector<vector<int>>& graph) {
        // Using DFS
        int n = graph.size();
        vector<int> visited(n, -1);
        for (int i = 0; i < n; i++) {
            if (visited[i] == -1) {
                if (!dfs(i, visited, graph))
                    return false;
            }
        }
        return true;
    }

    bool dfs(int node, vector<int>& visited, vector<vector<int>>& graph) {
        if (visited[node] == -1)
            visited[node] = 0;
        for (int adjacentNode : graph[node]) {
            if (visited[adjacentNode] == -1) {
                visited[adjacentNode] = !visited[node];
                if (!dfs(adjacentNode, visited, graph))
                    return false;
            } else {
                if (visited[adjacentNode] == visited[node])
                    return false;
            }
        }
        return true;
    }
};