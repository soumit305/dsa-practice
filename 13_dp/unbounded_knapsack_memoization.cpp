#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        vector<vector<int>> dp(n, vector<int>(capacity + 1, -1));
        return solve(n - 1, val, wt, capacity, dp);
    }
    int solve(int idx, vector<int>& val, vector<int>& wt, int capacity, vector<vector<int>>& dp) {
        if (idx == 0) {
            return (capacity / wt[idx]) * val[idx];
        }
        if (dp[idx][capacity] != -1)
            return dp[idx][capacity];
        int notpick = solve(idx - 1, val, wt, capacity, dp);
        int pick = 0;
        if (capacity >= wt[idx])
            pick = val[idx] + solve(idx, val, wt, capacity - wt[idx], dp);
        return dp[idx][capacity] = max(notpick, pick);
    }
};