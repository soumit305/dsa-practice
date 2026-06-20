/*
 * Reverse Pairs
 * https://takeuforward.org/data-structure/count-reverse-pairs/   (LeetCode 493)
 *
 * Time:  O(n log n)   -- merge sort; each merge = O(n) count pass + O(n) merge
 * Space: O(n)         -- temp buffer during merge
 */

#include <bits/stdc++.h>
using namespace std;

/* The approach:
 * Merge-sort counting. A reverse pair is (i, j) with i < j and nums[i] > 2*nums[j].
 * The pairs split into three buckets: both indices in the left half, both in the right,
 * or one across. Recursion handles the within-half buckets for free; findPairs counts the
 * CROSS pairs while both halves are still sorted. The 2x factor differs from the merge's
 * own comparison, so the cross count needs its OWN pass (findPairs) BEFORE merge fuses the
 * halves and erases the left/right boundary. Two sorted halves => pt2 only moves forward
 * => O(n) per merge. Cast to long: 2*nums[j] overflows int near +/-INT_MAX.
 */

class Solution {
   public:
    int findPairs(vector<int>& nums, int low, int mid, int high) {
        int cnt = 0;
        int pt1 = low;
        int pt2 = mid + 1;
        while (pt1 <= mid && pt2 <= high) {
            while (pt2 <= high && (long)nums[pt1] > (long)2 * nums[pt2]) {
                pt2++;
            }
            cnt += pt2 - (mid + 1);
            pt1++;
        }
        while (pt1 <= mid) {
            cnt += high - mid;
            pt1++;
        }
        return cnt;
    }

    int merge(vector<int>& nums, int low, int mid, int high) {
        vector<int> res;
        int left = low;
        int right = mid + 1;
        int cnt = findPairs(nums, low, mid, high);
        while (left <= mid && right <= high) {
            if (nums[left] <= nums[right]) {
                res.push_back(nums[left]);
                left++;
            } else {
                res.push_back(nums[right]);
                right++;
            }
        }
        while (left <= mid) {
            res.push_back(nums[left]);
            left++;
        }
        while (right <= high) {
            res.push_back(nums[right]);
            right++;
        }
        for (int i = low; i <= high; i++) {
            nums[i] = res[i - low];
        }
        return cnt;
    }

    int mergeSort(vector<int>& nums, int low, int high) {
        int count = 0;
        if (low >= high)
            return count;
        int mid = (low + high) / 2;
        count += mergeSort(nums, low, mid);
        count += mergeSort(nums, mid + 1, high);
        count += merge(nums, low, mid, high);
        return count;
    }

    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};

int main() {
    Solution sol;

    vector<int> t1 = {1, 3, 2, 3, 1};
    cout << "Test 1: " << sol.reversePairs(t1) << "  (expected 2)" << endl;

    vector<int> t2 = {2, 4, 3, 5, 1};
    cout << "Test 2: " << sol.reversePairs(t2) << "  (expected 3)" << endl;

    // edge: values at +/-INT_MAX -- the case that overflowed/crashed earlier
    vector<int> t3 = {2147483647, 2147483647, -2147483647, -2147483647, -2147483647, 2147483647};
    cout << "Test 3: " << sol.reversePairs(t3) << "  (expected 9)" << endl;

    return 0;
}