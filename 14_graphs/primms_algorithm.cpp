#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(V);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        // Priority Queue -> {wt,node,parent}
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        vector<pair<int, int>> mstEdges;
        vector<int> visited(V, 0);
        int sum = 0;
        pq.push({0, {0, -1}});

        // Primm's Algorithm
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int weight = it.first;
            int node = it.second.first;
            int parent = it.second.second;
            if (visited[node])
                continue;
            visited[node] = 1;
            mstEdges.push_back({node, parent});
            sum += weight;
            for (auto adjacent : adj[node]) {
                int nnode = adjacent.first;
                int nweight = adjacent.second;
                if (!visited[nnode]) {
                    pq.push({nweight, {nnode, node}});
                }
            }
        }

        return sum;
    }
};