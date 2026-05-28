#include <bits/stdc++.h>
using namespace std;

// Problem: Two Sum
// Link: https://leetcode.com/problems/two-sum/
// Time: O(?)
// Space: O(?)
/*
The approach :
(write your reasoning out loud here before you code)

Brute force:  ...
Better:       ...
Optimal:      ...

Hint to recognize the pattern (read only if stuck after thinking):
  For each element x, the partner you need is (target - x). If you
  have already seen that partner, you have your pair. Store value->index
  in a hashmap as you go. One pass -> O(n) time, O(n) space.
  Caveat: sort + two pointers is O(n log n) but LOSES original indices
  unless you carry (value, index) pairs.
*/

class Solution {
   public:
    // Return the indices {i, j} of the two numbers summing to target.
    // Assume exactly one solution exists.
    vector<int> twoSum(vector<int>& arr, int target) {
        unordered_map<int, int> map;
        int length = arr.size();
        for (int i = 0; i < length; i++) {
            if (map.find(target - arr[i]) != map.end()) {
                return {map.at(target - arr[i]), i};
            }
            map.insert({arr[i], i});
        }
        return {};
    }
};

int main() {
    // test cases
    Solution s;

    auto printPair = [](vector<int> v) {
        sort(v.begin(), v.end());  // order-independent display
        cout << "[";
        for (size_t i = 0; i < v.size(); ++i) {
            cout << v[i];
            if (i + 1 < v.size())
                cout << ", ";
        }
        cout << "]" << endl;
    };

    vector<int> a1 = {2, 7, 11, 15};
    cout << "Test 1 (expect [0, 1]):  ";
    printPair(s.twoSum(a1, 9));

    vector<int> a2 = {3, 2, 4};
    cout << "Test 2 (expect [1, 2]):  ";
    printPair(s.twoSum(a2, 6));

    vector<int> a3 = {3, 3};
    cout << "Test 3 (expect [0, 1]):  ";
    printPair(s.twoSum(a3, 6));

    vector<int> a4 = {-3, 4, 3, 90};
    cout << "Test 4 (expect [0, 2]):  ";
    printPair(s.twoSum(a4, 0));

    vector<int> a5 = {0, 4, 3, 0};
    cout << "Test 5 (expect [0, 3]):  ";
    printPair(s.twoSum(a5, 0));

    vector<int> a6 = {5, 75, 25};
    cout << "Test 6 (expect [1, 2]):  ";  // must NOT reuse index 0 twice
    printPair(s.twoSum(a6, 100));

    return 0;
}