#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int minCost(vector<int>& height) {
        int n = height.size();
        if (n == 0)
            return 0;
        vector<int> dp(n, -1);
        dp[0] = 0;
        return solve(n, height, dp);
    }

    int solve(int n, vector<int>& height, vector<int>& dp) {
        for (int i = 1; i < n; i++) {
            int first = dp[i - 1] + abs(height[i] - height[i - 1]);
            int second = INT_MAX;
            if (i > 1) {
                second = dp[i - 2] + abs(height[i] - height[i - 2]);
            }
            dp[i] = min(first, second);
        }
        return dp[n - 1];
    }
};