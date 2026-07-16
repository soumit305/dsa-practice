#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return solve(n - 1, target, arr, dp);
    }
    int solve(int idx, int target, vector<int>& arr, vector<vector<int>>& dp) {
        if (idx == 0) {
            if (target == 0 && arr[0] == 0)
                return 2;
            if (target == 0 || target == arr[0])
                return 1;
            return 0;
        }
        if (dp[idx][target] != -1)
            return dp[idx][target];
        int nonpick = solve(idx - 1, target, arr, dp);
        int pick = 0;
        if (target >= arr[idx]) {
            pick = solve(idx - 1, target - arr[idx], arr, dp);
        }
        return dp[idx][target] = nonpick + pick;
    }
};