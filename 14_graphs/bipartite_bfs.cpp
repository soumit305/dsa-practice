#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool isBipartite(vector<vector<int>>& graph) {
        // Using BFS
        int n = graph.size();
        vector<int> visited(n, -1);
        for (int i = 0; i < n; i++) {
            if (visited[i] == -1) {
                if (!bfs(i, visited, graph))
                    return false;
            }
        }
        return true;
    }

    bool bfs(int source, vector<int>& visited, vector<vector<int>>& graph) {
        queue<pair<int, int>> q;
        q.push({source, 0});
        visited[source] = 0;
        while (q.size()) {
            int node = q.front().first;
            int color = q.front().second;
            q.pop();
            for (int adjacentNode : graph[node]) {
                if (visited[adjacentNode] == -1) {
                    visited[adjacentNode] = !color;
                    q.push({adjacentNode, !color});
                } else {
                    if (visited[adjacentNode] == color)
                        return false;
                }
            }
        }
        return true;
    }
};