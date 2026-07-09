#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // Using Topological Sort
        int V = graph.size();

        // Reverse the Graph (Reverse the directed nodes)
        vector<int> indegree(V);
        vector<vector<int>> revGraph(V);
        for (int i = 0; i < V; i++) {
            for (int j : graph[i]) {
                revGraph[j].push_back(i);
                indegree[i]++;
            }
        }

        // Topological Sort
        queue<int> q;
        vector<int> topoSort;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topoSort.push_back(node);
            for (int adjacentNode : revGraph[node]) {
                indegree[adjacentNode]--;
                if (indegree[adjacentNode] == 0)
                    q.push(adjacentNode);
            }
        }
        sort(topoSort.begin(), topoSort.end());
        return topoSort;
    }
};