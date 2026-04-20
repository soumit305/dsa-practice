#include <bits/stdc++.h>
using namespace std;

// Problem: Find the Missing Number
// https://takeuforward.org/arrays/find-the-missing-number-in-an-array/
// Approach: ?
// Time: O(?)
// Space: O(?)

class Solution {
   public:
    int missingNumber(vector<int>& arr, int n) {
        // your code
        int check = 0;
        for (int i = 1; i < n + 1; i++) {
            check = check ^ i;
        }
        for (int x : arr) {
            check = check ^ x;
        }
        return check;
    }
};

int main() {
    Solution s;

    // Test 1: missing in middle
    vector<int> a1 = {1, 2, 4, 5};
    cout << "Test 1: " << s.missingNumber(a1, 5) << endl;  // 3

    // Test 2: missing first
    vector<int> a2 = {2, 3, 4, 5};
    cout << "Test 2: " << s.missingNumber(a2, 5) << endl;  // 1

    // Test 3: missing last
    vector<int> a3 = {1, 2, 3, 4};
    cout << "Test 3: " << s.missingNumber(a3, 5) << endl;  // 5

    // Test 4: n=1 (empty array, missing is 1)
    vector<int> a4 = {};
    cout << "Test 4: " << s.missingNumber(a4, 1) << endl;  // 1

    // Test 5: n=2, missing first
    vector<int> a5 = {2};
    cout << "Test 5: " << s.missingNumber(a5, 2) << endl;  // 1

    // Test 6: unsorted input
    vector<int> a6 = {5, 2, 1, 4};
    cout << "Test 6: " << s.missingNumber(a6, 5) << endl;  // 3

    // Test 7: larger case
    vector<int> a7 = {1, 2, 3, 5, 6, 7, 8, 9, 10};
    cout << "Test 7: " << s.missingNumber(a7, 10) << endl;  // 4

    return 0;
}