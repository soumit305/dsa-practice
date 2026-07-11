#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> rank, parent, size;

   public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i < n + 1; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ultp_u = findUPar(u);
        int ultp_v = findUPar(v);
        if (ultp_u == ultp_v)
            return;
        if (rank[ultp_u] < rank[ultp_v]) {
            parent[ultp_u] = ultp_v;
        } else if (rank[ultp_v] < rank[ultp_u]) {
            parent[ultp_v] = ultp_u;
        } else {
            parent[ultp_v] = ultp_u;
            rank[ultp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ultp_u = findUPar(u);
        int ultp_v = findUPar(v);
        if (ultp_u == ultp_v)
            return;
        if (size[ultp_u] < size[ultp_v]) {
            parent[ultp_u] = ultp_v;
            size[ultp_v] += size[ultp_u];
        } else {
            parent[ultp_v] = ultp_u;
            size[ultp_u] += size[ultp_v];
        }
    }
};

class Solution {
   public:
    bool isValid(int x, int y, int n, int m) {
        return (x > -1 && x < n && y > -1 && y < m);
    }
    vector<int> numOfIslands(int n, int m, vector<vector<int>>& operators) {
        DisjointSet ds(n * m);
        int visited[n][m];
        memset(visited, 0, sizeof visited);
        int cnt = 0;
        vector<int> ans;
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, -1, 0, 1};
        for (int i = 0; i < operators.size(); i++) {
            int x = operators[i][0];
            int y = operators[i][1];
            int node = m * x + y;
            if (visited[x][y]) {
                ans.push_back(cnt);
                continue;
            }
            visited[x][y] = 1;
            cnt++;
            for (int idx = 0; idx < 4; idx++) {
                int nx = x + delrow[idx];
                int ny = y + delcol[idx];
                int nnode = m * nx + ny;
                if (isValid(nx, ny, n, m)) {
                    if (visited[nx][ny]) {
                        if (ds.findUPar(nnode) != ds.findUPar(node)) {
                            cnt--;
                            ds.unionBySize(node, nnode);
                        }
                    }
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};
