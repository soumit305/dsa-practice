#include <bits/stdc++.h>
using namespace std;

// Problem: Longest Consecutive Sequence
// https://takeuforward.org/data-structure/longest-consecutive-sequence-in-an-array/
// Approach: ?
// Time: O(?)
// Space: O(?)

class Solution {
   public:
    int longestConsecutive(vector<int>& arr) {
        unordered_set<int> set;
        int max = 1;
        int check;
        int current_count = 0;
        int len = arr.size();
        if (len == 0)
            return 0;
        for (int x : arr) {
            set.insert(x);
        }
        for (auto x : set) {
            if (set.find(x - 1) == set.end()) {
                check = x;
                while (set.find(check) != set.end()) {
                    check++;
                    current_count++;
                }
            }
            if (current_count > max) {
                max = current_count;
            }
            current_count = 0;
        }
        return max;
    }
};

int main() {
    Solution s;

    vector<int> a1 = {100, 4, 200, 1, 3, 2};
    cout << "Test 1: " << s.longestConsecutive(a1) << endl;  // 4

    vector<int> a2 = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    cout << "Test 2: " << s.longestConsecutive(a2) << endl;  // 9

    vector<int> a3 = {1, 2, 0, 1};
    cout << "Test 3: " << s.longestConsecutive(a3) << endl;  // 3

    vector<int> a4 = {};
    cout << "Test 4: " << s.longestConsecutive(a4) << endl;  // 0

    vector<int> a5 = {5};
    cout << "Test 5: " << s.longestConsecutive(a5) << endl;  // 1

    vector<int> a6 = {1, 2, 3, 4, 5};
    cout << "Test 6: " << s.longestConsecutive(a6) << endl;  // 5

    vector<int> a7 = {10, 20, 30};
    cout << "Test 7: " << s.longestConsecutive(a7) << endl;  // 1

    vector<int> a8 = {-1, 0, 1, 2};
    cout << "Test 8: " << s.longestConsecutive(a8) << endl;  // 4

    return 0;
}