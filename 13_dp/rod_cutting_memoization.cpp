#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int cutRod(vector<int>& price) {
        int n = price.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solve(n - 1, n, price, dp);
    }
    int solve(int idx, int size, vector<int>& price, vector<vector<int>>& dp) {
        if (idx == 0) {
            return size * price[idx];
        }
        if (dp[idx][size] != -1)
            return dp[idx][size];
        int notpick = solve(idx - 1, size, price, dp);
        int pick = INT_MIN;
        int rodlength = idx + 1;
        if (size >= rodlength)
            pick = price[idx] + solve(idx, size - rodlength, price, dp);
        return dp[idx][size] = max(notpick, pick);
    }
};