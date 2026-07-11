#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> rank, parent;

   public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
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
};

int main() {
    DisjointSet ds(7);
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);

    if (ds.findUPar(3) == ds.findUPar(7))
        cout << "Same" << endl;
    else
        cout << "Not Same" << endl;

    ds.unionByRank(3, 7);

    if (ds.findUPar(3) == ds.findUPar(7))
        cout << "Same" << endl;
    else
        cout << "Not Same" << endl;

    return 0;
}