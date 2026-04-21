#include <bits/stdc++.h>
using namespace std;

// Problem: Find the Number that Appears Once
// https://takeuforward.org/arrays/find-the-number-that-appears-once-and-the-other-numbers-twice/
// Approach: ?
// Time: O(?)
// Space: O(?)

class Solution {
   public:
    int findUnique(vector<int>& arr) {
        // your code
        int ans = 0;
        for (int x : arr) {
            ans = ans ^ x;
        }
        return ans;

        /*
        Hashmap Method
        */
        // unordered_map<int, int> map;
        // for (int x : arr) {
        //     if (map.find(x) != map.end()) {
        //         map.erase(x);
        //         continue;
        //     }
        //     map[x] = 1;
        // }
        // return map.begin()->first

        // Using Sets

        //     unordered_set<int>
        //         seen;
        // for (int x : arr) {
        //     if (seen.count(x)) {
        //         seen.erase(x);
        //     } else {
        //         seen.insert(x);
        //     }
        // }
        // return *seen.begin();  // only one element remains
    }
};

int main() {
    Solution s;

    // Test 1: unique in middle
    vector<int> a1 = {1, 1, 2, 3, 3, 4, 4};
    cout << "Test 1: " << s.findUnique(a1) << endl;  // 2

    // Test 2: unique first
    vector<int> a2 = {5, 1, 1, 2, 2};
    cout << "Test 2: " << s.findUnique(a2) << endl;  // 5

    // Test 3: unique last
    vector<int> a3 = {1, 1, 2, 2, 7};
    cout << "Test 3: " << s.findUnique(a3) << endl;  // 7

    // Test 4: single element
    vector<int> a4 = {42};
    cout << "Test 4: " << s.findUnique(a4) << endl;  // 42

    // Test 5: negative numbers
    vector<int> a5 = {-1, -1, -5, 2, 2};
    cout << "Test 5: " << s.findUnique(a5) << endl;  // -5

    // Test 6: zero involved
    vector<int> a6 = {0, 1, 1};
    cout << "Test 6: " << s.findUnique(a6) << endl;  // 0

    // Test 7: larger case
    vector<int> a7 = {4, 1, 2, 1, 2};
    cout << "Test 7: " << s.findUnique(a7) << endl;  // 4

    return 0;
}