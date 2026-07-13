#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int maximumPoints(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<vector<int>> dp(n, vector<int>(4, -1));
        return solve(n - 1, 3, mat, dp);
    }

    int solve(int idx, int last, vector<vector<int>>& mat, vector<vector<int>>& dp) {
        if (idx == 0) {
            int maxi = 0;
            for (int i = 0; i < 3; i++) {
                if (i != last) {
                    int points = mat[idx][i];
                    maxi = max(maxi, points);
                }
            }
            return maxi;
        }
        if (dp[idx][last] != -1)
            return dp[idx][last];
        int maxi = 0;
        for (int i = 0; i < 3; i++) {
            if (i != last) {
                int points = mat[idx][i] + solve(idx - 1, i, mat, dp);
                maxi = max(maxi, points);
            }
        }
        return dp[idx][last] = maxi;
    }
};