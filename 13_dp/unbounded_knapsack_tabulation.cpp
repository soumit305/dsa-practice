#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));
        for (int weight = 0; weight <= capacity; weight++)
            dp[0][weight] = (weight / wt[0]) * val[0];
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= capacity; j++) {
                int notpick = dp[i - 1][j];
                int pick = 0;
                if (j >= wt[i])
                    pick = val[i] + dp[i][j - wt[i]];
                dp[i][j] = max(notpick, pick);
            }
        }
        return dp[n - 1][capacity];
        // return solve(n-1,val,wt,capacity,dp);
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