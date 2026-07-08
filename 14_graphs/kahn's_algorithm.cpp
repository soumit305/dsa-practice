#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<int> indegree(V);
        vector<vector<int>> adj(V);
        queue<int> q;
        vector<int> topoSort;
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            indegree[edges[i][1]]++;
        }
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topoSort.push_back(node);
            for (int adjacentNode : adj[node]) {
                indegree[adjacentNode]--;
                if (indegree[adjacentNode] == 0)
                    q.push(adjacentNode);
                ;
            }
        }
        return topoSort;
    }
};