#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V);
        vector<int> visited(V, 0);
        stack<int> st;
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, adj, visited, st);
            }
        }
        vector<int> ans;
        while (st.size()) {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
    void dfs(int node, vector<vector<int>>& adj, vector<int>& visited, stack<int>& st) {
        visited[node] = 1;
        for (int adjacentNode : adj[node]) {
            if (!visited[adjacentNode]) {
                dfs(adjacentNode, adj, visited, st);
            }
        }
        st.push(node);
    }
};