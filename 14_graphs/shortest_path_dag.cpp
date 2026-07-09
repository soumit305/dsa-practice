#include <bits/stdc++.h>
using namespace std;

class Solution {
   private:
    void dfs(int node, vector<int>& visited, vector<vector<pair<int, int>>>& adj, stack<int>& st) {
        visited[node] = 1;
        for (auto adjacentNode : adj[node]) {
            if (!visited[adjacentNode.first]) {
                dfs(adjacentNode.first, visited, adj, st);
            }
        }
        st.push(node);
    }

   public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int, int>>> adj(V);
        for (int i = 0; i < E; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int weight = edges[i][2];
            adj[u].push_back({v, weight});
        }

        stack<int> st;
        vector<int> visited(V, 0);
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, visited, adj, st);
            }
        }

        vector<int> shortestDist(V, INT_MAX);
        shortestDist[0] = 0;
        while (!st.empty()) {
            int node = st.top();
            st.pop();
            if (shortestDist[node] == INT_MAX)
                continue;
            for (auto it : adj[node]) {
                int adjacentNode = it.first;
                int weight = it.second;
                shortestDist[adjacentNode] =
                    min(shortestDist[adjacentNode], shortestDist[node] + weight);
            }
        }

        for (int& x : shortestDist)
            if (x == INT_MAX)
                x = -1;

        return shortestDist;
    }
};
