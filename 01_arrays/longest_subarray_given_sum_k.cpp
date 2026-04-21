#include <bits/stdc++.h>
using namespace std;

// Problem: Longest Subarray with Sum K (positives only)
// https://takeuforward.org/data-structure/longest-subarray-with-given-sum-k/
// Approach: ?
// Time: O(?)
// Space: O(?)

class Solution {
   public:
    int longestSubarrayWithSumK(vector<int>& arr, long long k) {
        // your code
        int window1 = 0;
        int window2 = 0;
        int len = arr.size();
        long long sum = 0;
        int ans = 0;
        while (window2 < len) {
            sum += arr[window2];
            while (sum > k) {
                sum -= arr[window1];
                window1++;
            }
            if (sum == k) {
                ans = max(ans, window2 - window1 + 1);
            }
            window2++;
        }
        return ans;
    }
};

int main() {
    Solution s;

    // Test 1: answer in the middle
    vector<int> a1 = {2, 3, 5, 1, 9};
    cout << "Test 1: " << s.longestSubarrayWithSumK(a1, 10) << endl;  // 3

    // Test 2: entire array sums to k
    vector<int> a2 = {1, 2, 3, 4};
    cout << "Test 2: " << s.longestSubarrayWithSumK(a2, 10) << endl;  // 4

    // Test 3: no subarray sums to k
    vector<int> a3 = {1, 2, 3};
    cout << "Test 3: " << s.longestSubarrayWithSumK(a3, 100) << endl;  // 0

    // Test 4: single element equals k
    vector<int> a4 = {5};
    cout << "Test 4: " << s.longestSubarrayWithSumK(a4, 5) << endl;  // 1

    // Test 5: single element doesn't equal k
    vector<int> a5 = {5};
    cout << "Test 5: " << s.longestSubarrayWithSumK(a5, 3) << endl;  // 0

    // Test 6: multiple valid, pick longest
    vector<int> a6 = {1, 2, 1, 0, 1, 1, 0};
    cout << "Test 6: " << s.longestSubarrayWithSumK(a6, 4) << endl;  // 7

    // Test 7: k = 0 with zeros in array
    vector<int> a7 = {0, 0, 0, 1};
    cout << "Test 7: " << s.longestSubarrayWithSumK(a7, 0) << endl;  // 3

    // Test 8: empty
    vector<int> a8 = {};
    cout << "Test 8: " << s.longestSubarrayWithSumK(a8, 5) << endl;  // 0

    return 0;
}