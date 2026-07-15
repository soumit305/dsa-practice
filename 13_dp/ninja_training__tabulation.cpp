#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int maximumPoints(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<vector<int>> dp(n, vector<int>(4, -1));
        dp[0][0] = max(mat[0][1], mat[0][2]);
        dp[0][1] = max(mat[0][0], mat[0][2]);
        dp[0][2] = max(mat[0][0], mat[0][1]);
        dp[0][3] = max(mat[0][0], max(mat[0][1], mat[0][2]));
        for (int task = 1; task < n; task++) {
            for (int last = 0; last < 3; last++) {
                int maxi = 0;
                for (int i = 0; i < 3; i++) {
                    if (i != last) {
                        int points = mat[task][i] + dp[task - 1][i];
                        maxi = max(maxi, points);
                    }
                }
                dp[task][last] = maxi;
            }
        }
        return max(dp[n - 1][0], max(dp[n - 1][1], dp[n - 1][2]));
    }
};