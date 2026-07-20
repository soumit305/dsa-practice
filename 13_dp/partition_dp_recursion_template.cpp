#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int matrixMultiplication(vector<int>& arr) {
        return solve(1, arr.size() - 1, arr);
    }
    int solve(int i, int j, vector<int>& arr) {
        if (i == j)
            return 0;
        int mini = 1e9;
        for (int k = i; k < j; k++) {
            int steps = (arr[i - 1] * arr[k] * arr[j]) + solve(i, k, arr) + solve(k + 1, j, arr);
            mini = min(mini, steps);
        }
        return mini;
    }
};