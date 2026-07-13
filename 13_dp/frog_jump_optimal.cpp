#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int minCost(vector<int>& height) {
        int n = height.size();
        if (n == 0)
            return 0;
        int prev1 = 0;
        int prev2 = 0;
        return solve(n, height, prev1, prev2);
    }

    int solve(int n, vector<int>& height, int prev1, int prev2) {
        for (int i = 1; i < n; i++) {
            int first = prev1 + abs(height[i] - height[i - 1]);
            int second = INT_MAX;
            if (i > 1) {
                second = prev2 + abs(height[i] - height[i - 2]);
            }
            int curri = min(first, second);
            prev2 = prev1;
            prev1 = curri;
        }
        return prev1;
    }
};