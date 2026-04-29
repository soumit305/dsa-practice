#include <bits/stdc++.h>
using namespace std;

// Problem: Longest Subarray with Sum K (positives, negatives, zeros)
// https://takeuforward.org/arrays/longest-subarray-with-sum-k-postives-and-negatives/
// Approach: ?
// Time: O(?)
// Space: O(?)

class Solution {
   public:
    int longestSubarrayWithSumK(vector<int>& arr, long long k) {
        unordered_map<long long, int> firstSeen;  // prefix sum -> earliest index
        long long sum = 0;
        int ans = 0;

        for (int i = 0; i < (int)arr.size(); i++) {
            sum += arr[i];

            // Case 1: the whole prefix [0..i] itself sums to k
            if (sum == k) {
                ans = max(ans, i + 1);
            }

            // Case 2: some earlier prefix + stuff-between = k
            // i.e., current sum - earlier sum = k
            // i.e., earlier sum = current sum - k
            if (firstSeen.count(sum - k)) {
                ans = max(ans, i - firstSeen[sum - k]);
            }

            // Record current prefix sum if this is its first occurrence
            if (firstSeen.find(sum) == firstSeen.end()) {
                firstSeen[sum] = i;
            }
        }

        return ans;
    }
};

int main() {
    Solution s;

    // Test 1: whole array sums to k
    vector<int> a1 = {10, 5, 2, 7, 1, -10};
    cout << "Test 1: " << s.longestSubarrayWithSumK(a1, 15) << endl;  // 6

    // Test 2: standard positives only (should still work)
    vector<int> a2 = {2, 3, 5, 1, 9};
    cout << "Test 2: " << s.longestSubarrayWithSumK(a2, 10) << endl;  // 3

    // Test 3: negatives cause cancellation
    vector<int> a3 = {-1, 1, 1};
    cout << "Test 3: " << s.longestSubarrayWithSumK(a3, 1) << endl;  // 3

    // Test 4: k = 0 with mixed signs
    vector<int> a4 = {1, -1, 2, -2, 3};
    cout << "Test 4: " << s.longestSubarrayWithSumK(a4, 0) << endl;  // 4

    // Test 5: k = 0 no valid subarray
    vector<int> a5 = {1, 2, 3};
    cout << "Test 5: " << s.longestSubarrayWithSumK(a5, 0) << endl;  // 0

    // Test 6: all negatives
    vector<int> a6 = {-1, -2, -3, -4};
    cout << "Test 6: " << s.longestSubarrayWithSumK(a6, -6)
         << endl;  // 3 (subarray [-1,-2,-3] or [-2,-4]... wait)
    // actually: [-1,-2,-3]=-6 length 3; [-2,-4]... no -4 is last. [-2,-3,-4]=-9. [-1,-2]=-3. So
    // answer is 3.

    // Test 7: single element equals k
    vector<int> a7 = {5};
    cout << "Test 7: " << s.longestSubarrayWithSumK(a7, 5) << endl;  // 1

    // Test 8: empty
    vector<int> a8 = {};
    cout << "Test 8: " << s.longestSubarrayWithSumK(a8, 5) << endl;  // 0

    // Test 9: answer is proper prefix
    vector<int> a9 = {1, 2, 3, -3, 10};
    cout << "Test 9: " << s.longestSubarrayWithSumK(a9, 3)
         << endl;  // 4 (the subarray [1,2,3,-3] sums to 3, length 4; also [3] and [1,2] are length
                   // 1 and 2)

    return 0;
}