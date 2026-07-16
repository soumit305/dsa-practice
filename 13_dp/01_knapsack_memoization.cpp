#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int knapsack(int W, vector<int>& val, vector<int>& wt) {
        int n = val.size();
        vector<vector<int>> dp(n, vector<int>(W + 1, -1));
        return solve(n - 1, W, val, wt, dp);
    }
    int solve(int idx, int W, vector<int>& val, vector<int>& wt, vector<vector<int>>& dp) {
        if (W == 0)
            return 0;
        if (idx == 0) {
            if (wt[idx] <= W)
                return val[idx];
            else
                return 0;
        }
        if (dp[idx][W] != -1)
            return dp[idx][W];
        int notpick = solve(idx - 1, W, val, wt, dp);
        int pick = INT_MIN;
        if (wt[idx] <= W)
            pick = val[idx] + solve(idx - 1, W - wt[idx], val, wt, dp);
        return dp[idx][W] = max(pick, notpick);
    }
};