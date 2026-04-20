#include <bits/stdc++.h>
using namespace std;

// Problem: Largest Element in Array
// Approach: Single pass, track max
// Time: O(n), Space: O(1)

class Solution {
public:
    int largestElement(vector<int>& arr) {
        int maxVal = INT32_MIN;
        for (int x : arr) {
            if (x > maxVal) {
                maxVal = x;
            }
        }
        return maxVal;
    }
};

int main() {
    Solution s;  // create an instance of the class

    // Test 1: normal case
    vector<int> a1 = {3, 7, 2, 9, 5};
    cout << "Test 1: " << s.largestElement(a1) << endl;  // expect 9

    // Test 2: single element
    vector<int> a2 = {42};
    cout << "Test 2: " << s.largestElement(a2) << endl;  // expect 42

    // Test 3: all negatives
    vector<int> a3 = {-5, -2, -9, -1};
    cout << "Test 3: " << s.largestElement(a3) << endl;  // expect -1

    // Test 4: all same
    vector<int> a4 = {7, 7, 7, 7};
    cout << "Test 4: " << s.largestElement(a4) << endl;  // expect 7

    return 0;
}