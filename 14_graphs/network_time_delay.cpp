#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (int i = 0; i < times.size(); i++) {
            int u = times[i][0];
            int v = times[i][1];
            int wt = times[i][2];
            adj[u].push_back({v, wt});
        }

        // PQ -> {time, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> minTime(n + 1, INT_MAX);
        pq.push({0, k});
        minTime[k] = 0;

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int curr_time = it.first;
            int curr_node = it.second;
            for (auto adjacent : adj[curr_node]) {
                int ntime = adjacent.second;
                int nnode = adjacent.first;
                if (curr_time + ntime < minTime[nnode]) {
                    minTime[nnode] = curr_time + ntime;
                    pq.push({curr_time + ntime, nnode});
                }
            }
        }

        int minimumTimeForAll = INT_MIN;
        for (int i = 1; i < minTime.size(); i++) {
            if (minTime[i] == INT_MAX)
                return -1;
            minimumTimeForAll = max(minimumTimeForAll, minTime[i]);
        }
        return minimumTimeForAll;
    }
};