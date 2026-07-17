#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string t = s;
        reverse(t.begin(), t.end());
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n][n];
        // return longestCommonSubseq(n,n,s,t,dp);
    }
    int longestCommonSubseq(int idx1, int idx2, string s, string t, vector<vector<int>>& dp) {
        if (idx1 == 0 || idx2 == 0)
            return 0;
        if (dp[idx1][idx2] != -1)
            return dp[idx1][idx2];
        if (s[idx1 - 1] == t[idx2 - 1])
            return dp[idx1][idx2] = 1 + longestCommonSubseq(idx1 - 1, idx2 - 1, s, t, dp);
        else {
            return dp[idx1][idx2] = max(longestCommonSubseq(idx1 - 1, idx2, s, t, dp),
                                        longestCommonSubseq(idx1, idx2 - 1, s, t, dp));
        }
    }
};