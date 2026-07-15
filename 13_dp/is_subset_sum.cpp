#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));
        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }
        dp[0][arr[0]] = true;
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < sum + 1; j++) {
                int notpick = dp[i - 1][j];
                int pick = false;
                if (j >= arr[i]) {
                    pick = dp[i - 1][j - arr[i]];
                }
                dp[i][j] = notpick || pick;
            }
        }
        return dp[n - 1][sum];
    }
    bool solve(int idx, int sum, vector<int>& arr, vector<vector<int>>& dp) {
        if (sum == 0)
            return true;
        if (idx == 0)
            return (arr[idx] == sum);
        if (dp[idx][sum] != -1)
            return dp[idx][sum];
        int notpick = solve(idx - 1, sum, arr, dp);
        int pick = false;
        if (sum >= arr[idx]) {
            pick = solve(idx - 1, sum - arr[idx], arr, dp);
        }
        return dp[idx][sum] = notpick || pick;
    }
};