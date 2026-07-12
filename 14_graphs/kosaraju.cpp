#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void dfs(int node, vector<int>& visited, vector<vector<int>>& adj, stack<int>& st) {
        visited[node] = 1;
        for (int adjacentNode : adj[node]) {
            if (!visited[adjacentNode]) {
                dfs(adjacentNode, visited, adj, st);
            }
        }
        st.push(node);
    }

    void dfs3(int node, vector<int>& visited, vector<int> adjT[]) {
        visited[node] = 1;
        for (int adjacentNode : adjT[node]) {
            if (!visited[adjacentNode]) {
                dfs3(adjacentNode, visited, adjT);
            }
        }
    }

    int kosaraju(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
        }

        vector<int> visited(V);
        stack<int> st;
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, visited, adj, st);
            }
        }

        vector<int> adjT[V];
        for (int i = 0; i < V; i++) {
            visited[i] = 0;
            for (int adjacentNode : adj[i]) {
                adjT[adjacentNode].push_back(i);
            }
        }

        int scc = 0;
        while (!st.empty()) {
            int node = st.top();
            st.pop();
            if (!visited[node]) {
                scc++;
                dfs3(node, visited, adjT);
            }
        }
        return scc;
    }
};