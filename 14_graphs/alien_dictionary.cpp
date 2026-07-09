#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    string findOrder(vector<string>& words) {
        // Forming Graph from Dictionary
        int numWords = words.size();
        unordered_map<char, int> indegree;
        unordered_map<char, vector<char>> adj;

        for (auto& w : words)  // PASS 1: every letter exists, indegree 0
            for (char c : w)
                indegree.emplace(c, 0);

        for (int i = 1; i < numWords; i++) {
            string &a = words[i - 1], &b = words[i];
            int j = 0, m = min(a.size(), b.size());
            while (j < m && a[j] == b[j])
                j++;
            if (j == m) {
                if (a.size() > b.size())
                    return "";  // bug-1 check lives here
            } else {
                adj[a[j]].push_back(b[j]);  // first difference = one edge
                indegree[b[j]]++;
            }
        }

        queue<char> q;
        for (auto it : indegree) {
            if (it.second == 0)
                q.push(it.first);
        }

        string ans;
        while (!q.empty()) {
            char node = q.front();
            q.pop();
            ans.push_back(node);
            for (char adjacentNode : adj[node]) {
                indegree[adjacentNode]--;
                if (indegree[adjacentNode] == 0)
                    q.push(adjacentNode);
            }
        }
        return (ans.size() < indegree.size()) ? "" : ans;
    }
};