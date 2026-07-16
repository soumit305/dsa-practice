#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        vector<int> prev(capacity + 1, 0), cur(capacity + 1, 0);
        for (int weight = 0; weight <= capacity; weight++)
            prev[weight] = (weight / wt[0]) * val[0];
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= capacity; j++) {
                int notpick = prev[j];
                int pick = 0;
                if (j >= wt[i])
                    pick = val[i] + cur[j - wt[i]];
                cur[j] = max(notpick, pick);
            }
            prev = cur;
        }
        return prev[capacity];
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