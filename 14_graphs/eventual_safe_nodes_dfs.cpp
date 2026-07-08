#include <bits/stdc++.h>
using namespace std;

class Solution {
   private:
    bool dfs(int node, vector<int>& visited, vector<int>& pathVisited, vector<vector<int>>& graph,
             vector<int>& safeNodes) {
        visited[node] = 1;
        pathVisited[node] = 1;
        for (int adjacentNode : graph[node]) {
            if (!visited[adjacentNode]) {
                if (dfs(adjacentNode, visited, pathVisited, graph, safeNodes))
                    return true;
            } else if (pathVisited[adjacentNode])
                return true;
        }
        safeNodes[node] = 1;
        pathVisited[node] = 0;
        return false;
    }

   public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();

        // Detect a cycle
        vector<int> visited(V, 0);
        vector<int> pathVisited(V, 0);
        vector<int> safeNodes(V, 0);
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, visited, pathVisited, graph, safeNodes);
            }
        }

        vector<int> ans;
        for (int i = 0; i < V; i++) {
            if (safeNodes[i])
                ans.push_back(i);
        }
        return ans;
    }
};